// LUABackEndPipeline.cpp — Lua back-end pipeline: AST -> Lua code blocks.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include "LUABackEndPipeline.h"

LUABackEndPipeline::LUABackEndPipeline()
{
	PipelineStage *first = new CNSASTToLUAStage(this);
	m_firstStage = dynamic_cast<InputASTPipelineStage *>(first);

	addStage(first);
}

void LUABackEndPipeline::run()
{
	reset();

	m_firstStage->setInputAST(m_AST);

	Pipeline::run();

}

void LUABackEndPipeline::reset()
{
	Pipeline::reset();

}
