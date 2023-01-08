#include "Circle.h"
#include <iostream>
Circle::Circle()
{
	ShpGfxInfo.isFilled = false;
	ShpGfxInfo.isSelected = false;
	center.x = 0;
	Corner.x = 0;
	center.y = 0;
	Corner.y = 0;

}
Circle::Circle(Point circenter, Point radius, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center = circenter;
	Corner = radius;
}

Circle::Circle(const Circle* lhs) 
{
	this->ID = lhs->ID;
	this->center.x = lhs->center.x;
	this->Corner.x = lhs->Corner.x;
	this->center.y = lhs->center.y;
	this->Corner.y = lhs->Corner.y;
	this->ShpGfxInfo.DrawClr = lhs->ShpGfxInfo.DrawClr;
	this->ShpGfxInfo.FillClr = lhs->ShpGfxInfo.FillClr;
	this->ShpGfxInfo.isFilled = lhs->ShpGfxInfo.isFilled;
	this->ShpGfxInfo.BorderWdth = lhs->ShpGfxInfo.BorderWdth;
	this->ShpGfxInfo.isSelected = false;

}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawCir to draw a circle on the screen	
	pUI->DrawCir(center, Corner, ShpGfxInfo);
}

void Circle::stick(GUI* pUI) const
{
	int radius = sqrt(pow((center.x - Corner.x), 2) + pow((center.y - Corner.y), 2)) / 2;
	int x = center.x - radius;
	int y = center.y - radius;
	string img = "images\\MenuIcons\\Menu_Circle.jpg";
	pUI->DrawImg(img,x,y,(2*radius),(2*radius));
	
}



bool Circle::Get(int x, int y) const
{
	int radius = sqrt(pow((center.x - Corner.x), 2) + pow((center.y - Corner.y), 2)) / 2;

	int pDistance = sqrt(pow((center.x - x), 2) + pow((center.y - y), 2));

	if (pDistance <= radius)
		return true;

	return false;
}

void Circle::Move(int x, int y)
{
	int radius = sqrt(pow((center.x - Corner.x), 2) + pow((center.y - Corner.y), 2)) / 2;
	this->center.x = x;
	this->center.y = y;
	this->Corner.x = this->center.x + radius;
	this->Corner.y = this->center.y;
}

void Circle::Rotate()
{

	// get the center point location 
	double x1, x2, y1, y2;
	int centerx, centery;
	centerx = center.x ;
	centery = center.y ;


	double PI = 3.14;



	x1 = center.x - centerx;
	x2 = Corner.x - centerx;
	y1 = center.y - centery;
	y2 = Corner.y - centery;

	cout << " X1 " << center.x << " Y1 " << center.y << " X2 " << Corner.x << " Y2 " << Corner.y << endl;

	this->center.x = (x1 * cos(PI / 2) - y1 * sin(PI / 2)) + centerx;	//5
	this->center.y = (x1 * sin(PI / 2) + y1 * cos(PI / 2)) + centery;		//3

	this->Corner.x = (x2 * cos(PI / 2) - y2 * sin(PI / 2)) + centerx;	//3
	this->Corner.y = (x2 * sin(PI / 2) + y2 * cos(PI / 2)) + centery;	//4

	cout << " X1 " << center.x << " Y1 " << center.y << " X2 " << Corner.x << " Y2 " << Corner.y << endl;

	// x = x * cos(degrees in radians) - y * sin(degrees in radians)
	// y = y * cos(degrees in radians) + x * sin(degrees in radians)




}

string Circle::Getinfo() const
{
	string FillColor;
	if (ShpGfxInfo.isFilled)
		FillColor = "Filled  Color R: " + to_string(ShpGfxInfo.FillClr.ucRed) + " G: " + to_string(ShpGfxInfo.FillClr.ucGreen) + " B: " + to_string(ShpGfxInfo.FillClr.ucBlue);
	else
		FillColor = "Non_Filled";
	ShpGfxInfo.DrawClr.ucRed;
	int radius = sqrt(pow((center.x - Corner.x), 2) + pow((center.y - Corner.y), 2)) / 2;

	string message = "Circle   " + to_string(ID) + "    Center (" + to_string(center.x) + " , " + to_string(center.y)
		+ ")   Radius= " + to_string(radius)
		+ "    Drawing Color R: " + to_string(ShpGfxInfo.DrawClr.ucRed) + " G: " + to_string(ShpGfxInfo.DrawClr.ucGreen) + " B: " + to_string(ShpGfxInfo.DrawClr.ucBlue)
		+ "   " + FillColor;
	return message;
}

void Circle::Save(ofstream& OutFile)
{
	
	OutFile << "CIRCLE  " << ID << "  " << center.x << "  " << center.y << "  " << Corner.x << "  " << Corner.y << "  ";
	OutFile << (int)(ShpGfxInfo.DrawClr.ucRed) << "  " << (int)ShpGfxInfo.DrawClr.ucGreen << "  " << (int)ShpGfxInfo.DrawClr.ucBlue << "  ";
	if (ShpGfxInfo.isFilled != false)
		OutFile << "True" << "  " << (int)ShpGfxInfo.FillClr.ucRed << "  " << (int)ShpGfxInfo.FillClr.ucGreen << "  " << (int)ShpGfxInfo.FillClr.ucBlue << endl;
	else
		OutFile << "False" << endl;
}

void Circle::Load(ifstream& Infile)
{
	int D1, D2, D3;
	int F1, F2, F3;

	Infile >> ID >> center.x >> center.y >> Corner.x >>  Corner.y;
	Infile >> D1 >> D2 >> D3;
	color C1(D1, D2, D3);
	ShpGfxInfo.DrawClr = C1;
	string conditon;
	Infile >> conditon;
	if (conditon == "True")
	{
		ShpGfxInfo.isFilled = true;
		Infile >> F1 >>F2 >> F3;
		color C2(F1, F2, F3);
		ShpGfxInfo.FillClr = C2;
	}
	else
	{
		ShpGfxInfo.isFilled = false;
	}
}
void Circle::RESIZE(double size) 
{
	
	int radius = sqrt(pow((center.x - Corner.x), 2) + pow((center.y - Corner.y), 2)) / 2;

	this->Corner.x = this->center.x + (radius * size);
	this->Corner.y = this->center.y;
}

shape* Circle::Copy()
{
	shape* S = new Circle(this);
	return S;
}
void Circle::mapshape(GUI* pUI)
{
	pUI->Mapx(center.x);
	pUI->Mapx(Corner.x);
	pUI->Mapy(center.y);
	pUI->Mapy(Corner.y);
}



void Circle::DuplicateGraph() {

}

Point Circle::GetFirstPoint() const
{
	int radius = sqrt(pow((center.x - Corner.x), 2) + pow((center.y - Corner.y), 2)) / 2;
	int x = center.x - radius;
	int y = center.y - radius;
	Point P1 = { x,y };
	return P1;
}
