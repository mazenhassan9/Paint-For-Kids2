#pragma once
#include "shape.h"


class Oval : public shape
{
private:
	Point P1;
	Point P2;
public:
	Oval();
	Oval(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Oval();
	virtual void Draw(GUI* pUI) const;
	virtual bool Get(int x, int y) const;
	virtual string Getinfo() const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};



