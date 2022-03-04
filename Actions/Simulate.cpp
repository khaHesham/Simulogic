#include"Simulate.h"
#include"../ApplicationManager.h"
#include"CircuitValidation.h"

Simulate::Simulate(ApplicationManager* pIpp) :Action(pIpp)
{

}

Simulate::~Simulate(void)
{

}

void  Simulate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();


}

bool  Simulate::Execute()
{
	CircuitValidation pAct(pManager);
	bool valid = pAct.Execute();
	if (!valid)
		return false;
	int n = pManager->GetCompCount();
	for (int i = 0; i < n; i++)
	{
		Component* cmp = pManager->GetCmp(i);
		if (cmp->GetType() == _SWITCH)
			cmp->Operate();
	}

	return true;
}

void Simulate::Undo()
{

}

void Simulate::Redo()
{

}
