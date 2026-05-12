// Pipeline.cpp — Pipeline base class: holds stages and runs them in order.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include "Pipeline.h"
#include <iostream>

Pipeline::Pipeline()
{
	m_stages.clear();
	reset();
}

Pipeline::~Pipeline()
{
	while(!m_stages.empty())
	{
		delete m_stages.back();
		m_stages.pop_back();
	}
}

void Pipeline::reset()
{
	m_curStage = 0;
	m_nErrors = 0;
	m_nWarnings = 0;
	m_curStageIter = m_stages.begin();
}

void Pipeline::addStage(PipelineStage * s)
{
	m_stages.push_back(s);
}

void Pipeline::run()
{
	std::list<PipelineStage *>::iterator lastStageIter = m_stages.begin();

	for(; m_curStageIter != m_stages.end(); m_curStageIter++, m_curStage++)
	{
		if(m_curStageIter != m_stages.begin())
		{
			// Set input from the last stage
			if(!plugPipelineStages(*lastStageIter, *m_curStageIter))
			{
				std::cerr << "Internal error: Mismatched pipeline data types" << std::endl;
				m_nErrors++;
				break;
			}
			lastStageIter ++;
		}

		// Run
		(*m_curStageIter)->run();

		// Check errors
		m_nErrors += (*m_curStageIter)->getNErrors();
		m_nWarnings += (*m_curStageIter)->getNWarnings();

		if((*m_curStageIter)->getNErrors() > 0)
		{
			break;
		}
	}
}

bool Pipeline::plugPipelineStages(PipelineStage * prev, PipelineStage * next)
{
	// Set the output of prev to the input of next
	// The output of the last stage must match with the input of the next

	if(prev->getOutputType() != next->getInputType())
	{
		return false;
	}

	switch((*m_curStageIter)->getInputType())
	{
		case PipelineStage::ED_AST:
		{
			OutputASTPipelineStage * out = dynamic_cast<OutputASTPipelineStage *> (prev);
			InputASTPipelineStage * in = dynamic_cast<InputASTPipelineStage *> (next);
			in->setInputAST(out->getOutputAST());
		}
		break;
		default:
			return false;
	}

	return true;
}
