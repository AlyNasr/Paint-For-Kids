#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum DrawMenuItem //Toolbar icons
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here

	ITM_LINE,
	ITM_RECT,		
	ITM_TRIAN,
	ITM_CIRC,		

	ITM_SELECT,
	ITM_DRAWCOLOR,
	ITM_DRAWCOLOR_RED,
	ITM_DRAWCOLOR_BLUE,
	ITM_DRAWCOLOR_GREEN,
	ITM_FILLCOLOR_BLACK,
	ITM_FILLCOLOR_RED,
	ITM_FILLCOLOR_BLUE,
	ITM_FILLCOLOR_GREEN,
	ITM_FILLCOLOR_WHITE,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_DELETE,
	ITM_SAVE,
	ITM_LOAD,
	ITM_EXITDRAW,		

	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum

};
 __declspec(selectany) //This line to prevent "redefinition error"


struct UI_Info	//User Interface Info.
{
	
	int	width, height,	    //Window width and height
		wx, wy,			    //Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu


	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	int CircleRadius;       //Radius of the circle

}UI;	//create a global object UI

#endif