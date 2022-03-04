#include "Copy.h"



Copyy::Copyy(ApplicationManager* papp) : Action(papp) //papp pointer to applicationmanger wad7aa a3tkd :)
{

	Pcomp = NULL;
	x1 = 0; 
	y2 = x1;
	noofselctd = 0;
	pOut = NULL;
	pIn = NULL;
}
void Copyy::ReadActionParameters()
{

}

bool Copyy::Execute()
{
	
	pOut = pManager->GetOutput();
	pIn  = pManager->GetInput();
	int size = pManager->GetCompCount();
	for (int k = 0 ; k < size ; k++)
	{

		Pcomp = pManager->GetCmp(k);
		
		if (Pcomp->selected())
		{
			pManager->set_copied_list(Pcomp);
		}
	}
	size = pManager->get_CopiedCount();
	if (size != 0)
	{
		pOut->ClearStatusBar();
		pOut->PrintMsg("copy is done");
	}
	else
	{
		pOut->ClearStatusBar();
		pOut->PrintMsg("please select component/s to be copied");
	}
	return false;
}

void Copyy::Undo()
{

}

void Copyy::Redo()
{

}


