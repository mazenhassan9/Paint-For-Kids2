#include "Polygon.h"

polygon::polygon(vector <Point> C, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	int i = 0;
	while (C[i].x)
	{
		Corners.push_back(C[i]);
		i++;
	}
	vertices = i;

}

polygon::~polygon()
{

}

void polygon::Draw(GUI* pUI) const
{
	pUI->DrawPoly(Corners,vertices, ShpGfxInfo);
}
