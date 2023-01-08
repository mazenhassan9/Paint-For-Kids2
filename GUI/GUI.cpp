#include"GUI.h"

GUI::GUI()
{
	//Initialize user interface parameters
	InterfaceMode = MODE_DRAW;

	width = 1100;
	height = 600;
	wx = 5;
	wy = 5;


	StatusBarHeight = 50;
	ToolBarHeight = 50;
	MenuIconWidth = 30;
	
	DrawColor = BLUE;	//default Drawing color
	FillColor = GREEN;	//default Filling color
	MsgColor = BLACK;		//Messages color
	BkGrndColor = WHITE;	//Background color
	HighlightColor = MAGENTA;	//This color should NOT be used to draw shapes. use if for highlight only
	StatusBarColor = LIGHTSEAGREEN;
	PenWidth = 3;	//default width of the shapes frames
	Borderwidth = 4;

	//Create the output window
	pWind = CreateWind(width, height, wx, wy);
	//Change the title
	pWind->ChangeTitle("- - - - - - - - - - PAINT ^ ^ PLAY - - - - - - - - - -");

	CreateDrawToolBar();
	CreateStatusBar();

	x0 = 0;
	y0 = ToolBarHeight;
	x1 = width;
	y1 = height - StatusBarHeight;

	originalx0 = x0;
	originaly0 = y0;
	originalx1 = x1;
	originaly1 = y1;

	x0 = 0;
	y0 = ToolBarHeight;
	x1 = width;
	y1 = height - StatusBarHeight;

	originalx0 = x0;
	originaly0 = y0;
	originalx1 = x1;
	originaly1 = y1;

	 prevx0 = x0;
	 prevy0 = y0;
	 prevx1 = x1;
	 prevy1 = y1;
}




//======================================================================================//
//								Input Functions										//
//======================================================================================//
void GUI::GetLastClick(int& x, int& y) const
{
	pWind->GetMouseCoord(x, y);
}
void GUI::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x,y);	//Wait for mouse click

}
void GUI::GetLastKey(char& K) const
{
	pWind->GetKeyPress(K);
}

