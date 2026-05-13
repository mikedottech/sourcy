// LUAGenSemanticActions.h — Semantic-action callbacks invoked by the luagen tree parser.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _LUAGENSEMANTICACTIONS_H_
#define _LUAGENSEMANTICACTIONS_H_

#include <antlr3.h>
#include "CNSCodeBlockType.h"
#include "CNSControllerUsage.h"

void luagenSemanticActions_init();
void luagenSemanticActions_end();
void luagenSemanticActions_setSourceFilename(const char *s);
void luagenSemanticActions_setEntityName(const char *s);

const char *luagenSemanticActions_getEntityName();

void luagenSemanticActions_beginCodeBlock(CNSCodeBlockType t);
void luagenSemanticActions_beginStateCodeBlock(CNSCodeBlockType t, char * stateNum);
void luagenSemanticActions_setCode(pANTLR3_STRING code);
void luagenSemanticActions_endCodeBlock();

void luagenSemanticActions_appendCodeLine(pANTLR3_STRING c);
void luagenSemanticActions_appendCodeLineC(const char * c);
void luagenSemanticActions_incInd();
void luagenSemanticActions_decInd();
void luagenSemanticActions_muteOutput();
void luagenSemanticActions_unMuteOutput();

const char * luagenSemanticActions_getCurCodeBlockID();
pANTLR3_STRING luagenSemanticActions_getNewString();
void luagenSemanticActions_closeBlocksToLevel(int lvl);

const char * luagenSemanticActions_getNameForStateInit(pANTLR3_STRING lhs, unsigned int *nArgs);
const char * luagenSemanticActions_getNameForControllerArg(cnsControllerUsage_t * pCU, pANTLR3_STRING lhs);
const char * luagenSemanticActions_getNameForTrigger(pANTLR3_STRING tName);

#ifdef __cplusplus
	void luagenSemanticActions_setCompilationUnit(void * cu);
#endif

#endif
