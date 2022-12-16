#include "Oval.h"
#include <iostream>

Oval::Oval(Point point1, Point point2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	P1 = point1;
	P2 = point2;
}

Oval::~Oval()
{}

void Oval::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawOval(P1, P2, ShpGfxInfo);
}

bool Oval::Get(int x, int y) const
{
	/*
	double rx = sqrt(pow((P1.x - P2.x), 2)) / 2;
	double ry = sqrt(pow((P1.y - P2.y), 2)) / 2;
	Point center = { rx,ry };
	double distance_x = sqrt(pow((center.x - x), 2));
	double distance_y = sqrt(pow((center.y - y), 2));
	cout << "input point  is " << x << " " << y << endl;
	cout << "Point p1 is " << P1.x << " " << P1.y << endl;
	cout << "Point p2 is " << P2.x << " " << P2.y << endl;
	cout << "Center is " << (P2.x - P1.x) / 2 << " " << (P2.y - P1.y) / 2 << endl;
	cout << distance_x << " yahahh " << distance_y << endl;
	cout << rx <<" yahahh " << ry << endl;
	*/

	if (((x >= P1.x && x <= P2.x) || (x <= P1.x && x >= P2.x)) &&
		((y >= P1.y && y <= P2.y) || (y <= P1.y && y >= P2.y)))
		return true;
	return false;
}
