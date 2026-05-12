// CNSCodeBlockType.h — Enumeration of CNS code-block kinds (state, info, command, buttons remap).
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _CNSCODEBLOCKTYPE_H_
#define _CNSCODEBLOCKTYPE_H_

typedef enum
{
	CBT_NONE,
	CBT_STATE,
	CBT_INFO,
	CBT_COMMAND,
	CBT_BUTTONSREMAP
} CNSCodeBlockType;

#endif
