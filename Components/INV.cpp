#include "INV.h"
INV::INV(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void INV::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	int x;
	x = GetInputPinStatus(1);

	m_OutputPin.setStatus((STATUS)!x);
	GetOutPin()->Operate();
}


// Function Draw
// Draws 2-input AND gate
void INV::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawINV(m_GfxInfo, Isselected);
}

//returns status of outputpin
int INV::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int INV::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void INV::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void INV::setm_InputPins()
{
	m_InputPins = new InputPin;
}

void INV::DrawCopied(Output* pOut, GraphicsInfo GInfo)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawINV(GInfo, Isselected);
}

void INV::Delete(Output* pOut)
{
	pOut->clearRectangle(m_GfxInfo);
}

void INV::save(ofstream& file, bool connection)
{
	if (!connection)
		file << "INV" << "	" << ID << "	" << GetLabel() << "	" << m_GfxInfo.x1 << "	" << m_GfxInfo.y1 << endl;

}