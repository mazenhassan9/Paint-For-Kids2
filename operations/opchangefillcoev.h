#pragma once
#include "operation.h"


class opChangefillcoev : public operation
{
public:
	opChangefillcoev(controller* pCont);
	virtual ~opChangefillcoev();
	virtual void Execute();

};
