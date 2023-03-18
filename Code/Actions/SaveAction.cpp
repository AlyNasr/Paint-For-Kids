#include "SaveAction.h"

SaveAction::SaveAction(ApplicationManager* pApp) :Action(pApp) {}

void SaveAction::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Read the text file name from the user
	FileName = pIn->GetSrting(pOut, "Save Action.");
}

void SaveAction::Execute() {

	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//open the file
	FileName += ".txt";
	ofstream outputfile(FileName);
	if (outputfile.is_open()) pOut->PrintMessage(FileName + " is opened successfully");
	
	//write the current drawing color
	color drawcolor = UI.DrawColor;
	if (drawcolor == BLACK) outputfile << BLACK_CLR << '\t';
	else if (drawcolor == RED) outputfile << RED_CLR << '\t';
	else if (drawcolor == BLUE) outputfile << BLUE_CLR << '\t';
	else if (drawcolor == GREEN) outputfile << GREEN_CLR << '\t';

	//write the current filling color
	color fillcolor = UI.FillColor;
	if (fillcolor == WHITE) outputfile << WHITE_CLR << endl;
	else if (fillcolor == BLACK) outputfile << BLACK_CLR << endl;
	else if (fillcolor == RED) outputfile << RED_CLR << endl;
	else if (fillcolor == BLUE) outputfile << BLUE_CLR << endl;
	else if (fillcolor == GREEN) outputfile << GREEN_CLR << endl;

	pManager->SaveGraph(outputfile);

	outputfile.close();
	pOut->PrintMessage("Graph is saved successfully in \"" + FileName +"\"");
}

