#include "Circle.h"

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
