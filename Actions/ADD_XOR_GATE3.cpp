#include"ADD_XOR_GATE3.h"
#include"..\ApplicationManager.h"

ADD_XOR_GATE3::ADD_XOR_GATE3(ApplicationManager* pXo3pp) :Action(pXo3pp)
{
}

ADD_XOR_GATE3::~ADD_XOR_GATE3(void)
{
}

void  ADD_XOR_GATE3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3 Input XOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}



bool  ADD_XOR_GATE3::Execute()
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
	XOR3* pxo3 = new XOR3(GInfo, default_FANOUT);
	pManager->AddComponent(pxo3);
	return true;
}

void ADD_XOR_GATE3::Undo()
{
	int count = pManager->GetCompCount();
	if (count == 0)
	{
		return;
	}
	Component* c1 = pManager->GetCmp(count - 1);
	GInfo = c1->GetGInfo();
	c1 = new XOR3(GInfo, default_FANOUT);
	pManager->AddToComp2(c1);
	pManager->DeleteComponent(count - 1);
}

void ADD_XOR_GATE3::Redo()
{
	int count = pManager->GetCompcount2();
	if (count == 0)
	{
		return;
	}
	Component* c1 = pManager->GetComp2(count - 1);
	GInfo = c1->GetGInfo();
	c1 = new XOR3(GInfo, default_FANOUT);
	pManager->AddComponent(c1);
	pManager->RemoveFromComp2(count - 1);
}
