#include "opSave.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"
opSave::opSave(controller* pCont) :operation(pCont)
{
}

opSave::~opSave()
{
}

void opSave::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->PrintMessage("Save Operation, Please Enter Filename");
	string filename = pUI->GetSrting();
	file.open(filename, ios::out);

	pGr->Save(file);
	file.close();
	pUI->ClearStatusBar();
	pUI->PrintMessage("File Saved successfully");
}
