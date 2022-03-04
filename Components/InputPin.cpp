#include "InputPin.h"

InputPin::InputPin()
{
	IsConnected = false;
}

void InputPin::setComponent(Component* pCmp)
{
	this->pComp = pCmp;
}

Component* InputPin::getComponent()
{
	return pComp;
}

void InputPin::Connect(bool s)
{
	IsConnected = s;
}

bool InputPin::Connected()
{
	return IsConnected;
}
void InputPin::set_conn(Connection* c)
{
	connection = c;
}
Connection* InputPin::get_conn()
{
	return connection;
}
void InputPin::delconn()
{

}