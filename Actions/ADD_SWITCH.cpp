#include"ADD_SWITCH.h"
#include"..\ApplicationManager.h"


ADD_SWITCH::ADD_SWITCH(ApplicationManager* pIpp) :Action(pIpp)
{
}

ADD_SWITCH::~ADD_SWITCH(void)
{
}

void  ADD_SWITCH::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("SWITCH : Click to add the COMPONENT");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}


bool ADD_SWITCH::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	if (!(Cy > 2 * UI.ToolBarHeight && Cy < UI.height - UI.StatusBarHeight))
		return false;

	//Calculate the rectangle Corners
	int Len = UI.GateHeight;
	int Wdth = UI.GateHeight;

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	SWITCH* pL = new SWITCH(GInfo, default_FANOUT);
	pManager->AddComponent(pL);
	return true;
}

void ADD_SWITCH::Undo()
{
	int x = pManager->GetCompCount();
	if (x == 0)
	{
		return;
	}
	Component* c1 = pManager->GetCmp(x - 1);
	GInfo = c1->GetGInfo();
	c1 = new SWITCH(GInfo, default_FANOUT);
	pManager->AddToComp2(c1);
	pManager->DeleteComponent(x - 1);
}

void ADD_SWITCH::Redo()
{
	int x = pManager->GetCompcount2();
	if (x == 0)
	{
		return;
	}
	Component* c1 = pManager->GetComp2(x - 1);
	GInfo = c1->GetGInfo();
	c1 = new SWITCH(GInfo, default_FANOUT);
	pManager->AddComponent(c1);
	pManager->RemoveFromComp2(x - 1);
}