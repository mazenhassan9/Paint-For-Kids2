#include"opDublicateGraph.h"
//#include"Shapes/Shape.h"
#include"Shapes/Graph.h"
#include"GUI/GUI.h"
#include"controller.h"


opDuplicateGraph::opDuplicateGraph(controller* pCont) :operation(pCont) {

}

opDuplicateGraph::~opDuplicateGraph() {}

void opDuplicateGraph::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
    pGr->DuplicateGraph();
}