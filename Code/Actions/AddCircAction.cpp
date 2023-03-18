#include "AddCircAction.h"

AddCircAction::AddCircAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at a center point");

	//Read the center point
	pIn->GetPointClicked(P.x, P.y);

	CircGfxInfo.isFilled = true;	
	//get drawing, filling colors from the interface
	CircGfxInfo.DrawClr = pOut->getCrntDrawColor();
	CircGfxInfo.FillClr = pOut->getCrntFillColor();

	pOut->ClearStatusBar();

}

//Execute the action
void AddCircAction::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();

	//Check if the points are within the drawing area
	Output* pOut = pManager->GetOutput();

	if (!(P.y >= UI.ToolBarHeight && P.y < UI.height - UI.StatusBarHeight))
	{
		pOut->PrintMessage("Drawing Failed! The center point is outside the drawing area");
		return;
	}
	
	//Create a circle with the parameters read from the user
	CCircle* C = new CCircle(P, CircGfxInfo);

	//Add the circle to the list of figures
	pManager->AddFigure(C);
}

