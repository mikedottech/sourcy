// CNSCheckSemanticActions.cpp — Semantic-action callbacks invoked by the cnscheck tree parser.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include "CNSSemantics.h"
#include "CNSControllerUsage.h"
#include "CNSControllerElement.h"
#include <string>
#include <unordered_map>
#include <list>
#include <assert.h>

extern "C"
{
#	include "Helpers.h"
}
cnsControllerUsage_t cns_stateDefProxyController =
{
	0,
	&cns_stateDefSignature
};

typedef enum
{
	CR_OK,
	CR_WARNING,
	CR_ERROR
} coercionResult_t;

typedef enum
{
	CM_NO,
	CM_CONTROLLER,
	CM_STATEDEF,
	CM_INFOBLOCK
} checkMode_t;


// Mutable file-scope state used by ANTLR3 C-style semantic action callbacks.
// ANTLR3 actions are free functions without a context pointer, so per-walk
// state has to live here. Not thread-safe; the compiler runs single-threaded.
int							statecount;
cnsControllerUsage_t		*pCurrentController;
cns_ControllerAttribute_t	*pCurrentAttribute;
int							currentArg;
bool						curControllerIsnullptr = false;
std::unordered_map<std::string, bool> usedAttributes;
checkMode_t					checkMode = CM_NO;
cns_TriggerSignature_t		*pCurTrigger;

bool isAttributeUsed(std::string attr)
{
	return usedAttributes.find(attr) != usedAttributes.end();
}

bool addUsedAttribute(std::string attr)
{
	if(isAttributeUsed(attr))
	{
		return false;
	} else {
		usedAttributes.insert(std::pair<std::string, bool>(attr, true));
	}
	return true;
}

void clearUsedAttributes()
{		
	usedAttributes.clear();
}

void reportMissingControllerArgs(cnsControllerUsage_t *cnt)
{
	cns_ControllerSyntax_t * pControllerSyntax = &(cnt->pSignature->syntaxes[cnt->usedSyntax]);

	unsigned int iend = pControllerSyntax->nAttrs;

	for(unsigned int i = 0; i < iend; ++i)
	{
		cns_ControllerAttribute_t *currentAttr = &(pControllerSyntax->attrs[i]);
		if(!currentAttr->optional && !isAttributeUsed(currentAttr->UCName))
		{
			fprintf(stderr, "%s\n", currentAttr->UCName);
		}
	}
}

bool getControllerSuitableSyntax(int *res, cnsControllerUsage_t *cnt)
{
	cns_ControllerSignature_t * pControllerSignature = cnt->pSignature;
	bool isSyntaxSuitable = false;

	for(unsigned int j = 0; j < pControllerSignature->nSyntaxes && !isSyntaxSuitable; ++j)
	{
		isSyntaxSuitable = true;
		cns_ControllerSyntax_t * pControllerSyntax = &(pControllerSignature->syntaxes[j]);
		for(unsigned int i = 0; i < pControllerSyntax->nAttrs && isSyntaxSuitable; ++i)
		{			
			cns_ControllerAttribute_t *currentAttr = &(pControllerSyntax->attrs[i]);
			if(isAttributeUsed(currentAttr->UCName))
			{
				continue;
			} else {
				isSyntaxSuitable &= currentAttr->optional;
			}
		}
		if(isSyntaxSuitable)
		{
			*res = j;			
		}
	}

	return isSyntaxSuitable;
}

bool isControllerCorrect(cnsControllerUsage_t *cnt)
{
	if(cnt->usedSyntax <= -1)
	{
		// Does the controller have no syntaxes?
		if(cnt->pSignature->nSyntaxes == 0)
		{			
			return true;
		} else {
			// Check if all of the non already specified attributes are optional for any syntax
			return getControllerSuitableSyntax(&cnt->usedSyntax, cnt);
		}
	}

	cns_ControllerSyntax_t * pControllerSyntax = &(cnt->pSignature->syntaxes[cnt->usedSyntax]);

	unsigned int iend = pControllerSyntax->nAttrs;

	for(unsigned int i = 0; i < iend; ++i)
	{
		cns_ControllerAttribute_t *currentAttr = &(pControllerSyntax->attrs[i]);
		if(!currentAttr->optional && !isAttributeUsed(currentAttr->UCName))
		{
			return false;
		}
	}

	return true;
}



