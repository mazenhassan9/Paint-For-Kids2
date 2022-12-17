#pragma once
#include "operation.h"


class opBorderwidth : public operation
{
public:
	opBorderwidth(controller* pCont);
	virtual ~opBorderwidth();

	
	virtual void Execute();

};