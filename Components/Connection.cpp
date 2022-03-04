#include "Connection.h"

Connection::Connection(const GraphicsInfo& r_GfxInfo, OutputPin* pSrcPin, InputPin* pDstPin, int rSrcCmpntID, int rDstCmpntID, int rDstPinIndex) :Component(r_GfxInfo)
{
	SrcPin = pSrcPin;
	DstPin = pDstPin;
	Isselected = false;
	SrcCmpntID = rSrcCmpntID;
	DstCmpntID = rDstCmpntID;
	DstPinIndex = rDstPinIndex + 1;
	OutIndex = 0;
	Colour = BLACK;
	type = _CONNECTION;
}
void Connection::setOutIndex(int n)
{
	OutIndex = n;
}
int Connection::getOutIndex()
{
	return OutIndex;
}
void Connection::setSourcePin(OutputPin* pSrcPin)
{
	SrcPin = pSrcPin;
}

OutputPin* Connection::getSourcePin()
{
	return SrcPin;
}


void Connection::setDestPin(InputPin* pDstPin)
{
	DstPin = pDstPin;
}

InputPin* Connection::getDestPin()
{
	return DstPin;
}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	DstPin->setStatus((STATUS)SrcPin->getStatus());
	if (SrcPin->getStatus())
		Colour = LIGHTGREEN;
	else
		Colour = DARKGREEN;
	Gate* gate = (Gate*)DstPin->getComponent();
	if (gate->Full())
		gate->Operate();
}

void Connection::Draw(Output* pOut)
{
	if (UI.AppMode == DESIGN)
		Colour = BLACK;
	pOut->DrawConnection(m_GfxInfo, Isselected, Colour);
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstPin->getStatus();
}


int Connection::getDstPinIndex()
{
	return 	DstPinIndex;
}

int Connection::getSrcCmpntID()
{
	return SrcCmpntID;
}

int Connection::getDstCmpntID()
{
	return DstCmpntID;
}

int Connection::GetInputPinStatus(int n)
{
	return SrcPin->getStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcPin->setStatus(s);
}


void Connection::Delete(Output* pOut)
{
	SrcPin->DeleteConn(OutIndex);

	Component* comp = DstPin->getComponent();

	((Gate*)comp)->DecrPin();

	DstPin->Connect(false);

	pOut->RemoveConnection(m_GfxInfo);
}

void Connection::save(ofstream& file, bool connection)
{
	if (connection)
		file << SrcCmpntID << "  " << DstCmpntID << "  " << DstPinIndex << endl;
}
color Connection::getcolor()
{
	return Colour;

}
void Connection::move(int sx, int sy, bool src)
{
	if (src)
	{
		m_GfxInfo.x1 += sx;
		m_GfxInfo.y1 += sy;
	}
	else
	{
		m_GfxInfo.x2 += sx;
		m_GfxInfo.y2 += sy;
	}
}