#pragma once   
#include "Shape.h"
#include "Square.h"

class Group: public shape
{
private:
	vector <shape*> groupshapesList; //a container to hold all shapes							   
	//vector<shape*> groupselectedShapes;
public:
	Group(vector <shape*> groupshapesListt);
	~Group();
		

	virtual void Draw(GUI* pUI) const;		
	virtual string Getinfo() const ; 
	void ChngDrawClr(color Dclr);	
	bool isshapein(shape*);

	void ChngFillClr(color Fclr);	
	void ungroup();
	virtual bool Get(int x, int y) const ; 

	virtual void Rotate();	
	virtual void Move(int x, int y) ;		
	vector<shape*> getgroupshapes();
	
	virtual void Save(ofstream& OutFile) ;	
	virtual shape* Copy();					
	virtual void Load(ifstream& Infile) ;	
	virtual void RESIZE(double size) ;
	virtual void stick(GUI* pUI)const;

};