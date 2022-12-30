#include "Circle.h"
Circle::Circle()
{
	ShpGfxInfo.isFilled = false;
	ShpGfxInfo.isSelected = false;

}
Circle::Circle(Point circenter, Point radius, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	center = circenter;
	Corner = radius;
}

Circle::~Circle()
{}

void Circle::Draw(GUI* pUI) const
{
	//Call Output::DrawCir to draw a circle on the screen	
	pUI->DrawCir(center, Corner, ShpGfxInfo);
}

bool Circle::Get(int x, int y) const
{
	int radius = sqrt(pow((center.x - Corner.x), 2) + pow((center.y - Corner.y), 2));

	int pDistance = sqrt(pow((center.x - x), 2) + pow((center.y - y), 2));

	if (pDistance <= radius)
		return true;

	return false;
}

void Circle::Move(int x, int y)
{
	int radius = sqrt(pow((center.x - Corner.x), 2) + pow((center.y - Corner.y), 2));
	this->center.x = x;
	this->center.y = y;
	this->Corner.x = this->center.x + radius;
	this->Corner.y = this->center.y;
}

void Circle::Rotate()
{
}

string Circle::Getinfo() const
{
	string FillColor;
	if (ShpGfxInfo.isFilled)
		FillColor = "Filled  Color R: " + to_string(ShpGfxInfo.FillClr.ucRed) + " G: " + to_string(ShpGfxInfo.FillClr.ucGreen) + " B: " + to_string(ShpGfxInfo.FillClr.ucBlue);
	else
		FillColor = "Non_Filled";
	ShpGfxInfo.DrawClr.ucRed;
	int radius = sqrt(pow((center.x - Corner.x), 2) + pow((center.y - Corner.y), 2));

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
