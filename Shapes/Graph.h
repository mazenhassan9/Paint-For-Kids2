#pragma once
#include "Shape.h"
#include "Group.h"
#include <fstream>
#include <vector>
<<<<<<< Updated upstream
#include <stack>
=======
<<<<<<< HEAD
=======
#include <stack>
>>>>>>> ec3dffe11c86db3ae37b9fcedf38190f298cbe1c
>>>>>>> Stashed changes

using namespace std;

//forward decl
class GUI;	

//A class that is responsible on everything related to shapes
class Graph
{
private:
	vector <shape*> shapesList; //a container to hold all shapes							   
	vector<shape*> selectedShapes;	//pointer to the currently selected shape
	vector<Group*> grouplist;
	vector<operationType> operations; 
	shape* copiedshape;
	vector<shape*>deletedShapes, modifiedShapes; 
	
public:										
	Graph();
	~Graph();
	void AddOperation(operationType op);
	
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void AddsGroup(Group* pShp);
	void DeleteShape(shape* pFig);
	void DeleteGroup(Group* pFig);
	void SetSelected(shape* pFig,bool flag); //set Selected pointer to a select.
	vector<shape*> GetSelected();
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape
	vector <shape*> getlistofshspes();
	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
	shape* getcopied()const;
	void setcopied(shape* cs);
	void mapshapes(GUI* pUI);


	void mapshapes(GUI* pUI);
	shape* GetLastSelected() const;
	operationType GetlastOperation() const;
	shape* GetLastDeleted();
	shape* GetLastModified();
	void Add(vector<shape*>, shape*);	//generic function to add shape in a ceration vector
	void Delete(vector<shape*>, shape*); //generic function to delete shape in a ceration vector
	void SendBack(shape* pFig);

};
