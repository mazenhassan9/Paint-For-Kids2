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
	pUI->ClearStatusBar();
	if (S2)
	{
		S2->SetSelected(false);
		pGr->SetSelected(S2, false);
	}
}