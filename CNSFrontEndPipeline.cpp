// CNSFrontEndPipeline.cpp — CNS front-end pipeline: file -> AST -> checked AST.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.

#include "CNSFrontEndPipeline.h"

CNSFrontEndPipeline::CNSFrontEndPipeline() : Pipeline()
{
	// Assemble the pipeline
	PipelineStage * first = new CNSFileToAST(this);
	PipelineStage * last  = new CNSCheckStage(this);
	
	m_firstStage = dynamic_cast<InputFilePipelineStage *>(first);
	m_lastStage	= dynamic_cast<OutputASTPipelineStage *>(last);

	addStage(first);
	addStage(last);
}

void CNSFrontEndPipeline::run()
{
	reset();

	// Set input to the first stage	
	m_firstStage->setInputFilePath(m_filename);

	// Run the pipeline
	Pipeline::run();
	
	if(m_nErrors == 0)
	{
		// Get output from the last stage
		m_AST = m_lastStage->getOutputAST();
	}
}

void CNSFrontEndPipeline::reset()
{
	Pipeline::reset();
}
