#pragma once
#include "shape.h"
#include <vector>

class Polygon : public shape
{
private:
	vector <Point*> Corners;
	int vertices;

public:
	Polygon(vector <Point*>, GfxInfo shapeGfxInfo);
	virtual ~Polygon();
	virtual void Draw(GUI* pUI) const;
};
