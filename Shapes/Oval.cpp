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

Oval::Oval(const Oval* lhs)
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

Oval::~Oval()
{}

void Oval::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawOval(P1, P2, ShpGfxInfo);
}

void Oval::stick(GUI* pUI) const
{

	int x = min(P1.x, P2.x);
	int y = min(P1.y, P2.y);
	int width = sqrt(pow((P2.x - P1.x), 2));
	int height = sqrt(pow((P2.y - P1.y), 2));
	string img = "images\\MenuIcons\\Menu_Oval.jpg";
	pUI->DrawImg(img, x, y, width, height);
	
}

bool Oval::Get(int x, int y) const
{

	if (((x >= P1.x && x <= P2.x) || (x <= P1.x && x >= P2.x)) &&
		((y >= P1.y && y <= P2.y) || (y <= P1.y && y >= P2.y)))
		return true;
	return false;
}

Point Oval::GetFirstPoint() const
{
	int x = min(P1.x, P2.x);
	int y = min(P1.y, P2.y);
	Point P1 = { x,y };
	return P1;
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

void Oval::Rotate()
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
void Oval::RESIZE(double size) 
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

shape* Oval::Copy()
{
	shape* S = new Oval(this);
	return S;
}

 void Oval::mapshape(GUI* pUI)
{
	pUI->Mapx(P1.x);
	pUI->Mapx(P2.x);
	pUI->Mapy(P1.y);
	pUI->Mapy(P2.y);
}

 void Oval::DuplicateGraph() {

 }