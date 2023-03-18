#include "CopyAction.h"

CopyAction::CopyAction(ApplicationManager* pApp) :Action(pApp) {}

void CopyAction::ReadActionParameters() {}

void CopyAction::Execute() {
	Output* pOut = pManager->GetOutput();
	CFigure* selectedFig = pManager->getSelectedFig();

	if (selectedFig != NULL) {
		pManager->setClipboard(selectedFig);
		pOut->PrintMessage("Selected figure is copied to clipboard");

		//Unselect the figure
		pManager->setSelectedFig(NULL);
		selectedFig->SetSelected(false);
	}
	else {
		pOut->PrintMessage("No figure is selected to copy it. Select a figure first");
	}
}
