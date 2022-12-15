#include "Square.h"

Square::Square(Point P1, double sidelen, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	origin = P1;
	sidelent = sidelen;
}

Square::~Square()
{}

void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawSquare(origin,sidelent , ShpGfxInfo);
}

bool Square::Get(int x, int y) const
{
	return false;
}
