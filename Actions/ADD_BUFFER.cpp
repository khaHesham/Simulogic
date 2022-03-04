#include"ADD_BUFFER.h"
#include"..\ApplicationManager.h"

ADD_BUFFER::ADD_BUFFER(ApplicationManager* pIpp) :Action(pIpp)
{
}

ADD_BUFFER::~ADD_BUFFER(void)
{
}

void  ADD_BUFFER::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("BUFFER Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}
bool  ADD_BUFFER::Execute()
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
	BUFF* pI = new BUFF(GInfo, default_FANOUT);
	pManager->AddComponent(pI);
	return true;
}

void ADD_BUFFER::Undo()
{
	int x = pManager->GetCompCount();
	if (x == 0)
	{
		return;
	}
	Component* c1 = pManager->GetCmp(x - 1);
	GInfo = c1->GetGInfo();
	c1 = new BUFF(GInfo, default_FANOUT);
	pManager->AddToComp2(c1);
	pManager->DeleteComponent(x - 1);
}

void ADD_BUFFER::Redo()
{
	int x = pManager->GetCompcount2();
	Component* c1 = pManager->GetComp2(x - 1);
	GInfo = c1->GetGInfo();
	c1 = new BUFF(GInfo, default_FANOUT);
	pManager->AddComponent(c1);
	pManager->RemoveFromComp2(x - 1);
}
