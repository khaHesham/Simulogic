#include "OR2.h"

OR2::OR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void OR2::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	int x, y;
	x = GetInputPinStatus(1);
	y = GetInputPinStatus(2);

	m_OutputPin.setStatus((STATUS)(x || y));
	GetOutPin()->Operate();

}


// Function Draw
// Draws 2-input AND gate
void OR2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawOR2(m_GfxInfo, Isselected);
}

//returns status of outputpin
int OR2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int OR2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void OR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

void OR2::setm_InputPins()
{
	m_InputPins = new InputPin[2];
}

void OR2::Delete(Output* pOut)
{
	pOut->clearRectangle(m_GfxInfo);
}

void OR2::save(ofstream& file, bool connection)
{
	if (!connection)
		file << "OR2" << "	" << ID << "	" << GetLabel() << "	" << m_GfxInfo.x1 << "	" << m_GfxInfo.y1 << endl;

}

void OR2::DrawCopied(Output* pOut, GraphicsInfo GInfo)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawOR2(GInfo, Isselected);
}
