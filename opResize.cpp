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

	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Enter resize ratio: ");
	double size = stod(pUI->GetSrting());
	pUI->ClearStatusBar();

	if (sh)
	{
		sh->RESIZE(size);
	}
	else
	{
		pUI->PrintMessage("No Shape Selecteed, Please select a shape");
	}


}