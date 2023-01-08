#include "Polygon.h"
#include <iostream>
#include <math.h>

polygon::polygon()
{
	ShpGfxInfo.isFilled = false;
	ShpGfxInfo.isSelected = false;

}

polygon::polygon(vector <Point> C,int N, GfxInfo shapeGfxInfo) : shape(shapeGfxInfo)
{
	for(int i =0; i < N;i++)
	{
		Corners.push_back(C[i]);
		
	}
	vertices = N;

}

polygon::polygon(const polygon* lhs)
{
	this->ID = lhs->ID;
	this->Corners = lhs->Corners;
	this->vertices = lhs->vertices;
	this->ShpGfxInfo.DrawClr = lhs->ShpGfxInfo.DrawClr;
	this->ShpGfxInfo.FillClr = lhs->ShpGfxInfo.FillClr;
	this->ShpGfxInfo.isFilled = lhs->ShpGfxInfo.isFilled;
	this->ShpGfxInfo.BorderWdth = lhs->ShpGfxInfo.BorderWdth;
	this->ShpGfxInfo.isSelected = false;

}

polygon::~polygon()
{

}

void polygon::Draw(GUI* pUI) const
{
	pUI->DrawPoly(Corners,vertices, ShpGfxInfo);
}

void polygon::stick(GUI* pUI) const
{
	int x = Corners[0].x, y = Corners[0].y;
	int width = 0, height = 0;
	for (int i = 1; i < vertices; i++)
	{
		if (x > Corners[i].x)
			x = Corners[i].x;
		if (y > Corners[i].y)
			y = Corners[i].y;
		for (int j = 0; j < vertices; j++)
		{
			if (sqrt(pow((Corners[i].x - Corners[j].x), 2)) > width)
				width = sqrt(pow((Corners[i].x - Corners[j].x), 2));

			if (sqrt(pow((Corners[i].y - Corners[j].y), 2)) > height)
				height = sqrt(pow((Corners[i].y - Corners[j].y), 2));
		}
	}


}


void polygon::Move(int x, int y)
{
	int centerx = 0, centery = 0;
	for (int i = 0; i < vertices; i++)
	{
		centerx += Corners[i].x;
		centery += Corners[i].y;
	}
	centerx /= vertices;
	centery /= vertices;
	for (int i = 0; i < vertices; i++)
	{
		this->Corners[i].x += (x - centerx);
		this->Corners[i].y += (y - centery);
	}
}
void polygon::Rotate()
{

	int centerx = 0, centery = 0;
	for (int i = 0; i < vertices; i++)
	{
		centerx += Corners[i].x;
		centery += Corners[i].y;
		

	}
	//cout << " X " << Corners[i].x << " Y " << Corners[i].y << endl;
	centerx  /= vertices;
	centery  /= vertices;

	
		
	int x, y;

	double PI = 3.14;

	for (int i = 0 ;i < vertices; i++)
	{
		x = Corners[i].x - centerx;
		y = Corners[i].y - centery;

		this->Corners[i].x = (x * cos(PI / 2) - y * sin(PI / 2)) + centerx;
		this->Corners[i].y = (x * sin(PI / 2) + y * cos(PI / 2)) + centery;
	}


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

Point polygon::GetFirstPoint() const
{
	int x = Corners[0].x, y = Corners[0].y;
	for (int i = 1; i < vertices; i++)
	{
		if (x > Corners[i].x)
			x = Corners[i].x;
		if (y > Corners[i].y)
			y = Corners[i].y;
		
	}
	Point P1 = { x,y };
	return P1;

}

string polygon::Getinfo() const
{
	string FillColor;
	if (ShpGfxInfo.isFilled)
		FillColor = "Filled  Color R: " + to_string(ShpGfxInfo.FillClr.ucRed) + " G: " + to_string(ShpGfxInfo.FillClr.ucGreen) + " B: " + to_string(ShpGfxInfo.FillClr.ucBlue);
	else
		FillColor = "Non_Filled";
	

	string message = "Polygon   " + to_string(ID);
	for (int i = 0; i < vertices; i++)
	{
		message += "    Point" +to_string(i)+ " (" + to_string(Corners[i].x) + " , " + to_string(Corners[i].y) + ")";
	}
		
		message += "    Drawing Color R: " + to_string(ShpGfxInfo.DrawClr.ucRed) + " G: " + to_string(ShpGfxInfo.DrawClr.ucGreen) + " B: " + to_string(ShpGfxInfo.DrawClr.ucBlue)
		+ "   " + FillColor;

	return message;
}

void polygon::Save(ofstream& OutFile)
{
	OutFile << "POLYGON  " << ID << "  " << vertices << "  ";
	for (int i = 0; i < vertices; i++)
	{
		OutFile << Corners[i].x << "  " << Corners[i].y << "  ";
	}
	OutFile << (int)(ShpGfxInfo.DrawClr.ucRed) << "  " << (int)ShpGfxInfo.DrawClr.ucGreen << "  " << (int)ShpGfxInfo.DrawClr.ucBlue << "  ";
	if (ShpGfxInfo.isFilled != false)
		OutFile << "True" << "  " << (int)ShpGfxInfo.FillClr.ucRed << "  " << (int)ShpGfxInfo.FillClr.ucGreen << "  " << (int)ShpGfxInfo.FillClr.ucBlue << endl;
	else
		OutFile << "False" << endl;
}

void polygon::Load(ifstream& Infile)
{
	int D1, D2, D3;
	int F1, F2, F3;
	Point P;
	Infile >> ID >> vertices;
	for (int i = 0; i < vertices; i++)
	{
		Infile >> P.x >> P.y;
		Corners.push_back(P);
	}

	Infile >> D1 >> D2 >> D3;
	color C1(D1, D2, D3);
	this->ShpGfxInfo.DrawClr = C1;
	string conditon;
	Infile >> conditon;
	if (conditon == "True")
	{
		this->ShpGfxInfo.isFilled = true;
		Infile >> F1 >> F2 >> F3;
		color C2(F1, F2, F3);
		this->ShpGfxInfo.FillClr = C2;
	}
	else
	{
		this->ShpGfxInfo.isFilled = false;
		
	}

}


shape* polygon::Copy()
{
	shape* S = new polygon(this);
	return S;
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
void polygon::RESIZE(double size) {
	int centerx = 0, centery = 0;
	for (int i = 0; i < vertices; i++)
	{
		centerx += Corners[i].x;
		centery += Corners[i].y;


	}
	centerx /= vertices;
	centery /= vertices;
	//scailing 
	for (int i = 0; i < vertices; i++)
	{
		this->Corners[i].x *= size;
		this->Corners[i].y *= size;

	}
	this->Move(centerx, centery); //shift back to its center
	



}

void polygon::mapshape(GUI* pUI)
{

	int centerx = 0, centery = 0;
	for (int i = 0; i < vertices; i++)
	{
		pUI->Mapx(Corners[i].x);
		pUI->Mapy(Corners[i].y);


		centerx += Corners[i].x;
		centery += Corners[i].y;
	}
	centerx /= vertices;
	centery /= vertices;

	pUI->Mapx(centerx);
	pUI->Mapy(centery);
	
}

void polygon::DuplicateGraph() {

}