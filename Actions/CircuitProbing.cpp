#include"CircuitProbing.h"
#include "..\ApplicationManager.h"


CircuitProbing::CircuitProbing(ApplicationManager* pM) :Action(pM)
{



}

CircuitProbing::~CircuitProbing(void)
{

}

void  CircuitProbing::ReadActionParameters()
{

}

bool  CircuitProbing::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Please select connection you want to know its status");
	while (true)
	{

		pIn->GetPointClicked(x, y);
		if ((y <= UI.ToolBarHeight && x >= 3 * UI.ToolItemWidth && x <= 4 * UI.ToolItemWidth))
		{
			return true;
		}

		cmp = pManager->selectedConn(x, y);
		if (cmp == NULL) continue;

		if (cmp->GetOutPinStatus())
		{
			pOut->PrintMsg("The connection you choose is : HIGH");
		}
		else
			pOut->PrintMsg("The connection you choose is : LOW");
	}

	return true;

}

void CircuitProbing::Undo()
{
	// in simulation no undo nor redo
}

void CircuitProbing::Redo()
{
	//in simulation no undo nor redo
}
