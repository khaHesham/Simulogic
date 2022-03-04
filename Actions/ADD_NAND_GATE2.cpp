#include"ADD_NAND_GATE2.h"
#include"..\ApplicationManager.h"

ADD_NAND_GATE2::ADD_NAND_GATE2(ApplicationManager* pN2pp) :Action(pN2pp)
{
	GInfo.x1 = GInfo.x2 = GInfo.y1 = GInfo.y2 = 0;
}

ADD_NAND_GATE2::~ADD_NAND_GATE2(void)
{
}

void  ADD_NAND_GATE2::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("2 Input NAND Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

bool  ADD_NAND_GATE2::Execute()
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
	NAND2* pN2 = new NAND2(GInfo, default_FANOUT);
	pManager->AddComponent(pN2);
	return true;
}

void ADD_NAND_GATE2::Undo()
{
	int x = pManager->GetCompCount();
	if (x == 0)
	{
		return;
	}
	Component* c1 = pManager->GetCmp(x - 1);
	GInfo = c1->GetGInfo();
	c1 = new NAND2(GInfo, default_FANOUT);
	pManager->AddToComp2(c1);
	pManager->DeleteComponent(x - 1);

}

void ADD_NAND_GATE2::Redo()
{
	int x = pManager->GetCompcount2();
	if (x == 0)
	{
		return;
	}
	Component* c1 = pManager->GetComp2(x - 1);
	GInfo = c1->GetGInfo();
	c1 = new NAND2(GInfo, default_FANOUT);
	pManager->AddComponent(c1);
	pManager->RemoveFromComp2(x - 1);
}
