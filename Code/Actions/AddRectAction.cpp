#include "AddRectAction.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

void AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Rectangle: Click at first corner");
	
	//Read 1st corner and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	
	pOut->PrintMessage("New Rectangle: Click at second corner");

	//Read 2nd corner and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);


	RectGfxInfo.isFilled = true;
	//get drawing, filling colors and pen width from the interface
	RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
	RectGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();
}

//Execute the action
void AddRectAction::Execute() 
{
	//This action needs to read some parameters first
	ReadActionParameters();

	
	//Check if the points are within the drawing area
	Output* pOut = pManager->GetOutput();

	if (!(P1.y >= UI.ToolBarHeight && P1.y < UI.height - UI.StatusBarHeight))
	{
		pOut->PrintMessage("Drawing Failed! The first corner is outside the drawing area");
		return;
	}

	if (!(P2.y >= UI.ToolBarHeight && P2.y < UI.height - UI.StatusBarHeight))
	{
		pOut->PrintMessage("Drawing Failed! The second corner is outside the drawing area");
		return;
	}

	//Create a rectangle with the parameters read from the user
	CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);
	
	//Add the rectangle to the list of figures
	pManager->AddFigure(R);
}
