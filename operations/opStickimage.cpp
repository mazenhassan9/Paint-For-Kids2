#include "opStickimage.h"
#include "..\Shapes\Polygon.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"

opStickimage::opStickimage(controller* pCont) :operation(pCont)
{
}

opStickimage::~opStickimage()
{
}

void opStickimage::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	shape* S1 = pGr->GetLastSelected();

	if (S1)
	{
		 S1->stick(pUI);
		

		pUI->PrintMessage("stick image to the selected shape");


	}
	else
		pUI->PrintMessage("No Shape Selecteed, Please select a shape");

}
