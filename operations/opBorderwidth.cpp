#include "opBorderwidth.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"


opBorderwidth::opBorderwidth(controller* pCont):operation(pCont)
{
}

opBorderwidth::~opBorderwidth()
{
}

void opBorderwidth::Execute()
{

	Point P1;
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	shape* bw = pGr->GetLastSelected();
	if (bw)
	{
		pGr->AddModifiedShape(bw->Copy(), true);
		pUI->PrintMessage("pick a Border width");
		double h = stod(pUI->GetSrting());
		bw->setBorderwidth(h);

		pUI->PrintMessage("Change Single border width Operation, The Selected shape has been border width changed");}

	else
	{
	pUI->PrintMessage("Change Single border width Operation, No Shape Selecteed, Please select a shape");
	}
	
}
