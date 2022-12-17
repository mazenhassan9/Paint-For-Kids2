#include "Polygon.h"

polygon::polygon(vector <Point> C,int N, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	for(int i =0; i < N;i++)
	{
		Corners.push_back(C[i]);
		
	}
	vertices = N;

}

polygon::~polygon()
{

}

void polygon::Draw(GUI* pUI) const
{
	pUI->DrawPoly(Corners,vertices, ShpGfxInfo);
}

bool polygon::Get(int x, int y) const
{
	// Create a point at infinity, y is same as point p
	Point p = {x,y};
	line exline = { p, { 9999, p.y } };
	int count = 0;
	int i = 0;
	do {

		// Forming a line from two consecutive points of
		// poly
		line side = { Corners[i], Corners[(i + 1) % vertices] };
		if (isIntersect(side, exline)) {

			// If side is intersects exline
			if (direction(side.p1, p, side.p2) == 0)
				return onLine(side, p);
			count++;
		}
		i = (i + 1) % vertices;
	} while (i != 0);

	// When count is odd
	return count & 1;
}
string polygon::Getinfo() const
{
	string FillColor;
	if (ShpGfxInfo.isFilled)
		FillColor = "Filled  Color R: " + to_string(ShpGfxInfo.FillClr.ucRed) + " G: " + to_string(ShpGfxInfo.FillClr.ucGreen) + " B: " + to_string(ShpGfxInfo.FillClr.ucBlue);
	else
		FillColor = "Non_Filled";
	ShpGfxInfo.DrawClr.ucRed;

	string message = "Polygon   " + to_string(ID);
	for (int i = 0; i < vertices; i++)
	{
		message += "    Point" +to_string(i)+ " (" + to_string(Corners[i].x) + " , " + to_string(Corners[i].y) + ")";
	}
		
		message += "    Drawing Color R: " + to_string(ShpGfxInfo.DrawClr.ucRed) + " G: " + to_string(ShpGfxInfo.DrawClr.ucGreen) + " B: " + to_string(ShpGfxInfo.DrawClr.ucBlue)
		+ "   " + FillColor;

	return message;
}

bool polygon::onLine(line l1, Point p) const
{
	// Check whether p is on the line or not
	if (p.x <= max(l1.p1.x, l1.p2.x)
		&& p.x <= min(l1.p1.x, l1.p2.x)
		&& (p.y <= max(l1.p1.y, l1.p2.y)
			&& p.y <= min(l1.p1.y, l1.p2.y)))
		return true;

	return false;
}

int polygon::direction(Point a, Point b, Point c)const
{
	int val = (b.y - a.y) * (c.x - b.x)
		- (b.x - a.x) * (c.y - b.y);

	if (val == 0)

		// Colinear
		return 0;

	else if (val < 0)

		// Anti-clockwise direction
		return 2;

	// Clockwise direction
	return 1;
}
bool polygon::isIntersect(line l1, line l2)const
{
	// Four direction for two lines and points of other line
	int dir1 = direction(l1.p1, l1.p2, l2.p1);
	int dir2 = direction(l1.p1, l1.p2, l2.p2);
	int dir3 = direction(l2.p1, l2.p2, l1.p1);
	int dir4 = direction(l2.p1, l2.p2, l1.p2);

	// When intersecting
	if (dir1 != dir2 && dir3 != dir4)
		return true;

	// When p2 of line2 are on the line1
	if (dir1 == 0 && onLine(l1, l2.p1))
		return true;

	// When p1 of line2 are on the line1
	if (dir2 == 0 && onLine(l1, l2.p2))
		return true;

	// When p2 of line1 are on the line2
	if (dir3 == 0 && onLine(l2, l1.p1))
		return true;

	// When p1 of line1 are on the line2
	if (dir4 == 0 && onLine(l2, l1.p2))
		return true;

	return false;
}