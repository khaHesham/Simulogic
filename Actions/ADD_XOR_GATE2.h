# pragma once
#include"Action.h"
#include"..\Components\XOR2.h"

class ADD_XOR_GATE2 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	GraphicsInfo GInfo;
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ADD_XOR_GATE2(ApplicationManager* pXpp);
	virtual ~ADD_XOR_GATE2(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};
