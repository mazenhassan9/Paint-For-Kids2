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
	if (pUI->getdefaultfilled() == false)
		file << "False" << "  " << (int)(pUI->getCrntDrawColor()).ucRed << "  " << (int)pUI->getCrntDrawColor().ucGreen << "  " << (int)pUI->getCrntDrawColor().ucBlue << "  " << pUI->getCrntPenWidth() << endl;
	else
		file << "True" <<"  " << (int)(pUI->getCrntDrawColor()).ucRed << "  " << (int)pUI->getCrntDrawColor().ucGreen << "  " << (int)pUI->getCrntDrawColor().ucBlue << "  " << (int)(pUI->getCrntFillColor()).ucRed << "  " << (int)pUI->getCrntFillColor().ucGreen << "  " << (int)pUI->getCrntFillColor().ucBlue << "  " << pUI->getCrntPenWidth() << endl;
	pGr->Save(file);
	file.close();
	pUI->ClearStatusBar();
	pUI->PrintMessage("File Saved successfully");
}
