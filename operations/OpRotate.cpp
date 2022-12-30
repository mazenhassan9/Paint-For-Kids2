#include "OpRotate.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"

OpRotate::OpRotate(controller* pCont) :operation(pCont)
{
}

OpRotate::~OpRotate()
{
}

void OpRotate::Execute()
{
	
	Graph* pGr = pControl->getGraph();
	shape* sh = pGr->GetSelected();

	GUI* pUI = pControl->GetUI();
	
	if (sh)
	{
		
		//pGr->DeleteShape(sh);
		
		sh->Rotate();

		/*pGr->Addshape(sh);
		pGr->Draw(pUI);*/
		
		pUI->PrintMessage("The shape is rotated by 90 degree");

		

		
	}

	else
	{
		pUI->PrintMessage("No Shape Selecteed, Please select a shape");
	}
	

}