#include "opSendBack.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"

opSendBack::opSendBack(controller* pCont):operation (pCont)
{
}

opSendBack::~opSendBack()
{
}

void opSendBack::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	shape* S1 = pGr->GetLastSelected();
	if (S1)
	{
		pGr->SendBack(S1);
		pUI->PrintMessage("the selected shape send to back succesfullu");
	}

	else
		pUI->PrintMessage("No Shape Selecteed, Please select a shap");
	}
