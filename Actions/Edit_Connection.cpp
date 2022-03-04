#include "Edit_Connection.h"
#include"..\GUI\Output.h"
#include"..\GUI\Input.h"
#include"..\ApplicationManager.h"
#include"..\Components\InputPin.h"
#include"..\Components\OutputPin.h"
#include"..\Components\Connection.h"
#include"..\Actions\DELETE_selected.h"
#include"..\Actions\Add_Connection.h"

EditConnection::EditConnection(ApplicationManager* pECpp) :Action(pECpp)
{
}

EditConnection::~EditConnection(void)
{

}

void EditConnection::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMsg("Please choose the connection you want to edit");
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}

bool EditConnection::Execute()
{
	ReadActionParameters();
	TYPE type;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	connection = pManager->selectedConn(x, y);
	if (connection != NULL)
	{
		connection->setselected(true);
		InputPin* DestPin;
		OutputPin* SourcePin;
		GInfo = connection->GetGInfo();
		DestPin = ((Connection*)connection)->getDestPin();
		SourcePin = ((Connection*)connection)->getSourcePin();
		int destcmpID = ((Connection*)connection)->getDstCmpntID();
		int sourceCmpID = ((Connection*)connection)->getSrcCmpntID();
		int PinIndex = ((Connection*)connection)->getDstPinIndex();
		Action* bAction;
		char key;
		pOut->PrintMsg("if you want to edit Source pin only->S , distination pin only ->D or both of them B");
		key = pIn->GetKeyPress();
		if (key == 's' || key == 'S')
		{
			pOut->PrintMsg("Please choose the source component");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			SourceComp = pManager->SelectedCmp(x, y);
			if (SourceComp == NULL)
				return false;
			type = SourceComp->GetType();
			if (type == _LED)
			{
				pOut->PrintMsg("LED has no output pin");
				connection->setselected(false);
				return false;
			}
			GInfo.x1 = SourceComp->GetGInfo().x2 - 1;
			GInfo.y1 = SourceComp->GetGInfo().y1 + UI.GateHeight / 2;
			((Gate*)SourceComp)->GetOutPin()->setconnected(true);
			SourcePin = ((Gate*)SourceComp)->GetOutPin();
			int SourceID = SourceComp->GetID();
			bAction = new DELETE_selected(pManager);
			bAction->Execute();
			Connection* pc = new Connection(GInfo, SourcePin, DestPin, SourceID, destcmpID, PinIndex);
			SourcePin->ConnectTo(pc);
			DestPin->set_conn(pc);
			pManager->AddComponent(pc);
			pManager->IncrementConn();
		}
		if (key == 'd' || key == 'D')
		{
			pOut->PrintMsg("Please choose the Destination component");
			pIn->GetPointClicked(x, y);
			pOut->ClearStatusBar();
			DestComp = pManager->SelectedCmp(x, y);
			if (DestComp == NULL)
				return false;

			int MaxInputs = ((Gate*)DestComp)->GetNumInputs();
			GInfo.x2 = DestComp->GetGInfo().x1;
			type = DestComp->GetType();

			if (type == _SWITCH)
			{
				pOut->PrintMsg("SWITCH has no input pin");
				connection->setselected(false);
				return false;
			}

			bool EmptyPIn = false;
			int PinIndex;

			for (int i = 0; i < MaxInputs; i++)
			{
				DestPin = ((Gate*)DestComp)->GetInPin(i);
				if (!DestPin->Connected())
				{
					EmptyPIn = true;
					DestPin->Connect(true);
					((Gate*)DestComp)->IncrPin();
					PinIndex = i;
					GInfo.y2 = DestComp->GetGInfo().y1 + 8 + 8 * i * (8 - 2 * MaxInputs);

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
				connection->setselected(false);
				return false;
			}
			int DistID = DestComp->GetID();
			bAction = new DELETE_selected(pManager);
			bAction->Execute();
			Connection* pc = new Connection(GInfo, SourcePin, DestPin, sourceCmpID, DistID, PinIndex);
			SourcePin->ConnectTo(pc);
			DestPin->set_conn(pc);
			pManager->AddComponent(pc);
			pManager->IncrementConn();
		}
		if (key == 'B' || key == 'b')
		{
			bAction = new DELETE_selected(pManager);
			bAction->Execute();
			bAction = new Add_Connection(pManager);
			bAction->Execute();
			delete bAction;
			return false;
		}
		delete bAction;
		return false;
	}
	return false;
}

void EditConnection::Undo()
{

}

void EditConnection::Redo()
{

}
