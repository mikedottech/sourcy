// PipelineStage.cpp — Base interface for pipeline stages (input/output type tagging).
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include "PipelineStage.h"

PipelineStage::PipelineStage(Pipeline * p,
							 ExchangeDataType_t input,
							 ExchangeDataType_t output) : m_inputType(input), m_outputType(output), m_pipeline(p)
{
	reset();
}

void PipelineStage::reset()
{	
	m_nErrors = 0;
	m_nWarnings = 0;
}
