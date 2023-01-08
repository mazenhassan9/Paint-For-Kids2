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
	Circle(const Circle* lhs);

	
	virtual ~Circle();
	virtual void Draw(GUI* pUI) const;
	virtual void stick(GUI* pUI) const;
	virtual bool Get(int x, int y) const;
	virtual void Move(int x, int y);
	virtual void Rotate();
	virtual string Getinfo() const;
	virtual void mapshape(GUI* pUI);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void RESIZE(double size);
	virtual shape* Copy();
	virtual void DuplicateGraph();
	virtual Point GetFirstPoint() const;
};