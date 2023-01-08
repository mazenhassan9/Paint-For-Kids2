#pragma once



#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Defs.h"
#include <vector>
#include <string>
using namespace std;



struct Point	//To be used for shapes points
{
	int x, y;
};
struct line {
	Point p1, p2;
};

struct GfxInfo	//Graphical info common for all shapes (you may add more members)
{
	color DrawClr;	//Draw color of the shape
	color FillClr;	//Fill color of the shape
	bool isFilled;	//shape Filled or not
	int BorderWdth;	//Width of shape borders
	bool isSelected;	//true if the shape is selected.
	bool isHidden;
};




class GUI
{
	enum GUI_MODE	//Graphical user interface mode
	{
		MODE_DRAW,	//Drawing mode (startup mode)
		MODE_PLAY	//Playing mode
	};

	enum DrawMenuIcon //The icons of the Draw menu (you should add more icons)
	{
		//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		ICON_RECT,		//Recangle icon in menu
		ICON_CIRC, 		//Circle icon in menu 
		ICON_OVAL,
		ICON_TRI,
		ICON_LINE,
		ICON_SQUARE,
		ICON_Reg,
		ICON_Irreg,
		ICON_STICK,
		ICON_Fillcolor,
		ICON_Single_Fill,
		ICON_PENWIDTH,
		ICON_PEN,
		ICON_Borderwidth,
		ICON_Bordercolor,
		ICON_UNDO,
		ICON_Delete,
		ICON_COPY,
		ICON_CUT,
		ICON_PASTE,
		ICON_Resize,
		ICON_Rotate,
		Icon_Save,
		ICON_Load,
		ICON_ZOOM,
		ICON_SENDTOBACK,
		ICON_GROUP,
		ICON_UNGROUOP,
		ICON_DUPLICATE,
		ICON_SWITCH,
		
		
		ICON_EXIT,		//Exit icon






		//TODO: Add more icons names here


		DRAW_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};

	enum PlayMenuIcon //The icons of the Play menu (you should add more icons)
	{

		//TODO: Add more icons names here
		PLAY_ICON_FIGCOLOR,
		PLAY_ICON_BACKDRAW,
		PLAY_ICON_HIDE,



		PLAY_ICON_SWITCH,
		PLAY_ICON_EXIT,//Note: Icons are ordered here as they appear in menu
		//If you want to change the menu icons order, change the order here
		PLAY_ICON_COUNT		//no. of menu icons ==> This should be the last line in this enum

	};




	GUI_MODE InterfaceMode;

	int	width, height,	//Window width and height
		wx, wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuIconWidth;		//Width of each icon in toolbar menu

	int x0;
	int y0;
	int x1;
	int y1;

	int prevx0;
	int prevy0;
	int prevx1;
	int prevy1;


	int originalx0;
	int originaly0;
	int originalx1;
	int originaly1;

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;
	double Borderwidth;    //width of the pen that draws shapes
	bool defaultFill = 0;

	/// Add more members if needed



	window* pWind;

public:

	GUI();

	void GetLastClick(int& x, int& y) const;

	// Input Functions  ---------------------------
	void GetPointClicked(int& x, int& y) const;
	void GetLastKey(char& K) const;
	//Get coordinate where user clicks
	string GetSrting() const;	 //Returns a string entered by the user
	operationType GetUseroperation() const; //Read the user click and map to an operation
	bool GetMouseStatus(button B1, int& x, int& y) const;
	void MouseFlush();
	void KeyboardFlush();
	bool Getmouseclik(int& x, int& y);
	void Mapx(int& x) const;
	void Mapy(int& y) const;
	void set0(Point& p0);
	void set1(Point& p1);
	// Output Functions  ---------------------------
	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreatePlayToolBar();	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area

	// -- shapes Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const;  //Draw a rectangle
	void DrawTri(Point P1, Point P2, Point p4, GfxInfo RectGfxInfo) const;
	void DrawCir(Point center, Point edge, GfxInfo CircleGfxInfo) const; // Draw a Circle
	void DrawSquare(Point P1, double sidelen, GfxInfo SquareGfxInfo) const; // Draw a square
	void DrawLine(Point P1, Point P2, GfxInfo OvalGfxInfo) const;
	void DrawPoly(vector<Point> Points, const int N , GfxInfo OvalGfxInfo) const;
	void DrawOval(Point P1, Point P2, GfxInfo OvalGfxInfo) const;

	void DrawImg(string str,int startX,int startY,int endX,int endY);

	

	///Make similar functions for drawing all other shapes.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color

	int getCrntPenWidth() const;		//get current pen width
	void setFillColor(color c);
	void setPenColor(color p);
	void setPenwidth(double p);
	void setBorderwidth(double bw);
	double getBorderwidth() const;
	color colorpalette();
	void changedefaultfilled(bool defill);
	bool getdefaultfilled();
	int getInterfaceMode()const;
	bool IsinDrawingArea(int x, int y) const;
	bool IsinPlayingArea(int x, int y) const;
	int getoriginalx0();
	int getoriginalx1();
	int getoriginaly0();
	int getoriginaly1();
	~GUI();
};

