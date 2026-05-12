// CNSSemanticsDefinitions.h — Type definitions backing the CNS semantic tables (controllers, triggers).
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _CNSSEMANTICSDEFINITIONS_H_
#define _CNSSEMANTICSDEFINITIONS_H_

#include "CNSDataType.h"
#include <antlr3.h>

typedef struct
{
	cns_Datatype_t dataType;
	const char **allowedIDs;
	bool optional;
} cns_Argument_t;

typedef struct
{
	const char		*UCName;		// Must be hashed
	const char		*properName;
	unsigned int	nArgs;
	cns_Argument_t	arguments[11];
	cns_Datatype_t	returnType;
} cns_TriggerSignature_t;

typedef struct
{
	const char		*UCName;		// Must be hashed
	const char		*properName;
	unsigned int	nArgs;
	cns_Argument_t	args[11];
	bool			optional;
} cns_ControllerAttribute_t;


typedef struct
{
	unsigned int	nAttrs;
	cns_ControllerAttribute_t attrs[90];	
} cns_ControllerSyntax_t;

typedef struct
{
	const char		*UCName;		// Must be hashed
	const char		*properName;
	unsigned int	nSyntaxes;
	cns_ControllerSyntax_t syntaxes[6];	
} cns_ControllerSignature_t;


typedef cns_TriggerSignature_t cns_SemanticTable_t[];
typedef cns_Datatype_t cns_dataTypeList_t[];

#endif
