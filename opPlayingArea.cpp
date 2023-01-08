#include"GUI/GUI.h"
#include"opPlayingArea.h"
#include"controller.h"
#include"Shapes/Graph.h"

opPlayingArea::opPlayingArea(controller* pCont) :operation(pCont)
{
}

opPlayingArea::~opPlayingArea()
{
}

void opPlayingArea::Execute()
{
	Point P1;
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();

	shape* S2 = pGr->GetLastSelected();
	if (S2)
	{
		S2->SetSelected(false);
		pGr->SetSelected(S2, false);
	}

	int x, y;
	pUI->GetPointClicked(x, y);
	pUI->ClearStatusBar();
	bool s = pGr->UnHideone(x, y, pUI);
	if (s)
	{
		pUI->PrintMessage("Unhiden is done");

	}
	else
	{
		pUI->PrintMessage("select again");
		
	}

	pUI->ClearStatusBar();
	int match = pGr->matchshapes();
	if (match == 1)
	{
		pUI->PrintMessage("Matching is done");

	}
	else if(match == 0)
	{
		pUI->PrintMessage("There is no matching happened ");
	}
}