#include "OpZoom.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Group.h"
#include"..\Shapes\Graph.h"
OpZoom::OpZoom(controller* pCont) :operation(pCont)
{
}

OpZoom::~OpZoom()
{
}

void OpZoom::Execute()
{

	Graph* grp = pControl->getGraph();
	Point p1, p2;
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Choose: 1 for zooming in , 2 for zooming out, 3 for default");
	int ssh = stod(pUI->GetSrting());
	 if(ssh==1){
	pUI->PrintMessage("Click on the first point");
	pUI->GetPointClicked(p1.x, p1.y);
	pUI->PrintMessage("Click on the second point");
	pUI->GetPointClicked(p2.x, p2.y);
	pUI->set0(p1);
	pUI->set1(p2);
	pUI->ClearStatusBar();
	grp->mapshapes(pUI);
	}
	if (ssh==2)
	{
		

		pUI->PrintMessage("Enter the zooming factor");
		double ss = stod(pUI->GetSrting());
		pUI->ClearStatusBar();
		double x_factor = (pUI->getoriginalx1() - pUI->getoriginalx0()) / 2 * ss;
		double y_factor = (pUI->getoriginaly1() - pUI->getoriginaly0()) / 2 * ss;
		Point p1 = { pUI->getoriginalx0() - x_factor,pUI->getoriginaly0() - y_factor }, p2 = { pUI->getoriginalx1() + x_factor ,pUI->getoriginaly1() + y_factor };
		pUI->set0(p1);
		pUI->set1(p2);
		grp->mapshapes(pUI);
	}
	if (ssh == 3)
	{
		/*pUI->PrintMessage("Enter the zooming factor");*/
		
		pUI->ClearStatusBar();
		Point p1 = { pUI->getoriginalx0(),pUI->getoriginaly0() }, p2 = { pUI->getoriginalx1() ,pUI->getoriginaly1() };
		pUI->set0(p1);
		pUI->set1(p2);
		grp->mapshapes(pUI);
	}

}
	
