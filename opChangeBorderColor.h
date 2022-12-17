#pragma once
#include "operations/operation.h"


class opChangeBorderColor : public operation
{
public:
	opChangeBorderColor(controller* pCont);
	virtual ~opChangeBorderColor();


	virtual void Execute();

};
