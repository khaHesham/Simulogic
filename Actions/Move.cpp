#include"Move.h"
#include"..\ApplicationManager.h"

Move::Move(ApplicationManager* popp) :Action(popp)
{

}

Move::~Move(void)
{
}

void Move::ReadActionParameters()
{

}

bool Move::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	int x, y;
	pIn->GetLastClick(x, y);
	Component* cmp = pManager->SelectedCmp(x, y);

	if (cmp == NULL)
		return true;

	while (true)
	{
		bool down = pIn->GetMousePosition(x, y);
		if (y < 2 * UI.ToolBarHeight)
			break;
		if (down)
		{
			((Gate*)cmp)->Move(x, y);
			pOut->ClearDrawingArea();
			pManager->UpdateInterface();
			Sleep(100);
		}
	}
	return true;
}

void Move::Undo()
{}

void Move::Redo()
{}