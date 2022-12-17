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
	virtual ~polygon();
	virtual void Draw(GUI* pUI) const;
	virtual bool Get(int x, int y) const;
	virtual string Getinfo() const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);

	bool onLine(line l1, Point p)const;

	int direction(Point a, Point b, Point c)const;

	bool isIntersect(line l1, line l2)const;

};
