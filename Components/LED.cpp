#include "LED.h"


LED::LED(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;

	type = _LED;
}


void LED::Operate()
{

}


// Function Draw

void LED::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	bool on = (UI.AppMode == SIMULATION && m_InputPins[0].getStatus()) ? true : false;

	pOut->DrawLED(m_GfxInfo, Isselected, on);
}

//returns status of outputpin
int LED::GetOutPinStatus()
{
	return -1;
}


//returns status of Inputpin #n
int LED::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void LED::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void LED::setm_InputPins()
{
	m_InputPins = new InputPin;
}

void LED::DrawCopied(Output* pOut, GraphicsInfo GInfo)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawLED(GInfo, Isselected);
}

void LED::Delete(Output* pOut)
{
	pOut->clearRectangle(m_GfxInfo);
}

void LED::save(ofstream& file, bool connection)
{
	if (!connection)
		file << "LED" << "	" << ID << "	" << GetLabel() << "	" << m_GfxInfo.x1 << "	" << m_GfxInfo.y1 << endl;
}