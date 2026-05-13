#ifndef _CPPPOSTGENERATOR_H_
#define _CPPPOSTGENERATOR_H_

#include "PostGenerator.h"
#include <map>
#include "CNSCodeBlock.h"
#include <list>

class CPPPostGenerator :
	public PostGenerator
{
public:
	CPPPostGenerator(void);
	virtual ~CPPPostGenerator(void);
	virtual bool generateFiles(std::list<CompilationUnit> & lcu);
private:
	// To prevent duplicate states
	std::map<int32_t, CNSCodeBlock*> m_statesCode;
};

#endif