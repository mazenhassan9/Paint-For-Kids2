#pragma once
#include"paste.h"
class Paste : public operation
{
public:
	Paste(controller* pCont);
	virtual ~Paste();

	virtual void Execute();

};