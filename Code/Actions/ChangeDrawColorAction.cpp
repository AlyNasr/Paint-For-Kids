#include "ChangeDrawColorAction.h"

ChangeDrawColorAction::ChangeDrawColorAction(ApplicationManager* pApp, color drawclr) :Action(pApp)
{
	DrawColor = drawclr;
}

void ChangeDrawColorAction::ReadActionParameters(){}

//Execute the action
void ChangeDrawColorAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure* selectedFig = pManager->getSelectedFig();

	//Change the draw color of a selected figure
	if (selectedFig != NULL) {
		selectedFig->ChngDrawClr(DrawColor);
		pOut->PrintMessage("Selected figure drawing color is changed");

		//Unselect the figure
		selectedFig->SetSelected(false);
		pManager->setSelectedFig(NULL);
	}
	else { //Change the drawing color for the upcoming figures
		UI.DrawColor = DrawColor;
		pOut->PrintMessage("Drawing color is changed");
	}
}
