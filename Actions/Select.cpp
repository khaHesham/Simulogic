#include "Select.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Output.h"

Select::Select(ApplicationManager* pBpp) :Action(pBpp)
{


}

Select::~Select(void)
{
}

void Select::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pOut = pManager->GetOutput();
	pIn->GetLastClick(x, y);
}

bool Select::Execute()
{

	ReadActionParameters();


	cmp = pManager->SelectedCmp(x, y);
	if (cmp == NULL)
	{
		cmp = pManager->selectedConn(x, y);
		if (cmp == NULL)
			return false;
	}


	if (cmp->selected())
	{
		cmp->setselected(false);
	}
	else
	{
		cmp->setselected(true);
	}
	cmp->Draw(pOut);

	return false;


}

void Select::Redo()
{
	
}


void Select::Undo()
{
	
}

