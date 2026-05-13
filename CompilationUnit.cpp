// CompilationUnit.cpp — A source file's collection of code blocks after front-end processing.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include "CompilationUnit.h"

CompilationUnit::CompilationUnit()
{
}

CompilationUnit::CompilationUnit(const std::string sourceFilename) : m_sourceFile(sourceFilename)
{
}

void CompilationUnit::addCodeBlock(const std::string id, std::shared_ptr<CodeBlock> cb)
{
	m_codeBlocks.insert({id, cb});
}

std::ostream& operator<<(std::ostream& out, CompilationUnit& x )
{
	const CompilationUnit::CodeBlocks& cbks = x.getCodeBlocks();

	for(const auto &i :cbks)
		out << (*i.second);

	return out;
}
