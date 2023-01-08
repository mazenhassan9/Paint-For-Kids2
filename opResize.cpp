#include "opResize.h"
#include"GUI/GUI.h"
#include"Shapes/Shape.h"
#include"controller.h"


opResize::opResize(controller* pCont) :operation(pCont)
{
}

opResize::~opResize()
{
}

void opResize::Execute()
{

	Graph* pGr = pControl->getGraph();
	shape* sh = pGr->GetLastSelected();
	double size;
	GUI* pUI = pControl->GetUI();

	pUI->ClearStatusBar();

	if (sh)
	{
		pGr->AddModifiedShape(sh->Copy(), true);
		pUI->PrintMessage("Enter resize ratio: ");
		size = stod(pUI->GetSrting());
		while (size <= 0)
		{
			pUI->PrintMessage("Error Resize Ratio!, Please Enter resize ratio > 0: ");
		}
		sh->RESIZE(size);
	}
	else
	{
		pUI->PrintMessage("No Shape Selecteed, Please select a shape");
	}


}