// Helpers.c — String and ANTLR3 helper utilities shared across the compiler.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include "Helpers.h"
#include <string.h>
#include <ctype.h>

void char_string_toUpper(char * d, char * s)
{
	unsigned int sz = strlen(s);
	unsigned int i;
	for(i = 0; i < sz; ++i)
	{
		d[i] = toupper(s[i]);
	}
}

void antlr3_string_toUpper(pANTLR3_STRING s)
{
	unsigned int sz = s->size;
	unsigned int i;
	for(i = 0; i < sz; ++i)
	{
		s->chars[i] = toupper(s->chars[i]);
	}
}

void char_string_toUpperSelf(char *s)
{
	unsigned int sz = strlen(s);
	unsigned int i;
	for(i = 0; i < sz; ++i)
	{
		s[i] = toupper(s[i]);
	}
}

