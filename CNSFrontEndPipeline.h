// CNSFrontEndPipeline.h — CNS front-end pipeline: file -> AST -> checked AST.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _CNSFRONTENDPIPELINE_H_
#define _CNSFRONTENDPIPELINE_H_

#include "Pipeline.h"
#include "CNSFileToAST.h"
#include "CNSCheckStage.h"
#include <string>

class CNSFrontEndPipeline : 
	public Pipeline,
	public InputFilePipelineStage,
	public OutputASTPipelineStage
{
public:
	CNSFrontEndPipeline();
	~CNSFrontEndPipeline() override = default;
	inline void setFileName(std::string &f) { m_filename = f; }
	void run() override;
	void reset() override;
	void setInputFilePath(std::string &fname) override { m_filename = fname; }
	pANTLR3_BASE_TREE getOutputAST()  override { return m_AST; }
	void* getOutput()  override { return (void*)getOutputAST(); }
private:
	std::string						m_filename;
	pANTLR3_BASE_TREE				m_AST;
	InputFilePipelineStage			*m_firstStage;
	OutputASTPipelineStage			*m_lastStage;
};

#endif
