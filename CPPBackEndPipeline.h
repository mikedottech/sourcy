#ifndef _CPPBACKENDPIPELINE_H_
#define _CPPBACKENDPIPELINE_H_

#include "Pipeline.h"
#include "cppgen.h"
#include "CNSASTToCPPStage.h"

class CPPBackEndPipeline :
	public Pipeline,
	public InputASTPipelineStage	
{
public:
	CPPBackEndPipeline(void);
	~CPPBackEndPipeline(void);
	virtual void run();
	virtual void reset();
	virtual void setInputAST(pANTLR3_BASE_TREE a) { m_AST = a; }
	virtual void* getOutput() { return reinterpret_cast<void *>((dynamic_cast<OutputCodeBlocksStage *>(m_firstStage))->getOutputCodeBlocks()); }
private:
	pANTLR3_BASE_TREE				m_AST;
	InputASTPipelineStage			*m_firstStage;
	//OutputASTPipelineStage			*m_lastStage;
};

#endif
