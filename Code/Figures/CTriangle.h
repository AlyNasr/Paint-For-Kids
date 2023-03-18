#pragma once
#include"CFigure.h"
class CTriangle: public CFigure
{
private:
	Point P1, P2, P3;  //three corners of the triangle
public:
	CTriangle(Point p1, Point p2, Point p3, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsPointInside(Point p);
	virtual void ShiftCoordinates(Point pClicked, Point& p2, Point& p3);
	double TriangleArea(Point A, Point B, Point C);   //calculates the triangle area, used in IsPointInside(Point p) function
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void PrintInfo(Output* pOut);
};

