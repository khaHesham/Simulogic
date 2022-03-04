#include "Cut.h"

Cutt::Cutt(ApplicationManager* papp) :Action(papp), Copyy(papp)
{
	Pcomp = NULL;
}

void Cutt::ReadActionParameters()
{
}

bool Cutt::Execute()
{

	Copyy::Execute();
	Copyy::pManager->set_cutcount(Copyy::pManager->get_CopiedCount());
	Output* pOut = Copyy::pManager->GetOutput();

	int size = Copyy::pManager->get_Cutcount();
	if (size != 0)
	{
		pOut->ClearStatusBar();
		pOut->PrintMsg("Cut is done");
	}
	else
	{
		pOut->ClearStatusBar();
		pOut->PrintMsg("please select component/s to be Cut");
	}

	return false;
}

void Cutt::Undo()
{

}

void Cutt::Redo()
{

}
