#pragma once
#include "Action.h"
#include "../GUI/Input.h"
#include"../GUI/Output.h"
#include "../ApplicationManager.h"
#include "../Defs.H"
#include <string>
class EditLabel :
	public Action
{
private:
	// el Graphics bta3t el gate el ana ha3dlha 
	Output* pOut;
	Input* pIn;
	Component* Pcomp;
	string name;
	GraphicsInfo GI;
	string label;
	string Choice;
public:
	EditLabel(ApplicationManager* pApp);
	virtual ~EditLabel(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};
