#include "OpGroup.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Group.h"
#include"..\Shapes\Graph.h"
OpGroup::OpGroup(controller* pCont) :operation(pCont)
{
}

OpGroup::~OpGroup()
{
}

void OpGroup::Execute()
{
	
	GUI* pUI = pControl->GetUI();
	Graph* gr = pControl->getGraph();
	Group* pGr = new Group(gr->GetSelected());
	gr->AddsGroup(pGr);
	pUI->PrintMessage("Done grouping");
}