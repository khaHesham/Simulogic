#pragma once
#include "Action.h"
#include"../Components/Connection.h"
#include "..\Components\InputPin.h"
#include "..\Components\OutputPin.h"
#include"../GUI/Input.h"

class CircuitValidation :public Action
{
	GraphicsInfo GInfo;
	Component* cmp;
	window* pWind;
public:
	CircuitValidation(ApplicationManager* pBpp);
	virtual ~CircuitValidation(void);

	virtual void ReadActionParameters();
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();

};