#include "Graph.h"
#include "../GUI/GUI.h"
#include<fstream>

Graph::Graph()
{
	selectedShape = nullptr;
}

Graph::~Graph()
{
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
void Graph::SetSelected(shape* pFig, bool flag)
{
	if (flag)
	{
		if (selectedShape)
		{
			selectedShape->SetSelected(false);
		}
		selectedShape = pFig;
	}
	else
	{
		
		selectedShape = nullptr;
	}

}
shape* Graph::GetSelected() const
{
	return selectedShape;
}
////////////////////////////////////////////////////////////////////////////////////
//Draw all shapes on the user interface
void Graph::Draw(GUI* pUI) const
{
	pUI->ClearDrawArea();
	for (auto shapePointer : shapesList)
		shapePointer->Draw(pUI);
}
vector <shape*>Graph::getlistofshspes()
{
	return shapesList;
}

void Graph::Save(ofstream& outfile)
{
	outfile << shapesList[0]->Get_Count() << endl;
	for (auto& itr : shapesList)
	{
		outfile << itr->Getinfo() << endl;
	}
}

void Graph::load(ifstream& inputfile)
{
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
