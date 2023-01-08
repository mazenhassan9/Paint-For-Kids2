#include "OpRedo.h"
#include "..\Shapes\Shape.h"

#include "..\controller.h"

#include "..\GUI\GUI.h"
#include <iostream>

OpRedo::OpRedo(controller* pCont):operation(pCont)
{
}

OpRedo::~OpRedo()
{
}

void OpRedo::Execute()
{
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	operationType uOp = pGr->GetLastUndo();
	vector<shape*> Shapes = pGr->getlistofshspes();
	shape* S1;
	pUI->PrintMessage("Redo Seleceted");
	
		if (uOp)
		{
			pGr->AddOperation(uOp);
			if (uOp >= 0 && uOp < 8) //Draw Images
			{
				S1 = pGr->GetLastDeletedUndo();
				if (S1)
				{
					pGr->Addshape(S1);
					S1 = nullptr;
					pUI->PrintMessage("Redo Add back Done");
				}
			}
			else if (uOp >= 8 && uOp < 13) //Modified
			{
				S1 = pGr->GetLastModifiedUndo();
				if (!Shapes.empty())
				{
					for (auto& itr : Shapes)
					{
						if (S1->GetID() == itr->GetID())
						{
							pGr->AddModifiedShape(itr->Copy(), true);
							pGr->DeleteShape(itr);
							pGr->Addshape(S1);

						}
					}
				}
				pUI->PrintMessage("Redo Modified Done");


			}
			else if (uOp == 13) //Deleted
			{
				S1 = pGr->GetLastDeletedUndo();
				if (S1)
				{
					pGr->Addshape(S1);
					pUI->PrintMessage("Redo Add Done");
				}
			}

		}
		else
		{
			pUI->PrintMessage("No Undo Operations Done");
		}

}


