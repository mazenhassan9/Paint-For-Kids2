#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"

#include"opCopy.h"

opCopy::opCopy(controller* pCont) :operation(pCont)
{
}

opCopy::~opCopy()
{
}
void opCopy::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	shape* S1 = pGr->GetLastSelected();
	
	if (S1 )
	{
		shape* S2 = S1->Copy();
		pGr->setcopied(S2);
		
		pUI->PrintMessage("Copy Operation, The Selected shape has been copied");
		

	}
	else
		pUI->PrintMessage("No Shape Selecteed, Please select a shape");

}