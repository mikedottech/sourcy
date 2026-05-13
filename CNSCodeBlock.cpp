// CNSCodeBlock.cpp — Code block specialized for CNS output (state / info / command / etc.).
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include "CNSCodeBlock.h"

CNSCodeBlock::CNSCodeBlock() : m_cnsBlockType(CBT_NONE)
{
}

CNSCodeBlock::CNSCodeBlock(const std::string &id) : CodeBlock(id)
{
}

CNSCodeBlock::CNSCodeBlock(const std::string &id, const std::string &code, CNSCodeBlockType t) : CodeBlock(id, code), m_cnsBlockType(t)
{
}

CNSCodeBlock::CNSCodeBlock(const std::string &id, const std::string &code, CNSCodeBlockType t, int32_t cnsStateId) : CodeBlock(id, code), m_cnsBlockType(t), m_cnsStateId(cnsStateId) {
}

CNSCodeBlock::CNSCodeBlock(const std::string &id, CNSCodeBlockType t) : CodeBlock(id), m_cnsBlockType(t)
{
}
