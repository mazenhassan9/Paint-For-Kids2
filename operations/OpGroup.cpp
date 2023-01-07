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
	vector<shape*> shapesList= gr->GetSelected();
	
	
	if (!shapesList.empty())
	{
		Group* pGr = new Group(shapesList);
		gr->AddsGroup(pGr);
		pUI->PrintMessage("Done grouping");

	}
	else
	{
		pUI->PrintMessage("There is no group selected , Please select a group of shapes and try again");
	}
	
}