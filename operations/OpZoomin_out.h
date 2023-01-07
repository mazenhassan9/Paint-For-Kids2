#pragma once

#include"operations/operation.h"

//Switch to play mood
class OpZoomin_out : public operation
{
public:
	OpZoomin_out(controller* pCont);


	virtual ~OpZoomin_out();

	//Execute Play mode toolbar
	virtual void Execute();

};