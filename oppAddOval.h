#pragma once
#include "operations/operation.h"

//Add Oval operation class
class opAddOval : public operation
{
public:
	opAddOval(controller* pCont);
	virtual ~opAddOval();

	//Add Oval to the controller
	virtual void Execute();

};

