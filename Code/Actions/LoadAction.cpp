#include "LoadAction.h"

LoadAction::LoadAction(ApplicationManager* pApp) :Action(pApp) {}

void LoadAction::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Read the text file name from the user
	FileName = pIn->GetSrting(pOut, "Load Action.");
}

void LoadAction::Execute() {

	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Open the file
	FileName += ".txt";
	ifstream inputfile(FileName);
	
	if (inputfile.is_open()) {
		int drawclr, fillclr;
		inputfile >> drawclr >> fillclr;
		switch (drawclr) {
		case BLACK_CLR:
			UI.DrawColor = BLACK;
			break;
		case RED_CLR:
			UI.DrawColor = RED;
			break;
		case BLUE_CLR:
			UI.DrawColor = BLUE;
			break;
		case GREEN_CLR: 
			UI.DrawColor = GREEN;
			break;
		default: 
			UI.DrawColor = BLACK;
		}

		switch (fillclr) {
		case BLACK_CLR:
			UI.FillColor = BLACK;
			break;
		case RED_CLR:
			UI.FillColor = RED;
			break;
		case BLUE_CLR:
			UI.FillColor = BLUE;
			break;
		case GREEN_CLR:
			UI.FillColor = GREEN;
			break;
		case WHITE_CLR:
			UI.FillColor = WHITE;
			break;
		default:
			UI.FillColor = WHITE;	
		}

		pManager->ClearGraph();

		int figcount;
		inputfile >> figcount;
		
		CFigure* fig;
		Point P1, P2, P3;
		P1.x = P1.y = P2.x = P2.y = P3.x = P3.y = 0;
		for (int i = 0; i < figcount;i++) {
			int type;
			inputfile >> type;
			if (type == LINE) {
				fig = new CLine(P1, P2, FigGfxInfo);
				fig->Load(inputfile);
			}
			else if (type == RECTANGLE) {
				fig = new CRectangle(P1, P2, FigGfxInfo);
				fig->Load(inputfile);
			}
			else if (type == TRIANGLE) {
				fig = new CTriangle(P1, P2, P3, FigGfxInfo);
				fig->Load(inputfile);
			}
			else if (type == CIRCLE) {
				fig = new CCircle(P1, FigGfxInfo);
				fig->Load(inputfile);
			}
			pManager->AddFigure(fig);
		}
		pOut->PrintMessage("File is loaded successfully");
	}
	else pOut->PrintMessage("Failed to load the file. Make sure the file exists in the same project folder");

	inputfile.close();
}