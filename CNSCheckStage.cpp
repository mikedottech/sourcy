// CNSCheckStage.cpp — Pipeline stage that validates the CNS AST (semantic / error checks).
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include "CNSCheckStage.h"

CNSCheckStage::CNSCheckStage(Pipeline * p) : PipelineStage(p, ED_AST, ED_AST), m_treePsr(nullptr), m_nodes(nullptr), m_AST(nullptr)
{
}

void CNSCheckStage::reset()
{
	PipelineStage::reset();
	if(m_treePsr)
	{
		m_treePsr->free(m_treePsr);	 m_treePsr = nullptr;
	}
	if(m_nodes)
	{
		m_nodes->free(m_nodes); m_nodes = nullptr;
	}
}

void CNSCheckStage::run()
{
	reset();
	
	m_nodes	= antlr3CommonTreeNodeStreamNewTree(m_AST, ANTLR3_SIZE_HINT); // SIZE HINT WILL SOON BE DEPRECATED!!

	m_treePsr	= cnscheckNew(m_nodes);

	// Here is where the validation takes place
	m_treePsr ->root(m_treePsr);
	////

	m_nErrors = m_treePsr->pTreeParser->rec->state->errorCount;
	
}
