#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 100;
	UI.wy = 100;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 59;

	UI.DrawColor = BLACK;         	   //Drawing color
	UI.FillColor = WHITE;	           //Filling color
	UI.MsgColor = STEELBLUE;		   //Messages color
	UI.BkGrndColor = WHITE;      	   //Drawing Area background color
	UI.HighlightColor = MAGENTA;	   //This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = PALEGOLDENROD;
	UI.PenWidth = 3;	               //width of the figures frames
	UI.CircleRadius = 70;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint For Kids Application");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);


}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);

	//Draw a line above the statusbar
	pWind->SetPen(LIGHTSTEELBLUE, 2);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\line.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rectangle.jpg";
	MenuItemImages[ITM_TRIAN] = "images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\circle.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_DRAWCOLOR] = "images\\MenuItems\\draw_color.jpg";
	MenuItemImages[ITM_DRAWCOLOR_RED] = "images\\MenuItems\\draw_color_red.jpg";
	MenuItemImages[ITM_DRAWCOLOR_BLUE] = "images\\MenuItems\\draw_color_blue.jpg";
	MenuItemImages[ITM_DRAWCOLOR_GREEN] = "images\\MenuItems\\draw_color_green.jpg";
	MenuItemImages[ITM_FILLCOLOR_BLACK] = "images\\MenuItems\\fill_color_black.jpg";
	MenuItemImages[ITM_FILLCOLOR_RED] = "images\\MenuItems\\fill_color_red.jpg";
	MenuItemImages[ITM_FILLCOLOR_BLUE] = "images\\MenuItems\\fill_color_blue.jpg";
	MenuItemImages[ITM_FILLCOLOR_GREEN] = "images\\MenuItems\\fill_color_green.jpg";
	MenuItemImages[ITM_FILLCOLOR_WHITE] = "images\\MenuItems\\fill_color_white.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\paste.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_EXITDRAW] = "images\\MenuItems\\exit.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++) {
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
		pWind->SetPen(LIGHTSTEELBLUE, 1);
		pWind->DrawLine(i * UI.MenuItemWidth, 0, i * UI.MenuItemWidth, UI.ToolBarHeight);
	}
	pWind->DrawLine(DRAW_ITM_COUNT * UI.MenuItemWidth, 0, DRAW_ITM_COUNT * UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line above the toolbar
	pWind->SetPen(LIGHTSTEELBLUE, 3);
	pWind->DrawLine(0, 0, UI.width, 0);

	//Draw a line under the toolbar
	pWind->SetPen(LIGHTSTEELBLUE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(LIGHTSTEELBLUE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	//Draw a line above the statusbar
	pWind->SetPen(LIGHTSTEELBLUE, 2);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.2), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//
void Output::DrawLine(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected) {
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		pWind->SetPen(DrawingClr, 2);
	}
	else {
		DrawingClr = RectGfxInfo.DrawClr;
		pWind->SetPen(DrawingClr, 2);
	}

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y);

}

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected) {
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		pWind->SetPen(DrawingClr, 2);
	}
	else {
		DrawingClr = RectGfxInfo.DrawClr;
		pWind->SetPen(DrawingClr, 2);
	}

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected) {
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		pWind->SetPen(DrawingClr, 2);
	}
	else {
		DrawingClr = RectGfxInfo.DrawClr;
		pWind->SetPen(DrawingClr, 2);
	}
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawCirc(Point P1, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected) {
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
		pWind->SetPen(DrawingClr, 2);
	}
	else {
		DrawingClr = RectGfxInfo.DrawClr;
		pWind->SetPen(DrawingClr, 2);
	}
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawCircle(P1.x, P1.y, UI.CircleRadius, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

