#pragma once
#include "component.h"
#include "InputPin.h"
#include "OutputPin.h"
#include "Gate.h"

class Connection : public Component
{
	int	SrcCmpntID;	 //Connection source component
	int	DstCmpntID;	 //Connection Destination component
	int	DstPinIndex; //The Input pin to which this connection is linked
	color Colour;
	int OutIndex;
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
public:
	void setOutIndex(int n);
	int getOutIndex();
	//Connection(const GraphicsInfo &r_GfxInfo, Component *pS=NULL,Component *pD=NULL, int Pin=0);
	Connection(const GraphicsInfo& r_GfxInfo, OutputPin* pSrcPin, InputPin* pDstPin, int rSrcCmpntID, int DstCmpntID, int rDstPinIndex);

	virtual void Operate();	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut);	//for each component to Draw itself


	void setSourcePin(OutputPin* pSrcPin);
	void setDestPin(InputPin* pDstPin);
	OutputPin* getSourcePin();
	InputPin* getDestPin();
	virtual void save(ofstream& file, bool connection);

	int getDstPinIndex();
	int getSrcCmpntID();
	int getDstCmpntID();
	color getcolor();
	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	void move(int sx, int sy, bool src);

	virtual void Delete(Output* pOut);
};
