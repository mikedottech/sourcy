// CNSCheckStage.h — Pipeline stage that validates the CNS AST (semantic / error checks).
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#pragma once
#include "PipelineStage.h"
#include "cnscheck.h"

class CNSCheckStage :
	public PipelineStage,
	public InputASTPipelineStage,
	public OutputASTPipelineStage
{
public:
	CNSCheckStage(Pipeline * p);
	void setInputAST(pANTLR3_BASE_TREE a) override { m_AST = a; }
	pANTLR3_BASE_TREE getOutputAST() override { return m_AST; }
	void reset() override;
	void run() override;
private:
	pcnscheck						m_treePsr;
	pANTLR3_COMMON_TREE_NODE_STREAM m_nodes;
	pANTLR3_BASE_TREE				m_AST;
};
