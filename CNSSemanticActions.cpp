// CNSSemanticActions.cpp — Semantic-action callbacks invoked by the cns parser.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include "CNSSemantics.h"
#include "CNSControllerUsage.h"
extern "C"
{
#	include "Helpers.h"
}


// Mutable file-scope state used by ANTLR3 C-style semantic action callbacks.
// ANTLR3 actions are free functions without a context pointer, so per-walk
// state has to live here. Not thread-safe; the compiler runs single-threaded.
cns_ControllerAttribute_t	*pCurControllerAttr;
cnsControllerUsage_t		*pCurControllerUsage;
cns_ControllerAttribute_t	*pCurStateAttribute;
bool						isControllernullptr;

typedef enum
{
	AC_STATEDEF,
	AC_STCONTROLLER
} assignContext_t;

assignContext_t assignCtx = AC_STATEDEF;

extern "C"
{
#	include "CNSSemanticActions.h"

ANTLR3_BOOLEAN cnsActions_triggerExist(const char * tName)
	{
		return (ANTLR3_BOOLEAN)cns_triggerExists(tName);
	}

	ANTLR3_BOOLEAN cnsActions_getControllerSignature(const char * cName, cnsControllerUsage_t * cu)
	{
		if(!cns_lookupControllerSignature(cName, cu->pSignature))
		{
			fprintf(stderr, "The controller %s does not exist.\n", cName);
			//return ANTLR3_FALSE;
			pCurControllerUsage->pSignature = nullptr;
			return ANTLR3_FALSE;
		}

		isControllernullptr = (!strcmp("nullptr", cu->pSignature->UCName));

		pCurControllerUsage = cu;
		return ANTLR3_TRUE;
	}

	ANTLR3_BOOLEAN cnsActions_setLHS(char * lhs)
	{			
		if(isControllernullptr)
		{
			return ANTLR3_TRUE;
		}

		char_string_toUpperSelf(lhs);

		switch(assignCtx)
		{
			case AC_STATEDEF:
				{
				int iend = cns_stateDefSignature.syntaxes[0].nAttrs;
				for(int i = 0; i < iend; ++i)
				{
					if(!strcmp(lhs, cns_stateDefSignature.syntaxes[0].attrs[i].UCName))
					{
						return ANTLR3_TRUE;
					}
					pCurStateAttribute = &cns_stateDefSignature.syntaxes[0].attrs[i];
				}
				fprintf(stderr, "ERROR: The attribute %s is not valid for a state definition.!\n", lhs);
				return ANTLR3_FALSE;
			}
			case AC_STCONTROLLER:
			{
				if(!pCurControllerUsage->pSignature)
				{
					fprintf(stderr, "ERROR: Controller type not set! (%s)\n", lhs);
					return ANTLR3_FALSE;
				}
				// First find controller argument in the common table
				int iend = cns_CommonControllerAttrs.nAttrs;
				
				for(int i = 0; i < iend; ++i)
				{
					if(!strcmp(lhs, cns_CommonControllerAttrs.attrs[i].UCName))
					{
						pCurControllerAttr = &(cns_CommonControllerAttrs.attrs[i]);
						return ANTLR3_TRUE;
					}
				}

				// Find controller argument in all syntaxes
				iend = pCurControllerUsage->pSignature->nSyntaxes;
				for(int i = 0; i < iend; ++i)
				{
					int jend = pCurControllerUsage->pSignature->syntaxes[i].nAttrs;
					for(int j = 0; j < jend; ++j)
					{
						pCurControllerAttr = &(pCurControllerUsage->pSignature->syntaxes[i].attrs[j]);
						if(!strcmp(pCurControllerAttr->UCName, lhs))
						{
							return ANTLR3_TRUE;
						}
					}
					
				}
				// TODO: Report error
				fprintf(stderr, "ERROR: The controller attribute %s doesn't exist in any syntax of the controller %s\n", lhs, pCurControllerUsage->pSignature->UCName);
				return ANTLR3_FALSE;
				
			}
			break;
		}
		return ANTLR3_FALSE;
	}

	void cnsActions_setController()
	{
		assignCtx = AC_STCONTROLLER;		
	}

	void cnsActions_setState()
	{
		assignCtx = AC_STATEDEF;
	}

	// Returns ANTLR3_TRUE if an ID was expected, otherwise returns false
	ANTLR3_BOOLEAN cnsActions_disambiguateTriggerID(int argIdx)
	{
		if(isControllernullptr)
		{
			return ANTLR3_FALSE;
		}

		switch(assignCtx)
		{
			case AC_STATEDEF:
			{
				if(!pCurStateAttribute)
				{
					return ANTLR3_FALSE;
				}

				if(argIdx >= (int)pCurStateAttribute->nArgs)
				{
					return ANTLR3_FALSE;
				}

				return (pCurStateAttribute->args[argIdx].dataType == CDT_ID) ? ANTLR3_TRUE : ANTLR3_FALSE;
			}			
			case AC_STCONTROLLER:
			{
				if(!pCurControllerAttr)
				{
					return ANTLR3_FALSE;
				}
				if(argIdx >= (int)pCurControllerAttr->nArgs)
				{
					return ANTLR3_FALSE;
				}

				return (pCurControllerAttr->args[argIdx].dataType == CDT_ID) ? ANTLR3_TRUE : ANTLR3_FALSE;
			}
		}
		return ANTLR3_FALSE;
	}
}
