#ifndef DEFS_H
#define DEFS_H


//This file contais some global constants and definitions to be used in the project.
enum operationType //The operations supported (you can add more if needed) //Arranged by who is used for Redo/Undo, and who is not.
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_SQAURE,    //Draw Square
	DRAW_CIRC,		//Draw Circle
	DRAW_OVAL,
	DRAW_POLY,
	DRAW_IRPOLY,
	CHNG_S_FILL_CLR, //change single fill color
	CHNG_BOR_CLR, //Change border of a single shape
	RESIZE,
	DRAG,
	ROTATE,

	DEL,
	
	UNDO,
	REDO,
				//Delete a shape(s)
	MOVE,	//Move a shape(s)
			//Resize a shape(s)
			//Rotate a shape(s)
	SEND_BACK,		//Send a shape to the back of all shapes
	BRNG_FRNT,		//Bring a shape to the front of all shapes
	SAVE,			//Save the whole graph to a file
	LOAD,			//Load a graph from a file
	GROUP,
	UNGROUP,
	ZOOM,
	
	CHNG_BK_CLR,	//Change background color
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	Select,           //select a shape 
	COPY,
	CUT,
	PASTE,
	PENWIDTH,
	PEN,
	STICK,
	SWITCH ,
	BORDER_WIDTH ,
	DUPLICATE_GRAPH,
	HIDE_GRAPH,
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	PLAYING_AREA,
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY	,		//Switch interface to Play mode

	///TODO: Add more operation types (if needed)
};

#endif