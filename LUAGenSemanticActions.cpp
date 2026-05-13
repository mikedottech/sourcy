// LUAGenSemanticActions.cpp — Semantic-action callbacks invoked by the luagen tree parser.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.


#include "CNSCodeBlock.h"
#include <iostream>
#include "CNSSemantics.h"
#include "antlr3.h"
#include "CompilationUnit.h"

extern "C"
{
#	include "Helpers.h"
#	include "LUAGenSemanticActions.h"
#include <memory>
#include <string>
}

// Mutable file-scope state used by ANTLR3 C-style semantic action callbacks.
// ANTLR3 actions are free functions without a context pointer, so per-walk
// state has to live here. Not thread-safe; the compiler runs single-threaded.
CompilationUnit *pcUnit = nullptr;
CNSCodeBlock	*pCurCodeBlock;
pANTLR3_STRING_FACTORY pStrFactory;
int				indent;
bool			isOutputMuted;
const char		*lgse_pEntityName;
const char		*lgse_pSourceFilename;

void luagenSemanticActions_setCompilationUnit(void * cu)
{
	pcUnit = reinterpret_cast<CompilationUnit *> (cu);
}

void luagenSemanticActions_setSourceFilename(const char * s)
{
	lgse_pSourceFilename = s;
}

void luagenSemanticActions_setEntityName(const char * s)
{
	lgse_pEntityName = s;
}

const char *luagenSemanticActions_getEntityName()
{
	return lgse_pEntityName;
}
void luagenSemanticActions_init()
{
	if(!pcUnit)
	{
		pcUnit = new CompilationUnit();
	}
	pStrFactory = antlr3StringFactoryNew(ANTLR3_ENC_UTF8);
	isOutputMuted = false;
}

void luagenSemanticActions_end()
{
//	delete pcUnit;
	pStrFactory->close(pStrFactory);
}

void luagenSemanticActions_beginCodeBlock()
{
}

void luagenSemanticActions_beginStateCodeBlock(CNSCodeBlockType t, char * stateNum)
{
	//printf("BEGIN CODE BLOCK %s\n", stateNum);
	luagenSemanticActions_beginCodeBlock();
	std::string id = std::string("state_") + stateNum;
	// Replace '-' with 'm'
	int idx = id.find_first_of("-", 0);
	if(idx >= 0)
		id.replace(idx, 1, "m");

	int idn = 0;

	if (t == CBT_STATE)
	{
		idn = atoi(stateNum);
	}

	auto p = std::make_shared<CNSCodeBlock>(id, "", t, idn);
	pCurCodeBlock = p.get();
	pcUnit->addCodeBlock(id, p);

	indent = 0;
}

void luagenSemanticActions_setCode(pANTLR3_STRING code)
{
	pCurCodeBlock->getCode() = reinterpret_cast<char *>(code->chars);
}

void luagenSemanticActions_endCodeBlock()
{	
	pCurCodeBlock->getCode().append("\n");	
	//std::cout << *pCurCodeBlock;
}

pANTLR3_STRING luagenSemanticActions_getNewString()
{
	return pStrFactory->newStr(pStrFactory, (pANTLR3_UINT8)"");
}

void luagenSemanticActions_appendCodeLine(pANTLR3_STRING c)
{
	luagenSemanticActions_appendCodeLineC((char *)c->chars);
}

void luagenSemanticActions_appendCodeLineC(const char * c)
{
	if(!isOutputMuted)
	{
		for(int i = 0; i < indent; ++i)
		{
			pCurCodeBlock->getCode().append("\t");
		}
		pCurCodeBlock->getCode().append(c);
		pCurCodeBlock->getCode().append("\n");
	}
}

void luagenSemanticActions_incInd()
{
	++indent;
}

void luagenSemanticActions_decInd()
{
	--indent;
}

const char * luagenSemanticActions_getCurCodeBlockID()
{
	return pCurCodeBlock->getID().c_str();
}

void luagenSemanticActions_closeBlocksToLevel(int lvl)
{
	while(indent > lvl)
	{
		--indent;
		luagenSemanticActions_appendCodeLineC("end");		
	}
}

void luagenSemanticActions_muteOutput()
{
	isOutputMuted = true;
}
void luagenSemanticActions_unMuteOutput()
{
	isOutputMuted = false;
}

const char * luagenSemanticActions_getNameForStateInit(pANTLR3_STRING lhs, unsigned int *nArgs)
{
	char * ret = nullptr;

	char * LHS = strdup((char *)lhs->chars);
	char_string_toUpperSelf(LHS);
	
	*nArgs = 0;

	for(unsigned int i = 0; i < cns_stateDefSignature.syntaxes[0].nAttrs; ++i)
	{
		cns_ControllerAttribute_t * pControllerAttr = &cns_stateDefSignature.syntaxes[0].attrs[i];
		if(!strcmp(LHS, pControllerAttr->UCName))
		{
			*nArgs = pControllerAttr->nArgs;
			ret = (char *)pControllerAttr->properName;
			break;
		}
	}

	delete[] LHS;

	return ret;
}

const char * luagenSemanticActions_getNameForControllerArg(cnsControllerUsage_t * pCU, pANTLR3_STRING lhs)
{
	char * ret = nullptr;
	static const char* kEmpty = "";

	char * LHS = strdup((char *)lhs->chars);
	char_string_toUpperSelf(LHS);

	for(unsigned int i = 0; i < pCU->pSignature->syntaxes[pCU->usedSyntax].nAttrs; ++i)
	{
		cns_ControllerAttribute_t * pControllerAttr = &pCU->pSignature->syntaxes[pCU->usedSyntax].attrs[i];
		if(!strcmp(LHS, pControllerAttr->UCName))
		{
			ret = (char *)pControllerAttr->properName;
			break;
		}
	}

	if(ret == nullptr)
	{
		// Lookup the common table
		for(unsigned int i = 0; i < cns_CommonControllerAttrs.nAttrs; ++i)
		{
			cns_ControllerAttribute_t * pControllerAttr = &cns_CommonControllerAttrs.attrs[i];
			if(!strcmp(LHS, pControllerAttr->UCName))
			{
				ret = (char *)pControllerAttr->properName;
				break;
			}
		}
	}

	delete[] LHS;

	return ret ? ret : kEmpty;
}

const char * luagenSemanticActions_getNameForTrigger(pANTLR3_STRING tName)
{
	char * ret = nullptr;

	char * TNAME = strdup((char *)tName->chars);
	char * TNAME2;

	char_string_toUpperSelf(TNAME);

	for(unsigned int i = 0; cns_RSTriggerSymbolTable[i].UCName[0] != '\0'; ++i)
	{	
		if(!strcmp(TNAME, cns_RSTriggerSymbolTable[i].UCName))
		{
			ret = (char *)cns_RSTriggerSymbolTable[i].properName;
			break;
		}
	}

	if(ret == nullptr)
	{
		// Remove the first char and try again (Fifelse / Sifelse / ....)
		TNAME2 = TNAME;
		++TNAME2;
		for(unsigned int i = 0; cns_RSTriggerSymbolTable[i].UCName[0] != '\0'; ++i)
		{	
			if(!strcmp(TNAME2, cns_RSTriggerSymbolTable[i].UCName))
			{
				ret = (char *)cns_RSTriggerSymbolTable[i].properName;
				break;
			}
		}
	}

	delete[] TNAME;

	return ret;
}

