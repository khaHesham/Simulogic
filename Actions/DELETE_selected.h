#pragma once
#include"Action.h"
#include"..\Components\Component.h"
#include"..\ApplicationManager.h"
#include"..\Components\Connection.h"
#include"..\Actions\Select.h"
#include"../Components/AND2.h"
#include"../Components/AND3.h"
#include"../Components/BUFF.h"
#include "../Components/INV.h"
#include "../Components/LED.h"
#include "../Components/NAND2.h"
#include "../Components/NOR2.h"
#include"../Components/NOR3.h"
#include"../Components/OR2.h"
#include "../Components/SWITCH.h"
#include"../Components/XNOR2.h"
#include"../Components/XOR3.h"
#include"../Components/XOR2.h"
class DELETE_selected :public Action
{
	GraphicsInfo Ginfo;
	Component* mdeletedcomp;
	int noOfDletedComp;
public:
	DELETE_selected(ApplicationManager* pIpp);
	virtual ~DELETE_selected(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();

};
