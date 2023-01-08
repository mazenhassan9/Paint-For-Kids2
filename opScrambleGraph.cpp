#include "opScrambeGraph.h"
#include"Shapes/Graph.h"
#include"GUI/GUI.h"
#include"controller.h"

opScrambleGraph::opScrambleGraph(controller* pCont) :operation(pCont) {

}

opScrambleGraph::~opScrambleGraph() {}

void opScrambleGraph::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pGr->ScrambleGraph();
}