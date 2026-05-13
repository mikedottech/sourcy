// CNSControllerElement.cpp — Wrapper around an AST subtree that represents a single CNS controller.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#include "CNSControllerElement.h"

extern "C"
{
#	include "Helpers.h"
}

CNSControllerElement::CNSControllerElement(pANTLR3_BASE_TREE grammarTree) : m_subTree(grammarTree), m_rank(0)
{
	classify();
}


void CNSControllerElement::classify()
{
	char * tmp = reinterpret_cast<char*> (m_subTree->getText(m_subTree)->chars);
	char * nodeName = strdup(tmp);
		
	char_string_toUpperSelf(nodeName);

	// Give this a rank depending on what the subtree contains
	/*
	- Sort statecnt sons:
		- cntname					-1		// ^(STATECNTID ...)
		- type						0		// ^(TYPE ...)
		- state common attrs		100		// ^(ASSIGNSTMT lhs rhs)
		- triggerall				200		// ^(TRIGGERSTMT ALL ...)
		- triggerX (sorted by X)	200 + X // ^(TRIGGERSTMT num ....)
		- controller args			1000	// ^(ASSIGNSTMT lhs rhs)
		- otherwise					10000	// ?
	*/

	if(!strcmp(nodeName, "STATECNTID"))
	{
		m_rank = -1;
	} else if(!strcmp(nodeName, "TYPE"))
	{
		m_rank = 0;
	} else if(!strcmp(nodeName, "TRIGGERSTMT"))
	{
		pANTLR3_BASE_TREE indexChild	= reinterpret_cast<pANTLR3_BASE_TREE> (m_subTree->getChild(m_subTree, 0));
		pANTLR3_STRING indexStr			= indexChild->getText(indexChild);

		m_rank = 200;
		if(strcmp(reinterpret_cast<char*>(indexStr->chars), "ALL")) // not all
		{
			m_rank += indexStr->toInt32(indexStr);
		}
	} else if(!strcmp(nodeName, "ASSIGNSTMT"))
	{
		pANTLR3_BASE_TREE lhsChild		= reinterpret_cast<pANTLR3_BASE_TREE> (m_subTree->getChild(m_subTree, 0));
		pANTLR3_STRING lhsStr			= lhsChild->getText(lhsChild);
		char * lhsCStr					= reinterpret_cast<char*>(lhsStr->chars);

		// Disambiguate between state common attrs or controller args

		cns_ControllerAttribute_t *cSig;

		if(cns_lookupControllerCommonAttrs(lhsCStr, cSig)) // Common attrs
		{
			//m_rank = 100;
			m_rank = 900;
		} else {
			m_rank = 1000;
		}
	} else {
		m_rank = 65535;
	}

	delete[] nodeName;
	//printf("My name is %s and my rank is %d\n", nodeName, m_rank);
}

bool CNSControllerElement::operator<(const CNSControllerElement& x) const
{
	return (m_rank < x.m_rank);
}

bool CNSControllerElement::operator==(const CNSControllerElement& x)
{
	return (m_rank == x.m_rank);
}

bool CNSControllerElement::operator()(const CNSControllerElement& x, const CNSControllerElement& y) const
{
	return (m_rank == x.m_rank);
}
