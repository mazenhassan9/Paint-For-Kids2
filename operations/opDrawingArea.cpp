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
	
	shape* S2 = pGr->GetSelected();
	if (S2)
	{
		S2->SetSelected(false);
		pGr->SetSelected(S2, false);
	}
	
}
