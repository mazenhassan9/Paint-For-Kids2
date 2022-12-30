#pragma once //Line.cpp
#include "Line.h"



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

Line::~Line()
{}

void Line::Draw(GUI* pUI) const
{
	//Call Output::DrawLine to draw a Line on the screen	
	pUI->DrawLine(P1, P2, ShpGfxInfo);
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

void Line::Rotate()
{
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

