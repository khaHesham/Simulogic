#pragma once
#include"Action.h"
#include"..\Components\AND3.h"

class Move : public Action
{
private:

public:
	Move(ApplicationManager* pApp);
	virtual ~Move(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};