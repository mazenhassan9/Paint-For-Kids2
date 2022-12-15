#pragma once
#include "shape.h"

class Square : public shape
{
private:
	Point origin;
	double sidelent;
public:
	Square(Point, double sidelen, GfxInfo shapeGfxInfo);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
	virtual bool Get(int x, int y) const;

};
