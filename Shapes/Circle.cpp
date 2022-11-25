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