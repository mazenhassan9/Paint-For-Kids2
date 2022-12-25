#include"GUI/GUI.h"
#include"StartGame.h"
#include"controller.h"
#include"Shapes/Graph.h"

StartGame::StartGame(controller* pCont) :operation(pCont)
{
}

StartGame::~StartGame()
{
}

void StartGame::Execute()
{

	GUI* pUI = pControl->GetUI();
	pUI->CreatePlayToolBar();
	pUI->GetUseroperation();
}
