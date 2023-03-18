#include "CFigure.h"

int CFigure::Count = 0;  //initialize the static member

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	
	Selected = false;
}

void CFigure::SetID(int id) {
	if (id > 0)  ID = id;
}

int CFigure::GetID() const {
	return ID;
}

void CFigure::ResetCount() {
	Count = 0;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

GfxInfo CFigure::getGFxInfo() const {
	return FigGfxInfo;
}

string CFigure::getDrawColor() const {
	if (FigGfxInfo.DrawClr == BLACK) return "black";
	else if (FigGfxInfo.DrawClr == BLUE) return "blue";
	else if (FigGfxInfo.DrawClr == RED) return "red";
	else return "green";
}

string CFigure::getFillColor() const {
	if (FigGfxInfo.FillClr == BLACK) return "black";
	else if (FigGfxInfo.FillClr == BLUE) return "blue";
	else if (FigGfxInfo.FillClr == RED) return "red";
	else if (FigGfxInfo.FillClr == WHITE) return "white";
	else return "green";
}

ColorName CFigure::DrawingColor() {
	if (FigGfxInfo.DrawClr == BLACK) return BLACK_CLR;
	else if (FigGfxInfo.DrawClr == BLUE) return BLUE_CLR;
	else if (FigGfxInfo.DrawClr == RED) return RED_CLR;
	else return GREEN_CLR;
}

ColorName CFigure::FillingColor() {
	if (FigGfxInfo.FillClr == BLACK) return BLACK_CLR;
	else if (FigGfxInfo.FillClr == BLUE) return BLUE_CLR;
	else if (FigGfxInfo.FillClr == RED) return RED_CLR;
	else if (FigGfxInfo.FillClr == GREEN) return GREEN_CLR;
	else return WHITE_CLR;	
}

