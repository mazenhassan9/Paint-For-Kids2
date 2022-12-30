#include "Square.h"

Square::Square()
{
	ShpGfxInfo.isFilled = false;
	ShpGfxInfo.isSelected = false;

}

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

void Square::Move(int x, int y)
{
	Point Corner2 = { origin.x + sidelent,origin.y + sidelent };
	Point Corner1 = origin;

	//need to solve the sidelen problem.
	int centerx, centery;
	centerx = (Corner1.x + Corner2.x) / 2;
	centery = (Corner1.y + Corner2.y) / 2;
	Corner1.x += x - centerx;
	Corner1.y += y - centery;

	Corner2.x += x - centerx;
	Corner2.y += y - centery;

	this->origin = Corner1;
	this->sidelent = sqrt(pow(Corner2.x - this->origin.x, 2));
}

void Square::Rotate()
{
}

string Square::Getinfo() const
{

	string FillColor;
	if (ShpGfxInfo.isFilled)
		FillColor = "Filled  Color R: " + to_string(ShpGfxInfo.FillClr.ucRed) + " G: " + to_string(ShpGfxInfo.FillClr.ucGreen) + " B: " + to_string(ShpGfxInfo.FillClr.ucBlue);
	else
		FillColor = "Non_Filled";

	string message = "Square   " + to_string(ID) + "    Center (" + to_string(origin.x) + " , " + to_string(origin.y) + ")"
		+ "    Sidelen (" + to_string(sidelent) + " , " + to_string(sidelent) + ")"
		+ "    Drawing Color R: " + to_string(ShpGfxInfo.DrawClr.ucRed) + " G: " + to_string(ShpGfxInfo.DrawClr.ucGreen) + " B: " + to_string(ShpGfxInfo.DrawClr.ucBlue)
		+ "   " + FillColor;
	return message;
}

void Square::Save(ofstream& OutFile)
{
	Point Corner2 = { origin.x + sidelent,origin.y + sidelent };
	Point Corner1 = origin;
	OutFile << "SQUARE  " << ID << "  " << Corner1.x << "  " << Corner1.y << "  " << Corner2.x << "  " << Corner2.y << "  ";
	OutFile << (int)(ShpGfxInfo.DrawClr.ucRed) << "  " << (int)ShpGfxInfo.DrawClr.ucGreen << "  " << (int)ShpGfxInfo.DrawClr.ucBlue << "  ";
	if (ShpGfxInfo.isFilled != false)
		OutFile << "True" << "  " << (int)ShpGfxInfo.FillClr.ucRed << "  " << (int)ShpGfxInfo.FillClr.ucGreen << "  " << (int)ShpGfxInfo.FillClr.ucBlue << endl;
	else
		OutFile << "False" << endl;
}

void Square::Load(ifstream& Infile)
{
	Point Corner1, Corner2;
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y ;
	origin = Corner1;
	sidelent = sqrt(pow(Corner2.x - origin.x, 2));

	int D1, D2, D3;
	int F1, F2, F3;

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


