#pragma once
#include "CFigure.h"
class CCircle : public CFigure
{
private:
	Point Center; //center point
public:
	CCircle(Point p, GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	virtual bool IsPointInside(Point p);
	virtual void ShiftCoordinates(Point pClicked, Point& p2, Point& p3);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void PrintInfo(Output* pOut);
};

