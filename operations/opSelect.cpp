#include "opSelect.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"

opSelect::opSelect(controller* pCont):operation(pCont)
{
}

opSelect::~opSelect()
{
}

void opSelect::Execute()
{
	Point P1;
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	
	pUI->PrintMessage("Select Operation, Please select a shape");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);
	shape* S1 = pGr->Getshape(P1.x, P1.y);
	if (S1 != nullptr)
	{
		if (S1->IsSelected())
		{
			S1->SetSelected(false);
			pGr->SetSelected(S1, false);
		}
		else
		{
			S1->SetSelected(true);
			pUI->PrintMessage(S1->Getinfo());
			pGr->SetSelected(S1, true);
		}
	}
	else
	{
		pUI->PrintMessage("Select Operation, No Shape Selected");
	}
	

	

}
