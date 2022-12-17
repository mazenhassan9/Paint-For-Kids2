#include "opLoad.h"
#include "..\Shapes\Shape.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opLoad::opLoad(controller* pCont):operation(pCont)
{
}

opLoad::~opLoad()
{
}

void opLoad::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	pUI->PrintMessage("Load Operation, Please Enter File name");
	string FileName = pUI->GetSrting();
	File.open(FileName, ios::in);

	pUI->changedefaultfilled(false);

	if (File.is_open())     //Check if There is a File with this Name or Not
	{
		//pUI->ClearDrawArea();
		pGr->load(File);
		
		File.close();
		pUI->ClearStatusBar();
		pUI->PrintMessage("File is Loaded Successfully");
	}

	else
		pUI->PrintMessage("Error: Could not open the file!");

}

