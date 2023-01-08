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
		pGr->AddOperationUndo(pOp);
		if (pOp >= 0 && pOp < 8) //Draw Images
		{
			S1 = pGr->GetLastAdded();
			if (S1)
			{
				pGr->AddDeletedShapeUndo(S1->Copy(), true);
				pUI->PrintMessage("Undo Delete Added Done");
			}
			S1 = nullptr;
			
		}
		else if (pOp >= 8 && pOp < 13) //Modified
		{
			S1 = pGr->GetLastModified();
			for (auto& itr : Shapes)
			{
				if (S1->GetID() == itr->GetID())
				{
					pGr->AddModifiedShapeUndo(itr->Copy(), true);
					pGr->DeleteShape(itr);
					pGr->Addshape(S1);

				}
			}
			S1 = nullptr;

		}
		else if (pOp == 13) //Deleted
		{
			S1 = pGr->GetLastDeleted();
			if (S1)
			{
				pGr->Addshape(S1);
				pGr->AddDeletedShapeUndo(S1->Copy(), true);
				pUI->PrintMessage("Undo Done");
			}
			S1 = nullptr;
		}
	}
	else
	{
		pUI->PrintMessage("No Operation Done yet");
	}
}
