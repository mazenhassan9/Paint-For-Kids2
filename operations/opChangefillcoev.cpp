#include "..\controller.h"
#include "..\GUI\GUI.h"
#include"..\Shapes\Graph.h"
#include "opchangefillcoev.h"


opChangefillcoev::opChangefillcoev(controller* pCont) :operation(pCont)
{
}

opChangefillcoev::~opChangefillcoev()
{
}

void opChangefillcoev::Execute()
{