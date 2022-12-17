#include "shape.h"
int shape::Shapes_Count = 0;
shape::shape()
{
	ShpGfxInfo.isFilled = false;
	ShpGfxInfo.isSelected = false;
	ID = Shapes_Count;
	Shapes_Count++;
}
shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
	ID = Shapes_Count;
	Shapes_Count++;
}
 
void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

void shape::ChngDrawClr(color Dclr)
{	ShpGfxInfo.DrawClr = Dclr; }

void shape::ChngFillClr(color Fclr)
{	
	
	ShpGfxInfo.isFilled = true;
	ShpGfxInfo.FillClr = Fclr; 
}

void shape::setBorderwidth(double bw)
{

	ShpGfxInfo.BorderWdth = bw;
}

int shape::Get_Count()
{
	return Shapes_Count;
}





