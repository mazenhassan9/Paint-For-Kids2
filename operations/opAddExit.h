#pragma once

#include "operation.h"


class opAddExit : public operation
{
public:
	opAddExit(controller* pCont);
	virtual ~opAddExit();

	
	virtual void Execute();

};