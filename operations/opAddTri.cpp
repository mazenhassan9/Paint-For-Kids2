#include "opAddTri.h"

#include "..\Shapes\Triangle .h"

#include "..\controller.h"

#include "..\GUI\GUI.h"


opAddTri::opAddTri(controller* pCont) : operation(pCont)
{
}
opAddTri::~opAddTri()
{
}
void opAddTri::Execute()
{
	Point P1, P2 ,P3;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Triangle: Click at first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y );

	pUI->ClearStatusBar();

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Click at second corner";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	pUI->ClearStatusBar();

	pUI->GetPointClicked(P2.x, P2.y );
	 msg += "Second corner is at (" + to_string(P2.x) + ", " + to_string(P2.y) + " )";
	msg += " ... Click at third corner";
	pUI->PrintMessage(msg);
	//Read 3nd corner and store in point P2
	pUI->GetPointClicked(P3.x, P3.y);
	pUI->ClearStatusBar();

	//Preapre all triangle parameters
	GfxInfo TriGfxInfo;

	//get drawing, filling colors and pen width from the interface
	TriGfxInfo.DrawClr = pUI->getCrntDrawColor();
	TriGfxInfo.FillClr = pUI->getCrntFillColor();
	TriGfxInfo.BorderWdth = pUI->getBorderwidth();


	TriGfxInfo.isFilled = pUI->getdefaultfilled();	//default is not filled
	TriGfxInfo.isSelected = false;	//defualt is not selected


	//Create a triangle with the above parameters
	Triangle* R = new Triangle(P1, P2,P3 , TriGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the triangle to the list of shapes
	pGr->Addshape(R);

}
