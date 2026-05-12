// Pipeline.h — Pipeline base class: holds stages and runs them in order.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _PIPELINE_H_
#define _PIPELINE_H_

#include <list>
#include <antlr3.h>

#include "PipelineStage.h"

class Pipeline
{
public:

	typedef struct
	{
		std::string sourceFile;
		std::string entityName;
		std::string sourceLang;
		std::string dstLang;
	} PSAttributes_t;

	Pipeline();
	virtual ~Pipeline();

	virtual void addStage(PipelineStage * s);
	virtual void run();
	virtual void reset();
	virtual void* getOutput() = 0;
	inline unsigned int getNErrors()		{ return m_nErrors; }
	inline unsigned int getNWarnings()		{ return m_nWarnings; }
	inline void setPSAttributes(PSAttributes_t & attr)		{ m_PSAttributes = attr; }
	inline PSAttributes_t & getPSAttributes()			{ return m_PSAttributes; }	

private:
	bool plugPipelineStages(PipelineStage * prev, PipelineStage * next);

	std::list<PipelineStage *>				m_stages;	
	std::list<PipelineStage *>::iterator	m_curStageIter;
	PSAttributes_t							m_PSAttributes;
	unsigned int							m_curStage;

protected:
	unsigned int							m_nErrors;
	unsigned int							m_nWarnings;
};

#endif
