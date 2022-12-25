#pragma once
#include"operations/operation.h"


class StartGame : public operation
{
public:
	StartGame(controller* pCont);
	virtual ~StartGame();

	virtual void Execute();

};