// LUABackEndPipeline.h — Lua back-end pipeline: AST -> Lua code blocks.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _LUABACKENDPIPELINE_H_
#define _LUABACKENDPIPELINE_H_

#include "Pipeline.h"
#include "luagen.h"
#include "CNSASTToLUAStage.h"

class LUABackEndPipeline :
	public Pipeline,
	public InputASTPipelineStage	
{
public:
	LUABackEndPipeline();
	~LUABackEndPipeline() override = default;
	void run() override;
	void reset() override;
	void setInputAST(pANTLR3_BASE_TREE a) override { m_AST = a; }
	void* getOutput() override { return reinterpret_cast<void *>((dynamic_cast<OutputCodeBlocksStage *>(m_firstStage))->getOutputCodeBlocks()); }
private:
	pANTLR3_BASE_TREE				m_AST;
	InputASTPipelineStage			*m_firstStage;
	//OutputASTPipelineStage			*m_lastStage;
};

#endif
