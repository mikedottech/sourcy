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

CodeBlock& CompilationUnit::addCodeBlock(const std::string id, CodeBlock&& cb)
{
	return (m_codeBlocks.emplace(id, cb).first)->second;
}

std::ostream& operator<<(std::ostream& out, CompilationUnit& x )
{
	const std::map<std::string, CodeBlock>& cbks = x.getCodeBlocks();

	std::map<std::string, CodeBlock>::const_iterator i;

	for(i = cbks.begin(); i != cbks.end(); ++i)
	{
		out << (i->second);
	}
	return out;
}
