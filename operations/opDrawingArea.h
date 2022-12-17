#pragma once

#include "operation.h"

//Add Rectangle operation class
class opDrawingArea : public operation
{
public:
	opDrawingArea(controller* pCont);
	virtual ~opDrawingArea();

	//Add rectangle to the controller
	virtual void Execute();

};