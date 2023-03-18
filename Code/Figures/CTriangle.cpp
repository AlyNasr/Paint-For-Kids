#include "CTriangle.h"

CTriangle::CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo) {
	P1 = p1;
	P2 = p2;
	P3 = p3;
	Count++;
	ID = Count;
}

void CTriangle::Draw(Output* pOut) const {
	pOut->DrawTri(P1, P2, P3, FigGfxInfo, Selected);
}

double CTriangle::TriangleArea(Point A, Point B, Point C)
{
	return abs((A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y)) / 2.0);
}

bool CTriangle::IsPointInside(Point p) {
	double area = TriangleArea(P1, P2, P3);
	double a1 = TriangleArea(p, P2, P3);
	double a2 = TriangleArea(P1, p, P3);
	double a3 = TriangleArea(P1, P2, p);

	return (area == a1 + a2 + a3);
}

void CTriangle::ShiftCoordinates(Point pClicked, Point& p2, Point& p3) {
	p2.x = P2.x - P1.x + pClicked.x;
	p2.y = P2.y - P1.y + pClicked.y;

	p3.x = P3.x - P1.x + pClicked.x;
	p3.y = P3.y - P1.y + pClicked.y;
}

void CTriangle::Save(ofstream& OutFile) {
	OutFile << TRIANGLE << '\t' << ID << '\t' << P1.x << '\t' << P1.y << '\t' << P2.x << '\t' << P2.y << '\t' << P3.x << '\t' << P3.y << '\t'
		<< DrawingColor() << '\t' << FillingColor() << endl;
}

void CTriangle::Load(ifstream& Infile) {
	int drawclr, fillclr;
	Infile >> ID >> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >> P3.y >> drawclr >> fillclr;

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

void CTriangle::PrintInfo(Output* pOut) {
	pOut->PrintMessage("Triangle, ID = " + to_string(ID) + ", corner1 = (" + to_string(P1.x) + "," + to_string(P1.y)
		+ "), corner2 = (" + to_string(P2.x) + "," + to_string(P2.y) + "), corner3 = (" + to_string(P3.x) + "," + to_string(P3.y)
		+ "), drawing color = " + this->getDrawColor() + ", filling color = " + this->getFillColor());
}