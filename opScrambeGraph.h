#pragma once
#include"operations/operation.h"


class opScrambleGraph : public operation
{
public:
	opScrambleGraph(controller* pCont);
	virtual ~opScrambleGraph();

	virtual void Execute();

};