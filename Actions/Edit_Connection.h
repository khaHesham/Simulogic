#pragma once
#include"Action.h"
#include"..\Components\Component.h"
#include"..\Components\InputPin.h"
#include"..\Components\OutputPin.h"
class EditConnection :public Action
{
private:
	int x, y;
	Component* connection;
	Component* DestComp;
	Component* SourceComp;
	GraphicsInfo GInfo;


public:
	EditConnection(ApplicationManager* pECpp);
	virtual ~EditConnection(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();
};
