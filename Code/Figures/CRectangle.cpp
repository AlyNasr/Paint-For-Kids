#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Count++;
	ID = Count;
}
	
void CRectangle::Draw(Output* pOut) const
{
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

bool CRectangle::IsPointInside(Point p) {

	if (Corner1.x < Corner2.x && Corner1.y < Corner2.y) {
		if  (p.x >= Corner1.x && p.x <= Corner2.x && p.y >= Corner1.y && p.y <= Corner2.y) 
			return true;
	}
	else if(Corner1.x > Corner2.x && Corner1.y > Corner2.y){
		if (p.x >= Corner2.x && p.x <= Corner1.x && p.y >= Corner2.y && p.y <= Corner1.y)
			return true;
	}
	else if (Corner1.x < Corner2.x && Corner1.y > Corner2.y) {
		if (p.x <= Corner2.x && p.x >= Corner1.x && p.y >= Corner2.y && p.y <= Corner1.y)
			return true;
	}
	else if (Corner1.x > Corner2.x && Corner1.y < Corner2.y) {
		if (p.x >= Corner2.x && p.x <= Corner1.x && p.y <= Corner2.y && p.y >= Corner1.y)
			return true;
	}
	else {
		return false; 
	}
}

void CRectangle::ShiftCoordinates(Point pClicked, Point& p2, Point& p3) {
	p2.x = Corner2.x - Corner1.x + pClicked.x;
	p2.y = Corner2.y - Corner1.y + pClicked.y;
}

void CRectangle::Save(ofstream& OutFile) {
	OutFile << RECTANGLE << '\t' << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t' << Corner2.x << '\t' << Corner2.y << '\t'
		    << DrawingColor() << '\t' << FillingColor() << endl;
}

void CRectangle::Load(ifstream& Infile) {
	int drawclr, fillclr;
	Infile >> ID >>Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> drawclr >> fillclr;

	switch (drawclr) {
	case BLACK_CLR:
		FigGfxInfo.DrawClr = BLACK;
		break;
	case RED_CLR:
		FigGfxInfo.DrawClr = RED;
		break;
	case BLUE_CLR:
		FigGfxInfo.DrawClr = BLUE;
		break;
	case GREEN_CLR:
		FigGfxInfo.DrawClr = GREEN;
		break;
	default:
		FigGfxInfo.DrawClr = BLACK;
	}

	switch (fillclr) {
	case BLACK_CLR:
		FigGfxInfo.FillClr = BLACK;
		break;
	case RED_CLR:
		FigGfxInfo.FillClr = RED;
		break;
	case BLUE_CLR:
		FigGfxInfo.FillClr = BLUE;
		break;
	case GREEN_CLR:
		FigGfxInfo.FillClr = GREEN;
		break;
	case WHITE_CLR:
		FigGfxInfo.FillClr = WHITE;
		break;
	default:
		FigGfxInfo.DrawClr = BLACK;
	}
}

void CRectangle::PrintInfo(Output* pOut) {
	pOut->PrintMessage("Rectangle, ID = " + to_string(ID) + ", corner1 = (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), corner2 = (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), drawing color = " + this->getDrawColor()
		+ ", filling color = " + this->getFillColor());
}