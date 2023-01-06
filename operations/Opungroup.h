#pragma once
#include "operation.h"

class Opungroup : public operation
{
public:
	Opungroup(controller* pCont);
	virtual ~Opungroup();

	virtual void Execute();

};