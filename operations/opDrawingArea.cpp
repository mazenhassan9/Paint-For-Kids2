#include "opDrawingArea.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"
opDrawingArea::opDrawingArea(controller* pCont):operation(pCont)
{
}

opDrawingArea::~opDrawingArea()
{
}

void opDrawingArea::Execute()
{
	Point P1;
	
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->GetPointClicked(P1.x, P1.y);
	shape* S1 = pGr->Getshape(P1.x,P1.y);
	shape* S2 = pGr->GetSelected();
	pUI->ClearStatusBar();
	if (S1)
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
	else if (S2)
	{
		S2->SetSelected(false);
		pGr->SetSelected(S2, false);
	}
	
}
