#pragma once
#include"Action.h"
#include"string.h"

class Exit :public Action
{

private:

public:
	Exit(ApplicationManager* pIpp);
	virtual ~Exit(void);

	virtual void ReadActionParameters();

	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();

};