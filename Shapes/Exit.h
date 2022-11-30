#pragma once

#include "shape.h"


class Exit : public shape
{
private:
	/*Point center;
	Point Corner;*/
public:
	/*Exit(Point, Point, GfxInfo shapeGfxInfo);*/
	virtual ~Exit();
	virtual void Draw(GUI* pUI) const;
};
