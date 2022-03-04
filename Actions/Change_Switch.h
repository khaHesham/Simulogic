#pragma once
#include"Action.h"
#include "../Components/SWITCH.h"

class Change_Switch : public Action
{
private:
	GraphicsInfo GInfo;
	SWITCH* Switch;
	int x, y;
public:
	Change_Switch(ApplicationManager* pApp);
	virtual ~Change_Switch(void);

	virtual void ReadActionParameters();
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};