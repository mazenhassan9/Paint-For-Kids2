#pragma once
# include "operation.h"

//Switch to play mood
class oPUndo : public operation
{
public:
	oPUndo(controller* pCont);


	virtual ~oPUndo();

	//Execute Play mode toolbar
	virtual void Execute();

};