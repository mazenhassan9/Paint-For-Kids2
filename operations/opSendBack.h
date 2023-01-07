#pragma once
#include "operation.h"


class opSendBack : public operation
{
public:
	opSendBack(controller* pCont);
	virtual ~opSendBack();

	
	virtual void Execute();

};
