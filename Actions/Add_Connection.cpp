#include "Add_Connection.h"
#include"..\ApplicationManager.h"
#include "..\Components\Component.h"
#include "..\Components\InputPin.h"
#include "..\Components\OutputPin.h"
#include "..\Components\INV.h"
#include "..\Components\BUFF.h"
#include "..\Components\LED.h"
#include "..\Components\SWITCH.h"

Add_Connection::Add_Connection(ApplicationManager* pBpp) :Action(pBpp)
{

}

Add_Connection::~Add_Connection(void)
{
}

void Add_Connection::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Please choose the source component");

	pIn->GetPointClicked(x1, y1);

	pOut->ClearStatusBar();

	pOut->PrintMsg("Please choose the destination component");

	pIn->GetPointClicked(x2, y2);

	pOut->ClearStatusBar();
}


bool Add_Connection::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	TYPE type;

	//Getting source component
	cmpSource = pManager->SelectedCmp(x1, y1);
	if (cmpSource == NULL)
		return true;

	type = cmpSource->GetType();

	if (type == _LED)
	{
		pOut->PrintMsg("LED has no output pin");
		return true;
	}

	GInfo.x1 = cmpSource->GetGInfo().x2 - 1;
	GInfo.y1 = cmpSource->GetGInfo().y1 + UI.GateHeight / 2;
	OutPutPin = ((Gate*)cmpSource)->GetOutPin();
	OutPutPin->setconnected(true);

	if (OutPutPin->full())
	{
		pOut->PrintMsg("Maximum fanout reached");
		return true;
	}

	//Getting Distination component

	cmpDest = pManager->SelectedCmp(x2, y2);
	if (cmpDest == NULL)
		return true;

	int MaxInputs = ((Gate*)cmpDest)->GetNumInputs();
	GInfo.x2 = cmpDest->GetGInfo().x1;
	type = cmpDest->GetType();

	if (type == _SWITCH)
	{
		pOut->PrintMsg("SWITCH has no input pin");
		return true;
	}

	bool EmptyPIn = false;
	int PinIndex;

	for (int i = 0; i < MaxInputs; i++)
	{
		InPutPin = ((Gate*)cmpDest)->GetInPin(i);
		if (!InPutPin->Connected())
		{
			EmptyPIn = true;
			InPutPin->Connect(true);
			((Gate*)cmpDest)->IncrPin();
			PinIndex = i;
			GInfo.y2 = cmpDest->GetGInfo().y1 + 8 + 8 * i * (8 - 2 * MaxInputs);

			if (MaxInputs == 1)
				GInfo.y2 += 16;

			if (type == _LED)
				GInfo.y2 += 16;

			break;
		}
	}

	if (!EmptyPIn)
	{
		pOut->PrintMsg("Sorry Max Number of Inputs Reached");
		return true;
	}

	int DistID = cmpDest->GetID();
	int SourceID = cmpSource->GetID();
	Connection* pc = new Connection(GInfo, OutPutPin, InPutPin, SourceID, DistID, PinIndex);
	OutPutPin->ConnectTo(pc);
	InPutPin->set_conn(pc);
	pManager->AddComponent(pc);
	pManager->IncrementConn();

	return true;
}


void Add_Connection::Undo()
{
	int x = pManager->GetCompCount() - 1;
	if (x <= 0)
	{
		return;
	}
	pManager->DeleteComponent(x);
}

void Add_Connection::Redo()
{

}
