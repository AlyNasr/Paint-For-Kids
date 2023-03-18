#include "CCircle.h"
CCircle::CCircle(Point p, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo) {
	Center = p;
	Count++;
	ID = Count;
}

void CCircle::Draw(Output* pOut) const {
	pOut->DrawCirc(Center, FigGfxInfo, Selected);
}

bool CCircle::IsPointInside(Point p) {
	return ((p.x - Center.x) * (p.x - Center.x) +
		(p.y - Center.y) * (p.y - Center.y) <= UI.CircleRadius * UI.CircleRadius);
}

void CCircle::ShiftCoordinates(Point pClicked, Point& p2, Point& p3) {}

void CCircle::Save(ofstream& OutFile) {
	OutFile << CIRCLE << '\t' << ID << '\t' << Center.x << '\t' << Center.y << '\t' << DrawingColor() << '\t' 
		    << FillingColor() << endl;
}

void CCircle::Load(ifstream& Infile) {
	int drawclr, fillclr;
	Infile >> ID >> Center.x >> Center.y >> drawclr >> fillclr;

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

void CCircle::PrintInfo(Output* pOut) {
	pOut->PrintMessage("Circle, ID = " + to_string(ID) + ", center = (" + to_string(Center.x) + "," + to_string(Center.y)
		+ "), radius = " + to_string(UI.CircleRadius) + ", drawing color = " + this->getDrawColor()
		+ ", filling color = " + this->getFillColor());
}