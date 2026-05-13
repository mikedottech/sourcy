// CodeBlock.h — Generic named block of generated code (id + code string).
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _CODEBLOCK_H_
#define _CODEBLOCK_H_

#include <string>
#include <ostream>

class CodeBlock
{
public:
	CodeBlock() = default;
	CodeBlock(const std::string & id);
	CodeBlock(const std::string & id, const std::string &code);
	virtual ~CodeBlock() = default;
	const std::string & getCodeConst() const { return m_code; }
	std::string& getCode() { return m_code; }
	const std::string & getID() const { return m_id; }
	bool operator==(const CodeBlock & rhs) const;
	//std::string &operator<<(CodeBlock & rhs) const;
	
protected:
	std::string m_code;
	std::string m_id;
};

std::ostream& operator<<(std::ostream& out, const CodeBlock& x );

#endif
