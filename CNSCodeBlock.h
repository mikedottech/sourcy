// CNSCodeBlock.h — Code block specialized for CNS output (state / info / command / etc.).
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _CNSCODEBLOCK_H_
#define _CNSCODEBLOCK_H_

#include "CodeBlock.h"
#include "CNSCodeBlockType.h"
#include <string>

class CNSCodeBlock :
	public CodeBlock
{
public:
	CNSCodeBlock();
	CNSCodeBlock(const std::string &id);
	CNSCodeBlock(const std::string &id, CNSCodeBlockType t);
	CNSCodeBlock(const std::string &id, const std::string &code, CNSCodeBlockType t);
	CNSCodeBlock(const std::string &id, const std::string &code, CNSCodeBlockType t, int32_t cnsStateId);

	void setBlockType(CNSCodeBlockType b) { m_cnsBlockType = b; }
	CNSCodeBlockType getBlockType() const { return m_cnsBlockType; }
	int32_t getCNSStateID() const { return m_cnsStateId; }
private:
	CNSCodeBlockType m_cnsBlockType;
	int32_t m_cnsStateId;
};

#endif
