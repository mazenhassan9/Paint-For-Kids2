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
		if (S1->IsSticked())
		{
			S1->SetSticked(false);
		}
		else {
			S1->SetSticked(true);
		}
		

		pUI->PrintMessage("Stick image to the selected shape");


	}
	else
		pUI->PrintMessage("No Shape Selected, Please select a shape");

}
