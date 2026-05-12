// CNSSemanticActions.h — Semantic-action callbacks invoked by the cns parser.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include <antlr3.h>
#include "CNSDataType.h"
#include "CNSControllerUsage.h"

ANTLR3_BOOLEAN cnsActions_triggerExist(const char * tName);
ANTLR3_BOOLEAN cnsActions_getControllerSignature(const char * tName, cnsControllerUsage_t * cu);
void cnsActions_setController();
void cnsActions_setState();
ANTLR3_BOOLEAN cnsActions_setLHS(char * lhs);
ANTLR3_BOOLEAN cnsActions_disambiguateTriggerID(int argIdx);
