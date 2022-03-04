#include "EditLabel.h"

EditLabel::EditLabel(ApplicationManager* pApp) :Action(pApp)
{
	pOut = NULL;
	pIn = NULL;
	GI.x1 = 0;
	GI.x2 = 0;
	GI.y1 = 0;
	GI.y2 = 0;
	Pcomp = NULL;
	Choice = " ";
}

EditLabel::~EditLabel(void)
{
}

void EditLabel::ReadActionParameters()
{

	pOut = pManager->GetOutput();
	do
	{
		pOut->PrintMsg("for Adding or changing current name enter A or C, while for deleting enter D");
		pIn = pManager->GetInput();
		Choice = pIn->GetSrting(pOut);

	} while (Choice != "A" && Choice != "C" && Choice != "D" && Choice != "a" && Choice != "c" && Choice != "d");

}

bool EditLabel::Execute()
{
	ReadActionParameters();
	if (Choice == "C" || Choice == "A" || Choice == "a" || Choice == "c")
	{
		pOut->PrintMsg("select a component to change its name");
		pIn = pManager->GetInput();
		if (pIn != NULL)
			pIn->GetPointClicked(GI.x1, GI.y1);

		Pcomp = pManager->SelectedCmp(GI.x1, GI.y1);

		while (Pcomp == NULL)
		{
			pOut->PrintMsg(" please click on a Component to Change its name ");
			pIn = pManager->GetInput();
			if (pIn != NULL)
				pIn->GetPointClicked(GI.x1, GI.y1);
			Pcomp = pManager->SelectedCmp(GI.x1, GI.y1);
		}

		pOut = pManager->GetOutput();
		pOut->PrintMsg("please enter the name : ");
		pIn = pManager->GetInput();
		name = pIn->GetSrting(pOut);
		label = Pcomp->GetLabel();

		if (label != "empty")
		{
			GI = Pcomp->GetGInfo();
			GI.x1 = GI.x1 - 30;
			GI.y1 = GI.y1 - 30;
			GI.x2 = GI.x2 + 10;
			GI.y2 = GI.y2 - 10;
			pOut->Drawremove(GI);
			pOut->SETbrush(BLACK);
		}

		Pcomp->SetLabel(name);
		GI = Pcomp->GetGInfo();
		GI.y2 = GI.y1;
		GI.x2 = GI.x1;
		Pcomp->DrawName(pOut);
		pOut->ClearStatusBar();

		return true;
	}

	else if (Choice == "D" || Choice == "d")
	{
		pOut->PrintMsg("for deleting the name of the component please press on it, while to delete an existing name just click on it");
		pIn = pManager->GetInput();
		if (pIn != NULL)
			pIn->GetPointClicked(GI.x1, GI.y1);
		Pcomp = pManager->SelectedCmp(GI.x1, GI.y1);
		if (Pcomp != NULL)
		{
			label = Pcomp->GetLabel();
			
			Pcomp->SetLabel("empty");
			GI = Pcomp->GetGInfo();
			GI.x1 = GI.x1 - 30;
			GI.y1 = GI.y1 - 30;
			GI.x2 = GI.x1 + label.size() * 8;
			GI.y2 = GI.y1 + 30;
			pOut->Drawremove(GI);
			pOut->SETbrush(BLACK);
			pOut->PrintMsg("deleted");
		}
	}
	else
	{
		pOut->PrintMsg("Invalid letter");
	}
}

void EditLabel::Undo()
{
	if (label != "empty")
	{
		if (Pcomp != NULL)
		{
			GI = Pcomp->GetGInfo();
			GI.x1 = GI.x1 - 30;
			GI.y1 = GI.y1 - 30;
			GI.x2 = GI.x2 + 10;
			GI.y2 = GI.y2 - 10;
			pOut->Drawremove(GI);
			pOut->SETbrush(BLACK);
			Pcomp->SetLabel(label);
			GI = Pcomp->GetGInfo();
			GI.y2 = GI.y1;
			GI.x2 = GI.x1;
			Pcomp->DrawName(pOut);
			pOut->ClearStatusBar();
		}
	}
	else if (label == "Deleted")
	{
		pOut->PrintMsg("sorry can't get the name again");
	}
	else
	{
		if (Pcomp != NULL)
		{
			GI = Pcomp->GetGInfo();
			GI.x1 = GI.x1 - 30;
			GI.y1 = GI.y1 - 30;
			GI.x2 = GI.x1 + name.size() * 10;
			GI.y2 = GI.y1 + 30;
			pOut->Drawremove(GI);
			Pcomp->SetLabel("empty");
			pOut->ClearStatusBar();
		}
	}
}

void EditLabel::Redo()
{
	if (label == "empty")
	{
		if (Pcomp != NULL)
		{
			pOut->SETbrush(BLACK);
			Pcomp->SetLabel(name);
			GI = Pcomp->GetGInfo();
			GI.y2 = GI.y1;
			GI.x2 = GI.x1;
			Pcomp->DrawName(pOut);
			pOut->ClearStatusBar();

		}
	}
	else if (label == "Deleted")
	{
		pOut->PrintMsg("sorry can't get the name again");
	}
	else
	{
		if (Pcomp != NULL)
		{
			GI = Pcomp->GetGInfo();
			GI.x1 = GI.x1 - 30;
			GI.y1 = GI.y1 - 30;
			GI.x2 = GI.x1 + label.size() * 8;
			GI.y2 = GI.y1 + 30;
			pOut->Drawremove(GI);
			pOut->SETbrush(BLACK);
			Pcomp->SetLabel(label);
			GI = Pcomp->GetGInfo();
			GI.y2 = GI.y1;
			GI.x2 = GI.x1;
			Pcomp->DrawName(pOut);
			pOut->ClearStatusBar();
		}
	}
}
