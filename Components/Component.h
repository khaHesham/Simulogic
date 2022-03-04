#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include<fstream>

//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;

protected:
	int ID;
	bool Isselected;
	GraphicsInfo m_GfxInfo;	//The parameters required to draw a component
	TYPE type;

public:
	Component(const GraphicsInfo& r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	bool InsideArea(int x, int y);
	void DrawName(Output* pOut);
	bool selected();
	void setselected(bool s);
	bool InsideConnection(int x, int y);
	virtual int GetOutPinStatus() = 0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n) = 0;	//returns status of Inputpin # n if SWITCH, return -1
	virtual void setInputPinStatus(int n, STATUS s) = 0;	//set status of Inputpin # n, to be used by connection class.
	virtual void Delete(Output* pOut) = 0;
	Component();

	virtual void save(ofstream& file, bool connection) = 0;

	void SetLabel(string label);
	string GetLabel();
	int GetID();
	void SetID(int rID);
	GraphicsInfo GetGInfo();
	TYPE GetType();
	void Move(int Cx, int Cy);
	virtual void DrawCopied(Output* pOut, GraphicsInfo GInfo) {};
	//Destructor must be virtual
	virtual ~Component();
};

#endif
