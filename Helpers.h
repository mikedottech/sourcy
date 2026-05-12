// Helpers.h — String and ANTLR3 helper utilities shared across the compiler.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _HELPERS_H_
#define _HELPERS_H_

#include <antlr3.h>

void char_string_toUpper(char * d, char * s);
void antlr3_string_toUpper(pANTLR3_STRING s);
void char_string_toUpperSelf(char *s);

#endif
