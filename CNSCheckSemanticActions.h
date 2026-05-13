// CNSCheckSemanticActions.h — Semantic-action callbacks invoked by the cnscheck tree parser.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include <antlr3.h>
#include "CNSDataType.h"

void lgNameState();
void lgNameStateDef(pANTLR3_STRING id);

cns_Datatype_t cnsVal_checkRegularTrigger(pANTLR3_STRING name, unsigned int nArgs, cns_Datatype_t types[]);
cns_Datatype_t cnsVal_checkOldStyleWithIDTrigger(pANTLR3_STRING name, pANTLR3_STRING string);
cns_Datatype_t cns_getTriggerReturnTypeSelID(char * tName, char * selID);

ANTLR3_BOOLEAN cns_beginStateController(void * controllerUsage);
ANTLR3_BOOLEAN cns_beginControllerAttribute(char *lhs);
ANTLR3_BOOLEAN cns_checkControllerAttribute(int nArgument, cns_Datatype_t dataType, char * id);
ANTLR3_BOOLEAN cns_finishControllerAttribute();
ANTLR3_BOOLEAN cns_finishStateController();
ANTLR3_BOOLEAN checkVarSubscript(cns_Datatype_t t, cns_VarType_t v);
ANTLR3_BOOLEAN cns_beginStateDecl();
ANTLR3_BOOLEAN cns_finishStateDecl();
ANTLR3_BOOLEAN cns_beginStateAttribute(char *lhs);
ANTLR3_BOOLEAN cns_checkStateAttribute(int nArgument, cns_Datatype_t dataType, char * id);
ANTLR3_BOOLEAN cns_beginTriggerCall(char *tName);
ANTLR3_BOOLEAN cns_checkTriggerArgument(int argNo, cns_Datatype_t dt, char *id);
cns_Datatype_t cns_finishTriggerCall();

void cns_reorderControllerElements(pANTLR3_BASE_TREE t);
