#include "PasteAction.h"

PasteAction::PasteAction(ApplicationManager* pApp) :Action(pApp) {}

void PasteAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Paste Action: Click at a point to paste the figure");

	pIn->GetPointClicked(pClicked.x, pClicked.y);
}

void PasteAction::Execute() {
	Output* pOut = pManager->GetOutput();
	CFigure* clipboard = pManager->getClipboard();

	if (clipboard != NULL) {
		ReadActionParameters();

		//check if the clicked point is within the drawing area
		if (!(pClicked.y >= UI.ToolBarHeight && pClicked.y < UI.height - UI.StatusBarHeight))
		{
			pOut->PrintMessage("Pasting failed! The clicked point is outside the drawing area");
			return;
		}

		//check the type of the figure in the clipboard using dynamic_cast
		if (dynamic_cast<CLine*>(clipboard)) {
			Point p2;
			Point p3;
			clipboard->ShiftCoordinates(pClicked, p2, p3);
			
			//Create a line with shifted coordinates
			CLine* L = new CLine(pClicked, p2, clipboard->getGFxInfo());
			
			//Add the line to the list of figures
			pManager->AddFigure(L);

			pOut->PrintMessage("Line is pasted successfully");
		}
		else if (dynamic_cast<CRectangle*>(clipboard)) {
			Point p2;
			Point p3;

			clipboard->ShiftCoordinates(pClicked, p2, p3);
			//Create a rectangle with shifted coordinates
			CRectangle* R = new CRectangle(pClicked, p2, clipboard->getGFxInfo());
			//Add the rectangle to the list of figures
			pManager->AddFigure(R);

			pOut->PrintMessage("Rectangle is pasted successfully");
		}
		else if (dynamic_cast<CTriangle*>(clipboard)) {
			Point p2;
			Point p3;

			clipboard->ShiftCoordinates(pClicked, p2, p3);
			//Create a triangle with shifted coordinates
			CTriangle* T = new CTriangle(pClicked, p2, p3, clipboard->getGFxInfo());
			//Add the triangle to the list of figures
			pManager->AddFigure(T);

			pOut->PrintMessage("Triangle is pasted successfully");
		}
		else {
			//Create a circle with shifted coordinates
			CCircle* C = new CCircle(pClicked, clipboard->getGFxInfo());

			//Add the circle to the list of figures
			pManager->AddFigure(C);
			pOut->PrintMessage("Circle is pasted successfully");
		}
	}
	else {
		pOut->PrintMessage("Pasting failed. Clipboard is empty");
	}
}

