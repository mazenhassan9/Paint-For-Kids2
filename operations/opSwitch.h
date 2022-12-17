#pragma once
# include "operation.h"

//Switch to play mood
class opSwitch : public operation
{
public:
	opSwitch(controller* pCont);


	virtual ~opSwitch();

	//Execute Play mode toolbar
	virtual void Execute();

};
