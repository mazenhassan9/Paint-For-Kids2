#include "OpAddPoly.h"
#include "..\Shapes\Polygon.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include <vector>
opAddPoly::opAddPoly(controller* pCont) :operation(pCont)
{
	
}

opAddPoly::~opAddPoly()
{
}

void opAddPoly::Execute()
{
	int n = 3;
	int side1, side2;
	double angle1, angle2;
	Point P1, P2, P3;
	int x_be, y_be;
	vector <Point> Points;
	// Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Polygon: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->GetPointClicked(P2.x, P2.y);

	side1 = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));

	pUI->ClearStatusBar();
	msg += "\nSecond corner is at (" + to_string(P2.x) + ", " + to_string(P2.y) + " )";
	msg += " ... Click at Third corner";
	pUI->PrintMessage(msg);
	//Read 3rd corner and store in point P2
	pUI->GetPointClicked(P3.x, P3.y);
	msg += "\Third corner is at (" + to_string(P3.x) + ", " + to_string(P3.y) + " )";
	msg += " ... Click at Third corner";
	pUI->PrintMessage(msg);
	side2 = sqrt(pow(P2.x - P3.x, 2) + pow(P2.y - P3.y, 2));

	angle1 = atan2(P2.y, P2.x);
	angle2 = atan2(P3.y, P3.y);
	Points.push_back(P1);
	Points.push_back(P2);
	Points.push_back(P3);
	//((side2 - side1) == 0) && (angle1 - angle2 == 0) &&
	while ( n <6 )
	{
		x_be = P3.x;
		y_be = P3.y;
		angle1 = atan2(y_be, x_be);
		pUI->GetPointClicked(P3.x, P3.y);
		angle2 = atan2(P3.y, P3.x);
		side2 = sqrt(pow(x_be - P3.x, 2) + pow(y_be - P3.y, 2));
		msg += "\Next corner is at (" + to_string(P3.x) + ", " + to_string(P3.y) + " )";
		msg += " ... Click at Third corner";
		pUI->PrintMessage(msg);
		n++;
		Points.push_back(P3);

	}
	pUI->ClearStatusBar();
	
	
		//Preapre all rectangle parameters
		GfxInfo PolyGfxInfo;

		//get drawing, filling colors and pen width from the interface
		PolyGfxInfo.DrawClr = pUI->getCrntDrawColor();
		PolyGfxInfo.FillClr = pUI->getCrntFillColor();
		PolyGfxInfo.BorderWdth = pUI->getCrntPenWidth();


		PolyGfxInfo.isFilled = pUI->getisfilled();	//default is not filled
		PolyGfxInfo.isSelected = false;	//defualt is not selected


		//Create a rectangle with the above parameters
		polygon* Poly = new polygon(Points,n ,PolyGfxInfo);

		//Get a pointer to the graph
		Graph* pGr = pControl->getGraph();

		//Add the rectangle to the list of shapes
		pGr->Addshape(Poly);
	


	
}
