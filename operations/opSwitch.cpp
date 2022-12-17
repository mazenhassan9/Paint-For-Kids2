#include "opSwitch.h"
#include "..\Shapes\Shape.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"


opSwitch::opSwitch(controller* pCont):operation(pCont)
{
}

opSwitch::~opSwitch()
{
}

void opSwitch::Execute()
{
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Switch to draw mode");
	pUI->CreateDrawToolBar();
}
