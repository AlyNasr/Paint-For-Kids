#include "AddLineAction.h"

AddLineAction::AddLineAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddLineAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Line: Click at first point");

	//Read 1st point and store in point P1
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Line: Click at second point");

	//Read 2nd point and store in point P2
	pIn->GetPointClicked(P2.x, P2.y);

	LineGfxInfo.isFilled = false;
	//get drawing color from the interface
	LineGfxInfo.DrawClr = pOut->getCrntDrawColor();

	pOut->ClearStatusBar();
}

//Execute the action
void AddLineAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Check if the points are within the drawing area
	Output* pOut = pManager->GetOutput();

	if (!(P1.y >= UI.ToolBarHeight && P1.y < UI.height - UI.StatusBarHeight))
	{
		pOut->PrintMessage("Drawing Failed! The first point is outside the drawing area");
		return;
	}

	if (!(P2.y >= UI.ToolBarHeight && P2.y < UI.height - UI.StatusBarHeight))
	{
		pOut->PrintMessage("Drawing Failed! The second point is outside the drawing area");
		return;
	}

	//Create a line with the parameters read from the user
	CLine* L = new CLine(P1, P2, LineGfxInfo);

	//Add the line to the list of figures
	pManager->AddFigure(L);
}