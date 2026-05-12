// PreEval.h — Pre-evaluated expression values, used for compile-time constant folding.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _PREEVAL_H_
#define _PREEVAL_H_

#include "CNSDataType.h"
#include "CNSGrammarInclude.h"

// Structure for expression pre-evaluation for optimizing code
typedef struct
{
	cns_Datatype_t valType;
	union
	{
		int intVal;
		float floatVal;
	} data;
	bool isConstant;
	
} preeval_t;

typedef enum
{
	OP_UNDEFINED,
	OP_INT_INT,
	OP_FLOAT_INT,
	OP_INT_FLOAT,
	OP_FLOAT_FLOAT
} preeval_op_type_t;

#endif
