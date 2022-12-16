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
	Point Corner2 = { origin.x + sidelent,origin.y + sidelent };
	Point Corner1 = origin;

	if (((x >= Corner1.x && x <= Corner2.x) || (x <= Corner1.x && x >= Corner2.x)) &&
		((y >= Corner1.y && y <= Corner2.y) || (y <= Corner1.y && y >= Corner2.y)))
		return true;
	return false;
}
