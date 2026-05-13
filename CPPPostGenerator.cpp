#include "CPPPostGenerator.h"
#include <fstream>
#include <algorithm>
#include <string>
#include <ctime>
#include "Version.h"
#include "CPPGenSemanticActions.h"
#include "CNSCodeBlock.h"
#include <iostream>
#include "HelpersCpp.h"

#include <string>
#include <vector>

/*
CPP MAIN TODO:
- Generate the following code blocks:
	CBT_INFO,
	CBT_COMMAND,
	CBT_BUTTONSREMAP
- Create stubs (FightActor)
- Compile!
*/


CPPPostGenerator::CPPPostGenerator(void)
{
}

CPPPostGenerator::~CPPPostGenerator(void)
{
}

bool CPPPostGenerator::generateFiles(std::list<CompilationUnit> & lcu)
{
	// Check for state duplicates across files
	// overrides? warn!
	std::list<std::string> genFilenames;
	std::string path;
	std::string entityName = lcu.front().getEntityName();

	// Header

	std::string headerV =
				"/*\n"
				"   %s\n"
				"   Generated from %s\n"
				"   on %s.\n"
				"\n"
				"   by Sourcy Code Translator\n"
				"   (c) 2012 - radexx\n"
				"\n"
				"   Runtime version: %s\n"
				"\n*/\n\n"
				;

	std::string headerM =
				"/*\n"
				"   %s\n"
				"   Master file for %s\n"
				"   Generated on %s.\n"
				"\n"
				"   by Sourcy Code Translator\n"
				"   (c) 2012 - radexx\n"
				"\n"
				"  Runtime version: %s\n"
				"\n*/\n\n"				
				;

	char hdrBuffer[2048];
	const std::string dateStr = date_string();

	std::list<CompilationUnit>::iterator i = lcu.begin();

	// First pass: scan for duplicate states
	for (; i != lcu.end(); ++i)
	{
		CompilationUnit & cu = *i;
		const CompilationUnit::CodeBlocks& cbks = cu.getCodeBlocks();
		std::unordered_map<std::string, CodeBlock>::iterator j;

		for (const auto& j : cbks)
		{
			CNSCodeBlock& cnsBlock = *((CNSCodeBlock*)j.second.get());

			// Dump only state controller code blocks
			if (cnsBlock.getBlockType() == CBT_STATE)
			{
				if (m_statesCode.find(cnsBlock.getCNSStateID()) != m_statesCode.end())
				{
					// Warning: Duplicate state
					std::cout << "WARNING: State " << cnsBlock.getCNSStateID() << " duplicated. Using last one processed. \n";
				}
				m_statesCode[cnsBlock.getCNSStateID()] = &cnsBlock;
			}
		}
	}

	i = lcu.begin();

	// Second pass: emit code
	for(;i != lcu.end(); ++i)
	{
		CompilationUnit & cu		= *i;
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
			genFilename		= fileNE + "_cmd.cpp";
		} else {
			genFilename		= fileNE + ".cpp";
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

		file << "#include \"" << entityName << "_master.h\"" << std::endl << std::endl;

		//file << cu;

		const CompilationUnit::CodeBlocks& cbks = cu.getCodeBlocks();

		for (const auto& j : cbks)
		{
			CNSCodeBlock& cnsBlock = *((CNSCodeBlock*)j.second.get());
			
			// Dump only state controller code blocks
			if (cnsBlock.getBlockType() == CBT_STATE)
			{
				std::map<int32_t, CNSCodeBlock*>::iterator storedBlock;
				storedBlock = m_statesCode.find(cnsBlock.getCNSStateID());
				if (storedBlock != m_statesCode.end())
				{
					if (storedBlock->second == &cnsBlock)
					{
						file << cnsBlock;
					}

				}
			}
		}
		
		file.close();
	}
	
	// Generate master header file
	{
		std::ofstream file;
		std::string genFilename = entityName + "_master.h";
		std::string fileToCreate = path + genFilename;
		file.open(fileToCreate.c_str());
		

		if (!file)
		{
			// TODO: Report error
			return false;
		}

		snprintf(hdrBuffer, sizeof(hdrBuffer), headerM.c_str(), genFilename.c_str(), entityName.c_str(), dateStr.c_str(), k_cns_rt_version);

		file << hdrBuffer;

		file << "#include \"FightActor.h\"" << std::endl << std::endl;

		file << "// Class definition" << std::endl;
		// Create the table for the entity
		file << "class " << entityName << " : public FightActor" << std::endl;
		file << "{" << std::endl <<
			"\tpublic:" << std::endl <<
			"\t\t" << entityName << "();" << std::endl <<
			"\t\t~" << entityName << "();" << std::endl <<
			"\t\t" << std::endl <<
			"\t\tvoid InitInfo(Constants& constants, ButtonRemaps& btnRemaps, Commands& commands, CommandDefaults& cmdDefaults);" << std::endl <<
			"\t\tbool RunState(int stateNum);" << std::endl;

		file << std::endl;

		file << "\t\t// Basic information" << std::endl;



		/*
		file << "\t\tstatic const char k_type[] = \"" << entityName << "\";" << std::endl;
		file << "\t\tstatic const char k_runtimeVersion[] = \"" << k_cns_rt_version << "\";" << std::endl;
			*/

		file << "\tprotected:" << std::endl;

		file << "\t\t// State definitions" << std::endl;
		
		std::map<int32_t, CNSCodeBlock*>::iterator j = m_statesCode.begin();
		
		for (; j != m_statesCode.end(); ++j)
		{
			file << "\t\tvoid " << j->second->getID() << "();" << std::endl;
		}


		//i = lcu.begin();
		//for (; i != lcu.end(); ++i)
		//{
		//	CompilationUnit &cu = *i;
		//	std::unordered_map<std::string, CodeBlock *>& blocks = cu.getCodeBlocks();
		//	std::unordered_map<std::string, CodeBlock *>::iterator j = blocks.begin();

		//	for (; j != blocks.end(); ++j)
		//	{
		//		CNSCodeBlock& cnsBlock = *((CNSCodeBlock*)j->second);
		//		if (cnsBlock.getBlockType() == CBT_STATE)
		//		{
		//			//cnsBlock.getCNSStateID();
		//			file << "\t\tvoid " << cnsBlock.getID() << "();" << std::endl;
		//		}
		//	}
		//}


		file << "};" << std::endl;


		file << std::endl << std::endl;
		file.close();

	}


	// Generate master file
	{
		std::ofstream file;
		std::string genFilename = entityName + "_master.cpp";
		std::string fileToCreate = path + genFilename;
		file.open(fileToCreate.c_str());
	
	
		
		if(!file)
		{
			// TODO: Report error
			return false;
		}

		snprintf(hdrBuffer, sizeof(hdrBuffer), headerM.c_str(), genFilename.c_str(), entityName.c_str(), dateStr.c_str(), k_cns_rt_version);

		file << hdrBuffer;

		file << std::endl << "#include \"" << entityName << "_master.h\"" << std::endl << std::endl;

		// Generate initializers

		file << "void " << entityName << "::InitInfo(Constants& constants, ButtonRemaps& btnRemaps, Commands& commands, CommandDefaults& cmdDefaults)" << std::endl <<
			"{" << std::endl;

		i = lcu.begin();
		for (; i != lcu.end(); ++i)
		{
			CompilationUnit &cu = *i;
			const CompilationUnit::CodeBlocks& blocks = cu.getCodeBlocks();

			for (const auto j : blocks)
			{
				const CNSCodeBlock& cnsBlock = *((CNSCodeBlock*)j.second.get());

				if (cnsBlock.getBlockType() != CBT_STATE)
				{
					file << cnsBlock;
				}
			}
		}

		file << "}" << std::endl << std::endl;

		// Generate state map function
		file << "bool " << entityName << "::RunState(int stateNum)" << std::endl <<
			"{" << std::endl <<			
			"\tswitch(stateNum)" << std::endl <<
			"\t{" << std::endl;

		std::map<int32_t, CNSCodeBlock*>::iterator j = m_statesCode.begin();

		for (; j != m_statesCode.end(); ++j)
		{
			file << "\t\tcase " << j->second->getCNSStateID() << ":" << std::endl <<
								"\t\t\t" << j->second->getID() << "();" << std::endl <<
								"\t\t\tbreak;" << std::endl;
		}

		//i = lcu.begin();
		//for (; i != lcu.end(); ++i)
		//{
		//	CompilationUnit &cu = *i;
		//	std::unordered_map<std::string, CodeBlock *>& blocks = cu.getCodeBlocks();
		//	std::unordered_map<std::string, CodeBlock *>::iterator j = blocks.begin();

		//	for (; j != blocks.end(); ++j)
		//	{
		//		CNSCodeBlock& cnsBlock = *((CNSCodeBlock*)j->second);

		//		if (cnsBlock.getBlockType() == CBT_STATE)
		//		{
		//			file << "\t\tcase " << cnsBlock.getCNSStateID() << ":" << std::endl <<
		//				"\t\t\t" << cnsBlock.getID() << "();" << std::endl <<
		//				"\t\t\tbreak;" << std::endl;
		//		}
		//	}
		//}

		file << "\t\tdefault: " << std::endl <<
			"\t\t\treturn false;" << std::endl;

		file << "\t}" << std::endl <<
			"\treturn true;" << std::endl <<
			"}" << std::endl;
		

		file << std::endl << std::endl;
		file.close();
	}

	// Generate additional files
	return true;
}
