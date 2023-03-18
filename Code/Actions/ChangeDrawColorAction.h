#pragma once
#include "Action.h"
class ChangeDrawColorAction : public Action
{
private:
	color DrawColor;
public:
	ChangeDrawColorAction(ApplicationManager* pApp, color drawClr);
	void ReadActionParameters();
	void Execute();
};

