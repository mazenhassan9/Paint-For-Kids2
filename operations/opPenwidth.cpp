#include "opPenwidth.h"
#include "..\Shapes\Shape.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opPenwidth::opPenwidth(controller* pCont) :operation(pCont)
{}
opPenwidth::~opPenwidth()
{}

//Execute the operation
void opPenwidth::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Do you want the pen width or not? yes: 0 || no: 1");
	string usss = pUI->GetSrting();
	if (usss == "1")
	{
		return; 
	}
	else
	{
		pUI->PrintMessage("Enter new pen width");
		double n = stod(pUI->GetSrting());
		pUI->setpenwidth(n);
	}
	

}

