#include "opHideGraph.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"

opHideGraph::opHideGraph(controller* pCont) :operation(pCont)
{
}

opHideGraph::~opHideGraph()
{
}

void opHideGraph::Execute() 
{

	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	vector<shape*> Shapes = pGr->getlistofshspes();
	pGr->HideAll(true);


}
