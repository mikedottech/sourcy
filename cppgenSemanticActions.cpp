
#include "CNSCodeBlock.h"
#include <iostream>
#include "CNSSemantics.h"
#include "antlr3.h"
#include "CompilationUnit.h"
#include <vector>

extern "C"
{
#	include "Helpers.h"
#	include "CPPGenSemanticActions.h"
}

static CompilationUnit *pcUnit = NULL;
static CNSCodeBlock	*pCurCodeBlock;
static pANTLR3_STRING_FACTORY pStrFactory;
static int				indent;
static bool			isOutputMuted;
static const char		*lgse_pEntityName;
static const char		*lgse_pSourceFilename;

void cppgenSemanticActions_setCompilationUnit(void * cu)
{
	pcUnit = reinterpret_cast<CompilationUnit *> (cu);
}

void cppgenSemanticActions_setSourceFilename(const char * s)
{
	lgse_pSourceFilename = s;
}

void cppgenSemanticActions_setEntityName(const char * s)
{
	lgse_pEntityName = s;
}

const char *cppgenSemanticActions_getEntityName()
{
	return lgse_pEntityName;
}
void cppgenSemanticActions_init()
{
	if(!pcUnit)
	{
		pcUnit = new CompilationUnit();
	}
	pStrFactory = antlr3StringFactoryNew(ANTLR3_ENC_UTF8);
	isOutputMuted = false;
	//stateFunctionNames.clear();
}

void cppgenSemanticActions_end()
{
//	delete pcUnit;
	pStrFactory->close(pStrFactory);
}

void cppgenSemanticActions_beginCodeBlock()
{
}

void cppgenSemanticActions_beginStateCodeBlock(CNSCodeBlockType t, char * stateNum)
{
	//printf("BEGIN CODE BLOCK %s\n", stateNum);
	cppgenSemanticActions_beginCodeBlock();
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

void cppgenSemanticActions_setCode(pANTLR3_STRING code)
{
	pCurCodeBlock->getCode() = reinterpret_cast<char *>(code->chars);
}

void cppgenSemanticActions_endCodeBlock()
{	
	pCurCodeBlock->getCode().append("\n");	
	//std::cout << *pCurCodeBlock;
}

pANTLR3_STRING cppgenSemanticActions_getNewString()
{
	return pStrFactory->newStr(pStrFactory, (pANTLR3_UINT8)"");
}

void cppgenSemanticActions_appendCodeLine(pANTLR3_STRING c)
{
	cppgenSemanticActions_appendCodeLineC((char *)c->chars);
}

void cppgenSemanticActions_appendCodeLineC(const char * c)
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

void cppgenSemanticActions_incInd()
{
	++indent;
}

void cppgenSemanticActions_decInd()
{
	--indent;
}

const char * cppgenSemanticActions_getCurCodeBlockID()
{
	return pCurCodeBlock->getID().c_str();
}

void cppgenSemanticActions_closeBlocksToLevel(int lvl)
{
	while(indent > lvl)
	{
		--indent;
		cppgenSemanticActions_appendCodeLineC("}");		
	}
}

void cppgenSemanticActions_muteOutput()
{
	isOutputMuted = true;
}
void cppgenSemanticActions_unMuteOutput()
{
	isOutputMuted = false;
}

const char * cppgenSemanticActions_getNameForStateInit(pANTLR3_STRING lhs, unsigned int *nArgs)
{
	char * ret = NULL;

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

const char * cppgenSemanticActions_getNameForControllerArg(cnsControllerUsage_t * pCU, pANTLR3_STRING lhs)
{
	char * ret = NULL;

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

	if(ret == NULL)
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

	return ret;
}

const char * cppgenSemanticActions_getNameForTrigger(pANTLR3_STRING tName)
{
	char * ret = NULL;

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

	if(ret == NULL)
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

