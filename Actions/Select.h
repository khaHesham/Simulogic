#pragma once
#include"Action.h"
#include"..\Components\Component.h"
#include "..\GUI\Output.h"
class Select :public Action
{
	Component* cmp;
	int x, y;
	Output* pOut;
	bool inside;
public:

	Select(ApplicationManager* pBpp);
	virtual ~Select(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();

};