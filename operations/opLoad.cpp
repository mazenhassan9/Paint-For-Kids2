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
	string condition;
	int DR, DG, DB;
	int FR, FG, FB;
	double Borderwidth;
	if (File.is_open())     //Check if There is a File with this Name or Not
	{
		File >> condition;
		//loading the headers of the file (Draw color, Fill color(if exist), Border width)
		if (condition == "False")
		{
			File >> DR >> DG >>  DB >>  Borderwidth;
			pUI->setBorderwidth(Borderwidth);
			pUI->setPenColor(color(DR, DG, DB));

		}
		else
		{
			File >> DR >>  DG >>  DB >>  FR >>  FG >>  FB >> Borderwidth;
			pUI->setBorderwidth(Borderwidth);
			pUI->setPenColor(color(DR, DG, DB));
			pUI->setFillColor(color(FR, FG, FB));
			pUI->changedefaultfilled(true);

		}
		pGr->load(File); //calling the load function of the graph.
		File.close();
		pUI->ClearStatusBar();
		pUI->PrintMessage("File is Loaded Successfully");
	}

	else
		pUI->PrintMessage("Error: Could not open the file!");

}

