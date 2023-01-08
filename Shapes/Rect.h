#pragma once

#include "shape.h"
#include <math.h>

class Rect : public shape
{
private:
	Point Corner1;	
	Point Corner2;
public:
	Rect();
	Rect(Point , Point, GfxInfo shapeGfxInfo );
	Rect(const Rect* lhs);
	virtual ~Rect();
	virtual void Draw(GUI* pUI) const;
	virtual void stick(GUI* pUI) const;
	virtual Point GetFirstPoint() const;
	virtual bool Get(int x, int y) const;
	virtual void Move(int x, int y);
	virtual string Getinfo() const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void Rotate();
	virtual void RESIZE(double size);
	virtual shape* Copy();
	virtual void mapshape(GUI* pUI);
	virtual void DuplicateGraph();
};