coercionResult_t tryCoerce(cns_Datatype_t dtExpected, cns_Datatype_t dtFound)
{
	if(dtExpected == CDT_INT && dtFound == CDT_FLOAT)
	{
		return CR_WARNING;
	} else if(dtExpected == CDT_NUMBER && (dtFound == CDT_INT || dtFound == CDT_FLOAT))
	{	// This is ok
		return CR_OK;
	} else if((dtExpected == CDT_INT || dtExpected == CDT_FLOAT) && dtFound == CDT_NUMBER)
	{	// OK also
		return CR_OK;
	} else if(dtExpected == CDT_FLOAT && dtFound == CDT_INT)
	{	// This is OK too
		return CR_OK;
	} else if(dtExpected != dtFound)
	{
		return CR_ERROR;
	}
	return CR_OK;	// Perfect match
}

void cns_reportMismatchSignatureError(bool isTrigger, char *name, unsigned int nArgs, cns_TriggerSignature_t * pSignature, cns_Datatype_t types [])
{
	unsigned int i;

	if(isTrigger)
	{
		fprintf(stderr,"ERROR: Call to trigger %s(", name);
	} else {
		fprintf(stderr,"ERROR: Argument %s = ", name);
	}
	
	for(i = 0; i < nArgs; ++i)
	{
		fprintf(stderr,"%s", cns_getDataTypeName(types[i]));
		if(i != nArgs-1)
		{
			fprintf(stderr, ", ");
		}
	}

	if(isTrigger)
	{
		fprintf(stderr,") doesn't match the trigger's signature ");
		fprintf(stderr,"%s(", name);
	} else {
		fprintf(stderr," doesn't match the attribute's signature ");
		fprintf(stderr,"%s = ", name);
	}
	for(i = 0; i < pSignature->nArgs; ++i)
	{
		if(pSignature->arguments[i].optional)
		{
			fprintf(stderr,"[");
		}
		fprintf(stderr,"%s", cns_getDataTypeName(pSignature->arguments[i].dataType));
		if(pSignature->arguments[i].optional)
		{
			fprintf(stderr,"]");
		}
		if(i != pSignature->nArgs-1)
		{
			fprintf(stderr, ", ");
		}
	}

	if(isTrigger)
	{
		fprintf(stderr, ")\n");
	} else {
		fprintf(stderr, "\n");
	}
	//fprintf(stderr, ")\nToo %s arguments in call to trigger %s\n", nArgs > pTriggerSig->nArgs ? "many" : "few", name->chars);
}

