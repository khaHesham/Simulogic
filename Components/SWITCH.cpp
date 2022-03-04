#include "SWITCH.h"

SWITCH::SWITCH(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;

	type = _SWITCH;
}


void SWITCH::Operate()
{
	GetOutPin()->Operate();
}


// Function Draw

void SWITCH::Draw(Output* pOut )
{
	//Call output class and pass gate drawing info to it.
	bool on = (m_OutputPin.getStatus() && UI.AppMode == SIMULATION) ? true : false;
	pOut->DrawSwitch(m_GfxInfo, Isselected, on);
}
//returns status of outputpin
int SWITCH::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int SWITCH::GetInputPinStatus(int n)
{
	return -1;	//n starts from 1 but array index starts from 0.
}


void SWITCH::setm_InputPins()
{

}


//Set status of an input pin ot HIGH or LOW
void SWITCH::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}



void SWITCH::Delete(Output *pOut)
{
    pOut->clearRectangle(m_GfxInfo);
}

void SWITCH::save(ofstream& file, bool connection)
{
	if (!connection)
		file << "SWITCH" << "	" << ID << "	" << GetLabel() << "	" << m_GfxInfo.x1 << "	" << m_GfxInfo.y1 << endl;

}

void SWITCH::ChangeStatus()
{
	if (m_OutputPin.getStatus() == HIGH)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);
}

void SWITCH::DrawCopied(Output* pOut, GraphicsInfo GInfo)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawSwitch(GInfo, Isselected);
}
