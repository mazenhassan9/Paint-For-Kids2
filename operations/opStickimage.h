#pragma once
#include "operation.h"


class opStickimage : public operation
{
public:
	opStickimage(controller* pCont);
	virtual ~opStickimage();

	
	virtual void Execute();

};