// LUAPostGenerator.h — Writes the per-file and master Lua output files to disk.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _LUAPOSTGENERATOR_H_
#define _LUAPOSTGENERATOR_H_

#include "PostGenerator.h"

class LUAPostGenerator :
	public PostGenerator
{
public:
	bool generateFiles(std::list<CompilationUnit> & lcu) override;
private:
	static std::string date_string();
};

#endif
