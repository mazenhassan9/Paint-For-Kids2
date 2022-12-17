#pragma once
# include "operation.h"


class opPenwidth : public operation
{
public:
	opPenwidth(controller* pCont);


	virtual ~opPenwidth();

	
	virtual void Execute();

};
