#pragma once
#include "..\defs.h"
#include "..\GUI\GUI.h"
#include<fstream>

//Base class for all shapes
class shape
{
protected:
	int ID;		//Each shape has an ID
	GfxInfo ShpGfxInfo;	//shape graphis info
	static int Shapes_Count;
	/*bool Issaved;*/
	/// Add more parameters if needed.
	bool isHidden, isStick;

public:
	shape();
	shape(GfxInfo shapeGfxInfo);
	//shape (const shape & n);
	virtual ~shape() {}

	int GetID() const;
	void SetSelected(bool s);	//select/unselect the shape
	bool IsSelected() const;	//check whether fig is selected
	void SetSticked(bool s);
	bool IsSticked() const;
	virtual void stick(GUI* pUI) const = 0;
	virtual void Draw(GUI* pUI) const  = 0 ;		//Draw the shape
	virtual string Getinfo() const = 0;  	//print all figure info on the status bar
	virtual Point GetFirstPoint() const = 0;
	GfxInfo getGraphics();
	int getID();

	virtual void ChngDrawClr(color Dclr);	//changes the shape's drawing color
	virtual void ChngFillClr(color Fclr);	//changes the shape's filling color
	virtual void setBorderwidth(double bw);
	static int Get_Count();

	virtual void mapshape(GUI* pUI) = 0;


	///The following functions should be supported by the shape class
	///It should be overridden by each inherited shape

	///Decide the parameters that you should pass to each function	
	virtual bool Get(int x, int y) const = 0; // Function to check if the point inside the shape.

	virtual void Rotate() = 0;	//Rotate the shape
	//virtual void Resize() = 0;	//Resize the shape
	virtual void Move(int x,int y) = 0;		//Move the shape

	virtual void Save(ofstream &OutFile) = 0;	//Save the shape parameters to the file
	virtual shape* Copy() = 0;					//Copy the shape parameters to the file
	virtual void Load(ifstream& Infile) = 0;	//Load the shape parameters to the file
	virtual void RESIZE(double size) = 0;
	void Hide(bool s);					
	bool HiddenItems();
	virtual void DuplicateGraph()=0;
};