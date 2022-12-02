#include "opAddExit.h"
//#include "..\shapes\Exit.h"

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
	pUI->PrintMessage("If you want to Exit pick 'y' for yes and 'n' for no");
	string user = pUI->GetSrting();

	//loop over the list to see unsaved objects//


}