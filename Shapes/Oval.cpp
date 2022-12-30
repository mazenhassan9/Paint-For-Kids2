#include "Oval.h"
#include <iostream>

Oval::Oval()
{
	ShpGfxInfo.isFilled = false;
	ShpGfxInfo.isSelected = false;

}

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

	if (((x >= P1.x && x <= P2.x) || (x <= P1.x && x >= P2.x)) &&
		((y >= P1.y && y <= P2.y) || (y <= P1.y && y >= P2.y)))
		return true;
	return false;
}

void Oval::Rotate()
{
}

string Oval::Getinfo() const
{
	string FillColor;
	if (ShpGfxInfo.isFilled)
		FillColor = "Filled  Color R: " + to_string(ShpGfxInfo.FillClr.ucRed) + " G: " + to_string(ShpGfxInfo.FillClr.ucGreen) + " B: " + to_string(ShpGfxInfo.FillClr.ucBlue);
	else
		FillColor = "Non_Filled";

	string message = "Oval   " + to_string(ID) + "    Point1 (" + to_string(P1.x) + " , " + to_string(P1.y) + ")"
		+ "    Point2 (" + to_string(P2.x) + " , " + to_string(P2.y) + ")"
		+ "    Drawing Color R: " + to_string(ShpGfxInfo.DrawClr.ucRed) + " G: " + to_string(ShpGfxInfo.DrawClr.ucGreen) + " B: " + to_string(ShpGfxInfo.DrawClr.ucBlue)
		+ "   " + FillColor;
	return message;
}

void Oval::Move(int x, int y)
{
	int centerx, centery;
	centerx = (P1.x + P2.x) / 2;
	centery = (P1.y + P2.y) / 2;
	this->P1.x += x - centerx;
	this->P1.y += y - centery;

	this->P2.x += x - centerx;
	this->P2.y += y - centery;
}

void Oval::Save(ofstream& OutFile)
{
	OutFile << "OVAL  " << ID << "  " << P1.x << "  " << P1.y << "  " << P2.x << "  " << P2.y << "  ";
	OutFile << (int)(ShpGfxInfo.DrawClr.ucRed) << "  " << (int)ShpGfxInfo.DrawClr.ucGreen << "  " << (int)ShpGfxInfo.DrawClr.ucBlue << "  ";
	if (ShpGfxInfo.isFilled != false)
		OutFile << "True" << "  " << (int)ShpGfxInfo.FillClr.ucRed << "  " << (int)ShpGfxInfo.FillClr.ucGreen << "  " << (int)ShpGfxInfo.FillClr.ucBlue << endl;
	else
		OutFile << "False" << endl;
}

void Oval::Load(ifstream& Infile)
{
	
	int D1, D2, D3;
	int F1, F2, F3;

	Infile >> ID >> P1.x >> P1.y >> P2.x >> P2.y;
	Infile >> D1 >> D2 >> D3;
	color C1(D1, D2, D3);
	ShpGfxInfo.DrawClr = C1;
	string conditon;
	Infile >> conditon;
	if (conditon == "True")
	{
		ShpGfxInfo.isFilled = true;
		Infile >> F1 >> F2 >> F3;
		color C2(F1, F2, F3);
		ShpGfxInfo.FillClr = C2;
	}
	else
	{
		ShpGfxInfo.isFilled = false;
	}

}


