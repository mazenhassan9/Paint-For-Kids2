#pragma once
#include "operation.h"
class opCut : public operation
{
public:
	opCut(controller* pCont);
	virtual ~opCut();

	virtual void Execute();

}; 
