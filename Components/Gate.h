#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

class Gate :public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
	int PinCount;         //Actual number of input pins
public:
	Gate(int r_Inputs, int r_FanOut);
	virtual void setm_InputPins() = 0;
	void DecrPin();
	void IncrPin();
	OutputPin* GetOutPin();
	InputPin* GetInPin(int n);
	int GetNumInputs();
	int Full();
	void Move(int Cx, int Cy);

};

#endif
