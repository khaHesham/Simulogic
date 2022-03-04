#pragma once
#include"Action.h"
#include"../Components/Component.h"
#include"../ApplicationManager.h"
#include"../GUI/Output.h"

class Copyy : public Action
{

private:
	Output* pOut;
	Input* pIn;
	Component* Pcomp; //pointer to the selected component
	int noofselctd; // no of selected objects
	int x1, y2;	// the point clicked by the user
public:
	Copyy(ApplicationManager* papp);
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();
};


