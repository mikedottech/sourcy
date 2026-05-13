// CNSSemantics.h — CNS controller, trigger and symbol-table definitions and lookups.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _CNSSEMANTICS_H_
#define _CNSSEMANTICS_H_

#include "CNSSemanticsDefinitions.h"

extern cns_SemanticTable_t cns_RSTriggerSymbolTable;
extern cns_dataTypeList_t cns_IDreturns;
extern const char* dataTypeNames[];
extern cns_dataTypeList_t cns_hitVarReturns;
extern const char * cns_hitVarIDs[];
extern cns_dataTypeList_t cns_IDreturns;
extern const char * constIDs[];
extern cns_dataTypeList_t cns_stageVarReturns;

extern cns_ControllerSignature_t cns_ControllerSymbolTable[];
extern cns_ControllerSyntax_t cns_CommonControllerAttrs;
extern cns_ControllerSignature_t cns_stateDefSignature;

int lookupConstStringTable(const char **table, const char *what);
bool lookupTriggerSignature(const char * tName, cns_TriggerSignature_t * &ts);
bool cns_lookupControllerSignature(const char * cName, cns_ControllerSignature_t * &cs);
cns_Datatype_t cns_getTriggerReturnType(const char* tName);
const char* cns_getDataTypeName(cns_Datatype_t t);
bool cns_triggerExists(const char * tName);
bool cns_lookupControllerCommonAttrs(char * lhs, cns_ControllerAttribute_t *& attr);

#endif
