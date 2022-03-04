#include "LOAD_FILE.h"
#include "../ApplicationManager.h"
#include "../Components/AND2.h"
#include "../Components/AND3.h"
#include "../Components/BUFF.h"
#include "../Components/INV.h"
#include "../Components/LED.h"
#include "../Components/NAND2.h"
#include "../Components/NOR2.h"
#include "../Components/NOR3.h"
#include "../Components/OR2.h"
#include "../Components/SWITCH.h"
#include "../Components/XNOR2.h"
#include "../Components/XOR2.h"
#include "../Components/XOR3.h"
#include "../Components/Connection.h"
#include <fstream>



LOAD_FILE::LOAD_FILE(ApplicationManager* pApp) :Action(pApp)
{
}

LOAD_FILE::~LOAD_FILE(void)
{
}

void LOAD_FILE::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("File name: ");
	FileName = pIn->GetSrting(pOut);
}

bool LOAD_FILE::Execute()
{
	ReadActionParameters();

	ifstream file;
	string path = "circuits/" + FileName + ".txt";
	file.open(path);

	if (!file.is_open())
	{
		Output* pOut = pManager->GetOutput();
		pOut->PrintMsg("File not found");
		return true;
	}

	int GateCount;
	file >> GateCount;

	//Loading components
	for (int i = 0; i < GateCount; i++)
	{
		int id, x, y;
		string name, label;
		GraphicsInfo GInfo;

		file >> name >> id >> label >> x >> y;

		GInfo.x1 = x;
		GInfo.x2 = x + UI.GateWidth;
		GInfo.y1 = y;
		GInfo.y2 = y + UI.GateHeight;
		Component* gate;

		if (name == "AND2")
			gate = new AND2(GInfo, default_FANOUT);
		else if (name == "AND3")
			gate = new AND3(GInfo, default_FANOUT);
		else if (name == "BUFF")
			gate = new BUFF(GInfo, default_FANOUT);
		else if (name == "INV")
			gate = new INV(GInfo, default_FANOUT);
		else if (name == "LED")
		{
			GInfo.x2 = x + UI.GateHeight;
			gate = new LED(GInfo, default_FANOUT);
		}
		else if (name == "NAND2")
			gate = new NAND2(GInfo, default_FANOUT);
		else if (name == "NOR2")
			gate = new NOR2(GInfo, default_FANOUT);
		else if (name == "NOR3")
			gate = new NOR3(GInfo, default_FANOUT);
		else if (name == "OR2")
			gate = new OR2(GInfo, default_FANOUT);
		else if (name == "SWITCH")
		{
			GInfo.x2 = x + UI.GateHeight;
			gate = new SWITCH(GInfo, default_FANOUT);
		}
		else if (name == "XNOR2")
			gate = new XNOR2(GInfo, default_FANOUT);
		else if (name == "XOR2")
			gate = new XOR2(GInfo, default_FANOUT);
		else if (name == "XOR3")
			gate = new XOR3(GInfo, default_FANOUT);
		else
			return true;

		gate->SetLabel(label);
		gate->SetID(id);
		pManager->AddComponent(gate);

	}

	//Loading connections

	string str;
	file >> str; //skipping the empty "Connection" line

	while (true)
	{
		int SourceID, DistID, PinIndex;
		file >> SourceID >> DistID >> PinIndex;
		GraphicsInfo GInfo;

		if (SourceID == -1)
			break;

		//Source
		Component* SrcCmp = pManager->GetCmp(SourceID - 1);
		OutputPin* OutPin = ((Gate*)SrcCmp)->GetOutPin();
		GInfo.x1 = SrcCmp->GetGInfo().x2 - 1;
		GInfo.y1 = SrcCmp->GetGInfo().y1 + UI.GateHeight / 2;

		//Destination
		Component* DstCmp = pManager->GetCmp(DistID - 1);
		InputPin* InPin = ((Gate*)DstCmp)->GetInPin(PinIndex - 1);
		int MaxInputs = ((Gate*)DstCmp)->GetNumInputs();
		GInfo.x2 = DstCmp->GetGInfo().x1;
		GInfo.y2 = DstCmp->GetGInfo().y1 + 8 + 8 * (PinIndex - 1) * (8 - 2 * MaxInputs);
		if (MaxInputs == 1)
			GInfo.y2 += 16;
		if (DstCmp->GetType() == _LED)
			GInfo.y2 += 16;

		//Adding the connection
		InPin->Connect(true);
		((Gate*)DstCmp)->IncrPin();
		Connection* pc = new Connection(GInfo, OutPin, InPin, SourceID, DistID, PinIndex - 1);
		InPin->set_conn(pc);
		OutPin->ConnectTo(pc);
		pManager->AddComponent(pc);
		pManager->IncrementConn();
	}

	file.close();
	return true;
}

void LOAD_FILE::Undo()
{}

void LOAD_FILE::Redo()
{}
