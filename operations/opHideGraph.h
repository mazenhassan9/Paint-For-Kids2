#pragma once
#include "operation.h"

//Add Cicle operation class
class opHideGraph : public operation
{
public:
	opHideGraph(controller* pCont);
	virtual ~opHideGraph();

	//Add circle to the controller
	virtual void Execute();

};
