#pragma once
#include "Shape.h"
class Triangle : public shape
{
private :
	Point x1;
	Point x2;
	Point x3;
public :
	Triangle(Point, Point, Point , GfxInfo shapeGfxInfo);
	virtual ~Triangle();
	virtual void Draw(GUI* pUI) const;
};
