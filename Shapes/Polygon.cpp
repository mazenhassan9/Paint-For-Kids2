#include "Polygon.h"

polygon::polygon(vector <Point> C,int N, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	for(int i =0; i < N;i++)
	{
		Corners.push_back(C[i]);
		
	}
	vertices = N;

}

polygon::~polygon()
{

}

void polygon::Draw(GUI* pUI) const
{
	pUI->DrawPoly(Corners,vertices, ShpGfxInfo);
}
