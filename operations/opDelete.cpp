#include "opDelete.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"

opDelete::opDelete(controller* pCont) :operation(pCont)
{
}

opDelete::~opDelete()
{
}

void opDelete::Execute()
{
	
	Point P1;
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	shape* S1 = pGr->GetLastSelected();
	if (S1)
	{
		pGr->DeleteShape(S1);
		pUI->PrintMessage("Delete Operation, The Selected shape has been deleted");
	}
	else 
	{
		pUI->PrintMessage("Delete Operation,No Shape Selecteed, Please select a shape");
	}
	
}
