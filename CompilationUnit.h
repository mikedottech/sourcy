// CompilationUnit.h — A source file's collection of code blocks after front-end processing.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.

#ifndef _COMPILATIONUNIT_H_
#define _COMPILATIONUNIT_H_

#include <map>

#include "CodeBlock.h"

class CompilationUnit
{
public:
	typedef std::map<std::string, std::shared_ptr<CodeBlock>> CodeBlocks;
	CompilationUnit();
	CompilationUnit(const std::string sourceFilename);
	void addCodeBlock(const std::string id, std::shared_ptr<CodeBlock> cb);
	void setSourceFile(const std::string sf) { m_sourceFile = sf; }
	std::string getSourceFile() { return m_sourceFile; }
	void setEntityName(const std::string en) { m_entityName = en; }
	std::string getEntityName() { return m_entityName; }
	const CodeBlocks & getCodeBlocks() const {return m_codeBlocks;}
private:
	CodeBlocks m_codeBlocks;
	std::string m_sourceFile;
	std::string m_entityName;
};

std::ostream& operator<<(std::ostream& out, CompilationUnit& x );

#endif
