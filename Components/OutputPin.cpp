#include "OutputPin.h"
#include "Connection.h"

OutputPin::OutputPin(int r_FanOut)
{
	m_Conn = 0;		//initially Pin is not connected to anything.
	m_FanOut = r_FanOut > MAX_CONNS ? MAX_CONNS : r_FanOut;	//set the fan out of the pin.

}

//Functionn ConnectTo:
//Connects the ouput pin the the passed connection if the fan out permits
//if the no. of connections is already equals to the fan out, no more connections can be created.
bool OutputPin::ConnectTo(Connection* r_Conn)
{
	if (m_Conn < m_FanOut)
	{
		r_Conn->setOutIndex(m_Conn);
		m_Connections[m_Conn++] = r_Conn;	//add a new connection the the array of connections
		return true;
	}

	return false;	//can't connect to any more connections
}

void OutputPin::Decr_m_conn()
{
	m_Conn--;
}

bool OutputPin::full()
{
	if (m_Conn == m_FanOut)
		return true;
	return false;
}

void OutputPin::Operate()
{
	for (int i = 0; i < m_Conn; i++)
	{
		m_Connections[i]->Operate();
	}
}
void OutputPin::DeleteConn(int n)
{
	for (int i = n; i < m_Conn - 1; i++)
	{
		m_Connections[i] = m_Connections[i + 1];
	}
	m_Conn--;
}


void OutputPin::selectConn()
{
	for (int i = 0; i < m_Conn; i++)
	{
		m_Connections[i]->setselected(true);
	}
}
int OutputPin::getConnNumber()
{
	return m_Conn;
}
void OutputPin::setconnected(bool s)
{
	isconnected = s;
}
bool OutputPin::getconnected()
{
	return isconnected;
}

void OutputPin::move(int sx, int sy)
{
	for (int i = 0; i < m_Conn; i++)
	{
		m_Connections[i]->move(sx, sy, true);
	}
}