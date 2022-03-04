#pragma once
#include "Action.h"
#include"../Components/Connection.h"
#include "..\Components\InputPin.h"
#include "..\Components\OutputPin.h"
#include"../GUI/Input.h"

class CircuitProbing :public Action
{
	GraphicsInfo GInfo;
	Component* cmp;
	window* pWind;
	int x, y;
public:
	CircuitProbing(ApplicationManager* pBpp);
	virtual ~CircuitProbing(void);

	virtual void ReadActionParameters();
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();

};