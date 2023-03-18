#pragma once
#include "CFigure.h"
class CLine :public CFigure
{
private:
	Point P1;   //start point
	Point P2;   //end point
public:
	CLine(Point p1, Point p2, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsPointInside(Point p);
	virtual void ShiftCoordinates(Point pClicked, Point& p2, Point& p3);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void PrintInfo(Output* pOut);
};

