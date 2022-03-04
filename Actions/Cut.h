#pragma once
#include "../Actions/Action.h"
#include"../Components/Component.h"
#include"../ApplicationManager.h"
#include"../GUI/Output.h"
#include"../Actions/Copy.h"
class Cutt :
	public Action, public Copyy
{
private:

	Component* Pcomp; //pointer to the selected component

public:
	Cutt(ApplicationManager* papp);
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();
};

