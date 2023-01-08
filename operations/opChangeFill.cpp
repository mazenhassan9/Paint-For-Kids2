#include "opChangeFill.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"

opChangeFill::opChangeFill(controller* pCont) :operation(pCont)

{
}

opChangeFill::~opChangeFill()
{
}

void opChangeFill::Execute()
{
	Point P1;
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	shape* S1 = pGr->GetLastSelected();
	if (S1)
	{
		pGr->AddModifiedShape(S1->Copy(), true);
		pUI->PrintMessage("pick a color from the window");
		color picked = pUI->colorpalette();
		S1->ChngFillClr(picked);
		
		
		pUI->PrintMessage("Change Single Fill color Operation, The Selected shape has been fill color changed");
	}
	else
	{
		pUI->PrintMessage("Change Single Fill color Operation, No Shape Selecteed, Please select a shape");
	}
}
