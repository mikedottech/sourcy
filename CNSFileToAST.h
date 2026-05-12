// CNSFileToAST.h — Pipeline stage that reads a CNS source file and produces an AST.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#pragma once
#include "PipelineStage.h"
#include "CNSParserStuff.h"
#include <string>

class CNSFileToAST :
	public PipelineStage,
	public InputFilePipelineStage,
	public OutputASTPipelineStage
{
public:
	CNSFileToAST(Pipeline * p);
	~CNSFileToAST();
	void reset() override;
	void run() override;
	void setInputFilePath(std::string &fname) override { m_filename = fname; }
	pANTLR3_BASE_TREE getOutputAST() override { return m_cnsAST.tree; }
private:
	std::string						m_filename;
	pANTLR3_INPUT_STREAM			m_input;
	pcnsLexer						m_lxr;
	pANTLR3_CUSTOM_TOKEN_STREAM		m_tstream;
	pcnsParser						m_psr;
	cnsParser_cns_return			m_cnsAST;

};
