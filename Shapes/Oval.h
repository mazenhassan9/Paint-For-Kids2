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
	Oval(const Oval* lhs);
	virtual ~Oval();
	virtual void Draw(GUI* pUI) const;
	virtual void stick(GUI* pUI) const;
	virtual bool Get(int x, int y) const;
	virtual Point GetFirstPoint() const;
	virtual void Rotate();
	virtual string Getinfo() const;
	virtual void Move(int x, int y);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void RESIZE(double size);
	virtual shape* Copy();
	virtual void mapshape(GUI* pUI);
	virtual void DuplicateGraph();
};
