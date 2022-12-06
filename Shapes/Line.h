#pragma once   //Line.h
#include "Shape.h"

class Line : public shape
{
private:
	Point P1;
	Point P2;
public:
	Line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
};
