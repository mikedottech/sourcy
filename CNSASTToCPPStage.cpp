#include "CNSASTToCPPStage.h"
#include "Pipeline.h"

extern "C"
{
}

#	include "CPPGenSemanticActions.h"


CNSASTToCPPStage::CNSASTToCPPStage(Pipeline *p) : PipelineStage(p, PipelineStage::ED_AST, PipelineStage::ED_CODEBLOCKS)
{
	m_treePsr = NULL;
	m_nodes	  = NULL;
}

CNSASTToCPPStage::~CNSASTToCPPStage(void)
{
}

void CNSASTToCPPStage::reset()
{
	PipelineStage::reset();
	if(m_treePsr)
	{
		m_treePsr->free(m_treePsr);	 m_treePsr = NULL;
	}
	if(m_nodes)
	{
		m_nodes->free(m_nodes); m_nodes = NULL;
	}

	m_compilationUnit.setSourceFile(m_pipeline->getPSAttributes().sourceFile);
	m_compilationUnit.setEntityName(m_pipeline->getPSAttributes().entityName);

}

void CNSASTToCPPStage::run()
{
	reset();

	m_nodes	= antlr3CommonTreeNodeStreamNewTree(m_AST, ANTLR3_SIZE_HINT); // SIZE HINT WILL SOON BE DEPRECATED!!

	m_treePsr	= cppgenNew(m_nodes);

	//printf("%s\n", m_AST->toStringTree(m_AST)->chars);

	cppgenSemanticActions_setSourceFilename(m_pipeline->getPSAttributes().sourceFile.c_str());
	cppgenSemanticActions_setEntityName(m_pipeline->getPSAttributes().entityName.c_str());
	cppgenSemanticActions_setCompilationUnit(&m_compilationUnit);

	// Here is where the code generation takes place
	m_treePsr ->root(m_treePsr);
	////

	m_nErrors = m_treePsr->pTreeParser->rec->state->errorCount;

}
