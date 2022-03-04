#pragma once

#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "UI_Info.h"

class Output;
class Input		//The application manager should have a pointer to this class
{
private:
	int mLastX, mLastY;		// Last point clicked
	bool AddGate;
	window* pWind;	//Pointer to the Graphics Window

public:
	Input(window*);
	clicktype GetPointClicked(int&, int&);	//Get coordinate where user clicks
	bool GetMousePosition(int&, int&);
	void GetLastClick(int&, int&);
	string GetSrting(Output*);		//Returns a string entered by the user
	clicktype Highlight(int& x, int& y);
	char GetKeyPress();
	ActionType GetUserAction(); //Reads the user click and maps it to an action

	~Input();
};
