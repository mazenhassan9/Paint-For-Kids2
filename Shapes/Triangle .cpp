#include "Triangle .h"
#include"iostream"

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

Triangle::Triangle(const Triangle* lhs)
{
	this->ID = lhs->ID;

	this->Corner1.x = lhs->Corner1.x;
	this->Corner2.x = lhs->Corner2.x;
	this->Corner1.y = lhs->Corner1.y;
	this->Corner2.y = lhs->Corner2.y;
	this->Corner3.x = lhs->Corner3.x;
	this->Corner3.y = lhs->Corner3.y;
	this->ShpGfxInfo.DrawClr = lhs->ShpGfxInfo.DrawClr;
	this->ShpGfxInfo.FillClr = lhs->ShpGfxInfo.FillClr;
	this->ShpGfxInfo.isFilled = lhs->ShpGfxInfo.isFilled;
	this->ShpGfxInfo.BorderWdth = lhs->ShpGfxInfo.BorderWdth;
	this->ShpGfxInfo.isSelected = false;
}

Triangle::~Triangle()
{
}

void Triangle::Draw(GUI* pUI) const
{
	pUI->DrawTri(Corner1, Corner2 , Corner3 , ShpGfxInfo);
}

void Triangle::stick(GUI* pUI) const
{
	int height, width,x,y;
	int height1 = sqrt(pow((Corner2.y - Corner1.y), 2));
	int height2 = sqrt(pow((Corner3.y - Corner1.y), 2));
	int height3 = sqrt(pow((Corner3.y - Corner2.y), 2));

	int width1 = sqrt(pow((Corner1.x - Corner2.x), 2));
	int width2 = sqrt(pow((Corner3.x - Corner2.x), 2));
	int width3 = sqrt(pow((Corner3.x - Corner1.x), 2));
	width = max(max(width1, width2), width3);
	height = max(max(height1,height2),height3);
	x = min(min(Corner1.x, Corner2.x),Corner3.x);
	y = min(min(Corner1.y, Corner2.y), Corner3.y);
	string img = "images\\MenuIcons\\Menu_Tri.jpg";
	pUI->DrawImg(img, x, y, width+1, height+1);
}

bool Triangle::Get(int x, int y) const
{
	double denominator = ((Corner2.y - Corner3.y) * (Corner1.x - Corner3.x) + (Corner3.x - Corner2.x) * (Corner1.y - Corner3.y));
	double a = ((Corner2.y - Corner3.y) * (x - Corner3.x) + (Corner3.x - Corner2.x) * (y - Corner3.y)) / denominator;
	double b = ((Corner3.y - Corner1.y) * (x - Corner3.x) + (Corner1.x - Corner3.x) * (y - Corner3.y)) / denominator;
	double c = 1 - a - b;
	return (0 <= a && a <= 1 && 0 <= b && b <= 1 && 0 <= c && c <= 1);
}

Point Triangle::GetFirstPoint() const
{
	int x = min(min(Corner1.x, Corner2.x), Corner3.x);
	int y = min(min(Corner1.y, Corner2.y), Corner3.y);
	Point P1 = { x,y };
	return P1;
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

void Triangle::Move(int x, int y)
{
	int centerx, centery;
	centerx = (Corner1.x + Corner2.x + Corner3.x) / 3;
	centery = (Corner1.y + Corner2.y + Corner3.y) / 3;
	this->Corner1.x += x - centerx;
	this->Corner1.y += y - centery;

	this->Corner2.x += x - centerx;
	this->Corner2.y += y - centery;

	this->Corner3.x += x - centerx;
	this->Corner3.y += y - centery;

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
shape* Triangle::Copy()
{
	shape* S = new Triangle(this);
	return S;
}
void Triangle::Rotate()
{

	// get the center point location 
	double x1, x2,x3, y1, y2,y3;
	int centerx, centery;
	centerx = (Corner1.x + Corner2.x + Corner3.x) / 3;
	centery = (Corner1.y + Corner2.y + Corner3.y) / 3;


	double PI = 3.14;



	x1 = Corner1.x - centerx;
	x2 = Corner2.x - centerx;
	x3 = Corner3.x - centerx;
	y1 = Corner1.y - centery;
	y2 = Corner2.y - centery;
	y3 = Corner3.y - centery;

	cout << " X1 " << Corner1.x << " Y1 " << Corner1.y << " X2 " << Corner2.x << " Y2 " << Corner2.y << endl;

	Corner1.x = (x1 * cos(PI / 2) - y1 * sin(PI / 2)) + centerx;	//5
	Corner1.y = (x1 * sin(PI / 2) + y1 * cos(PI / 2)) + centery;		//3

	Corner2.x = (x2 * cos(PI / 2) - y2 * sin(PI / 2)) + centerx;	//3
	Corner2.y = (x2 * sin(PI / 2) + y2 * cos(PI / 2)) + centery;	//4

	Corner3.x = (x3 * cos(PI / 2) - y3 * sin(PI / 2)) + centerx;	//3
	Corner3.y = (x3 * sin(PI / 2) + y3 * cos(PI / 2)) + centery;

	cout << " X1 " << Corner1.x << " Y1 " << Corner1.y << " X2 " << Corner2.x << " Y2 " << Corner2.y << endl;

	// x = x * cos(degrees in radians) - y * sin(degrees in radians)
	// y = y * cos(degrees in radians) + x * sin(degrees in radians)




}

void Triangle::RESIZE(double size) {
	int centerx, centery;
	centerx = (Corner1.x + Corner2.x + Corner3.x) / 3;
	centery = (Corner1.y + Corner2.y + Corner3.y) / 3;

	this->Corner1.x *= size;
	this->Corner1.y *= size;

	this->Corner2.x *= size;
	this->Corner2.y *= size;

	this->Corner3.x *= size;
	this->Corner3.y *= size;

	this->Move(centerx, centery);
}

void Triangle::mapshape(GUI* pUI)
{
	

	pUI->Mapx(Corner1.x);
	pUI->Mapx(Corner2.x);
	pUI->Mapx(Corner3.x);
	pUI->Mapy(Corner1.y);
	pUI->Mapy(Corner2.y);
	pUI->Mapy(Corner3.y);
}

void Triangle::DuplicateGraph(){}


