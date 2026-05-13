// PipelineStage.h — Base interface for pipeline stages (input/output type tagging).
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _PIPELINESTAGE_H_
#define _PIPELINESTAGE_H_

#include <antlr3.h>
#include <string>
#include <list>
#include "CompilationUnit.h"

class Pipeline;

class PipelineStage
{
public:
	typedef enum
	{
		ED_CHARSTREAM,
		ED_AST,
		ED_FILE,
		ED_CODEBLOCKS
	} ExchangeDataType_t;

public:

	PipelineStage(Pipeline * p,
					ExchangeDataType_t input,
					ExchangeDataType_t output);
	virtual ~PipelineStage() = default;
	virtual void reset();
	virtual void run() = 0;
	bool hasErrors() const { return m_nErrors > 0; }
	unsigned int getNErrors() const { return m_nErrors; }
	unsigned int getNWarnings() const { return m_nWarnings; }
	ExchangeDataType_t getInputType() const { return m_inputType; }
	ExchangeDataType_t getOutputType() const { return m_outputType; }
	const Pipeline * getPipeline() const { return m_pipeline; }
protected:
	unsigned int		m_nErrors{};
	unsigned int		m_nWarnings{};
	Pipeline			*m_pipeline;
private:
	ExchangeDataType_t	m_inputType;
	ExchangeDataType_t	m_outputType;	
};

class InputASTPipelineStage
{
public:
	virtual void setInputAST(pANTLR3_BASE_TREE a) = 0;
};

class OutputASTPipelineStage
{
public:
	virtual pANTLR3_BASE_TREE getOutputAST() = 0;
};

class InputFilePipelineStage
{
public:
	virtual void setInputFilePath(std::string &fname) = 0;
};

class OutputFilePipelineStage
{
public:
	virtual void setOutputFilePath(std::string &fname) = 0;
};

class OutputCodeBlocksStage
{
protected:
	CompilationUnit m_compilationUnit;
public:
	CompilationUnit * getOutputCodeBlocks() { return &m_compilationUnit; };
};

#endif
