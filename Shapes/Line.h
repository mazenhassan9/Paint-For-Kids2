#pragma once   
#include "Shape.h"

class Line : public shape
{
private:
	Point P1;
	Point P2;
public:
	Line();
	Line(Point, Point, GfxInfo shapeGfxInfo);
	Line(const Line* lhs);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	virtual void stick(GUI* pUI) const;
	virtual bool Get(int x, int y) const;
	virtual void Move(int x, int y);
	virtual Point GetFirstPoint() const;
	virtual void Rotate();
	virtual string Getinfo() const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void RESIZE(double size);
	virtual shape* Copy();
	virtual void mapshape(GUI* pUI);
	virtual void DuplicateGraph();
};