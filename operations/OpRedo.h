#pragma once
# include "operation.h"

class OpRedo : public operation
{
public:
	OpRedo(controller* pCont);


	virtual ~OpRedo();

	//Execute Play mode toolbar
	virtual void Execute();

};