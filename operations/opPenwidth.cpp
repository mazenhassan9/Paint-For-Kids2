#include "opPenwidth.h"
#include "..\Shapes\Shape.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opPenwidth::opPenwidth(controller* pCont):operation(pCont)
{
}

opPenwidth::~opPenwidth()
{
}

void opPenwidth::Execute()
{
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("enter the new pen width");
	
	double pw =stod( pUI->GetSrting());
	pUI->setPenwidth(pw);
	
}
