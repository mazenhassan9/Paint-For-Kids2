#pragma once
#include"operations/operation.h"


class opDuplicateGraph : public operation
{
public:
	opDuplicateGraph(controller* pCont);
	virtual ~opDuplicateGraph();

	virtual void Execute();

};