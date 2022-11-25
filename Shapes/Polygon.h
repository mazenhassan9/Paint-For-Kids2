#pragma once
#include "shape.h"

class Polygon : public shape
{
private:
	Point* Corners;
	int vertices;

public:
	Polygon(Point*, int, GfxInfo shapeGfxInfo);
	virtual ~Polygon();
	virtual void Draw(GUI* pUI) const;
};
