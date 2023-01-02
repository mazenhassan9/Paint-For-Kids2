#pragma once
#include "operation.h"
class opPaste : public operation
{
public:
	opPaste(controller* pCont);
	virtual ~opPaste();

	virtual void Execute();

};
