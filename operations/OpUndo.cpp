#include "OpUndo.h"
#include "..\Shapes\Shape.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"
#include<iostream>
oPUndo::oPUndo(controller* pCont):operation(pCont)
{
}

oPUndo::~oPUndo()
{
}

void oPUndo::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	operationType pOp = pGr->GetlastOperation();
	vector<shape*> Shapes = pGr->getlistofshspes();
	shape* S1;
	pUI->PrintMessage("Undo Seleceted");
	while (pOp == UNDO)
	{
		pOp = pGr->GetlastOperation();
	}
	if (pOp)
	{
		
		if (pOp >= 0 && pOp < 8) //Draw Images
		{
			S1 = pGr->GetLastAdded();
			delete S1;
			S1 = nullptr;
			pUI->PrintMessage("Undo Done");
		}
		else if (pOp >= 8 && pOp < 13) //Modified
		{
			S1 = pGr->GetLastModified();
			for (auto& itr : Shapes)
			{
				if (S1->GetID() == itr->GetID())
				{
					itr = S1;

				}
			}

		}
		else if (pOp == 13) //Deleted
		{
			S1 = pGr->GetLastDeleted();
			pGr->Addshape(S1);
			pUI->PrintMessage("Undo Done");

		}
	}
	else
	{
		pUI->PrintMessage("No Operation Done yet");
	}
}
