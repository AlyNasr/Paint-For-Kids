#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		            //Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig;           //Pointer to the selected figure
	CFigure* Clipboard;             //Pointer to the copied/cut figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	void RemoveFigure(CFigure* pFig);       //Removes a figure from the FigList
	CFigure *GetFigure(Point p) const;      //Search for a figure given a point inside the figure
	void SaveGraph(ofstream& outputfile);   //Save all figures drawn in the graph
	void ClearGraph();                      //Delete all figures and clear the drawing area
	void setSelectedFig(CFigure* ptr);      
	CFigure* getSelectedFig() const;
	void setClipboard(CFigure* ptr);
	CFigure* getClipboard() const;

	// -- Interface Management Functions
	Input *GetInput() const;          //Return pointer to the input
	Output *GetOutput() const;        //Return pointer to the output
	void UpdateInterface() const;	  //Redraws all the drawing window	
};

#endif