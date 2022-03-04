#include "BUFF.h"

BUFF::BUFF(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void BUFF::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	int x;
	x = GetInputPinStatus(1);

	m_OutputPin.setStatus((STATUS)x);
	GetOutPin()->Operate();

}


// Function Draw

void BUFF::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBUFFER(m_GfxInfo, Isselected);
}

//returns status of outputpin
int BUFF::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int BUFF::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void BUFF::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void BUFF::setm_InputPins()
{
	m_InputPins = new InputPin;
}


void BUFF::Delete(Output* pOut)
{
	pOut->clearRectangle(m_GfxInfo);
}

void BUFF::save(ofstream& file, bool connection)
{
	if (!connection) //saving components
		file << "BUFF" << "	" << ID << "	" << GetLabel() << "	" << m_GfxInfo.x1 << "	" << m_GfxInfo.y1 << endl;

}

void BUFF::DrawCopied(Output* pOut, GraphicsInfo GInfo)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBUFFER(GInfo, Isselected);
}
