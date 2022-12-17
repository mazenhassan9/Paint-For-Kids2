#include "opChangeBorderColor.h"
#include"controller.h"
#include"GUI/GUI.h"
#include"Shapes/Graph.h"


opChangeBorderColor::opChangeBorderColor(controller* pCont) :operation(pCont)
{
}

opChangeBorderColor::~opChangeBorderColor()
{
}

void opChangeBorderColor::Execute()
{

	Point P1;
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	shape* bw = pGr->GetSelected();
	if (bw)
	{
		pUI->PrintMessage("pick a color from the window");


		color c = stod(pUI->GetSrting());
		c = pUI->colorpalette();
		bw->ChngDrawClr(c);

		pUI->PrintMessage("The border color of Selected shape has been changed");
	}

	else
	{
		pUI->PrintMessage("No Shape Selecteed, Please select a shape");
	}

}