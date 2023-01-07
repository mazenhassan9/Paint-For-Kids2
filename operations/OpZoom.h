#pragma once
#include "operation.h"



class OpZoom : public operation
{
public:
	OpZoom(controller* pCont);
	virtual ~OpZoom();

	//Add circle to the controller
	virtual void Execute();

};

