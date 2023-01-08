#include "Group.h"
#include "../GUI/GUI.h"
#include<fstream>
#include <iostream>
#include"Circle.h"
#include"Line.h"
#include"Oval.h"
#include"Polygon.h"
#include"Rect.h"
#include"Square.h"
#include"Triangle .h"

Group::Group(vector<shape*> groupshapesListt):groupshapesList(groupshapesListt)
{

}

Group::Group()
{
}

Group::~Group()
{
	//while (groupshapesList.size() != 0)
	//{
	//	delete* groupshapesList.begin();
	//	groupshapesList.erase(groupshapesList.begin());
	//}
}

void Group::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	groupshapesList.push_back(pShp);
}


void Group::ChngDrawClr(color Dclr)
{
	for (auto& itr : groupshapesList)
	{
		itr->ChngDrawClr(Dclr);
	}
}

bool Group::isshapein(shape*shp)
{
	for (auto& itr : groupshapesList)
	{
		if (itr == shp)
		{
			return true;
		}
	}
	return false;
}



void Group::Draw(GUI* pUI) const
{
	for (auto& itr : groupshapesList)
	{
		itr->Draw(pUI);
	}

}

string  Group::Getinfo() const
{
	string s = "";
	for (auto& itr : groupshapesList)
	{
		s+=itr->Getinfo();
	}
	return s;
}

void Group::ungroup()
{
	groupshapesList.clear();
}

void  Group::ChngFillClr(color Fclr)
{
	for (auto& itr : groupshapesList)
	{
		itr->ChngFillClr(Fclr);
	}

}

bool  Group::Get(int x, int y) const
{
	return 0;
}

Point Group::GetFirstPoint() const
{
	return Point();
}

void  Group::Rotate()
{
	for (auto& itr : groupshapesList)
	{
		itr->Rotate();
	}
}
void  Group::Move(int x, int y)
{
	for (auto& itr : groupshapesList)
	{
		itr->Move(x,y);
	}

}
vector<shape*> Group::getgroupshapes()
{
	return groupshapesList;
}
void  Group::Save(ofstream& OutFile)
{
	OutFile << "Group\n";
	for (auto& itr : groupshapesList)
	{
		itr->Save(OutFile);
	}
}
shape* Group::Copy()
{
	vector <shape*> sp;
	
	for (auto& itr : groupshapesList)
	{
		sp.push_back(itr->Copy());
	}
	shape* S = new Group(sp);
	return S;
}
void  Group::Load(ifstream& Infile)
{
	for (auto& itr : groupshapesList)
	{
		itr->Load(Infile);
	}
}
void  Group::RESIZE(double size)
{
	for (auto& itr : groupshapesList)
	{
		itr->RESIZE(size);
	}

}
void Group::setBorderwidth(double bw)
{
	for (auto& itr : groupshapesList)
	{
		itr->setBorderwidth(bw);
	}
}

void Group::stick(GUI* pUI) const
{

}
void Group::mapshape(GUI* pUI)
{

}
void Group::DuplicateGraph() {}
