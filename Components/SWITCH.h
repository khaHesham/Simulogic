#pragma once
#include "Gate.h"
class SWITCH :
	public Gate
{
public:
	SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);
	virtual void Delete(Output* pOut);
	virtual int GetOutPinStatus();
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setm_InputPins();
	void ChangeStatus();
	virtual void DrawCopied(Output* pOut, GraphicsInfo GInfo);
	virtual void setInputPinStatus(int n, STATUS s);//set status of Inputpin # n, to be used by connection class.
	virtual void save(ofstream& file, bool connection);

};

