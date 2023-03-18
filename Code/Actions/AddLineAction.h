#pragma once
#include "Action.h"
class AddLineAction :  public Action
{
private:
	Point P1, P2;        //Line points
	GfxInfo LineGfxInfo;
public:
	AddLineAction(ApplicationManager* pApp);

	//Reads Line parameters
	virtual void ReadActionParameters();

	//Add Line to the ApplicationManager
	virtual void Execute();

};

