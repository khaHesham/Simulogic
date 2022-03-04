#include"ADD_LED.h"
#include"..\ApplicationManager.h"

ADD_LED::ADD_LED(ApplicationManager* pIpp) :Action(pIpp)
{
}

ADD_LED::~ADD_LED(void)
{
}

void  ADD_LED::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("LED : Click to add the COMPONENT");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}


bool  ADD_LED::Execute()
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
	LED* pL = new LED(GInfo, default_FANOUT);
	pManager->AddComponent(pL);
	return true;
}

void ADD_LED::Undo()
{
	int x = pManager->GetCompCount();
	if (x == 0)
	{
		return;
	}
	Component* c1 = pManager->GetCmp(x - 1);
	GInfo = c1->GetGInfo();
	c1 = new LED(GInfo, default_FANOUT);
	pManager->AddToComp2(c1);
	pManager->DeleteComponent(x - 1);

}

void ADD_LED::Redo()
{
	int x = pManager->GetCompcount2();
	if (x == 0)
	{
		return;
	}
	Component* c1 = pManager->GetComp2(x - 1);
	GInfo = c1->GetGInfo();
	c1 = new LED(GInfo, default_FANOUT);
	pManager->AddComponent(c1);
	pManager->RemoveFromComp2(x - 1);
}
