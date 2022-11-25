#pragma once
#include "shape.h"
#include <vector>

class polygon : public shape
{
private:
	vector <Point> Corners;
	int vertices;

public:
	polygon(vector <Point>, GfxInfo shapeGfxInfo);
	virtual ~polygon();
	virtual void Draw(GUI* pUI) const;
};
