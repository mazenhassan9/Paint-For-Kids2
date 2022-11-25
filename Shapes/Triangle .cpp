#include "Triangle .h"

Triangle::Triangle(Point p1, Point p2,Point p3 , GfxInfo shapeGfxInfo) : shape (shapeGfxInfo)
{
	x1 = p1;
	x2 = p2;
	x3 = p3;
	
}

Triangle::~Triangle()
{
}

void Triangle::Draw(GUI* pUI) const
{
	pUI->DrawTri(x1, x2 ,x3 , ShpGfxInfo);
}
