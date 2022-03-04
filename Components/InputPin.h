#ifndef _INPUTPIN_H
#define _INPUTPIN_H

#include "Pin.h"
class Connection;
class Component; //Forward class declaration

class InputPin : public Pin	//inherited from class Pin
{
	Connection* connection;
	Component* pComp; //Component at which this pin is associated
	bool IsConnected; //bool variable to know is the input pin is connected or not 
public:
	void set_conn(Connection* c);
	Connection* get_conn();
	InputPin();
	void setComponent(Component* pCmp);	//sets the component of this input pin
	Component* getComponent();	//returns the component of this input pin
	void Connect(bool s);
	bool Connected();
	void delconn();
};

#endif