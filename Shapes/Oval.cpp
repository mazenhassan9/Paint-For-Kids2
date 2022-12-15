#include "Oval.h"

Oval::Oval(Point point1, Point point2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	P1 = point1;
	P1 = point2;
}

Oval::~Oval()
{}

void Oval::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawOval(P1, P2, ShpGfxInfo);
}

bool Oval::Get(int x, int y) const
{
	return false;
}
