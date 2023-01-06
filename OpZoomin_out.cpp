#include"operations/OpZoomin_out.h"
#include "Shapes/Shape.h"

#include "controller.h"

#include "GUI\GUI.h"

OpZoomin_out::OpZoomin_out(controller* pCont) :operation(pCont)
{
}

OpZoomin_out::~OpZoomin_out()
{
}

void OpZoomin_out::Execute()
{
	
	window* pWind = nullptr;
	Point P1, P2;
	char key;
	Graph* pGr = pControl->getGraph();
	/*shape* sh = pGr->GetLastSelected();*/

	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("Press 'I' for zoming in and 'O' for zoming out ");
	string user = pUI->GetSrting();
	pWind->WaitKeyPress(key);
		
	if (key == 'O')
	{

		pUI->GetLastKey(key); pUI->PrintMessage("Click the area you want to zoom in it  ");
		pUI->GetLastClick(P1.x, P1.y);
		pUI->PrintMessage("Enter the zoom ratio ");
		float user = stod(pUI->GetSrting());
		P1.x *= user;
		P1.y *= user;
	}
	if (key == 'I')
	{

		pUI->GetLastKey(key); pUI->PrintMessage("Click the area you want to zoom in it  ");
		pUI->GetLastClick(P1.x, P1.y);
		pUI->PrintMessage("Enter the zoom out ratio ");
		float user = stod(pUI->GetSrting());
		P1.x *= user;
		P1.y *= user;
	}

	
	
}