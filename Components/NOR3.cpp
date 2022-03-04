#include "NOR3.h"


NOR3::NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void NOR3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	int x, y, z;
	x = GetInputPinStatus(1);
	y = GetInputPinStatus(2);
	z = GetInputPinStatus(3);

	m_OutputPin.setStatus((STATUS)!(x || y || z));
	GetOutPin()->Operate();

}


// Function Draw

void NOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR3(m_GfxInfo, Isselected);
}

//returns status of outputpin
int NOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

void NOR3::DrawCopied(Output* pOut, GraphicsInfo GInfo)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR3(GInfo, Isselected);
}

//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void NOR3::setm_InputPins()
{
	m_InputPins = new InputPin[3];
}

void NOR3::Delete(Output* pOut)
{
	pOut->clearRectangle(m_GfxInfo);
}

void NOR3::save(ofstream& file, bool connection)
{
	if (!connection)
		file << "NOR3" << "	" << ID << "	" << GetLabel() << "	" << m_GfxInfo.x1 << "	" << m_GfxInfo.y1 << endl;

}