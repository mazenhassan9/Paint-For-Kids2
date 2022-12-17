#include "opChangePenColor.h"
#include "Shapes/Shape.h"
#include "controller.h"
#include "GUI/GUI.h"


opChangePenColor::opChangePenColor(controller* pCont) :operation(pCont)
{}
opChangePenColor::~opChangePenColor()
{}

//Execute the operation
void opChangePenColor::Execute()
{
	//Get a Pointer to the Input / Output Interfaces
	GUI* pUI = pControl->GetUI();	

	pUI->PrintMessage("pick a color from the window to change pen color");
	
	color picked = pUI->colorpalette();

	pUI->setPenColor(picked);
	


}
