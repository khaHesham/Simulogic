#include "Component.h"

Component::Component(const GraphicsInfo& r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
}

Component::Component()
{}

Component::~Component()
{}
bool Component::InsideConnection(int x, int y)
{
	int X_intermediate = (m_GfxInfo.x1 + m_GfxInfo.x2) / 2;
	if (((x >= m_GfxInfo.x1) && (x <= X_intermediate) && (y <= m_GfxInfo.y1 + 5) && (y >= m_GfxInfo.y1 - 5)) || ((x <= X_intermediate + 5) && (x >= X_intermediate - 5) && (y <= m_GfxInfo.y1) && (y >= m_GfxInfo.y2)) || ((x <= m_GfxInfo.x2) && (x >= X_intermediate) && (y <= m_GfxInfo.y2 + 5) && (y >= m_GfxInfo.y2 - 5)))
	{
		return true;
	}
	return false;
}
bool Component::InsideArea(int x, int y)
{
	if ((x >= m_GfxInfo.x1) && (x <= m_GfxInfo.x2) && (y >= m_GfxInfo.y1) && (y <= m_GfxInfo.y2))
		return true;

	return false;
}

void Component::DrawName(Output* pOut)
{
	if (m_Label == "empty")
		return;
	GraphicsInfo GI;
	GI.x1 = m_GfxInfo.x1 - 30;
	GI.y1 = m_GfxInfo.y1 - 30;
	GI.x2 = m_GfxInfo.x2 + 10;
	GI.y2 = m_GfxInfo.y2 - 10;
	pOut->SETbrush(BLACK);
	pOut->Drawname(GI, m_Label);
}

bool Component::selected()
{
	return Isselected;
}

void Component::setselected(bool s)
{
	Isselected = s;
}

string Component::GetLabel()
{
	return m_Label;
}

void Component::SetLabel(string label)
{
	m_Label = label;
}

int Component::GetID()
{
	return ID;
}
GraphicsInfo Component::GetGInfo()
{
	return m_GfxInfo;
}

void Component::SetID(int rID)
{
	ID = rID + 1;
}

TYPE Component::GetType()
{
	return type;
}

