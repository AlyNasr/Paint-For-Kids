#include "Input.h"
#include "Output.h"


Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int& x, int& y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output* pO, string msg) const
{
	string Label;
	char Key;
	pO->PrintMessage(msg + " Enter a file name without any extension: ");
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
		{
			return Label;
		}
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(msg + " Enter a file name without any extension: " + Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{
	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_LINE: return DRAW_LINE;
			case ITM_RECT: return DRAW_RECT;
			case ITM_TRIAN: return DRAW_TRI;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_SELECT: return SEL;
			case ITM_DRAWCOLOR: return CHNG_DRAW_CLR_BLACK;
			case ITM_DRAWCOLOR_RED: return CHNG_DRAW_CLR_RED;
			case ITM_DRAWCOLOR_BLUE: return CHNG_DRAW_CLR_BLUE;
			case ITM_DRAWCOLOR_GREEN: return CHNG_DRAW_CLR_GREEN;
			case ITM_FILLCOLOR_BLACK: return CHNG_FILL_CLR_BLACK;
			case ITM_FILLCOLOR_RED: return CHNG_FILL_CLR_RED;
			case ITM_FILLCOLOR_BLUE: return CHNG_FILL_CLR_BLUE;
			case ITM_FILLCOLOR_GREEN: return CHNG_FILL_CLR_GREEN;
			case ITM_FILLCOLOR_WHITE: return CHNG_FILL_CLR_WHITE;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_DELETE: return DEL;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_EXITDRAW: return EXIT;
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	
}
/////////////////////////////////

Input::~Input()
{
}
