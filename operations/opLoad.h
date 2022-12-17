#pragma once
#include "operation.h"
#include "..\Shapes\Shape.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

class opLoad : public operation
{
	ifstream File;
	string FileName;
public:
	opLoad(controller* pCont);
	virtual ~opLoad();
	virtual void Execute();

};