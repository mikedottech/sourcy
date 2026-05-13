// main.cpp — Program entry point: argument parsing, pipeline wiring, driving compilation.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.



#include "Version.h"
//#include "console.h"

#include "ApplicationUsage.h"
#include "ArgumentParser.h"

#include "Pipelines.h"
#include "PostGenerators.h"

#include <iostream>
#include <algorithm>
#include <string>

#include "CPPPostGenerator.h"


bool normalizeEntityName(std::string & en)
{	
	if(!isalpha(en.at(0)))
	{
		return false;
	}
	
	en[0] = toupper(en[0]);

	for(unsigned int i = 1; i < en.length(); ++i)
	{
		en[i] = tolower(en[i]);
		if(!isalnum(en.at(i)) && en.at(i) != '_')
		{
			en[i] = '_';
		}
	}
	return true;
}

void printBanner()
{
	std::cout << "Sourcy " << "compiler and translator" << std::endl;
	std::cout << "(c) 2012 - radexx" << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "Version: " << k_app_version << std::endl;
}

bool thereAreInputFiles(ArgumentParser & args)
{
	// Check if there are input files
	for(int pos = 1; pos < args.argc(); ++pos)
		if(!args.isOption(pos))
			return true;
	return false;
}

// Entry point
int main(int argc, char *argv[])
{
	printBanner();
	std::cout << std::endl;

	// Parse the input arguments
	ArgumentParser args(&argc, argv);

	// Setup the help info
    args.getApplicationUsage()->setApplicationName(args.getApplicationName());
    args.getApplicationUsage()->setDescription(args.getApplicationName() + " is a code translation and generation tool. It translates cns/cmd to other languages (LUA by default) and/or generates bytecode.\n2012 - radexx");
    args.getApplicationUsage()->setCommandLineUsage(args.getApplicationName()+" [options] files ...");
	args.getApplicationUsage()->addCommandLineOption("--version","Prints out the version and quits.");
	args.getApplicationUsage()->addCommandLineOption("--output <language>","Specifies the output language (default: LUA).");
    //args.getApplicationUsage()->addCommandLineOption("--dontwrapops","Don't wrap operators with custom functions.");
	args.getApplicationUsage()->addCommandLineOption("--entityname <name>","Specifies the name of the generated entity.");
	//args.getApplicationUsage()->addCommandLineOption("--assemble","Generates executable bytecode.");
	//args.getApplicationUsage()->addCommandLineOption("--forcesourcegen","Generates source files even if --assemble is specified.");
	//args.getApplicationUsage()->addCommandLineOption("--rtver","Runtime version (default: 1.0).");
	

	// Print out help info and quit if requested
    unsigned int helpType = 0;
    if ((helpType = args.readHelpType()))
    {
		args.getApplicationUsage()->write(std::cout, helpType);
        return 1;
    }

    // report any errors if they have occurred when parsing the program arguments
    if (args.errors())
    {
        args.writeErrorMessages(std::cout);
        return 1;
    }

	// Check that at least 1 (without accounting for the exe name) parameters have been given
    if (args.argc() <= 1)
    {
        args.getApplicationUsage()->write(std::cout, ApplicationUsage::COMMAND_LINE_OPTION);
        return 1;
    }

	// Print out the version and quit if requested
	if(args.read("--version"))
	{		
		return 0;
	}

    // Any option left unread are converted into errors to write out later.
    args.reportRemainingOptionsAsUnrecognized();

    // Report any errors if they have occurred when parsing the program arguments.
    if (args.errors())
    {
        args.writeErrorMessages(std::cout);
        return 1;
    }
	
	std::string outputLanguage = "LUA";
    while(args.read("--output",outputLanguage));

	if(outputLanguage != "LUA" && outputLanguage != "CPP")
	{
		std::cerr << "Error: The output format '" << outputLanguage << "' is not supported." << std::endl;
		return 1;
	}

	std::string entityName = "";
    while(args.read("--entityname",entityName));

	if(entityName == "")
	{
		std::cerr << "Error: Missing entity name (use the '--entityname' flag)" << std::endl;
		return 1;
	} else {
		if(!normalizeEntityName(entityName))
		{
			std::cerr << "Error: The entity name '" << entityName << "' is not valid. Examples of valid entity names: rooky, my_fighter, Chaseman" << std::endl;
			return 1;
		}
	}

	// Main section
	if(!thereAreInputFiles(args))
	{
		std::cerr << "Error: No input files" << std::endl;
		return 1;
	}

	std::string						filename;
	std::list<CompilationUnit>		compUnits;

	// For each input file
	for(int pos = 1; pos < args.argc(); ++pos)
	{
		if(!args.isOption(pos))	
		{
			filename = std::string(args.argv()[pos]);

			// Build front end
			Pipeline *pFrontEnd = nullptr;
			Pipeline *pBackEnd = nullptr;

			// Get the extension of the file
			std::string ext = filename.substr(filename.find_last_of(".")+1);
			std::transform(ext.begin(), ext.end(),ext.begin(), ::toupper);

			if(ext == "CNS" || ext == "CMD")
			{
				CNSFrontEndPipeline *p = new CNSFrontEndPipeline();			
				p->setFileName(filename);
				pFrontEnd = p;
			} else {
				std::cerr << "Error: The input format '" << ext << "' is not supported." << std::endl;
				return 1;
			}

			std::cout << "Processing " << filename << " ..." << std::endl;

			pFrontEnd->run();

			if(pFrontEnd->getNErrors() > 0)
			{
				delete pFrontEnd;
				std::cout << "Compilation failed" /*" with " << pFrontEnd->getNErrors() << " errors"*/ << std::endl;
				std::cout << "Failure detected in front end" << std::endl;
				return 1;
			}

			// Build a back end
			if(outputLanguage == "LUA")
			{
				LUABackEndPipeline *l = new LUABackEndPipeline();
				// Build the LUA back-end
				pBackEnd = l;

				// Set the output of the front-end as the input of the
				// back-end
				l->setInputAST(static_cast<pANTLR3_BASE_TREE>(pFrontEnd->getOutput()));
			}
			else if (outputLanguage == "CPP")
			{
				CPPBackEndPipeline *l = new CPPBackEndPipeline();
				// Build the LUA back-end
				pBackEnd = l;

				// Set the output of the front-end as the input of the
				// back-end
				l->setInputAST(static_cast<pANTLR3_BASE_TREE>(pFrontEnd->getOutput()));
			}

			// Set backend data for code generation
			pBackEnd->getPSAttributes().sourceFile	= filename;
			pBackEnd->getPSAttributes().entityName	= entityName;
			pBackEnd->getPSAttributes().dstLang		= outputLanguage;
			pBackEnd->getPSAttributes().sourceLang	= ext;

			// Run the back end
			pBackEnd->run();

			// Check for errors
			if(pBackEnd->getNErrors() > 0)
			{
				std::cout << std::endl << "Compilation failed with " << pBackEnd->getNErrors() << " errors" << std::endl;
				std::cout << "Failure detected in back end" << std::endl;
				return 1;
			}		
			
			// Copy the code blocks generated by the back end
			compUnits.push_back(*(CompilationUnit *)pBackEnd->getOutput());
			
			// Destroy both ends
			if(pFrontEnd)
				delete pFrontEnd;
			if(pBackEnd)
				delete pBackEnd;
			// End of the loop
		}
	}

	// Build a post generator
	PostGenerator * pPostGen = nullptr;


	if(outputLanguage == "LUA")
	{
		pPostGen = new LUAPostGenerator();
	}
	else if (outputLanguage == "CPP")
	{
		pPostGen = new CPPPostGenerator();
	}

	// Post generate files
	if(!pPostGen->generateFiles(compUnits))
	{	
		std::cout << std::endl << "Compilation failed with " << std::endl;
		std::cout << "Failure detected in post generation" << std::endl;
	}


// Display summary

// Exit

////
	std::cout << std::endl << "Operation successful" << std::endl;
    return 0;
}
