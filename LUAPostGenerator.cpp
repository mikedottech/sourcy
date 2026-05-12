// LUAPostGenerator.cpp — Writes the per-file and master Lua output files to disk.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include "LUAPostGenerator.h"
#include <fstream>
#include <algorithm>
#include <string>
#include <ctime>
#include "Version.h"

std::string LUAPostGenerator::date_string()
{
	time_t rawtime;
	std::time(&rawtime);
	struct tm *tinfo = std::localtime(&rawtime);
	char buffer[12];
	strftime(buffer, 12, "%F", tinfo);
	return std::string(buffer);
}

bool LUAPostGenerator::generateFiles(std::list<CompilationUnit> & lcu)
{
	// Check for state duplicates across files
	// overrides? warn!
	std::list<std::string> genFilenames;
	std::string path;
	std::string entityName = lcu.front().getEntityName();

	// Header

	std::string headerV =
				"--[[\n"
				"   %s\n"
				"   Generated from %s\n"
				"   on %s.\n"
				"\n"
				"   by Sourcy Code Translator\n"
				"   (c) 2012 - radexx\n"
				"\n"
				"   Runtime version: %s\n"
				"\n]]\n\n"
				;

	std::string headerM =
				"--[[\n"
				"   %s\n"
				"   Master file for %s\n"
				"   Generated on %s.\n"
				"\n"
				"   by Sourcy Code Translator\n"
				"   (c) 2012 - radexx\n"
				"\n"
				"  Runtime version: %s\n"
				"\n]]\n\n"
				;


	char hdrBuffer[2048];
	const std::string dateStr = date_string();

	while(!lcu.empty())
	{
		CompilationUnit & cu		= lcu.front();
		std::ofstream file;
		std::string filename		= cu.getSourceFile();
		
		std::string originalFname;

		// Accept either separator on input; emit POSIX-style on output (Lua
		// handles '/' on every platform, including Windows).
		const std::string::size_type sep = filename.find_last_of("/\\");
		if (sep == std::string::npos)
		{
			path			= "";
			originalFname	= filename;
		} else {
			path			= filename.substr(0, sep) + "/";
			originalFname	= filename.substr(sep + 1);
		}

		std::string fileNE			= originalFname.substr(0, originalFname.find_last_of("."));
		std::transform(fileNE.begin(), fileNE.end(),fileNE.begin(), ::tolower);
		std::string ext				= filename.substr(filename.find_last_of(".")+1);
		std::transform(ext.begin(), ext.end(),ext.begin(), ::toupper);
		std::string genFilename;

		if(ext == "CMD")
		{
			genFilename		= fileNE + "_cmd.lua";
		} else {
			genFilename		= fileNE + ".lua";
		}

		std::string fileToCreate	= path + genFilename;

		genFilenames.push_back(genFilename);

		file.open(fileToCreate.c_str());

		if(!file)
		{
			// TODO: Report error
			return false;
		}

		snprintf(hdrBuffer, sizeof(hdrBuffer), headerV.c_str(), genFilename.c_str(), originalFname.c_str(), dateStr.c_str(), k_cns_rt_version);

		file << hdrBuffer;
		file << cu;
		lcu.pop_front();
		file.close();
	}
	
	// Generate master file
	{
		std::ofstream file;
		std::string genFilename = entityName + "_master.lua";
		std::string fileToCreate = path + genFilename;
		file.open(fileToCreate.c_str());

		if(!file)
		{
			// TODO: Report error
			return false;
		}

		snprintf(hdrBuffer, sizeof(hdrBuffer), headerM.c_str(), genFilename.c_str(), entityName.c_str(), dateStr.c_str(), k_cns_rt_version);

		file << hdrBuffer;

		file << "-- Class definition" << std::endl;
		// Create the table for the entity
		file << entityName << " = BaseClass(FightActor)" << std::endl << std::endl;

		file << "-- Add some attributes definitions to be filled later on" << std::endl;

		file << entityName << ".m_constants = {}" << std::endl;
		file << entityName << ".m_commands = {}" << std::endl;
		file << entityName << ".m_buttonsRemap = {}" << std::endl;
		file << std::endl;

/*
		file << "-- Add states and other definitions" << std::endl;
		// dofile all of the other files
		for(std::list<std::string>::iterator i = genFilenames.begin(); i != genFilenames.end(); ++i)
		{
			file << "dofile(\"";
			file << *i;
			file << "\")" << std::endl;
		}
*/

		file << "-- Set the path of this file" << std::endl;
		file << "require(\"debug\")" << std::endl;
		file << "local dpath = debug.getinfo(1, \"S\").source" << std::endl;
		file << entityName << ".m_path = dpath:match\"@(.+/).+%..+\"" << std::endl;

		file << std::endl;

		file << "-- List of scripts" << std::endl;
		file << entityName << ".m_scriptList = {" << std::endl;

		// dofile all of the other files
		for(std::list<std::string>::iterator i = genFilenames.begin(); i != genFilenames.end(); ++i)
		{
			file << "\t\"";
			file << *i;
			file << "\"," << std::endl;
		}

		file << "}" << std::endl;
		file << std::endl;

		// Constructor
		file << "-- " << entityName << "'s constructor" << std::endl;
		file << "function " << entityName << ":constructor()" << std::endl;
//		file << "\t-- Call the superclass constructor" << std::endl;
//		file << "\tFightActor.init(self)" << std::endl;
		file << std::endl << "\t-- Other attributes" << std::endl;
		file << "\tself._type = \"" << entityName << "\"" << std::endl;
		file << "\tself.runtimeVersion = \"" << k_cns_rt_version << "\"" << std::endl;
		file << "end" << std::endl;
		
		file << std::endl;
		file << "-- First-time load of scripts" << std::endl;
		file << "FightActor.reloadScripts(" << entityName << ")" << std::endl;

		file << std::endl;
		file << "return " << entityName << std::endl;

		file << std::endl << std::endl;
		file.close();
	}

	// Generate additional files
	return true;
}
