// CNSASTToLUAStage.h — Pipeline stage that walks the CNS AST and emits Lua code blocks.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _CNSASTTOLUASTAGE_H_
#define _CNSASTTOLUASTAGE_H_

#include "PipelineStage.h"
#include "luagen.h"

class CNSASTToLUAStage :
	public PipelineStage,
	public InputASTPipelineStage,
	public OutputCodeBlocksStage
{
public:
	CNSASTToLUAStage(Pipeline * p);
	void run() override;
	void reset() override;
	void setInputAST(pANTLR3_BASE_TREE a) override { m_AST = a; }
private:
	pluagen							m_treePsr;
	pANTLR3_COMMON_TREE_NODE_STREAM m_nodes;
	pANTLR3_BASE_TREE				m_AST;
};

#endif
