#pragma once
#include "Shape.h"
class Triangle : public shape
{
private :
	Point Corner1;
	Point Corner2;
	Point Corner3;
public :
	Triangle();
	Triangle(Point, Point, Point , GfxInfo shapeGfxInfo);
	virtual ~Triangle();
	virtual void Draw(GUI* pUI) const;
	virtual bool Get(int x, int y) const;
	virtual string Getinfo() const;
	virtual void Move(int x, int y);
	virtual void Rotate();
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};
