#include "DeleteAction.h"

DeleteAction::DeleteAction(ApplicationManager* pApp):Action(pApp){}

void DeleteAction::ReadActionParameters(){}

void DeleteAction::Execute() {
	Output* pOut = pManager->GetOutput();
	CFigure* selectedFig = pManager->getSelectedFig();

	if (selectedFig != NULL) {
		pManager->RemoveFigure(selectedFig);
		pManager->setSelectedFig(NULL);
		pOut->PrintMessage("The selected figure is deleted");

		selectedFig->SetSelected(false);
		delete selectedFig;
	}
	else {
		pOut->PrintMessage("No figure is selected to delete it. Select a figure first");
	}

}