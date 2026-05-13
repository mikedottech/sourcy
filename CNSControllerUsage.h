// CNSControllerUsage.h — Tracks how a controller is used: signature plus the syntax form invoked.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _CNSCONTROLLERUSAGE_H_
#define _CNSCONTROLLERUSAGE_H_
#include "CNSSemanticsDefinitions.h"

typedef struct
{
	int							usedSyntax;		// Syntax used in the controller
	cns_ControllerSignature_t * pSignature;		// Signature of the controller
} cnsControllerUsage_t;

#endif
