#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include<string>
#include<cmath>
#include<fstream>

//Base class for all figures
class CFigure
{
protected:

	int ID;		        //Each figure has a unique ID
	bool Selected;	    //True if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info	
	static int Count;   //Ensure the uniqueness of IDs of the figures

public:
	CFigure(GfxInfo FigureGfxInfo);

	void SetID(int id);
	int GetID() const;

	static void ResetCount();       //sets count = 0

	void SetSelected(bool s);	    //select/unselect the figure
	bool IsSelected() const;	    //check whether fig is selected
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	GfxInfo getGFxInfo() const;     //gets the figure info

	string getDrawColor() const;   	//gets the drawing color name as a string, used in printInfo() function
	string getFillColor() const;   	//gets the filling color name as a string, used in printInfo() function
	
	ColorName DrawingColor();       //gets the color enum type , used in save and load actions
	ColorName FillingColor();       //gets the color enum type , used for save and load actions

	
	//The following functions should be supported by the figure class
	//It should be overridden by each inherited figure
	
	//draws a figure
	virtual void Draw(Output* pOut) const = 0;           

	//checks if a point is inside a figure, used in select action
	virtual bool IsPointInside(Point p) = 0;                                 

	//shift the figure cordinates related to pClicked, used in paste action
	virtual void ShiftCoordinates(Point pClicked, Point& p2, Point& p3) = 0;

	//saves the figure parameters to the file
	virtual void Save(ofstream &OutFile) = 0;	

	//loads the figure parameters to the file
	virtual void Load(ifstream &Infile) = 0;	

	//prints all figure info on the status bar
	virtual void PrintInfo(Output* pOut) = 0;	
};
#endif