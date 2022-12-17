#include "opLoad.h"
#include "..\Shapes\Shape.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"

opLoad::opLoad(controller* pCont):operation(pCont)
{
	LFig = NULL;
}

opLoad::~opLoad()
{
}

void opLoad::Execute()
{
	GUI* pUI = pControl->GetUI();
	Graph* pGr = pControl->getGraph();
	shape* bw = pGr->GetSelected();
	File.open(FileName, ios::in);
	int Figcount;

	if (File.is_open())     //Check if There is a File with this Name or Not
	{
		pUI->PrintMessage("enter file name");
		pUI->ClearDrawArea();
		string Fig;
		int FCount;

		//Load Figures Count	
		File >> FCount;

		

			LFig->load(File);
			
			LFig = NULL;

		

		File.close();
		pUI->ClearStatusBar();
		pUI->PrintMessage("File is Loaded Successfully");
	}

	else
		pUI->PrintMessage("Error: Could not open the file!");

}

