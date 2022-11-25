#include "Polygon.h"

Polygon::Polygon(vector <Point*> C, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	int i = 0;
	while (C[i] != nullptr)
	{
		Corners.push_back(C[i]);
		i++;
	}
	vertices = i;

}

Polygon::~Polygon()
{

}

void Polygon::Draw(GUI* pUI) const
{
}
