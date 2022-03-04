#include "XOR3.h"


XOR3::XOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins
	int x, y, z;

	x = GetInputPinStatus(1);
	y = GetInputPinStatus(2);
	z = GetInputPinStatus(3);

	m_OutputPin.setStatus((STATUS)(x ^ y ^ z));
	GetOutPin()->Operate();


}


// Function Draw

void XOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR3(m_GfxInfo, Isselected);
}

//returns status of outputpin
int XOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

void XOR3::DrawCopied(Output* pOut, GraphicsInfo GInfo)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR3(GInfo, Isselected);
}

//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
void XOR3::setm_InputPins()
{
	m_InputPins = new InputPin[3];
}

void XOR3::Delete(Output* pOut)
{
	pOut->clearRectangle(m_GfxInfo);
}

void XOR3::save(ofstream& file, bool connection)
{
	if (!connection)
		file << "XOR3" << "	" << ID << "	" << GetLabel() << "	" << m_GfxInfo.x1 << "	" << m_GfxInfo.y1 << endl;

}