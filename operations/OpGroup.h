#pragma once
#include "operation.h"

class OpGroup : public operation
{
public:
	OpGroup(controller* pCont);
	virtual ~OpGroup();

	virtual void Execute();

};
