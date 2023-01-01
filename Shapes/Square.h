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
	virtual ~Square();
	virtual void Draw(GUI* pUI) const;
	virtual bool Get(int x, int y) const;
	virtual void Move(int x, int y);
	virtual void Rotate();
	virtual string Getinfo() const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void RESIZE(double size);
};
