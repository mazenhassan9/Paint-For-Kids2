#pragma once
#include "shape.h"
#include <vector>

class polygon : public shape
{
private:
	vector <Point> Corners;
	int vertices;

public:
	polygon();
	polygon(vector <Point>, int,GfxInfo shapeGfxInfo);
	polygon(const polygon* lhs);
	virtual ~polygon();
	virtual void Draw(GUI* pUI) const;
	virtual void stick(GUI* pUI) const;
	virtual bool Get(int x, int y) const;
	virtual Point GetFirstPoint() const;
	virtual void Move(int x, int y);
	virtual void Rotate();
	virtual string Getinfo() const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void RESIZE(double size);
	virtual shape* Copy();
	bool onLine(line l1, Point p)const;

	int direction(Point a, Point b, Point c)const;

	bool isIntersect(line l1, line l2)const;
	virtual void mapshape(GUI* pUI);
	virtual void DuplicateGraph();
};