extern "C"
{
#	include "CNSCheckSemanticActions.h"


void lgNameState()
	{
		printf("%d, ", statecount);
		statecount++;
	}

	void lgNameStateDef(pANTLR3_STRING id)
	{
		printf("\nStatedef : %s\n", id->chars);
		statecount = 0;
	}

	ANTLR3_BOOLEAN checkVarSubscript(cns_Datatype_t t, cns_VarType_t v)
	{
		if(t != CDT_INT)
		{
			printf("Warning: The expression used as a subscript for the variable must evaluate to an integer. The found %s will be truncated!\n", cns_getDataTypeName(t));
		}
		return ANTLR3_TRUE;
	}
		
	cns_Datatype_t cnsVal_checkRegularTrigger(pANTLR3_STRING name, unsigned int nArgs, cns_Datatype_t types [])
	{
		cns_Datatype_t dtExpected, dtFound;
		unsigned int i;

		antlr3_string_toUpper(name);

		cns_TriggerSignature_t * pTriggerSig;

		if(!lookupTriggerSignature((const char *)name->chars, pTriggerSig))
		{
			fprintf(stderr, "Error: The trigger %s does not exist!\n", name->chars);
			return CDT_ERROR;
		}
		
		
		// Check argument types
		for(i = 0; i < pTriggerSig->nArgs; ++i)
		{
			dtExpected = pTriggerSig->arguments[i].dataType;

			if(i == nArgs)	// Should go from 0 to nArgs - 1
			{
				if(pTriggerSig->arguments[i].optional)
				{
					break; // First optional arg. It's assumed to be the last in the signature
				} else {
					goto mismatchSignatureError;
				}
			}

			dtFound = types[i];

			switch(tryCoerce(dtExpected, dtFound))
			{
			case CR_WARNING:
					printf("Warning: Trigger %s expects %s as argument %d, but a %s was found instead!\n", name->chars, cns_getDataTypeName(dtExpected), i + 1, cns_getDataTypeName(dtFound));
				break;
			case CR_ERROR:
				goto mismatchSignatureError;
			case CR_OK:
				break;
			}
		}

		if(nArgs > pTriggerSig->nArgs)
		{
			goto mismatchSignatureError;
		}

		if(pTriggerSig->returnType == CDT_SAME)
		{
			return pTriggerSig->arguments[0].dataType;
		} else {
			return pTriggerSig->returnType;
		}

mismatchSignatureError:
		cns_reportMismatchSignatureError(true, (char*)name->chars, nArgs, pTriggerSig, types);
		return CDT_ERROR;
	}

	cns_Datatype_t cnsVal_checkOldStyleWithIDTrigger(pANTLR3_STRING name, pANTLR3_STRING string)
	{
		antlr3_string_toUpper(name);
		antlr3_string_toUpper(string);

		cns_TriggerSignature_t * pTriggerSig;

		if(!lookupTriggerSignature((const char *)name->chars, pTriggerSig))
		{
			fprintf(stderr, "Error: The trigger %s does not exist!\n", name->chars);
			return CDT_ERROR;
		}
		
		

		return CDT_ERROR;
	}

	ANTLR3_BOOLEAN cns_beginControllerAttribute(char *lhs)
	{
		assert(checkMode == CM_CONTROLLER || checkMode == CM_STATEDEF);

		if(curControllerIsnullptr)
			return ANTLR3_TRUE;

/*		if(!strcmp("VARADD", pCurrentController->pSignature->UCName))
		{
			printf("VARADD.%s\n", lhs);
		}
*/
		cns_ControllerSignature_t *pSignature = pCurrentController->pSignature;
		
		char * LHS = strdup(lhs);
		
		char_string_toUpper(LHS, lhs);

		currentArg = 0;

		if(cns_lookupControllerCommonAttrs(LHS, pCurrentAttribute))
		{
			goto attr_ok;
		}
	
		if(pCurrentController->usedSyntax < 0)
		{
			// No syntax yet, lookup in every syntax
			int nSyn = pSignature->nSyntaxes;
			for(int i = 0; i < nSyn; ++i)
			{
				int nAttrs = pSignature->syntaxes[i].nAttrs;
				for(int j = 0; j < nAttrs; ++j)
				{
					if(!strcmp(LHS, pSignature->syntaxes[i].attrs[j].UCName))
					{
						// Check if the argument is shared across syntaxes
						for(int k = 0; k < nSyn; ++k)
						{
							if(k != i)
							{
								int nAttrs2 = pSignature->syntaxes[k].nAttrs;
								for(int l = 0; l < nAttrs2; ++l)
								{
									if(!strcmp(LHS, pSignature->syntaxes[k].attrs[l].UCName))
									{
										pCurrentAttribute = &(pSignature->syntaxes[k].attrs[l]);
										goto attr_ok;	// Return here and don't set usedSyntax
									}
								}
							}
						}
						pCurrentController->usedSyntax = i;
						pCurrentAttribute = &(pSignature->syntaxes[i].attrs[j]);
						
						goto attr_ok;		// Okay, this attribute exists
					}
				}
			}
			
			if(checkMode == CM_CONTROLLER)
			{
				fprintf(stderr,"ERROR: The attribute %s doesn't belong to the controller type %s in any of its syntaxes.\n", lhs, pSignature->UCName);
			} else {
				fprintf(stderr,"ERROR: The attribute %s can't be specified for a StateDef block.\n", lhs);
			}

			//system("pause");
		} else {
			// Lookup only the used syntax
			int nAttrs = pSignature->syntaxes[pCurrentController->usedSyntax].nAttrs;
			for(int j = 0; j < nAttrs; ++j)
			{
				if(!strcmp(LHS, pSignature->syntaxes[pCurrentController->usedSyntax].attrs[j].UCName))
				{
					pCurrentAttribute = &(pSignature->syntaxes[pCurrentController->usedSyntax].attrs[j]);
					goto attr_ok;
				}
			}			

			if(checkMode == CM_CONTROLLER)
			{
				fprintf(stderr,"ERROR: The attribute %s doesn't belong to the controller type %s in the used syntax.\n", lhs, pSignature->UCName);
			} else {
				fprintf(stderr,"ERROR: The attribute %s can't be specified for a StateDef block.\n", lhs);
			}			
			//system("pause");
		}
		
		//printf("[%s]\n", lhs);

		delete [] LHS;
		return ANTLR3_FALSE;

attr_ok:
		delete [] LHS;
		if(!addUsedAttribute(pCurrentAttribute->UCName))
		{
			if(checkMode == CM_CONTROLLER)
			{
				fprintf(stderr,"ERROR: The attribute %s has been already specified for the controller %s.\n", lhs, pSignature->UCName);
			} else {
				fprintf(stderr,"ERROR: The attribute %s has been already specified for the StateDef.\n", lhs);
			}

			curControllerIsnullptr = true;
			return ANTLR3_FALSE;
		}
		return ANTLR3_TRUE;
	}
	
	ANTLR3_BOOLEAN cns_beginTriggerCall(char *tName)
	{
		char *TNAME = strdup(tName);
		
		char_string_toUpper(TNAME, tName);

		bool res = lookupTriggerSignature(TNAME, pCurTrigger);

		delete[] TNAME;

		if(!res)
		{
			fprintf(stderr, "Error: The trigger %s does not exist!\n", tName);
			return ANTLR3_FALSE;
		}

		return ANTLR3_TRUE;
	}


	void reportAllowedIDs(const char ** transIDList)
	{
		const char * curID = transIDList[0];
		int i = 0;
		while(curID[0] != '\0')
		{
			fprintf(stderr, "%s", curID);
			curID = transIDList[++i];
			if(curID[0] != '\0')
			{
				fprintf(stderr, ", ");
			}
		}
		fprintf(stderr, "\n");
	}

	ANTLR3_BOOLEAN cns_checkTriggerArgument(int argNo, cns_Datatype_t dt, char *id)
	{
		ANTLR3_BOOLEAN result = ANTLR3_FALSE;
		char * ID = strdup(id);
		char_string_toUpper(ID, id);

		//printf("%d, %s\n", argNo, id);
		if(dt == CDT_ID)
		{
			char * curID = (char*)pCurTrigger->arguments[argNo].allowedIDs[0];
			int i = 0;
			while(curID[0] != '\0')
			{
				if(!strcmp(ID, curID))
				{
					result = ANTLR3_TRUE;
					break;
				}
				curID = (char*)pCurTrigger->arguments[argNo].allowedIDs[++i];
			}
		}

		delete []ID;

		if(!result)
		{
			fprintf(stderr, "ERROR: The id %s is not valid as argument %d of trigger %s.\n", id, argNo + 1, pCurTrigger->UCName);
			fprintf(stderr, "The allowed IDs for this argument are: ");
			reportAllowedIDs(pCurTrigger->arguments[argNo].allowedIDs);
		}

		return result;
	}

	cns_Datatype_t cns_finishTriggerCall()
	{
		cns_Datatype_t retType = pCurTrigger->returnType;
		pCurTrigger = nullptr;
		return retType;
	}

	ANTLR3_BOOLEAN cns_beginStateController(void * controllerUsage)
	{
		pCurrentController	= (cnsControllerUsage_t *) controllerUsage;
		curControllerIsnullptr = !strcmp(pCurrentController->pSignature->UCName, "nullptr");
		pCurrentAttribute	= nullptr;
		checkMode			= CM_CONTROLLER;
		clearUsedAttributes();
		return ANTLR3_TRUE;
	}


	ANTLR3_BOOLEAN cns_checkControllerAttribute(int nArgument, cns_Datatype_t dataType, char * id)
	{
		assert(checkMode == CM_CONTROLLER || checkMode == CM_STATEDEF);
		// First: Check previous arguments for missing mandatory args
		
		// Don't check if the current controller is nullptr
		if(curControllerIsnullptr)
			return ANTLR3_TRUE;

		if(!pCurrentAttribute)
			return ANTLR3_FALSE;

		if(nArgument >= (int)pCurrentAttribute->nArgs)
		{
			fprintf(stderr, "ERROR: Too many arguments for attribute %s. Expected %d, found %d.\n", pCurrentAttribute->UCName, pCurrentAttribute->nArgs, nArgument+1);
			return ANTLR3_FALSE;
		}

		while(currentArg < nArgument)
		{
			if(!pCurrentAttribute->args[currentArg].optional)
			{
				fprintf(stderr, "ERROR: The argument %d for the attribute %s is not optional.\n", currentArg+1, pCurrentAttribute->UCName);
				return ANTLR3_FALSE;
			}
			++currentArg;
		}

		// pCurrentAttribute points to the attribute indicated by current lhs

		// type validation
	
		if(!pCurrentAttribute)	// The LHS was not recognized
		{			
			return ANTLR3_FALSE;
		}
		
		cns_Datatype_t dtFound = dataType, dtExpected = pCurrentAttribute->args[currentArg].dataType;
		currentArg = nArgument + 1;

		switch(tryCoerce(dtExpected, dtFound))
		{
		case CR_OK:
			if(dtExpected == CDT_ID || dtExpected == CDT_STRING)
			{				
				if(id == nullptr)
				{
					/*
					if(checkMode == CM_CONTROLLER)
					{
						printf("WARNING: Type coercion. The argument %d for the attribute %s in the controller %s has to be a %s. The found %s will be truncated. Consider using the FLOOR trigger.\n", currentArg, pCurrentAttribute->UCName, pCurrentController->pSignature->UCName,cns_getDataTypeName(dtExpected), cns_getDataTypeName(dtFound));
					} else {
						printf("WARNING: Type coercion. The argument %d for the attribute %s in a StateDef block has to be a %s. The found %s will be truncated. Consider using the FLOOR trigger.\n", currentArg, pCurrentAttribute->UCName, cns_getDataTypeName(dtExpected), cns_getDataTypeName(dtFound));
					}*/
					return ANTLR3_FALSE;
				}

				ANTLR3_BOOLEAN result = ANTLR3_FALSE;

				char * ID = strdup(id);
				
				char_string_toUpper(ID, id);

				// Do ID validation
				int i = 0;

				const char ** IDList = pCurrentAttribute->args[nArgument].allowedIDs;
				if(IDList != nullptr)
				{
					const char * curID = pCurrentAttribute->args[nArgument].allowedIDs[0];
					while(curID[0] != '\0')
					{
						if(!strcmp(curID,ID))
						{
							result = ANTLR3_TRUE;	// Match!
							break;
						}
						curID = pCurrentAttribute->args[nArgument].allowedIDs[++i];
					}						
				} else {					
					result = ANTLR3_TRUE;
				}

				delete[] ID;
				
				if(result == ANTLR3_FALSE)
				{
					if(checkMode == CM_CONTROLLER)
					{
						fprintf(stderr, "ERROR: The non-allowed id '%s' was specified as argument %d for the attribute %s in the controller %s.\n", id, currentArg, pCurrentAttribute->UCName, pCurrentController->pSignature->UCName);
					} else {
						fprintf(stderr, "ERROR: The non-allowed id '%s' was specified as argument %d for the attribute %s in a StateDef block.\n", id, currentArg, pCurrentAttribute->UCName);
					}
					if(IDList != nullptr)
					{
						// Report allowed IDs
						fprintf(stderr, "The allowed IDs for this attribute are: \n");
						reportAllowedIDs(IDList);
					}
				}
				return result;
			}
			return ANTLR3_TRUE;
		case CR_WARNING:
			// Report waring
			if(checkMode == CM_CONTROLLER)
			{
				printf("WARNING: Type coercion. The argument %d for the attribute %s in the controller %s has to be a %s. The found %s will be truncated. Consider using the FLOOR trigger.\n", currentArg, pCurrentAttribute->UCName, pCurrentController->pSignature->UCName,cns_getDataTypeName(dtExpected), cns_getDataTypeName(dtFound));
			} else {
				printf("WARNING: Type coercion. The argument %d for the attribute %s in a StateDef block has to be a %s. The found %s will be truncated. Consider using the FLOOR trigger.\n", currentArg, pCurrentAttribute->UCName, cns_getDataTypeName(dtExpected), cns_getDataTypeName(dtFound));
			}
			return ANTLR3_TRUE;
		case CR_ERROR:
			// Report error
			if(checkMode == CM_CONTROLLER)
			{				
				fprintf(stderr, "ERROR: Type mismatch. The argument %d for the attribute %s in the controller %s has to be a %s. A %s was found instead.\n", currentArg, pCurrentAttribute->UCName, pCurrentController->pSignature->UCName,cns_getDataTypeName(dtExpected), cns_getDataTypeName(dtFound));
			} else {
				fprintf(stderr, "ERROR: Type mismatch. The argument %d for the attribute %s in a StateDef block has to be a %s. A %s was found instead.\n", currentArg, pCurrentAttribute->UCName, cns_getDataTypeName(dtExpected), cns_getDataTypeName(dtFound));
			}

			return ANTLR3_FALSE;
		}
		
		return ANTLR3_FALSE;
	}

	ANTLR3_BOOLEAN cns_finishControllerAttribute()
	{
		// Missing mandatory arguments? -> false : true
		if(curControllerIsnullptr)
			return ANTLR3_TRUE;


		if(!pCurrentAttribute)
		{
			return ANTLR3_FALSE;
		}

		int found = currentArg;

		while(currentArg < (int)pCurrentAttribute->nArgs)
		{
			if(!pCurrentAttribute->args[currentArg].optional)
			{
				fprintf(stderr, "ERROR: Too few arguments for attribute %s. Expected at least %d, found %d.\n", pCurrentAttribute->UCName, currentArg + 1, found);
				return ANTLR3_FALSE;
			}
			++currentArg;
		}

		return ANTLR3_TRUE;
	}

	ANTLR3_BOOLEAN cns_finishStateController()
	{
		// Missing mandatory attributes? -> false : true
		checkMode			= CM_NO;

		if(pCurrentController->pSignature->nSyntaxes == 0)
		{
			return ANTLR3_TRUE;
		}

		if(!isControllerCorrect(pCurrentController))
		{
			if(pCurrentController->usedSyntax >= 0)
			{
				fprintf(stderr, "ERROR: Incomplete state controller. The following mandatory attributes are missing in the controller %s:\n", pCurrentController->pSignature->UCName);
				reportMissingControllerArgs(pCurrentController);
			} else {
				fprintf(stderr, "ERROR: Incomplete state controller. Missing attributes for the controller %s.\n", pCurrentController->pSignature->UCName);
			}
			return ANTLR3_FALSE;
		}

		return ANTLR3_TRUE;
	}

	cns_Datatype_t cns_getTriggerReturnTypeSelID(char * tName, char * selID)
	{
		cns_Datatype_t  result = CDT_ERROR;
		cns_TriggerSignature_t *pTriggerSignature;
		
		char *TNAME = strdup(tName);
		char *SELID = strdup(selID);

		char_string_toUpper(TNAME, tName);
		char_string_toUpper(SELID, selID);

		if(lookupTriggerSignature(TNAME, pTriggerSignature))
		{
			cns_Datatype_t		*pselRetList;
			char				**pselNameList = (char **)pTriggerSignature->arguments[0].allowedIDs;

			if(!strcmp(TNAME, "CONST"))
			{
				pselRetList	= cns_IDreturns;
			} else if(!strcmp(TNAME, "GETHITVAR")) {	// Must be GetHitVar (forced by the grammar)
				pselRetList	= cns_hitVarReturns;
			} else {	// STAGEVAR
				pselRetList	= cns_stageVarReturns;
			}

			int idx = lookupConstStringTable((const char **)pselNameList, SELID);

			if(idx > -1)
			{
				result = pselRetList[idx];
			} else {
				fprintf(stderr, "ERROR: The trigger %s was called with a non-allowed ID '%s'\n", tName, selID);
				result = CDT_ERROR;
			}

		} else {
			result = CDT_ERROR;
		}

		delete[] TNAME;
		delete[] SELID;

		return result;
	}

	void cns_reorderControllerElements(pANTLR3_BASE_TREE t)
	{
		std::list<CNSControllerElement> l;

		// 1.- Walk its children and generate a list of CNSControllerElement(s)
		for(unsigned int i = 0; i < t->children->count; ++i)
		{
			l.push_back(CNSControllerElement((pANTLR3_BASE_TREE)t->children->elements[i].element));
		}

		// 2.- Sort them
		l.sort();
		
		// 3.- Walk the list and reassign the references of the children
		
		int j = 0;
		for(std::list<CNSControllerElement>::iterator i = l.begin(); i != l.end(); i++)
		{
			t->setChild(t, j++, (void*)(*i).getSubTree());
		}
	}
}

ANTLR3_BOOLEAN cns_beginStateDecl()
{	
	// TODO: Set this to the special "state" controller def
	pCurrentController	= &cns_stateDefProxyController;
	curControllerIsnullptr = false;
	pCurrentAttribute	= nullptr;
	checkMode			= CM_STATEDEF;
	clearUsedAttributes();	
	return ANTLR3_TRUE;
}

ANTLR3_BOOLEAN cns_finishStateDecl()
{
	return cns_finishStateController();
}
