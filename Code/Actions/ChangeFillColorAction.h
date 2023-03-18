#pragma once
#include "Action.h"
class ChangeFillColorAction :public Action
{
private:
	color FillColor;
public:
	ChangeFillColorAction(ApplicationManager* pApp, color fillclr);
	void ReadActionParameters();
	void Execute();
};

