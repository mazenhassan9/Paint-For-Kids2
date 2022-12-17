#pragma once

#include "shape.h"


class Circle : public shape
{
private:
	Point center;
	Point Corner;
public:
	Circle();
	Circle(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	virtual bool Get(int x, int y) const;
	virtual string Getinfo() const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

