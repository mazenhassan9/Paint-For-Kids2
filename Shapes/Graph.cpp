#include "Graph.h"
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

Graph::Graph()
{

}

Graph::~Graph()
{
	while (shapesList.size() != 0)
	{
		delete* shapesList.begin();
		shapesList.erase(shapesList.begin());
	}
	while (selectedShapes.size() != 0)
	{
		delete* selectedShapes.begin();
		selectedShapes.erase(selectedShapes.begin());
	}
}

void Graph::AddOperation(operationType op)
{
	operations.push_back(op);
}

operationType Graph::GetlastOperation() 
{
	if (!operations.empty())
	{
		operationType r = operations.back();
		operations.pop_back();
		return r;
	}
	
}

shape* Graph::GetLastAdded()
{
	if (!shapesList.empty())
	{
		shape* output = shapesList.back()->Copy();
		shapesList.pop_back();
		return output;
	}
}

//==================================================================================//
//						shapes Management Functions								//
//==================================================================================//

//Add a shape to the list of shapes
void Graph::Addshape(shape* pShp)
{
	//Add a new shape to the shapes vector
	shapesList.push_back(pShp);	
}


void Graph::AddsGroup(Group* pShp)
{
	//Add a new shape to the shapes vector
	grouplist.push_back(pShp);
}
void Graph::DeleteShape(shape* pFig)
{
	int i = 0;
	for (auto& itr : shapesList)
	{
		
		if (pFig == itr)
		{
			shapesList[i] = shapesList.back(); 
			shapesList.pop_back();
		}
		i++;
	}

}

void Graph::DeleteGroup(Group* pFig)
{
	int i = 0;
	for (auto& itr : grouplist)
	{

		if (pFig == itr)
		{
			grouplist[i] = grouplist.back();
			grouplist.pop_back();
			vector<shape*>se = itr->getgroupshapes();
			for (auto& itr : se)
			{
				this->DeleteShape(itr);
			}

		}
		i++;
	}

}
void Graph::SetSelected(shape* pFig, bool flag)
{
	if (flag)
	{
		
		selectedShapes.push_back(pFig);
	}
	else
	{
		int i = 0;
		for (auto& itr : selectedShapes)
		{

			if (pFig == itr)
			{
				selectedShapes[i] = selectedShapes.back();
				selectedShapes.pop_back();
			}
			i++;
		}
		
	}

}
shape* Graph::GetLastSelected() const
{
	if (selectedShapes.size() != 0)
	{
		if (grouplist.size() != 0)
		{
			for (auto& itr : grouplist)
			{
				if (itr->isshapein(selectedShapes[selectedShapes.size() - 1]))
					return itr;
			}
		}
		return selectedShapes[selectedShapes.size()-1];
	}
	else
		return nullptr;
}
vector<shape*> Graph::GetSelected() 
{
	return selectedShapes;
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	int Img_width=62, Img_Height=100;

	string img = "images\\card.jpg";
	Point P;
	pUI->ClearDrawArea();
	for (auto& shapePointer : shapesList)
	{
		if (!shapePointer->HiddenItems())
		{
			shapePointer->Draw(pUI);
			
		}
		else
		{
			shapePointer->SetSticked(false);
			P = shapePointer->GetFirstPoint();
			if(P.x)
				pUI->DrawImg(img, P.x, P.y, Img_width, Img_Height);
		}
		if (shapePointer->IsSticked())
			shapePointer->stick(pUI);
	}
}


vector <shape*>Graph::getlistofshspes()
{
	return shapesList;
}

void Graph::Save(ofstream& outfile)
{
	outfile << shapesList.size() << endl;
	bool flag = 0;
	for (auto& itr : shapesList)
	{
		flag = 0;
		for (auto& group: grouplist)
		{
			if (group->isshapein(itr))
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
			itr->Save(outfile);
	}
	for (auto& itr : grouplist)
	{
		itr->Save(outfile);
	}
}

void Graph::load(ifstream& inputfile)
{
	string name;
	int Scount;
	shape* R;
	Group* g=nullptr;
	grouplist.clear();
	shapesList.clear();
	//Load Figures Count	
	inputfile >> Scount;

	while(inputfile >> name)
	{
		if (name == "Group")
		{
			g = new Group;
			AddsGroup(g);
		}
		else if (name == "CIRCLE")
			R = new Circle;
		else if (name == "LINE")
			R = new Line;
		else if (name == "OVAL")
			R = new Oval;
		else if (name == "POLYGON")
			R = new polygon;
		else if (name == "RECT")
			R = new Rect;
		else if (name == "SQUARE")
			R = new Square;
		else if (name == "TRIANGLE")
			R = new Triangle;
		
		if (R)
		{
			R->Load(inputfile);
			Addshape(R);
			if (g)
				g->Addshape(R);
			R = NULL;
		}
		
	}
}

shape* Graph::getcopied() const
{
	return copiedshape;
}

void Graph::setcopied(shape* cs)
{
	copiedshape = cs;
}

shape* Graph::GetLastDeleted() 
{
	shape* output = deletedShapes.back()->Copy();
	deletedShapes.pop_back();
	return output;
}

shape* Graph::GetLastModified() 
{
	shape* output = modifiedShapes.back()->Copy();
	modifiedShapes.pop_back();
	return output;
}

void Graph::AddDeletedShape(shape* pShp, bool s)
{
	if (s)
	{
		deletedShapes.push_back(pShp);
	}
	else
	{
		int i = 0;
		for (auto& itr : deletedShapes)
		{

			if (pShp == itr)
			{
				deletedShapes[i] = deletedShapes.back();
				deletedShapes.pop_back();
			}
			i++;
		}

	}
}

void Graph::AddModifiedShape(shape* pShp, bool s)
{
	if (s)
	{
		modifiedShapes.push_back(pShp);
	}
	else
	{
		int i = 0;
		for (auto& itr : modifiedShapes)
		{

			if (pShp == itr)
			{
				modifiedShapes[i] = modifiedShapes.back();
				modifiedShapes.pop_back();
			}
			i++;
		}

	}
}





void Graph::SendBack(shape* pFig)
{
}

void Graph::HideAll(bool s)
{
	for (auto& itr : shapesList)
	{
		itr->Hide(s);
	}
}

shape* Graph::Getshape(int x, int y) const
{
	//If a shape is found return a pointer to it.
	//if this point (x,y) does not belong to any shape return NULL


	///Add your code here to search for a shape given a point x,y	
	for (auto& itr : shapesList)
	{
		if (itr->Get(x, y))

		{
			return itr;
		}
	}

	return nullptr;
}

void Graph::mapshapes(GUI* pUI)
{
	for (auto& itr : shapesList)
	{
		itr->mapshape(pUI);
	}

}


void Graph::DuplicateGraph() {
	for (auto& itr : shapesList)
	{
		itr->DuplicateGraph();
	}
}






