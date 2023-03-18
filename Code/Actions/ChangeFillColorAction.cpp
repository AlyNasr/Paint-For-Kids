#include "ChangeFillColorAction.h"

ChangeFillColorAction::ChangeFillColorAction(ApplicationManager* pApp, color fillclr) :Action(pApp)
{
	FillColor = fillclr;
}

void ChangeFillColorAction::ReadActionParameters(){}

//Execute the action
void ChangeFillColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	CFigure* selectedFig = pManager->getSelectedFig();

	// Change the fill color of a selected figure
	if (selectedFig != NULL) {
		selectedFig->ChngFillClr(FillColor);
		pOut->PrintMessage("Selected figure filling color is changed");

		//Unselect the figure
		selectedFig->SetSelected(false);
		pManager->setSelectedFig(NULL);
	}
	else { //Change the filling color for the upcoming figures
		UI.FillColor = FillColor;
		pOut->PrintMessage("Filling color is changed");
		}

}
