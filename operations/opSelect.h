#pragma once
#pragma once

#include "operation.h"

//Add Rectangle operation class
class opSelect : public operation
{
public:
	opSelect(controller* pCont);
	virtual ~opSelect();

	//Add rectangle to the controller
	virtual void Execute();

};