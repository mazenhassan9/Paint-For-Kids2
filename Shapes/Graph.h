#pragma once
#include "Shape.h"
#include "Group.h"
#include <fstream>
#include <vector>


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
	vector<operationType> UndoOperations;
	shape* copiedshape;
	vector<shape*>deletedShapes, modifiedShapes; 
	vector<shape*>deletedShapesUndo, modifiedShapesUndo;
public:										
	Graph();
	~Graph();
	
	vector <shape*> getlistofshspes();
	void Addshape(shape* pFig); //Adds a new shape to the shapesList
	void AddsGroup(Group* pShp);
	void DeleteShape(shape* pFig);
	void DeleteGroup(Group* pFig);


	void SetSelected(shape* pFig,bool flag); //set Selected pointer to a select.
	vector<shape*> GetSelected();
	shape* Getshape(int x, int y) const; //Search for a shape given a point inside the shape
	shape* GetLastSelected() const;

	
	void Draw(GUI* pUI) const;			//Draw the graph (draw all shapes)
	
	
	void Save(ofstream& outfile);	//Save all shapes to a file
	void load(ifstream& inputfile);	//Load all shapes from a file
	shape* getcopied()const;
	void setcopied(shape* cs);
	void mapshapes(GUI* pUI);
	void SendBack(shape* pFig);
	void HideAll(bool s);
	void DuplicateGraph();
	int matchshapes();
	bool UnHideone(int x, int y, GUI* pGUI);

	//Undo Functions
	void AddOperation(operationType op);
	operationType GetlastOperation();
	shape* GetLastAdded();
	shape* GetLastDeleted();	//shapes before deleted.
	shape* GetLastModified(); //shapes state before modification
	void AddDeletedShape(shape*pShp, bool s);
	void AddModifiedShape(shape* pShp, bool s);
	

	//Redo Functions
	void AddOperationUndo(operationType op);
	operationType GetLastUndo();
	shape* GetLastDeletedUndo();	//shapes before deleted.
	shape* GetLastModifiedUndo();
	void AddDeletedShapeUndo(shape* pShp, bool s);
	void AddModifiedShapeUndo(shape* pShp, bool s);
};
