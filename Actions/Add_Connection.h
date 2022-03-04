#pragma once
#include "Action.h"
#include"../Components/Connection.h"
#include "..\Components\InputPin.h"
#include "..\Components\OutputPin.h"

class Add_Connection :public Action
{

private:
	GraphicsInfo GInfo;
	int x1, y1;//coordinates of the source pin
	int x2, y2;//coordinates of the destination pin
	Component* cmpSource; //source component
	Component* cmpDest; //destination component
	InputPin* InPutPin;
	OutputPin* OutPutPin;
public:
	Add_Connection(ApplicationManager* pBpp);
	virtual ~Add_Connection(void);

	virtual void ReadActionParameters();
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();

};
