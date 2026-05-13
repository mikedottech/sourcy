#include "CPPBackEndPipeline.h"

CPPBackEndPipeline::CPPBackEndPipeline(void)
{
	PipelineStage *first = new CNSASTToCPPStage(this);
	m_firstStage = dynamic_cast<InputASTPipelineStage *>(first);

	addStage(first);
}

CPPBackEndPipeline::~CPPBackEndPipeline(void)
{
}

void CPPBackEndPipeline::run()
{
	reset();
	
	m_firstStage->setInputAST(m_AST);

	Pipeline::run();

}

void CPPBackEndPipeline::reset()
{
	Pipeline::reset();

}
