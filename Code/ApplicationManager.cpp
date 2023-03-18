#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\AddCircAction.h"
#include"Actions/ChangeDrawColorAction.h"
#include"Actions/ChangeFillColorAction.h"
#include"Actions/SelectAction.h"
#include"Actions/DeleteAction.h"
#include"Actions/CopyAction.h"
#include"Actions/CutAction.h"
#include"Actions/PasteAction.h"
#include"Actions/SaveAction.h"
#include"Actions/LoadAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	pOut->PrintMessage("Welcome to Paint For Kids Application");

	FigCount = 0;
	SelectedFig = NULL;
	Clipboard = NULL;

	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}

//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case DRAW_CIRC:
			pAct = new AddCircAction(this);
			break;

		case CHNG_DRAW_CLR_BLACK:
			pAct = new ChangeDrawColorAction(this, BLACK);
			break;

		case CHNG_DRAW_CLR_RED:
			pAct = new ChangeDrawColorAction(this, RED);
			break;

		case CHNG_DRAW_CLR_BLUE:
			pAct = new ChangeDrawColorAction(this, BLUE);
			break;

		case CHNG_DRAW_CLR_GREEN:
			pAct = new ChangeDrawColorAction(this, GREEN);
			break;
		
		case CHNG_FILL_CLR_BLACK:
			pAct = new ChangeFillColorAction(this, BLACK);
			break;

		case CHNG_FILL_CLR_RED:
			pAct = new ChangeFillColorAction(this, RED);
			break;

		case CHNG_FILL_CLR_BLUE:
			pAct = new ChangeFillColorAction(this, BLUE);
			break;

		case CHNG_FILL_CLR_GREEN:
			pAct = new ChangeFillColorAction(this, GREEN);
			break;

		case CHNG_FILL_CLR_WHITE:
			pAct = new ChangeFillColorAction(this, WHITE);
			break;

		case SEL:
			pAct = new SelectAction(this);
			break;

		case DEL:
			pAct = new DeleteAction(this);
			break;

		case COPY:
			pAct = new CopyAction(this);
			break;

		case CUT:
			pAct = new CutAction(this);
			break;

		case PASTE:
			pAct = new PasteAction(this);
			break;

		case SAVE:
			pAct = new SaveAction(this);
			break;

		case LOAD:
			pAct = new LoadAction(this);
			break;

		case EXIT:	    
			return;

		case STATUS:	    //a click on the status bar ==> no action
			return;

		case EMPTY:	        //a click on an empty part in status bar ==> no action
			return;

		case DRAWING_AREA:	//a click on an empty space in drawing area without meaningful action ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

void ApplicationManager::AddFigure(CFigure* pFig)
{
	if (FigCount < MaxFigCount) {
		FigList[FigCount] = pFig;
		FigList[FigCount]->PrintInfo(pOut);
		FigCount++;
	}
}

void ApplicationManager::RemoveFigure(CFigure* pFig) {
	//Create new array of figures
	CFigure* newList[MaxFigCount];
	for (int i = 0; i < MaxFigCount; i++)
		newList[i] = NULL;

	int j = 0;
	for (int i = 0; i < FigCount; i++) {
		if (FigList[i] != pFig) {
			newList[j] = FigList[i];
			j++;
		}
	}

	FigCount--;

	//Assign FigList to the newList
	for (int i = 0; i < MaxFigCount; i++)
		FigList[i] = newList[i];

}

CFigure *ApplicationManager::GetFigure(Point p) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for (int i = FigCount - 1; i >= 0; i--)
	{
		if (FigList[i]->IsPointInside(p) == true)
			return FigList[i];
	}
	return NULL;
}

void ApplicationManager::SaveGraph(ofstream& outputfile) {
	outputfile << FigCount << endl;
	for (int i = 0; i < FigCount; i++) {
		FigList[i]->Save(outputfile);
	}
}

void ApplicationManager::ClearGraph() {
	for (int i = 0; i < FigCount; i++) {
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
	CFigure::ResetCount();
	Clipboard = NULL;
}

void ApplicationManager::setSelectedFig(CFigure* ptr) {
	SelectedFig = ptr;
}
CFigure* ApplicationManager::getSelectedFig() const {
	return SelectedFig;
}

void ApplicationManager::setClipboard(CFigure* ptr) {
	Clipboard = ptr;
}
CFigure* ApplicationManager::getClipboard() const {
	return Clipboard;
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();
	for (int i = 0; i < FigCount; i++) 
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	
	pOut->CreateDrawToolBar();
}

Input *ApplicationManager::GetInput() const
{	return pIn; }

Output *ApplicationManager::GetOutput() const
{	return pOut; }

//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;	
}
