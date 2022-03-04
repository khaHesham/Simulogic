#pragma once

#include"Action.h"
#include"..\Components\NOR2.h"

class ADD_NOR_GATE2 : public Action
{
private:
	GraphicsInfo GInfo;
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ADD_NOR_GATE2(ApplicationManager* pNo2pp);
	virtual ~ADD_NOR_GATE2(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};