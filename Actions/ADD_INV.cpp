#include"ADD_INV.h"
#include"..\ApplicationManager.h"


ADD_INV::ADD_INV(ApplicationManager* pIpp) :Action(pIpp)
{
}

ADD_INV::~ADD_INV(void)
{
}

void  ADD_INV::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("INVERTOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

bool  ADD_INV::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	if (!(Cy > 2 * UI.ToolBarHeight && Cy < UI.height - UI.StatusBarHeight))
		return false;

	//Calculate the rectangle Corners
	int Len = UI.GateWidth;
	int Wdth = UI.GateHeight;

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	INV* pI = new INV(GInfo, default_FANOUT);
	pManager->AddComponent(pI);
	return true;
}

void ADD_INV::Undo()
{
	int x = pManager->GetCompCount();
	if (x == 0)
	{
		return;
	}
	Component* c1 = pManager->GetCmp(x - 1);
	GInfo = c1->GetGInfo();
	c1 = new INV(GInfo, default_FANOUT);
	pManager->AddToComp2(c1);
	pManager->DeleteComponent(x - 1);
}

void ADD_INV::Redo()
{
	int x = pManager->GetCompcount2();
	if (x == 0)
	{
		return;
	}
	Component* c1 = pManager->GetComp2(x - 1);
	GInfo = c1->GetGInfo();
	c1 = new INV(GInfo, default_FANOUT);
	pManager->AddComponent(c1);
	pManager->RemoveFromComp2(x - 1);
}

