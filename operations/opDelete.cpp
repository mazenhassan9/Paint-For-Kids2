#include "opDelete.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"

opDelete::opDelete(controller* pCont) :operation(pCont)
{
}

opDelete::~opDelete()
{
}

void opDelete::Execute()
{
	
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	shape* S1 = pGr->GetLastSelected();
	vector<shape*> Shapes = pGr->GetSelected();
	if (S1)
	{
		
		Group* group = dynamic_cast<Group*> (S1);
		if (group)
		{
			pGr->DeleteGroup(group);
			//delete group;
		}
		
			pGr->AddDeletedShape(S1->Copy(), true);
			for (auto& itr : Shapes)
			{
				pGr->DeleteShape(itr);

			}
		
		pUI->PrintMessage("Delete Operation, All Selected shapes have been deleted");
	}
	else 
	{
		pUI->PrintMessage("Delete Operation,No Shape Selecteed, Please select a shape");
	}
	
}
