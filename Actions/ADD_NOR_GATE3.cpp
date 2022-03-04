#include"ADD_NOR_GATE3.h"
#include"..\ApplicationManager.h"

ADD_NOR_GATE3::ADD_NOR_GATE3(ApplicationManager* pNo3pp) :Action(pNo3pp)
{
}

ADD_NOR_GATE3::~ADD_NOR_GATE3(void)
{
}

void ADD_NOR_GATE3::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("3 Input NOR Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

bool  ADD_NOR_GATE3::Execute()
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
	NOR3* pNo3 = new NOR3(GInfo, default_FANOUT);
	pManager->AddComponent(pNo3);
	return true;
}

void ADD_NOR_GATE3::Undo()
{
	int x = pManager->GetCompCount();
	if (x == 0)
	{
		return;
	}
	Component* c1 = pManager->GetCmp(x - 1);
	GInfo = c1->GetGInfo();
	c1 = new NOR3(GInfo, default_FANOUT);
	pManager->AddToComp2(c1);
	pManager->DeleteComponent(x - 1);
}

void ADD_NOR_GATE3::Redo()
{
	int x = pManager->GetCompcount2();
	if (x == 0)
	{
		return;
	}
	Component* c1 = pManager->GetComp2(x - 1);
	GInfo = c1->GetGInfo();
	c1 = new NOR3(GInfo, default_FANOUT);
	pManager->AddComponent(c1);
	pManager->RemoveFromComp2(x - 1);
}
