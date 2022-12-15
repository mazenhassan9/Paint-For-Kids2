#include "Triangle .h"

Triangle::Triangle(Point p1, Point p2,Point p3 , GfxInfo shapeGfxInfo) : shape (shapeGfxInfo)
{
	Corner1 = p1;
	Corner2 = p2;
	Corner3 = p3;
	
}

Triangle::~Triangle()
{
}

void Triangle::Draw(GUI* pUI) const
{
	pUI->DrawTri(Corner1, Corner2 , Corner3 , ShpGfxInfo);
}

bool Triangle::Get(int x, int y) const
{
	double denominator = ((Corner2.y - Corner3.y) * (Corner1.x - Corner3.x) + (Corner3.x - Corner2.x) * (Corner1.y - Corner3.y));
	double a = ((Corner2.y - Corner3.y) * (x - Corner3.x) + (Corner3.x - Corner2.x) * (y - Corner3.y)) / denominator;
	double b = ((Corner3.y - Corner1.y) * (x - Corner3.x) + (Corner1.x - Corner3.x) * (y - Corner3.y)) / denominator;
	double c = 1 - a - b;
	return (0 <= a && a <= 1 && 0 <= b && b <= 1 && 0 <= c && c <= 1);
}
