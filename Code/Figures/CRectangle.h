#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	//rectangle corners
	Point Corner1;	
	Point Corner2;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool IsPointInside(Point p);
	virtual void ShiftCoordinates(Point pClicked, Point& p2, Point& p3);
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	virtual void PrintInfo(Output* pOut);
};

#endif