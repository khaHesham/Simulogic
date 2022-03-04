#include"Change_Switch.h"
#include"../ApplicationManager.h"

Change_Switch::Change_Switch(ApplicationManager* pIpp) :Action(pIpp)
{

}

Change_Switch::~Change_Switch(void)
{

}

void  Change_Switch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pIn->GetLastClick(x, y);


	Component* cmp = pManager->SelectedCmp(x, y);

	if (cmp != NULL && cmp->GetType() == _SWITCH) //if the user clicked on a switch
		Switch = (SWITCH*)cmp;

	else Switch = NULL;

}

bool  Change_Switch::Execute()
{
	ReadActionParameters();
	if (Switch == NULL)
		return true;

	Switch->ChangeStatus();
	Switch->Operate();

	return true;
}

void Change_Switch::Undo()
{
	// in simulation no undo nor redo
}

void Change_Switch::Redo()
{
	//in simulation no undo nor redo
}
