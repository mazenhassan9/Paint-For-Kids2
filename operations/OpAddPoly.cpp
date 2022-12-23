#include "OpAddPoly.h"
#include "..\Shapes\Polygon.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include <math.h>
#include <vector>
opAddPoly::opAddPoly(controller* pCont) :operation(pCont)
{
	
}

opAddPoly::~opAddPoly()
{
}

void opAddPoly::Execute()
{
	const double PI = 3.1416;
	int n , sideL;
	double angle1;
	Point P1;
	int x_C,y_C;
	vector <Point> Points;

	// Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Regular Polygon: Enter the number of sides");
	n = stod(pUI->GetSrting());
	while (n < 3)
	{
		pUI->ClearStatusBar();
		pUI->PrintMessage("New Regular Polygon: Wrong number of sides, Sides must be larger than 3");
		n = stod(pUI->GetSrting());

	}
	pUI->ClearStatusBar();
	pUI->PrintMessage("New Regular Polygon: Enter the Length of sides");
	sideL = stod(pUI->GetSrting());

	sideL = sideL * 10; //resizing to be seen.
	pUI->ClearStatusBar();
	pUI->PrintMessage("New Regular Polygon: Enter the Center of Polgon");
	pUI->GetPointClicked(x_C, y_C);

	for (int i = 0; i < n; i++)
	{
		P1.x = x_C + (sideL * cos(2 * PI * i / n));
		P1.y = y_C + (sideL * sin(2 * PI * i / n));
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
