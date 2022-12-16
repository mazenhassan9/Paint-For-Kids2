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
	pUI->PrintMessage("Do you want the shape fill or not? yes: 0 || no: 1");
	string usss = pUI->GetSrting();
	if (usss == "1")
	{
		pUI->changedefaultfilled(false);
		return;
	}
	pUI->PrintMessage("pick a color from the window");
	color picked = pUI->colorpalette();
	pUI->setFillColor(picked);
	pUI->changedefaultfilled(true);
	
	
}
