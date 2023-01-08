#pragma once //Line.cpp
#include "Line.h"
#include <iostream>



Line::Line()
{
	ShpGfxInfo.isFilled = false;
	ShpGfxInfo.isSelected = false;

}

Line::Line(Point p1, Point p2, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	P1 = p1;
	P2 = p2;
}

Line::Line(const Line* lhs)
{
	this->ID = lhs->ID;

	this->P1.x = lhs->P1.x;
	this->P2.x = lhs->P2.x;
	this->P1.y = lhs->P1.y;
	this->P2.y = lhs->P2.y;
	this->ShpGfxInfo.DrawClr = lhs->ShpGfxInfo.DrawClr;
	this->ShpGfxInfo.FillClr = lhs->ShpGfxInfo.FillClr;
	this->ShpGfxInfo.isFilled = lhs->ShpGfxInfo.isFilled;
	this->ShpGfxInfo.BorderWdth = lhs->ShpGfxInfo.BorderWdth;
	this->ShpGfxInfo.isSelected = false;
}

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	pUI->DrawLine(P1, P2, ShpGfxInfo);
}

void Line::stick(GUI* pUI) const
{
	int x = min(P1.x, P2.x);
	int y = min(P1.y,P2.y);
	int width = sqrt(pow((P2.x - P1.x), 2));
	int height = sqrt(pow((P2.y - P1.y), 2));
	string img = "images\\MenuIcons\\Menu_LINE.jpg";
	pUI->DrawImg(img, x, y, width, height);
}

bool Line::Get(int x, int y) const
{
	if (((x >= P1.x && x <= P2.x) || (x <= P1.x && x >= P2.x)) &&
		((y >= P1.y && y <= P2.y) || (y <= P1.y && y >= P2.y)))
		return true;
	return false;
}

void Line::Move(int x, int y)
{
	int centerx, centery;
	centerx = (P1.x + P2.x) / 2;
	centery = (P1.y + P2.y) / 2;
	this->P1.x += x - centerx;
	this->P1.y += y - centery;

	this->P2.x += x - centerx;
	this->P2.y += y - centery;
}

Point Line::GetFirstPoint() const
{
	int x = min(P1.x, P2.x);
	int y = min(P1.y, P2.y);
	Point P1 = { x,y };
	return P1;
}



void Line::Rotate()
{

	// get the center point location 
	double x1, x2, y1, y2;
	int centerx, centery;
	centerx = (P1.x + P2.x) / 2;
	centery = (P1.y + P2.y) / 2;


	double PI = 3.14;



	x1 = P1.x - centerx;
	x2 = P2.x - centerx;
	y1 = P1.y - centery;
	y2 = P2.y - centery;

	cout << " X1 " << P1.x << " Y1 " << P1.y << " X2 " << P2.x << " Y2 " << P2.y << endl;

	this->P1.x = (x1 * cos(PI / 2) - y1 * sin(PI / 2)) + centerx;	//5
	this->P1.y = (x1 * sin(PI / 2) + y1 * cos(PI / 2)) + centery;		//3

	this->P2.x = (x2 * cos(PI / 2) - y2 * sin(PI / 2)) + centerx;	//3
	this->P2.y = (x2 * sin(PI / 2) + y2 * cos(PI / 2)) + centery;	//4

	cout << " X1 " << P1.x << " Y1 " << P1.y << " X2 " << P2.x << " Y2 " << P2.y << endl;

	// x = x * cos(degrees in radians) - y * sin(degrees in radians)
	// y = y * cos(degrees in radians) + x * sin(degrees in radians)




}

string Line::Getinfo() const
{
	

	string message = "Line   " + to_string(ID) + "    Point1 (" + to_string(P1.x) + " , " + to_string(P1.y) + ")"
		+ "    Point2 (" + to_string(P2.x) + " , " + to_string(P2.y) + ")"
		+ "    Drawing Color R: " + to_string(ShpGfxInfo.DrawClr.ucRed) + " G: " + to_string(ShpGfxInfo.DrawClr.ucGreen) + " B: " + to_string(ShpGfxInfo.DrawClr.ucBlue)
		+ "   ";
	return message;
}

void Line::Save(ofstream& OutFile)
{
	OutFile << "LINE  " << ID << "  " << P1.x << "  " << P1.y << "  " << P2.x << "  " << P2.y << "  ";
	OutFile << (int)(ShpGfxInfo.DrawClr.ucRed) << "  " << (int)ShpGfxInfo.DrawClr.ucGreen << "  " << (int)ShpGfxInfo.DrawClr.ucBlue << "  " << endl;
	
	
}

void Line::Load(ifstream& Infile)
{

	int D1, D2, D3;
	int F1, F2, F3;

	Infile >> ID >> P1.x >> P1.y >> P2.x >> P2.y;
	Infile >> D1 >> D2 >> D3;
	color C1(D1, D2, D3);
	ShpGfxInfo.DrawClr = C1;
	ShpGfxInfo.isFilled = false;
}
void Line::RESIZE(double size) 
{
	int centerx, centery;
	centerx = (P1.x + P2.x) / 2;
	centery = (P1.y + P2.y) / 2;

	this->P1.x *= size;
	this->P1.y *= size;

	this->P2.x *= size;
	this->P2.y *= size;
	this->Move(centerx, centery);
}

shape* Line::Copy()
{
	shape* S = new Line(this);
	return S;
}
void Line::mapshape(GUI* pUI)
{
	pUI->Mapx(P1.x);
	pUI->Mapx(P2.x);
	pUI->Mapy(P1.y);
	pUI->Mapy(P1.y);

	
}
void Line::DuplicateGraph() {

}