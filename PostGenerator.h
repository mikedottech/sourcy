// PostGenerator.h — Base interface for post-generators (final on-disk file writers).
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _POSTGENERATOR_H_
#define _POSTGENERATOR_H_

#include "CompilationUnit.h"
#include <list>

class PostGenerator
{
public:
	PostGenerator();
	virtual ~PostGenerator() = default;
	virtual bool generateFiles(std::list<CompilationUnit> & lcu) = 0;
};

#endif
