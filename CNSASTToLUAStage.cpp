// CNSASTToLUAStage.cpp — Pipeline stage that walks the CNS AST and emits Lua code blocks.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include "CNSASTToLUAStage.h"
#include "Pipeline.h"

extern "C"
{
}

#	include "LUAGenSemanticActions.h"


CNSASTToLUAStage::CNSASTToLUAStage(Pipeline *p) : PipelineStage(p, PipelineStage::ED_AST, PipelineStage::ED_CODEBLOCKS),
                                                  m_AST(nullptr), m_treePsr(nullptr), m_nodes(nullptr)
{
}

void CNSASTToLUAStage::reset()
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

	m_compilationUnit.setSourceFile(m_pipeline->getPSAttributes().sourceFile);
	m_compilationUnit.setEntityName(m_pipeline->getPSAttributes().entityName);

}

void CNSASTToLUAStage::run()
{
	reset();

	m_nodes	= antlr3CommonTreeNodeStreamNewTree(m_AST, ANTLR3_SIZE_HINT); // SIZE HINT WILL SOON BE DEPRECATED!!

	m_treePsr	= luagenNew(m_nodes);

	//printf("%s\n", m_AST->toStringTree(m_AST)->chars);

	luagenSemanticActions_setSourceFilename(m_pipeline->getPSAttributes().sourceFile.c_str());
	luagenSemanticActions_setEntityName(m_pipeline->getPSAttributes().entityName.c_str());
	luagenSemanticActions_setCompilationUnit(&m_compilationUnit);

	// Here is where the code generation takes place
	m_treePsr ->root(m_treePsr);
	////

	m_nErrors = m_treePsr->pTreeParser->rec->state->errorCount;

}
