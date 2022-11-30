#pragma once

#include "operation.h"

//Add Cicle operation class
class opAddExit : public operation
{
public:
	opAddExit(controller* pCont);
	virtual ~opAddExit();

	//Add circle to the controller
	virtual void Execute();

};