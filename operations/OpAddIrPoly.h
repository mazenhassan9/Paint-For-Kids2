#pragma once

#include "operation.h"

//Add Rectangle operation class
class opAddIrPoly : public operation
{
public:
	opAddIrPoly(controller* pCont);
	virtual ~opAddIrPoly();

	//Add rectangle to the controller
	virtual void Execute();

};