#include "Circle.h"

Circle::Circle(Point circenter, Point radius, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center = circenter;
	Corner = radius;
}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawCir to draw a circle on the screen	
	pUI->DrawCir(center, Corner, ShpGfxInfo);
}

bool Circle::Get(int x, int y) const
{
	int radius = sqrt(pow((center.x - Corner.x), 2) + pow((center.y - Corner.y), 2));

	int pDistance = sqrt(pow((center.x - x), 2) + pow((center.y - y), 2));

	if (pDistance <= radius)
		return true;

	return false;
}
