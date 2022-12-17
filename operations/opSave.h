#pragma once

#include "operation.h"
#include<iostream>
#include<fstream>
//Add Rectangle operation class
class opSave : public operation
{
	ofstream file;
public:
	opSave(controller* pCont);
	virtual ~opSave();

	//Add rectangle to the controller
	virtual void Execute();

};