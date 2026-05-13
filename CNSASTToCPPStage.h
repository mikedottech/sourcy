#ifndef _CNSASTTOCPPSTAGE_H_
#define _CNSASTTOCPPSTAGE_H_

#include "PipelineStage.h"
#include "cppgen.h"

class CNSASTToCPPStage :
	public PipelineStage,
	public InputASTPipelineStage,
	public OutputCodeBlocksStage
{
public:
	CNSASTToCPPStage(Pipeline * p);
	~CNSASTToCPPStage(void);
	virtual void run();
	virtual void reset();
	virtual void setInputAST(pANTLR3_BASE_TREE a) { m_AST = a; }	
private:
	pcppgen							m_treePsr;
	pANTLR3_COMMON_TREE_NODE_STREAM m_nodes;
	pANTLR3_BASE_TREE				m_AST;
};

#endif
