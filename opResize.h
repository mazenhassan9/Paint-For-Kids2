#pragma once
#include"operations/operation.h"


class opResize : public operation
{
public:
	opResize(controller* pCont);
	virtual ~opResize();

	//Add rectangle to the controller
	virtual void Execute();

};