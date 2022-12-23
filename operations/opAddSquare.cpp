#include "opAddSquare.h"
#include "..\shapes\Square.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opAddSquare::opAddSquare(controller* pCont) :operation(pCont)
{}
opAddSquare::~opAddSquare()
{}

//Execute the operation
void opAddSquare::Execute()
{
	Point P1, P2;

	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();

	pUI->PrintMessage("New Square: Click at the first corner");
	//Read 1st corner and store in point P1
	pUI->GetPointClicked(P1.x, P1.y);

	string msg = "First corner is at (" + to_string(P1.x) + ", " + to_string(P1.y) + " )";
	msg += " ... Enter the sidelength of the square";
	pUI->PrintMessage(msg);
	//Read 2nd corner and store in point P2
	double sl = stod(pUI->GetSrting());
	pUI->ClearStatusBar();
	

	//Preapre all rectangle parameters
	GfxInfo SquareGfxInfo;

	//get drawing, filling colors and pen width from the interface
	SquareGfxInfo.DrawClr = pUI->getCrntDrawColor();
	SquareGfxInfo.FillClr = pUI->getCrntFillColor();
	SquareGfxInfo.BorderWdth = pUI->getBorderwidth();


	SquareGfxInfo.isFilled = pUI->getdefaultfilled();	//default is not filled
	SquareGfxInfo.isSelected = false;	//defualt is not selected


	//Create a Square with the above parameters
	Square* R = new Square(P1, sl, SquareGfxInfo);

	//Get a pointer to the graph
	Graph* pGr = pControl->getGraph();

	//Add the Square to the list of shapes
	pGr->Addshape(R);

}