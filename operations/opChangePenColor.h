#pragma once

#include "operation.h"


class opChangePenColor : public operation
{
public:
	opChangePenColor(controller* pCont);
	virtual ~opChangePenColor();
	virtual void Execute();

};
