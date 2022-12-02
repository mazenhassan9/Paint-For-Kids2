#pragma once

#include "operation.h"

//Add Square operation class
class opGeneralfillcolor : public operation
{
public:
	opGeneralfillcolor(controller* pCont);
	virtual ~opGeneralfillcolor();
	

	//Add Square to the controller
	virtual void Execute();

};
