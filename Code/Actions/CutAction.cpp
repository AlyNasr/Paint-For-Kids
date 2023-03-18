#include "CutAction.h"

CutAction::CutAction(ApplicationManager* pApp) :Action(pApp) {}

void CutAction::ReadActionParameters() {}

void CutAction::Execute() {
	Output* pOut = pManager->GetOutput();
	CFigure* selectedFig = pManager->getSelectedFig();

	if (selectedFig != NULL) {
		pManager->setClipboard(selectedFig);
		pOut->PrintMessage("Selected figure is cut to clipboard");

		//Remove the figure
		pManager->RemoveFigure(selectedFig);
		pManager->setSelectedFig(NULL);
		selectedFig->SetSelected(false);
	}
	else {
		pOut->PrintMessage("No figure is selected to cut it. Select a figure first");
	}
}

