#pragma once
#include "Action.h"

class SaveAction : public Action
{
private:
	string FileName;
public:
	SaveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

