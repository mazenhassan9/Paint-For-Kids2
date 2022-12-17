#include "controller.h"
#include "operations\opAddRect.h"
#include "operations\opAddCircle.h"
#include "operations\opAddSquare.h"
#include "operations/opAddTri.h"
#include "operations\opAddPoly.h"
#include "operations\oppAddOval.h"
#include "operations\oppAddLine.h"
#include "operations\opAddExit.h"
#include "operations\opGeneralfillcolor.h"
#include "opChangePenColor.h"
#include"opChangeBorderColor.h"
#include"operations/OpAddIrPoly.h"
#include"operations/opSelect.h"
#include"operations/opDelete.h"
#include"operations/opChangeFill.h"
#include "operations/opBorderwidth.h"
#include "operations/opPenwidth.h"
#include"operations/opDrawingArea.h"
#include"operations/opSave.h"
#include"operations/opLoad.h"
//Constructor
controller::controller()
{
	pGraph = new Graph;
	pGUI = new GUI;	//Create GUI object
}

//==================================================================================//
//								operations-Related Functions							//
//==================================================================================//
operationType controller::GetUseroperation() const
{
	//Ask the input to get the operation from the user.
	return pGUI->GetUseroperation();		
}

////////////////////////////////////////////////////////////////////////////////////
//Creates an operation and executes it
operation* controller::createOperation(operationType OpType)
{
	operation* pOp = nullptr;
	
	//According to operation Type, create the corresponding operation object
	switch (OpType)
	{
		case DRAW_RECT:
			pOp = new opAddRect(this);
			break;
		case DRAW_CIRC:
			pOp = new opAddCircle(this);
			break;
		case DRAW_POLY:
			pOp = new opAddPoly(this);
			break;
		case DRAW_LINE:
			pOp = new opAddLine(this);
			break;
		case DRAW_IRPOLY:
			pOp = new opAddIrPoly(this);
			break;
		case DRAW_TRI :
			pOp = new opAddTri(this);
			break;
		case DRAW_SQAURE:
			pOp = new opAddSquare(this);
			break;
		case DRAW_OVAL:
			pOp = new opAddOval(this);
			break;
		case CHNG_S_FILL_CLR:
			pOp = new opChangeFill(this);
			break;
		case CHNG_DRAW_CLR:
			pOp = new opChangePenColor(this);
			break;
		case CHNG_BOR_CLR:
			pOp = new opChangeBorderColor(this);
			break;

		case Select:
			pOp = new opSelect(this);
			break;
		case DEL:
			pOp = new opDelete(this);
			break;
		case SAVE:
			pOp = new opSave(this);
			break;
		case LOAD:
			pOp = new opLoad(this);
			break;
		case EXIT:
			///create Exitoperation here
			pOp = new opAddExit(this);
			break;
		case CHNG_FILL_CLR:
			pOp = new opGeneralfillcolor(this);
			break;
		case PENWIDTH :
			pOp = new opPenwidth(this);
			break;

		case DRAWING_AREA:
			pOp = new opDrawingArea(this);
			break;
		case BORDER_WIDTH:
			pOp = new opBorderwidth(this);
			break;
		case STATUS:	//a click on the status bar ==> no operation
			break;
	}

	return pOp;
	
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all shapes on the user interface
void controller::UpdateInterface() const
{	
	pGraph->Draw(pGUI);
}

//void controller::colorall(color c)
//{
//	for(int i =0;i<pGraph->getlistofshspes().size(); i++)
//	{
//		pGraph->getlistofshspes()[i]->ChngFillClr(c);
//		/*pGraph->getlistofshspes()[i]->ChngDrawClr(c);*/
//		
//	}
//	
//	
//}


////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the UI
GUI *controller::GetUI() const
{	return pGUI; }
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the Graph
Graph* controller::getGraph() const
{
	return pGraph;
}





//Destructor
controller::~controller()
{
	delete pGUI;
	delete pGraph;
	
}



//==================================================================================//
//							Run function											//
//==================================================================================//
void controller::Run()
{
	operationType OpType;
	do
	{

		
		//1. Ask the GUI to read the required operation from the user
		OpType = GetUseroperation();

		//2. Create an operation coresspondingly
		operation* pOpr = createOperation(OpType);
		 
		//3. Execute the created operation
		if (pOpr)
		{
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}

		//Update the interface
		UpdateInterface();

	} while (OpType != EXIT);
	delete this;

}
