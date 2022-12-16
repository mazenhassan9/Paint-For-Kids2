#pragma once

#include "operation.h"

//Add Rectangle operation class
class opChangeFill : public operation
{
public:
	opChangeFill(controller* pCont);
	virtual ~opChangeFill();

	//Add rectangle to the controller
	virtual void Execute();

};