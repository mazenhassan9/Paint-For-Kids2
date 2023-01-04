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
	char key = -1;
	shape* S3;
	button B1 = LEFT_BUTTON;
	Graph* pGr = pControl->getGraph();
	GUI* pUI = pControl->GetUI();
	pUI->ClearStatusBar();
	
	//Select Operation & multi select.

	pUI->GetLastClick(P1.x, P1.y);
	shape* S1 = pGr->Getshape(P1.x, P1.y);
	shape* S2 = pGr->GetLastSelected();
	vector<shape*> Shapes = pGr->GetSelected();

	if (S1) //if shape found
	{
		if (S1->IsSelected())  //if shape is selected (unselect it)
		{
			S1->SetSelected(false);
			
			pGr->SetSelected(S1, false);
		}
		else  //if shape is unselected
		{
			S1->SetSelected(true);     //select it
			pUI->PrintMessage(S1->Getinfo()); //print info
			pUI->GetLastKey(key); //check if it is a multi select.
			if (S2 && key !=115)  //if the (s) button is not selected (unselect all) (otherwise the rest will stay be selected)
			{
				for (auto& itr : Shapes)
				{
					itr->SetSelected(false);
					pGr->SetSelected(itr, false);
				}

			}
			pGr->SetSelected(S1, true);
			pUI->KeyboardFlush();
		}
	}
	else if (S2) //if the point clicked is not on a shape (therefore background) (and there's a shape selected) (unselect all shapes)
	{
		
		
			for (auto& itr : Shapes)
			{
				itr->SetSelected(false);
				pGr->SetSelected(itr, false);
			}

		
	}
	//pUI->GetLastKey(key);
	//cout << key << endl;
	//if (key == 100) //"D" is press
	//{
	//	if (S2)
	//	{
	//		for (auto& itr : Shapes)
	//		{
	//			pGr->DeleteShape(itr);
	//			pGr->Draw(pUI);
	// Trial of Delete Operation (with D) key
	//		}
	//	}
	//}
	//pUI->KeyboardFlush();

	
		
	

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
