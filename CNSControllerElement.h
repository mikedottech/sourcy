// CNSControllerElement.h — Wrapper around an AST subtree that represents a single CNS controller.
//
// Part of Sourcy — CNS -> Lua compiler for MUGEN-style characters.
// Licensed under the MIT License. See LICENSE in the project root.
//
// Author: Miguel Angel Exposito Sanchez (radexx), 2012.

#ifndef _CNSCONTROLLERELEMENT_H_
#define _CNSCONTROLLERELEMENT_H_

#include <antlr3.h>
#include <assert.h>
#include "CNSSemantics.h"

class CNSControllerElement
{
private:
	pANTLR3_BASE_TREE	m_subTree;
	int					m_rank;

public:
	CNSControllerElement(pANTLR3_BASE_TREE grammarTree);
	virtual ~CNSControllerElement() = default;
	void classify();

	bool operator<(const CNSControllerElement& x) const;
	bool operator==(const CNSControllerElement& x);
	bool operator()(const CNSControllerElement& x, const CNSControllerElement& y) const;
	pANTLR3_BASE_TREE getSubTree() const { return m_subTree; }
};

#endif
