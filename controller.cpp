#include "controller.h"
#include "operations\opAddRect.h"
#include "operations\OpRotate.h"
#include "operations\opAddCircle.h"
#include "operations\opAddSquare.h"
#include "operations/opAddTri.h"
#include "operations\opAddPoly.h"
#include "operations/OpGroup.h"
#include "operations/Opungroup.h"
#include "operations\oppAddOval.h"
#include "operations\oppAddLine.h"
#include "operations\opAddExit.h"
#include "operations\opGeneralfillcolor.h"
#include "opChangePenColor.h"
#include"opChangeBorderColor.h"
#include"operations/OpAddIrPoly.h"
#include"operations/OpZoom.h"
#include"operations/opDelete.h"
#include"operations/opChangeFill.h"
#include "operations/opBorderwidth.h"
#include "operations/opPenwidth.h"
#include"operations/opDrawingArea.h"
#include "opPlayingArea.h"
#include"operations/opSave.h"
#include"operations/opLoad.h"
#include"operations/opSwitch.h"
#include"StartGame.h"
#include"opResize.h"
#include "operations/opCopy.h"
#include "operations/opPaste.h"
#include"operations/OpCut.h"
#include "operations/opStickimage.h"
#include "operations/opSendBack.h"
#include"opDublicateGraph.h"
#include"operations/opHideGraph.h"
#include"operations/OpUndo.h"

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
		case UNDO:
			pOp = new oPUndo(this);
			break;

		case ZOOM:
			pOp = new OpZoom(this);
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
		case COPY:
			pOp = new opCopy(this);
			break;
		case UNGROUP:
			pOp = new Opungroup(this);
			break;
		case CUT:
			pOp = new opCut(this);
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
		case SEND_BACK:
			pOp = new opSendBack(this);
			break;

		case DRAWING_AREA:
			pOp = new opDrawingArea(this);
			break;
		case PLAYING_AREA:                         //playing area
			pOp = new opPlayingArea(this);
			break;
		case BORDER_WIDTH:
			pOp = new opBorderwidth(this);
			break;
		case ROTATE:
			pOp = new OpRotate(this);
			break;
		case GROUP:
			pOp = new OpGroup(this);
			break;
		case SWITCH: 
			pOp = new opSwitch(this);
			break;
		case STATUS:	//a click on the status bar ==> no operation
			break;
		case TO_PLAY:
			pOp = new StartGame(this);
			break;
		case RESIZE:
			pOp = new opResize(this);
			break;
		case PASTE:
			pOp = new opPaste(this);
			break;
		case STICK:
			pOp = new opStickimage(this);
			break;
		case DUPLICATE_GRAPH:
			pOp = new opDuplicateGraph(this);
			break;
		case HIDE_GRAPH://OpUnhide
			pOp = new opHideGraph(this);
			break;

		default:
			if(pGUI->getInterfaceMode() == 0)
				pOp = new opDrawingArea(this);
			else
				pOp = new opPlayingArea(this);



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
			if(OpType >= 0 && OpType < 16)
			{
				pGraph->AddOperation(OpType);
			}
			pOpr->Execute();//Execute
			delete pOpr;	//operation is not needed any more ==> delete it
			pOpr = nullptr;
		}
		UpdateInterface();
		
		//Update the interface
		

	} while (OpType != EXIT);
//delete this;

}
