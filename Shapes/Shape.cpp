#include "shape.h"
int shape::Shapes_Count = 0;
shape::shape()
{
	ShpGfxInfo.isFilled = false;
	ShpGfxInfo.isSelected = false;
	ID = Shapes_Count;
	Shapes_Count++;
	isHidden = false;
	isStick = false;
}
shape::shape(GfxInfo shapeGfxInfo)
{ 
	ShpGfxInfo = shapeGfxInfo;	//Default status is non-filled.
	ID = Shapes_Count;
	Shapes_Count++;
	isHidden = false;
	isStick = false;
}


 
int shape::GetID() const
{
	return ID;
}

void shape::SetSelected(bool s)
{	ShpGfxInfo.isSelected = s; }

bool shape::IsSelected() const
{	return ShpGfxInfo.isSelected; }

void shape::SetSticked(bool s)
{
	isStick = s;
}

bool shape::IsSticked() const
{
	return isStick;
}

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

void shape::Hide(bool s)
{
	isHidden = s;
}

bool shape::HiddenItems()
{
	return isHidden;
}

GfxInfo shape::getGraphics()
{
	return ShpGfxInfo;
}
int shape::getID()
{
	return ID;
}