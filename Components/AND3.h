#pragma once
#include "Gate.h"


class AND3 :public Gate
{
public:
	AND3(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate
	virtual void Delete(Output* pOut);
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


	virtual void setm_InputPins();

	virtual void save(ofstream& file, bool connection);
	virtual void DrawCopied(Output* pOut, GraphicsInfo GInfo);
};

