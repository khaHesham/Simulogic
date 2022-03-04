#pragma once
#include"Action.h"
#include"..\Components\NAND2.h"

class ADD_NAND_GATE2 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	GraphicsInfo GInfo;
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ADD_NAND_GATE2(ApplicationManager* pN2pp);
	virtual ~ADD_NAND_GATE2(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};
