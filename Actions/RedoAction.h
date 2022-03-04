#pragma once
#include "..\ApplicationManager.h"
#include"Copy.h"
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

class RedoAction : public Action
{
private:
	Component* mComp;
	GraphicsInfo Ginfo;
public:
	/* Constructor */
	RedoAction(ApplicationManager* pAppMan);

	/* Reads parameters required for action to execute */
	virtual void ReadActionParameters();

	/* Executes action */
	virtual bool Execute();

	/* Undo action */
	virtual void Undo();

	/* Redo action */
	virtual void Redo();

	/* Destructor */
	virtual ~RedoAction();
};

