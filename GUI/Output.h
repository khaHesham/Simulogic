#pragma once
#include "..\Defs.h"
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window

public:
	Output(); // Performs the Window Initialization
	Input* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;
	void EditConn() const;
	void clearEdit() const;
	void CreateDesignToolBar() const;	//Tool bar of the design mode
	void CreateAddGateToolBar() const; //tool bar  ------------------->
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void clearRectangle(GraphicsInfo g) const;
	void SETbrush(color c);
	void Drawname(GraphicsInfo Ginfo, string name);
	void CreateStatusBar() const;	//Create Status bar
	window* getpWind();
	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area
	void ClearAddGateBar() const;  //clears ADD Gate Bar & Simulation Bar    --------------------->
	void ClearFirstBar() const;
	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window
	void RemoveConnection(GraphicsInfo r_GfxInfo) const;

	// Draws 2-input AND gate
	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNAND2(GraphicsInfo r_GfxInfo, bool selected = false) const; //----------------------->trial
	void DrawOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawINV(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXNOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawLED(GraphicsInfo r_GfxInfo, bool selected = false, bool on = false) const;
	void DrawSwitch(GraphicsInfo r_GfxInfo, bool selected = false, bool on = false) const;
	void Drawremove(GraphicsInfo r_GfxInfo) const;
	// Draws Connection
	void DrawConnection(GraphicsInfo r_GfxInfo, bool s, color colour = BLACK) const;

	void PrintMsg(string msg) const;	//Print a message on Status bar

	~Output();
};
