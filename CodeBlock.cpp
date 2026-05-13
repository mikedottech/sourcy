// CodeBlock.cpp — Generic named block of generated code (id + code string).
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include "CodeBlock.h"
#include <iostream>
#include <string>
#include <ostream>

CodeBlock::CodeBlock(const std::string & id) : m_id(id)
{
}

CodeBlock::CodeBlock(const std::string & id, const std::string &code) : m_id(id), m_code(code)
{
}

bool CodeBlock::operator==(const CodeBlock & rhs) const
{
	return (m_id == rhs.m_id);
}

/*
std::string & CodeBlock::operator<<(CodeBlock &rhs) const
{
	return rhs.getCode();
}
*/

std::ostream& operator<<(std::ostream& out, const CodeBlock& x )
{
	out << x.getCodeConst();
	return out;
}
