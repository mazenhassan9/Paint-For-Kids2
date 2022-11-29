#pragma once

#include "operation.h"

//Add Cicle operation class
class opAddCircle : public operation
{
public:
	opAddCircle(controller* pCont);
	virtual ~opAddCircle();

	//Add circle to the controller
	virtual void Execute();

};
