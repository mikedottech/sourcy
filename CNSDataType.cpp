// CNSDataType.cpp — CNS data-type enumeration and stringification helpers.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

extern "C"
{
#	include "CNSDataType.h"
char * cns_VarTypeNames_t[] =
	{
		"VAR",
		"FVAR",
		"SYSVAR",
		"SYSFVAR"
	};


	char * cns_getDataTypeString(cns_VarType_t v)
	{	
		return cns_VarTypeNames_t[(int)v];
	}
}
