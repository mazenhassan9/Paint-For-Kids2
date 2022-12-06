#pragma once
#include "shape.h"


class Oval : public shape
{
private:
	Point P1;
	Point P2;
public:
	Oval(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Oval();
	virtual void Draw(GUI* pUI) const;
};



