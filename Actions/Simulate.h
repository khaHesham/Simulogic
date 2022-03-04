#pragma once
#include"Action.h"
#include "../Components/Connection.h"


class Simulate : public Action
{
private:
	GraphicsInfo GInfo;
public:
	Simulate(ApplicationManager* pApp);
	virtual ~Simulate(void);

	virtual void ReadActionParameters();
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();

};