string GUI::GetSrting() const
{
	string Label;
	char Key;
	keytype ktype;
	pWind->FlushKeyQueue();
	while (1)
	{
		ktype = pWind->WaitKeyPress(Key);
		if (ktype == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if (Key == 8)	//BackSpace is pressed
			if( Label.size() > 0)	
				Label.resize(Label.size() - 1);
			else
				Key = '\0';		
		else
			Label += Key;
		PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired operation
operationType GUI::GetUseroperation() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on

			switch (ClickedIconOrder)
			{
			case ICON_RECT: return DRAW_RECT;
			case ICON_CIRC: return DRAW_CIRC;
			case ICON_TRI: return DRAW_TRI;
			case ICON_LINE: return DRAW_LINE;
			case ICON_SQUARE:return DRAW_SQAURE;
			case ICON_Reg: return DRAW_POLY;
			case ICON_Irreg: return DRAW_IRPOLY;
			case ICON_OVAL: return DRAW_OVAL;
			case ICON_STICK: return STICK;
			case ICON_Fillcolor: return CHNG_FILL_CLR;
			case ICON_PENWIDTH: return PENWIDTH;
			case ICON_PEN: return CHNG_DRAW_CLR;
			case ICON_Borderwidth: return BORDER_WIDTH;
			case ICON_Bordercolor: return CHNG_BOR_CLR;
			case ICON_UNDO: return UNDO;
			case ICON_REDO:return REDO;
			case ICON_Delete: return DEL;
			case ICON_GROUP:return GROUP;
			case ICON_UNGROUOP:return UNGROUP;
			case ICON_COPY: return COPY;
			case ICON_CUT: return CUT;
			case ICON_PASTE: return PASTE;
			case ICON_Resize: return RESIZE ;
			case ICON_Rotate: return ROTATE;
			case ICON_ZOOM: return ZOOM;
			case Icon_Save: return SAVE;
			case ICON_Load: return LOAD;
			case ICON_SENDTOBACK: return SEND_BACK;
			case ICON_Single_Fill: return CHNG_S_FILL_CLR;
			case ICON_DUPLICATE: return DUPLICATE_GRAPH;
			case ICON_SWITCH: return SWITCH;
			case ICON_EXIT: return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= ToolBarHeight && y < height - StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//GUI is in PLAY mode
	{
		if (y >= 0 && y < ToolBarHeight)
		{
			//Check whick Menu icon was clicked
			//==> This assumes that menu icons are lined up horizontally <==
			int ClickedIconOrder = (x / MenuIconWidth);
			//Divide x coord of the point clicked by the menu icon width (int division)
			//if division result is 0 ==> first icon is clicked, if 1 ==> 2nd icon and so on
		
			switch (ClickedIconOrder)
			{
			
			case PLAY_ICON_SWITCH: return SWITCH;
			case PLAY_ICON_HIDE:	return HIDE_GRAPH;
			case PLAY_ICON_EXIT: return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}
	}

}
bool GUI::GetMouseStatus(button B1, int& x, int& y) const
{
	return pWind->GetButtonState(B1,x,y);
}
void GUI::MouseFlush() 
{
	pWind->FlushMouseQueue();
}
void GUI::KeyboardFlush()
{
	pWind->FlushKeyQueue();
}
bool GUI::Getmouseclik(int& x, int& y)
{
	clicktype out = pWind->GetMouseClick(x, y);
	return (out != NO_CLICK);
}
void  GUI::Mapx(int& x) const
{
	
	if (x1 - x0 == 0)
		return;
	
	x= prevx0 + (x - x0) * (prevx1 - prevx0) / (x1 - x0);
	
}

void GUI::Mapy(int& y) const
{
	if ((y1 - y0) == 0)
		return;
	
	
	y= prevy0 + (y - y0) * (prevy1 - prevy0) / (y1 - y0);
	
}

void GUI::set0(Point& p0)
{
	prevx0 = x0;
	prevy0 = y0;

	x0 = p0.x;
	y0 = p0.y;
}
void GUI::set1(Point& p1)
{
	prevx1 = x1;
	prevy1 = y1;
	x1 = p1.x;
	y1 = p1.y;
}
////////////////////////////////////////////////////



//======================================================================================//
//								Output Functions										//
//======================================================================================//

window* GUI::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(BkGrndColor);
	pW->SetPen(BkGrndColor, 1);
	pW->DrawRectangle(0, ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateStatusBar() const
{
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(StatusBarColor, 1);
	pWind->SetBrush(StatusBarColor);
	pWind->DrawRectangle(0, height - StatusBarHeight, width, height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void GUI::CreateDrawToolBar() 
{
	pWind->SetBrush(BkGrndColor);
	pWind->SetPen(BkGrndColor, 1);
	pWind->DrawRectangle(0, 0, width, ToolBarHeight);


	InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu icon
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuIcon
	string MenuIconImages[DRAW_ICON_COUNT];
	MenuIconImages[ICON_RECT] = "images\\MenuIcons\\Menu_Rect.jpg";
	MenuIconImages[ICON_CIRC] = "images\\MenuIcons\\Menu_Circle.jpg";
	MenuIconImages[ICON_OVAL] = "images\\MenuIcons\\Menu_Oval.jpg";
	MenuIconImages[ICON_TRI] = "images\\MenuIcons\\Menu_Tri.jpg";
	MenuIconImages[ICON_LINE] = "images\\MenuIcons\\Menu_LINE.jpg";
	MenuIconImages[ICON_SQUARE] = "images\\MenuIcons\\Menu_SQUARE.jpg";
	MenuIconImages[ICON_Reg] = "images\\MenuIcons\\Menu_REG.JPG";
	MenuIconImages[ICON_Irreg] = "images\\MenuIcons\\Menu_IRREG.JPG";
	MenuIconImages[ICON_STICK] = "images\\MenuIcons\\STICK.JPG";
	MenuIconImages[ICON_Fillcolor] = "images\\MenuIcons\\Menu_Fillcolor.jpg";
	MenuIconImages[ICON_PENWIDTH] = "images\\MenuIcons\\PENWIDTH.jpg";
	MenuIconImages[ICON_PEN] = "images\\MenuIcons\\pen.jpg";
	MenuIconImages[ICON_Borderwidth] = "images\\MenuIcons\\BORDERWIDTH.jpg";
	MenuIconImages[ICON_Bordercolor] = "images\\MenuIcons\\bordercolor.jpg";
	MenuIconImages[ICON_UNDO] = "images\\MenuIcons\\undo.jpg";
	MenuIconImages[ICON_REDO] = "images\\MenuIcons\\redo.jpg";
	MenuIconImages[ICON_Delete] = "images\\MenuIcons\\Delete.jpg";
	MenuIconImages[ICON_COPY] = "images\\MenuIcons\\copy.jpg";
	MenuIconImages[ICON_CUT] = "images\\MenuIcons\\cut.jpg";
	MenuIconImages[ICON_PASTE] = "images\\MenuIcons\\paste.jpg";
	MenuIconImages[ICON_Resize] = "images\\MenuIcons\\Resize.jpg";
	MenuIconImages[ICON_Rotate] = "images\\MenuIcons\\Rotate.jpg";
	MenuIconImages[ICON_ZOOM] = "images\\MenuIcons\\zoom.jpg";
	MenuIconImages[ICON_SENDTOBACK] = "images\\MenuIcons\\SENDTOBACK.jpg";
	MenuIconImages[Icon_Save] = "images\\MenuIcons\\Save.jpg";
	MenuIconImages[ICON_Load] = "images\\MenuIcons\\Load.jpg";
	MenuIconImages[ICON_Single_Fill] = "images\\MenuIcons\\Menu_Single_Fill_color.jpg";
	MenuIconImages[ICON_GROUP] = "images\\MenuIcons\\group.jpg";
	MenuIconImages[ICON_UNGROUOP] = "images\\MenuIcons\\ungroup.jpg";
	MenuIconImages[ICON_DUPLICATE]= "images\\MenuIcons\\Duplicate.jpg";
	MenuIconImages[ICON_SWITCH] = "images\\MenuIcons\\SWITCH.JPG";
	MenuIconImages[ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";

	

	//TODO: Prepare images for each menu icon and add it to the list

	//Draw menu icon one image at a time
	for (int i = 0; i < DRAW_ICON_COUNT; i++)
		pWind->DrawImage(MenuIconImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::CreatePlayToolBar() 
{
	pWind->SetBrush(BkGrndColor);
	pWind->SetPen(BkGrndColor, 1);
	pWind->DrawRectangle(0, 0, width, ToolBarHeight);

	InterfaceMode = MODE_PLAY;
	///TODO: write code to create Play mode menu
	string MenuItemImages[PLAY_ICON_COUNT];
	
	
	MenuItemImages[PLAY_ICON_FIGCOLOR] = "images\\MenuIcons\\FIGURE_COLOR.jpg";
	MenuItemImages[PLAY_ICON_BACKDRAW] = "images\\MenuIcons\\BACK_Draw.jpg";
	MenuItemImages[PLAY_ICON_HIDE] = "images\\MenuIcons\\HideGraph.jpg";
	MenuItemImages[PLAY_ICON_SWITCH] = "images\\MenuIcons\\SWITCH.JPG";
	MenuItemImages[PLAY_ICON_EXIT] = "images\\MenuIcons\\Menu_Exit.jpg";

	for (int i = 0; i < PLAY_ICON_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * MenuIconWidth, 0, MenuIconWidth, ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, ToolBarHeight, width, ToolBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::ClearDrawArea() const
{
	pWind->SetPen(BkGrndColor, 1);
	pWind->SetBrush(BkGrndColor);
	pWind->DrawRectangle(0, ToolBarHeight, width, height - StatusBarHeight);


}
//////////////////////////////////////////////////////////////////////////////////////////

void GUI::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(MsgColor, 50);
	pWind->SetFont(24, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, height - (int)(0.75 * StatusBarHeight), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::getCrntDrawColor() const	//get current drwawing color
{

	return DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color GUI::colorpalette() {
	int x, y;
	window* wp = CreateWind(300,300,300,300);
	int x11 = 0; int y11 = 0; int x12 = 150; int y12 = 150; 
	int x21 = 150; int y21 = 0; int x22 = 300; int y22 = 150;
	int x31 = 150; int y31 = 150; int x32 = 300; int y32 = 300;
	int x41 = 0; int y41 = 150; int x42 = 150; int y42 = 300;

	wp->SetPen(SKYBLUE, 1); wp->SetBrush(SKYBLUE);
	wp->DrawRectangle(x11, y11, x12, y12);

	wp->SetPen(LIGHTGREY, 1); wp->SetBrush(LIGHTGREY);
	wp->DrawRectangle(x21, y21, x22, y22);

	wp->SetPen(TAN, 1); wp->SetBrush(TAN);
	wp->DrawRectangle(x31, y31, x32, y32);

	wp->SetPen(ROSYBROWN, 1); wp->SetBrush(ROSYBROWN);
	wp->DrawRectangle(x41, y41, x42, y42);
	
	wp->WaitMouseClick(x, y);
	delete wp;
	if (x >= x11 && y>=y11 && x<x12 && y< y12 )
	{
		return SKYBLUE;
	}
	if (x >= x21 && y >= y21 && x < x22 && y < y22)
	{
		return LIGHTGREY;
	}
	if (x >= x31 && y >= y31 && x < x32 && y < y32)
	{
		return TAN;
	}
	if (x >= x11 && y >= y11 && x < x12 && y < y42)
	{
		return ROSYBROWN;

	}
	
	return SKYBLUE;
}

color GUI::getCrntFillColor() const	//get current filling color
{
	
	return FillColor; 
} 
            ////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////

int GUI::getCrntPenWidth() const		//get current pen width
{
	return PenWidth;
}

//======================================================================================//
//								shapes Drawing Functions								//
//======================================================================================//

void GUI::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo) const
{
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	if (RectGfxInfo.BorderWdth>0)

		pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width
	else
		pWind->SetPen(DrawingClr, Borderwidth);

	drawstyle style = FRAME;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	
		
	pWind->DrawRectangle(P1.x, P1.y, P2.x,P2.y, style);
	

}


void GUI::DrawSquare(Point P1,double sidelen, GfxInfo SquareGfxInfo) const
{
	color DrawingClr;
	if (SquareGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	if (SquareGfxInfo.BorderWdth>0)

		pWind->SetPen(DrawingClr, SquareGfxInfo.BorderWdth);	//Set Drawing color & width
	else
		pWind->SetPen(DrawingClr, Borderwidth);

	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;


		
	pWind->DrawRectangle(P1.x, P1.y,P1.x+sidelen,P1.y+sidelen, style);
	
	
}
void GUI::DrawTri(Point P1, Point P2, Point p3, GfxInfo RectGfxInfo) const {
	color DrawingClr;
	if (RectGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	if (RectGfxInfo.BorderWdth>0)

		pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width
	else
		pWind->SetPen(DrawingClr, Borderwidth);

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, p3.x, p3.y, style);
	
}

void GUI::DrawCir(Point center, Point edge, GfxInfo CircleGfxInfo) const
{


	int R = sqrt(pow(center.x - edge.x, 2) + pow(center.y - edge.y, 2)) / 2;
	
		color DrawingClr;
		if (CircleGfxInfo.isSelected)	//shape is selected
			DrawingClr = HighlightColor; //shape should be drawn highlighted
		else
			DrawingClr = CircleGfxInfo.DrawClr;

		if(CircleGfxInfo.BorderWdth>0)
		
			pWind->SetPen(DrawingClr, CircleGfxInfo.BorderWdth);	//Set Drawing color & width
		else
			pWind->SetPen(DrawingClr, Borderwidth);
		drawstyle style;
		if (CircleGfxInfo.isFilled)
		{

			style = FILLED;
			pWind->SetBrush(CircleGfxInfo.FillClr);
		}
		else
			style = FRAME;

		pWind->DrawCircle(center.x, center.y, R, style);
		
	
}


void GUI::DrawPoly(vector <Point> Points,const int N, GfxInfo PolyGfxInfo) const {

	int* X = new int[N];
	int* Y = new int[N];
	for (int i = 0; i < N; i++)
	{
		X[i] = Points[i].x;
		Y[i] = Points[i].y;
	}
	color DrawingClr;
	if (PolyGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = PolyGfxInfo.DrawClr;

	if (PolyGfxInfo.BorderWdth>0)

		pWind->SetPen(DrawingClr, PolyGfxInfo.BorderWdth);	//Set Drawing color & width
	else
		pWind->SetPen(DrawingClr, Borderwidth);

	drawstyle style;
	if (PolyGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(PolyGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawPolygon(X, Y, N, style);

	

}

void GUI::DrawLine(Point P1, Point P2, GfxInfo LineGfxInfo) const
{
	color DrawingClr;
	if (LineGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = LineGfxInfo.DrawClr;

	if (LineGfxInfo.BorderWdth>0)

		pWind->SetPen(DrawingClr, LineGfxInfo.BorderWdth);	//Set Drawing color & width
	else
		pWind->SetPen(DrawingClr, Borderwidth);
	drawstyle style;
	
	
	style = FRAME;
	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y, style);
	
}



void GUI::DrawOval(Point P1, Point P2, GfxInfo OvalGfxInfo) const
{
	color DrawingClr;
	if (OvalGfxInfo.isSelected)	//shape is selected
		DrawingClr = HighlightColor; //shape should be drawn highlighted
	else
		DrawingClr = OvalGfxInfo.DrawClr;

	if (OvalGfxInfo.BorderWdth>0)

		pWind->SetPen(DrawingClr, OvalGfxInfo.BorderWdth);	//Set Drawing color & width
	else
		pWind->SetPen(DrawingClr, Borderwidth);

	drawstyle style;
	if (OvalGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(OvalGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawEllipse(P1.x, P1.y, P2.x, P2.y, style);
	
}

void GUI::DrawImg(string str, int startX, int startY, int endX, int endY)
{
	pWind->DrawImage(str, startX, startY, endX, endY);
}




void GUI::setFillColor(color c)
{
	
	FillColor=c;
	
}
void GUI::setPenColor(color p)
{
	DrawColor=p;
}
void GUI::setPenwidth(double p)
{

	PenWidth = p;

}
void GUI::setBorderwidth(double bw)
{

	Borderwidth = bw;

}
double GUI::getBorderwidth() const
{
	return Borderwidth;
}
void GUI::changedefaultfilled(bool defill)
{
	defaultFill = defill;
}
bool GUI::getdefaultfilled()
{
	return defaultFill;
}

int GUI::getInterfaceMode() const
{
	return InterfaceMode;
}



bool GUI::IsinDrawingArea(int x, int y) const
{
	if (y > ToolBarHeight && y < height - StatusBarHeight)
		return true;
	return false;
}


bool GUI::IsinPlayingArea(int x, int y) const
{
	if (y > ToolBarHeight && y < height - StatusBarHeight)
		return true;
	return false;
}

//////////////////////////////////////////////////////////////////////////////////////////
GUI::~GUI()
{
	delete pWind;
}

int  GUI::getoriginalx0()
{
	return originalx0;
}
int GUI::getoriginalx1()
{
	return originalx1;
}
int GUI::getoriginaly0()
{
	return originaly0;
}
int GUI::getoriginaly1()
{
	return originaly1;
}


