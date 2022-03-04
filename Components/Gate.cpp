#include "Gate.h"
#include"Connection.h"

//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut) :m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate

	Isselected = false;
	PinCount = 0;
	SetLabel("empty");
	type = _GATE;

	//Associate all input pins to this gate
	for (int i = 0; i < m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}

int Gate::GetNumInputs()
{
	return m_Inputs;
}

OutputPin* Gate::GetOutPin()
{
	return &m_OutputPin;
}

InputPin* Gate::GetInPin(int n)
{
	return &m_InputPins[n];
}

int Gate::Full()
{
	if (PinCount == m_Inputs)
		return true;
	return false;
}

void Gate::IncrPin()
{
	PinCount++;
}
void Gate::DecrPin()
{
	PinCount--;
}

void Gate::Move(int Cx, int Cy)
{
	int Len = UI.GateWidth;
	int Wdth = UI.GateHeight;
	if (type == _SWITCH || type == _LED)
	{
		Len = UI.GateHeight;
	}

	GraphicsInfo shift = m_GfxInfo;

	m_GfxInfo.x1 = Cx - Len / 2;
	m_GfxInfo.x2 = Cx + Len / 2;
	m_GfxInfo.y1 = Cy - Wdth / 2;
	m_GfxInfo.y2 = Cy + Wdth / 2;

	if (!(m_GfxInfo.y1 > 2 * UI.ToolBarHeight && m_GfxInfo.y2 < (UI.height - UI.StatusBarHeight)  && m_GfxInfo.x2 < 1040))
	{
		m_GfxInfo = shift;
		return;
	}

	shift.x1 = m_GfxInfo.x1 - shift.x1;
	shift.x2 = m_GfxInfo.x2 - shift.x2;
	shift.y1 = m_GfxInfo.y1 - shift.y1;
	shift.y2 = m_GfxInfo.y2 - shift.y2;

	for (int i = 0; i < PinCount; i++)
	{
		m_InputPins[i].get_conn()->move(shift.x1, shift.y1, false);
	}
	m_OutputPin.move(shift.x2, shift.y1);
}