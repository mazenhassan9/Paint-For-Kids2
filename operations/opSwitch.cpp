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
	
	
	int Mode = pUI->getInterfaceMode();
	if (Mode)
	{
		pUI->CreateDrawToolBar();
		pUI->PrintMessage("Switched to draw mode");
	}
	else
	{
		pUI->CreatePlayToolBar();
		pUI->PrintMessage("Switched to Play mode");
	}
}
