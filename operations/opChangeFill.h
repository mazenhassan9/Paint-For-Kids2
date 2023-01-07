#pragma once

#include "operation.h"


class opChangeFill : public operation
{
public:
	opChangeFill(controller* pCont);
	virtual ~opChangeFill();

	
	virtual void Execute();

};