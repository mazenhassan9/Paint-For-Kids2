#pragma once

#include "operation.h"

//Add Rectangle operation class
class opDelete : public operation
{
public:
	opDelete(controller* pCont);
	virtual ~opDelete();

	//Add rectangle to the controller
	virtual void Execute();

};