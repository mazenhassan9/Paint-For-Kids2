#include "opGeneralfillcolor.h"

#include "..\Shapes\Shape.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"
opGeneralfillcolor::opGeneralfillcolor(controller* pCont) :operation(pCont)
{}
opGeneralfillcolor::~opGeneralfillcolor()
{}

//Execute the operation
void opGeneralfillcolor::Execute()
{
	
	
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();
	/*pUI->colorpalette();*/
	pUI->PrintMessage("pick a color from the window");
	
	/*pUI->getCrntFillColor();
	
	shape* upi;
	upi->ChngFillClr();*/

}