#pragma once

#include "operation.h"


class OpRotate : public operation
{
public:
	OpRotate(controller* pCont);
	virtual ~OpRotate();

	//Add rectangle to the controller
	virtual void Execute();

};