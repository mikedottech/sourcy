#ifndef _cppGENSEMANTICACTIONS_H_
#define _cppGENSEMANTICACTIONS_H_

#include <antlr3.h>
#include "CNSCodeBlockType.h"
#include "CNSControllerUsage.h"

void cppgenSemanticActions_init();
void cppgenSemanticActions_end();
void cppgenSemanticActions_setSourceFilename(const char *s);
void cppgenSemanticActions_setEntityName(const char *s);

const char *cppgenSemanticActions_getEntityName();

void cppgenSemanticActions_beginCodeBlock(CNSCodeBlockType t);
void cppgenSemanticActions_beginStateCodeBlock(CNSCodeBlockType t, char * stateNum);
void cppgenSemanticActions_setCode(pANTLR3_STRING code);
void cppgenSemanticActions_endCodeBlock();

void cppgenSemanticActions_appendCodeLine(pANTLR3_STRING c);
void cppgenSemanticActions_appendCodeLineC(const char * c);
void cppgenSemanticActions_incInd();
void cppgenSemanticActions_decInd();
void cppgenSemanticActions_muteOutput();
void cppgenSemanticActions_unMuteOutput();

const char * cppgenSemanticActions_getCurCodeBlockID();
pANTLR3_STRING cppgenSemanticActions_getNewString();
void cppgenSemanticActions_closeBlocksToLevel(int lvl);

const char * cppgenSemanticActions_getNameForStateInit(pANTLR3_STRING lhs, unsigned int *nArgs);
const char * cppgenSemanticActions_getNameForControllerArg(cnsControllerUsage_t * pCU, pANTLR3_STRING lhs);
const char * cppgenSemanticActions_getNameForTrigger(pANTLR3_STRING tName);

#ifdef __cplusplus
	void cppgenSemanticActions_setCompilationUnit(void * cu);
#endif

#endif
