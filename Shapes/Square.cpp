#include "Square.h"

Square::Square(Point P1, double sidelen, GfxInfo shapeGfxInfo) :shape(shapeGfxInfo)
{
	origin = P1;
	sidelent = sidelen;
}

Square::~Square()
{}

void Square::Draw(GUI* pUI) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pUI->DrawSquare(origin,sidelent , ShpGfxInfo);
}

bool Square::Get(int x, int y) const
{
	Point Corner2 = { origin.x + sidelent,origin.y + sidelent };
	Point Corner1 = origin;

	if (((x >= Corner1.x && x <= Corner2.x) || (x <= Corner1.x && x >= Corner2.x)) &&
		((y >= Corner1.y && y <= Corner2.y) || (y <= Corner1.y && y >= Corner2.y)))
		return true;
	return false;
}

string Square::Getinfo() const
{

	string FillColor;
	if (ShpGfxInfo.isFilled)
		FillColor = "Filled  Color R: " + to_string(ShpGfxInfo.FillClr.ucRed) + " G: " + to_string(ShpGfxInfo.FillClr.ucGreen) + " B: " + to_string(ShpGfxInfo.FillClr.ucBlue);
	else
		FillColor = "Non_Filled";
	ShpGfxInfo.DrawClr.ucRed;

	string message = "Square   " + to_string(ID) + "    Center (" + to_string(origin.x) + " , " + to_string(origin.y) + ")"
		+ "    Sidelen (" + to_string(sidelent) + " , " + to_string(sidelent) + ")"
		+ "    Drawing Color R: " + to_string(ShpGfxInfo.DrawClr.ucRed) + " G: " + to_string(ShpGfxInfo.DrawClr.ucGreen) + " B: " + to_string(ShpGfxInfo.DrawClr.ucBlue)
		+ "   " + FillColor;
	return message;
}

