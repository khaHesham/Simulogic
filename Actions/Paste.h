#pragma once
#include "../Actions/Action.h"
#include "../GUI/Output.h"
#include "../ApplicationManager.h"
#include"../Actions/Copy.h"
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
class Paste : public Action
{
	GraphicsInfo Ginfo;
	Copyy* cptr;
	Output* Pout;
	Input* Pin;
	Component* mComp;
	Component** ArrtoPaste;
	int Arrsize;
	int x1, y2;	// the point clicked by the user
	int x2, y1;
public:
	Paste(ApplicationManager* papp);

	virtual void ReadActionParameters();

	virtual bool Execute();

	virtual void Undo();

	virtual void Redo();
};