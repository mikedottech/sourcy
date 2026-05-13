// CNSDataType.h — CNS data-type enumeration and stringification helpers.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _CNSDATATYPE_H_
#define _CNSDATATYPE_H_

typedef enum
{
	CDT_ERROR = 0,
	CDT_INT,
	CDT_FLOAT,
	CDT_NUMBER,
	CDT_ID,
	CDT_SAME,
	CDT_STRING
} cns_Datatype_t;

typedef enum
{
	VT_VAR = 0,
	VT_FVAR,
	VT_SYSVAR,
	VT_SYSFVAR
} cns_VarType_t;

extern char * cns_VarTypeNames_t[];
char * cns_getDataTypeString(cns_VarType_t v);

#endif
