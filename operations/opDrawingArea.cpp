#include "opDrawingArea.h"
#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"
#include <iostream>
opDrawingArea::opDrawingArea(controller* pCont):operation(pCont)
{
}

opDrawingArea::~opDrawingArea()
{
}

void opDrawingArea::Execute()
{
	Point P1,P2;
	shape* S3;
	button B1 = LEFT_BUTTON;
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->ClearStatusBar();

	//Select Operation

	pUI->GetLastClick(P1.x, P1.y);
	shape* S1 = pGr->Getshape(P1.x, P1.y);
	shape* S2 = pGr->GetSelected();
	pUI->ClearStatusBar();
	if (S1)
	{
		if (S1->IsSelected())
		{
			S1->SetSelected(false);
			pGr->SetSelected(S1, false);
		}
		else
		{
			S1->SetSelected(true);
			pUI->PrintMessage(S1->Getinfo());
			pGr->SetSelected(S1, true);
		}
	}
	else if (S2)
	{
		S2->SetSelected(false);
		pGr->SetSelected(S2, false);
	}
	



	//Drag  Operation
	int refresh = 0; //to slow down the drawing. 
	bool flag = pUI->GetMouseStatus(B1, P2.x, P2.y);
	while (flag)
	{
		S3 = pGr->Getshape(P2.x, P2.y);
		if (S3)
		{
			refresh++;
			pGr->DeleteShape(S3);
			
			S3->Move(P2.x, P2.y);
			pGr->Addshape(S3);
			if (refresh == 200)
			{
				pGr->Draw(pUI);
				refresh = 0;
				
			}
			pUI->PrintMessage("Shape Dragging release the mouse!");
			
		}
		flag = pUI->GetMouseStatus(B1, P2.x, P2.y);
		
		
	}
	
	

	//pUI->ClearStatusBar();

	
	
	
	
}
