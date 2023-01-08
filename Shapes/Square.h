#pragma once
#include "shape.h"

class Square : public shape
{
private:
	Point origin;
	double sidelent;
public:
	Square();
	Square(Point, double sidelen, GfxInfo shapeGfxInfo);
	Square(const Square* lhs);
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
	virtual void stick(GUI* pUI) const;
	virtual bool Get(int x, int y) const;
	virtual Point GetFirstPoint() const;
	virtual void Move(int x, int y);
	virtual void Rotate();
	virtual string Getinfo() const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual shape* Copy();
	virtual void RESIZE(double size);
	virtual void mapshape(GUI* pUI);
	virtual void DuplicateGraph();
};
