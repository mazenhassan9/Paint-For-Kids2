#include "opAddExit.h"
#include"opSave.h"


#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddExit::opAddExit(controller* pCont) :operation(pCont)
{}
opAddExit::~opAddExit()
{}

//Execute the operation
void opAddExit::Execute()
{

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("If you want to Exit with saving pick 'y' for yes otherwise pick 'n' for no");
	string user = pUI->GetSrting();

	if (user == "y")
	{
		operation* exitsave = new opSave(pControl);
		exitsave->Execute();
	}
}