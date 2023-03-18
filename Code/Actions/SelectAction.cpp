#include "SelectAction.h"

SelectAction::SelectAction(ApplicationManager* pApp) :Action(pApp)
{}

void SelectAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Select Action: Click on a figure");

	//Read clicked point
	pIn->GetPointClicked(ClickedPoint.x, ClickedPoint.y);
	pOut->ClearStatusBar();

}

//Execute the action
void SelectAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	CFigure* prevFig = pManager->getSelectedFig();
	
	ReadActionParameters();

	CFigure* fig = pManager->GetFigure(ClickedPoint);

	if (fig && prevFig == fig) //case of Unselect figure
	{
		fig->SetSelected(false);
		pManager->setSelectedFig(NULL);
		pOut->PrintMessage("A figure is unselected");
	}
	else if (fig) 
	{
		if (prevFig) { prevFig->SetSelected(false); }
		pManager->setSelectedFig(fig);
		fig->SetSelected(true);
		pOut->PrintMessage("A figure is selected");
	}
	else
	{
		pOut->PrintMessage("No figure is selected");
	}
}
