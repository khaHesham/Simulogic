#include "CircuitValidation.h"
#include "..\ApplicationManager.h"

CircuitValidation::CircuitValidation(ApplicationManager* pBpp) :Action(pBpp)
{
}

CircuitValidation::~CircuitValidation(void)
{

}

void CircuitValidation::ReadActionParameters()
{
}

bool CircuitValidation::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetCompCount() == 0)
	{
		pOut->PrintMsg("Add some components to simulate");
		return false;
	}
	TYPE type;
	cmp = pManager->InValidCmp();
	if (cmp != NULL)
	{
		GInfo = cmp->GetGInfo();
		pOut->PrintMsg("sorry you can't simulate because that marked component has an error in its input and output pins");
		pWind = pOut->getpWind();
		pWind->SetPen(RED, 2);
		pWind->DrawRectangle(GInfo.x1 - 5, GInfo.y1 - 5, GInfo.x2 + 5, GInfo.y2 + 5);
		return false;
	}
	cmp = pManager->FirstLevel();
	if (cmp != NULL)
	{

		type = cmp->GetType();
		if (type != _SWITCH)
		{
			GInfo = cmp->GetGInfo();
			pOut->PrintMsg("sorry you can't simulate because the first level of the circuit must obtain switches only,the marked component isn't switch");
			pWind = pOut->getpWind();
			pWind->SetPen(RED, 2);
			pWind->DrawRectangle(GInfo.x1 - 5, GInfo.y1 - 5, GInfo.x2 + 5, GInfo.y2 + 5);
			return false;
		}
	}
	cmp = pManager->lastLevel();
	if (cmp != NULL)
	{

		type = cmp->GetType();
		if (type != _LED)
		{
			GInfo = cmp->GetGInfo();
			pOut->PrintMsg("sorry you can't simulate because the last level of the circuit must obtain LEDs only,the marked component isn't LED");
			pWind = pOut->getpWind();
			pWind->SetPen(RED, 2);
			pWind->DrawRectangle(GInfo.x1 - 5, GInfo.y1 - 5, GInfo.x2 + 5, GInfo.y2 + 5);
			return false;
		}
	}


	pOut->PrintMsg("your circuit is valid so you can use simulation mode now");

	return true;
}

void CircuitValidation::Undo()
{
}

void CircuitValidation::Redo()
{
}
