#include "CLine.h"
CLine::CLine(Point p1, Point p2, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo) {
	P1 = p1;
	P2 = p2;

	Count++;
	ID = Count;
}

void CLine::Draw(Output* pOut) const {
	pOut->DrawLine(P1, P2, FigGfxInfo, Selected);
}

bool CLine::IsPointInside(Point p) {
	double dist = sqrt(pow(P1.x - P2.x, 2) + pow(P1.y - P2.y, 2));    
	double dist1 = sqrt(pow(p.x - P1.x, 2) + pow(p.y - P1.y, 2));   
	double dist2 = sqrt(pow(p.x - P2.x, 2) + pow(p.y - P2.y, 2));    
	if ((dist1 + dist2 == dist) || (dist1 + dist2 - dist <= 0.5))   // 0.5 for tolerance 
	{
		return true;
	}
	else
		return false;
}

void CLine::ShiftCoordinates(Point pClicked, Point& p2, Point& p3) {
	p2.x = P2.x - P1.x + pClicked.x;
	p2.y = P2.y - P1.y + pClicked.y;
}

void CLine::Save(ofstream& OutFile) {
	OutFile << LINE << '\t' << ID  << '\t' << P1.x << '\t' << P1.y << '\t' << P2.x << '\t' << P2.y << '\t' << DrawingColor() << '\t'
		    << WHITE_CLR << endl;

}

void CLine::Load(ifstream& Infile) {
	int x, drawclr;
	Infile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> drawclr >> x;

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
}

void CLine::PrintInfo(Output* pOut) {

	pOut->PrintMessage("Line, ID = " + to_string(ID) + ", start point = (" + to_string(P1.x) + "," + to_string(P1.y)
		+ "), end point = (" + to_string(P2.x) + "," + to_string(P2.y) + "), color = " + this->getDrawColor());
}