#pragma once

#include "operation.h"


class opGeneralfillcolor : public operation
{
public:
	opGeneralfillcolor(controller* pCont);
	virtual ~opGeneralfillcolor();
	

	
	virtual void Execute();

};
