#include "Rect.h"
#include <iostream>


Rect::Rect()
{
	ShpGfxInfo.isFilled = false;
	ShpGfxInfo.isSelected = false;

}

Rect::Rect(Point P1, Point P2, GfxInfo shapeGfxInfo):shape(shapeGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
}

Rect::~Rect()
{}

void Rect::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawRect(Corner1, Corner2, ShpGfxInfo);
}

bool Rect::Get(int x, int y) const
{
	if (((x >= Corner1.x && x <= Corner2.x) || (x <= Corner1.x && x >= Corner2.x)) &&
		((y >= Corner1.y && y <= Corner2.y) || (y <= Corner1.y && y >= Corner2.y)))
		return true;
	return false;
}

void Rect::Move(int x, int y)
{
	int centerx, centery;
	centerx = (Corner1.x + Corner2.x ) / 2;
	centery = (Corner1.y + Corner2.y) / 2;
	this->Corner1.x += x - centerx;
	this->Corner1.y += y - centery;

	this->Corner2.x += x - centerx;
	this->Corner2.y += y - centery;

}

string Rect::Getinfo() const
{
	string FillColor;
	if (ShpGfxInfo.isFilled)
		FillColor = "Filled  Color R: " + to_string(ShpGfxInfo.FillClr.ucRed) + " G: " + to_string(ShpGfxInfo.FillClr.ucGreen) + " B: " + to_string(ShpGfxInfo.FillClr.ucBlue);
	else
		FillColor = "Non_Filled";

	string message = "Rectangle   " + to_string(ID) + "    Point1 (" + to_string(Corner1.x) + " , " + to_string(Corner1.y) + ")"
		+ "    Point2 (" + to_string(Corner2.x) + " , " + to_string(Corner2.y) + ")"
		+ "    Drawing Color R: " + to_string(ShpGfxInfo.DrawClr.ucRed) + " G: " + to_string(ShpGfxInfo.DrawClr.ucGreen) + " B: " + to_string(ShpGfxInfo.DrawClr.ucBlue)
		+ "   " + FillColor;
	return message;
}

void Rect::Save(ofstream& OutFile)
{
	OutFile << "RECT  " << ID << "  " << Corner1.x << "  " << Corner1.y << "  " << Corner2.x << "  " << Corner2.y << "  ";
	OutFile << (int)(ShpGfxInfo.DrawClr.ucRed) << "  " << (int)ShpGfxInfo.DrawClr.ucGreen << "  " << (int)ShpGfxInfo.DrawClr.ucBlue << "  ";
	if (ShpGfxInfo.isFilled != false)
		OutFile << "True" << "  " << (int)ShpGfxInfo.FillClr.ucRed << "  " << (int)ShpGfxInfo.FillClr.ucGreen << "  " << (int)ShpGfxInfo.FillClr.ucBlue << endl;
	else
		OutFile << "False" << endl;
}

void Rect::Load(ifstream& Infile)
{
	int D1, D2, D3;
	int F1, F2, F3;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y;

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
void Rect::Rotate()
{
	
	// get the center point location 
	double x1, x2,y1 , y2;
	int centerx, centery;
	centerx = (Corner1.x + Corner2.x) / 2;
	centery = (Corner1.y + Corner2.y) / 2;

	
	double PI = 3.14;
	
	/*int w = Corner1.x - Corner2.x;
	int h = Corner1.y - Corner2.y;*/
	
	
	x1 = Corner1.x- centerx;
	x2 = Corner2.x- centerx;
	y1 = Corner1.y- centery;
	y2 = Corner2.y- centery;

	cout << " X1 " << Corner1.x << " Y1 " << Corner1.y << " X2 " << Corner2.x << " Y2 " << Corner2.y << endl;

	this->Corner1.x = (x1 * cos(PI/2) - y1 * sin(PI/2)) + centerx;	//5
	this->Corner1.y = (x1* sin(PI/2) + y1 * cos(PI/2)) + centery;		//3

	this->Corner2.x = (x2 * cos(PI/2) - y2 * sin(PI/2)) + centerx;	//3
	this->Corner2.y = (x2 * sin(PI/2) + y2 * cos(PI/2)) + centery;	//4

	cout << " X1 " << Corner1.x << " Y1 " << Corner1.y << " X2 " << Corner2.x << " Y2 " << Corner2.y << endl;

	// x = x * cos(degrees in radians) - y * sin(degrees in radians)
	// y = y * cos(degrees in radians) + x * sin(degrees in radians)


	

}
