#ifndef ADD_RECT_ACTION_H
#define ADD_RECT_ACTION_H

#include "Action.h"

class AddRectAction: public Action
{
private:
	Point P1, P2; 
	GfxInfo RectGfxInfo;
public:
	AddRectAction(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute() ;	
};

#endif