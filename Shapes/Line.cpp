#pragma once //Line.cpp
#include "Line.h"



Line::Line(Point p1, Point p2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	P1 = p1;
	P2 = p2;
}

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	pUI->DrawLine(P1, P2, ShpGfxInfo);
}

bool Line::Get(int x, int y) const
{
	if (((x >= P1.x && x <= P2.x) || (x <= P1.x && x >= P2.x)) &&
		((y >= P1.y && y <= P2.y) || (y <= P1.y && y >= P2.y)))
		return true;
	return false;
}
