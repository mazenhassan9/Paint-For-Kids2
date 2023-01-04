#include "OpCut.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"
opCut::opCut(controller* pCont):operation(pCont)
{
}

opCut::~opCut()
{
}

void opCut::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	shape* S1 = pGr->GetLastSelected();

	if (S1)
	{
		shape* S2 = S1->Copy();
		pGr->setcopied(S2);
		pGr->DeleteShape(S1);

		pUI->PrintMessage("Cut Operation, The Selected shape has been Cut");


	}
	else
		pUI->PrintMessage("No Shape Selected, Please select a shape");
}
