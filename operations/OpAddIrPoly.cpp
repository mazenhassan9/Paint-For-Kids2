#include "OpAddIrPoly.h"
#include "..\Shapes\Polygon.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include <vector>
opAddIrPoly::opAddIrPoly(controller* pCont) :operation(pCont)
{
	
}

opAddIrPoly::~opAddIrPoly()
{
}

void opAddIrPoly::Execute()
{
	int side1,n;
	Point P1;
	vector <Point> Points;
	// Get a Pointer to the Input / Output Interfaces


	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New IR-Regular Polygon: Enter the number of sides");
	//Read 1st corner and store in point P1
	n = stod(pUI->GetSrting());
	while (n < 3)
	{
		pUI->ClearStatusBar();
		pUI->PrintMessage("New IR-Regular Polygon: Wrong number of sides, Sides must be larger than 3");
		n = stod(pUI->GetSrting());

	}

	for (int i = 0; i < n; i++)
	{
		pUI->ClearStatusBar();
		pUI->PrintMessage("New IR-Regular Polygon: Click at the " + to_string(i+1)+ " Point");
		pUI->GetPointClicked(P1.x, P1.y);
		Points.push_back(P1);
	}
	

	
	pUI->ClearStatusBar();
	
	
	//Preapre all rectangle parameters
	GfxInfo PolyGfxInfo;

	//get drawing, filling colors and pen width from the interface
	PolyGfxInfo.DrawClr = pUI->getCrntDrawColor();
	PolyGfxInfo.FillClr = pUI->getCrntFillColor();
	PolyGfxInfo.BorderWdth = pUI->getBorderwidth();


	PolyGfxInfo.isFilled = pUI->getdefaultfilled();	//default is not filled
	PolyGfxInfo.isSelected = false;	//defualt is not selected


	//Create a rectangle with the above parameters
	polygon* Poly = new polygon(Points,n ,PolyGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

		//Add the rectangle to the list of shapes
	pGr->Addshape(Poly);
	
}
