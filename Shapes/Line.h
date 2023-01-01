#pragma once   //Line.h
#include "Shape.h"

class Line : public shape
{
private:
	Point P1;
	Point P2;
public:
	Line();
	Line(Point, Point, GfxInfo shapeGfxInfo);
	virtual ~Line();
	virtual void Draw(GUI* pUI) const;
	virtual bool Get(int x, int y) const;
	virtual void Move(int x, int y);
	virtual void Rotate();
	virtual string Getinfo() const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void RESIZE(double size);
};

