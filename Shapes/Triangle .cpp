#include "Triangle .h"


Triangle::Triangle()
{
	ShpGfxInfo.isFilled = false;
	ShpGfxInfo.isSelected = false;

}

Triangle::Triangle(Point p1, Point p2,Point p3 , GfxInfo shapeGfxInfo) : shape (shapeGfxInfo)
{
	Corner1 = p1;
	Corner2 = p2;
	Corner3 = p3;
	
}

Triangle::~Triangle()
{
}

void Triangle::Draw(GUI* pUI) const
{
	pUI->DrawTri(Corner1, Corner2 , Corner3 , ShpGfxInfo);
}

bool Triangle::Get(int x, int y) const
{
	double denominator = ((Corner2.y - Corner3.y) * (Corner1.x - Corner3.x) + (Corner3.x - Corner2.x) * (Corner1.y - Corner3.y));
	double a = ((Corner2.y - Corner3.y) * (x - Corner3.x) + (Corner3.x - Corner2.x) * (y - Corner3.y)) / denominator;
	double b = ((Corner3.y - Corner1.y) * (x - Corner3.x) + (Corner1.x - Corner3.x) * (y - Corner3.y)) / denominator;
	double c = 1 - a - b;
	return (0 <= a && a <= 1 && 0 <= b && b <= 1 && 0 <= c && c <= 1);
}

string Triangle::Getinfo() const
{
	string FillColor;
	if (ShpGfxInfo.isFilled)
		FillColor = "Filled  Color R: " + to_string(ShpGfxInfo.FillClr.ucRed) + " G: " + to_string(ShpGfxInfo.FillClr.ucGreen) + " B: " + to_string(ShpGfxInfo.FillClr.ucBlue);
	else
		FillColor = "Non_Filled";

	string message = "Triangle   " + to_string(ID) + "    Point1 (" + to_string(Corner1.x) + " , " + to_string(Corner1.y) + ")"
		+ "    Point2 (" + to_string(Corner2.x) + " , " + to_string(Corner2.y) + ")"
		+ "    Point3 (" + to_string(Corner3.x) + " , " + to_string(Corner3.y) + ")"
		+ "    Drawing Color R: " + to_string(ShpGfxInfo.DrawClr.ucRed) + " G: " + to_string(ShpGfxInfo.DrawClr.ucGreen) + " B: " + to_string(ShpGfxInfo.DrawClr.ucBlue)
		+ "   " + FillColor;
	return message;
}

void Triangle::Save(ofstream& OutFile)
{
	OutFile << "TRIANGLE  " << ID << "  " << Corner1.x << "  " << Corner1.y << "  " << Corner2.x << "  " << Corner2.y << "  " << Corner3.x << "  " << Corner3.y << "  ";
	OutFile << (int)(ShpGfxInfo.DrawClr.ucRed) << "  " << (int)ShpGfxInfo.DrawClr.ucGreen << "  " << (int)ShpGfxInfo.DrawClr.ucBlue << "  ";
	if (ShpGfxInfo.isFilled != false)
		OutFile <<"True" <<"  " << (int)ShpGfxInfo.FillClr.ucRed << "  " << (int)ShpGfxInfo.FillClr.ucGreen << "  " << (int)ShpGfxInfo.FillClr.ucBlue << endl;
	else
		OutFile << "False" << endl;
}

void Triangle::Load(ifstream& Infile)
{
	Infile >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y;
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


