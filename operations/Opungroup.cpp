#include "Opungroup.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Group.h"
#include"..\Shapes\Graph.h"
Opungroup::Opungroup(controller* pCont) :operation(pCont)
{
}

Opungroup::~Opungroup()
{
}

void Opungroup::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* gr = pControl->getGraph();
	Group* pGr = dynamic_cast<Group*> (gr->GetLastSelected());
	if (pGr)
	{

		pGr->ungroup();
		gr->DeleteGroup(pGr);
		delete pGr;
		pUI->PrintMessage("Done ungrouping");

	}
	else
	{
		pUI->PrintMessage("There is not a group selected");
	}

}