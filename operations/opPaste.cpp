#include "opPaste.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"
opPaste::opPaste(controller* pCont) :operation(pCont)
{
}

opPaste::~opPaste()
{
}

void opPaste::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	shape* S1= pGr->getcopied();
	Point P1;

	pUI->PrintMessage("Paste operation : Click a point ");
	pUI->GetPointClicked(P1.x , P1.y);
	shape* S2 = S1->Copy();
	S2->Move(P1.x, P1.y);
	pGr->Addshape(S2);

	

}
