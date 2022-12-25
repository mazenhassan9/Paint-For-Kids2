#pragma once

#include"operations/operation.h"


class opPlayingArea : public operation
{
public:
	opPlayingArea(controller* pCont);
	virtual ~opPlayingArea();

	virtual void Execute();

};
