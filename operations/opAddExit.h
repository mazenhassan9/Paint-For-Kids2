#pragma once

#include "operation.h"
#include"opSave.h"


class opAddExit : public operation
{
public:
	opAddExit(controller* pCont);
	virtual ~opAddExit();
	
	
	virtual void Execute();

};