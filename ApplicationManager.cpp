#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include"Actions\ADD_OR_GATE2.h"
#include"Actions\ADD_NAND_GATE2.h"
#include"Actions\ADD_INV.h"
#include"Actions\ADD_AND_GATE3.h"
#include"Actions\ADD_BUFFER.h"
#include"Actions\ADD_NOR_GATE2.h"
#include"Actions\ADD_NOR_GATE3.h"
#include"Actions\ADD_XNOR_GATE2.h"
#include"Actions\ADD_XOR_GATE2.h"
#include"Actions\ADD_XOR_GATE3.h"
#include"Actions\ADD_LED.h"
#include"Actions\ADD_SWITCH.h"
#include"Actions\DELETE_selected.h"
#include "Actions\Select.h"
#include"Actions\Edit_Connection.h"
#include"Actions\CircuitValidation.h"
#include"Actions\RedoAction.h"
#include "Actions\Add_Connection.h"
#include"Actions\Copy.h"
#include"Actions\Paste.h"
#include "Actions\Cut.h"
#include "Actions\EditLabel.h"
#include "Actions\SAVE_FILE.h"
#include "Actions\LOAD_FILE.h"
#include "Actions\Change_Switch.h"
#include "Actions\Simulate.h"
#include"Actions/Move.h"
#include"Actions\CircuitProbing.h"
#include"Actions/Exit.h"
#include <fstream>

ApplicationManager::ApplicationManager()
{
	Undocount = 0;
	CompCount = 0;
	CompCount2 = 0;
	ConnectionCount = 0;
	Cutcount = 0;
	AddConnection = NULL;
	Copiedcount = 0;
	for (int i = 0; i < MaxCompCount; i++)
	{
		CompList[i] = NULL;
		CopiedList[i] = NULL;
		CompList2[i] = NULL;
	}
	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();

}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	pComp->SetID(CompCount - ConnectionCount);
	CompList[CompCount++] = pComp;
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction();
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{

	Action* delslct = NULL;
	Action* pAct = NULL;
	switch (ActType)
	{
	case DSN_MODE:
		OutputInterface->ClearFirstBar();
		OutputInterface->CreateDesignToolBar();
		OutputInterface->ClearDrawingArea();
		OutputInterface->ClearStatusBar();
		break;

	case ADD_DESIGN:

		OutputInterface->CreateAddGateToolBar();
		break;
	case ADD_AND_GATE_2:
		pAct = new AddANDgate2(this);
		Undocount = 0;

		break;
	case ADD_OR_GATE_2:
		pAct = new ADD_OR_GATE2(this);
		Undocount = 0;

		break;
	case ADD_CONNECTION:

		OutputInterface->EditConn();
		pAct = new Add_Connection(this);
		AddConnection = pAct;
		Undocount = 0;
		break;
	case ADD_NAND_GATE_2:
		pAct = new ADD_NAND_GATE2(this);

		Undocount = 0;
		break;
	case ADD_AND_GATE_3:
		pAct = new ADD_AND_GATE3(this);

		Undocount = 0;
		break;
	case ADD_Buff:
		pAct = new ADD_BUFFER(this);

		Undocount = 0;
		break;
	case ADD_XNOR_GATE_2:
		pAct = new ADD_XNOR_GATE2(this);

		Undocount = 0;
		break;
	case ADD_XOR_GATE_2:
		pAct = new ADD_XOR_GATE2(this);
		break;
	case ADD_XOR_GATE_3:
		pAct = new ADD_XOR_GATE3(this);

		break;
	case ADD_INVERTER:
		pAct = new ADD_INV(this);

		break;
	case EDIT:
		pAct = new EditConnection(this);
		break;
	case Validation:
		pAct = new CircuitValidation(this);
		break;
	case ADD_NOR_GATE_2:
		pAct = new ADD_NOR_GATE2(this);

		break;
	case ADD_NOR_GATE_3:
		pAct = new ADD_NOR_GATE3(this);

		break;
	case ADD_Switch:
		pAct = new ADD_SWITCH(this);
		break;
	case ADD_led:
		pAct = new ADD_LED(this);

		break;
	case DEL:
		pAct = new DELETE_selected(this);

		break;
	case MOVE:
		pAct = new Move(this);
		break;
	case SAVE:
		pAct = new SAVE_FILE(this);
		break;
	case LOAD:
		pAct = new LOAD_FILE(this);
		break;
	case UNDO:
		if (mUndoStack.empty()) {// bt2kd en el stack msh fady 
			return;
		}
		Undo();

		break;
	case REDO:
		if (mRedoStack.empty()) {// bt2kd en el stack msh fady 
			return;
		}

		Redo();
		//pAct = new RedoAction(this);
		break;
	case SELECT:
		pAct = new Select(this);
		break;

	case ADD_Label:
		pAct = new EditLabel(this);
		break;
	case COPY:
		if (Copiedcount != 0)
		{
			OutputInterface->PrintMsg("there is already something copied or cut");
			break;
		}
		pAct = new Copyy(this);
		break;
	case CUT:
		if (Copiedcount != 0)
		{
			OutputInterface->PrintMsg("there is already something copied or cut");
			break;
		}
		pAct = new Cutt(this);
		break;
	case PASTE:
		pAct = new Paste(this);

		// da condition b3rf meno howa 3aml cut wla copy
		if (Cutcount != 0)
		{
			pAct->Execute();
			delslct = new DELETE_selected(this);
			delslct->Execute();
			OutputInterface->PrintMsg("Pasted");
			Cutcount = 0; // khleh b 0 b3d ma akhls kol haga baa 
		}
		break;
	case SIM_MODE:
		OutputInterface->ClearFirstBar();
		OutputInterface->ClearAddGateBar();
		OutputInterface->CreateSimulationToolBar();
		break;
	case PROBING:
		pAct = new CircuitProbing(this);
		break;
	case SIMULATE:
		pAct = new Simulate(this);
		break;
	case CHANGE_SWITCH:
		pAct = new Change_Switch(this);
		break;
	case EXIT:
		pAct = new Exit(this);
		break;
	}
	if (delslct != NULL) // condition 5as bl paste bs , 34an ana fl paste b3ml new mn Delete , fa lazm ams7o 
	{
		mUndoStack.push(pAct);
		while (!mRedoStack.empty()) delete mRedoStack.top(), mRedoStack.pop();	// Clear the RedoStack
		delete delslct;
	}
	else if (pAct != NULL) {
		if (pAct->Execute()) {
			mUndoStack.push(pAct);
			while (!mRedoStack.empty()) delete mRedoStack.top(), mRedoStack.pop();	// Clear the RedoStack
		}
		else {
			if (ActType == EXIT) ActType = DSN_TOOL;	// To cancel exit action
			delete pAct;
		}
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] == NULL)
			continue;

		CompList[i]->Draw(OutputInterface);
		CompList[i]->DrawName(OutputInterface);
	}
}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////
ApplicationManager::~ApplicationManager()
{
	for (int i = 0; i < CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void ApplicationManager::set_cutcount(int cc)
{
	cc >= 0 ? Cutcount = cc : Cutcount = 0;
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

int ApplicationManager::get_Cutcount()
{
	return Cutcount;
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

int ApplicationManager::GetCompcount2()
{
	return CompCount2;
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

Component* ApplicationManager::GetComp2(int i)
{
	return CompList2[i];
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void ApplicationManager::Undo() {

	Action* lastAction = mUndoStack.top(); // de bt3ml undo 3la akher haga fl top 
	lastAction->Undo();
	mUndoStack.pop();
	mRedoStack.push(lastAction);
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void ApplicationManager::Redo() {

	Action* lastAction = mRedoStack.top();// de bt3ml redo 3la akher haga fl top 
	if (lastAction == AddConnection) return;
	lastAction->Redo();
	mRedoStack.pop();
	mUndoStack.push(lastAction);
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void ApplicationManager::AddToComp2(Component* pComp)
{
	CompList2[CompCount2++] = pComp;
	for (int i = CompCount2 - 1; i > 0; i--)
	{
		//ana 3auz eny el 7aga el adkhlha teb2a awl haga fl array .
		swap(CompList2[i], CompList2[i - 1]);
	}
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void ApplicationManager::RemoveFromComp2(int i)
{
	CompList2[i] = NULL;
	CompCount2--;
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void ApplicationManager::swap(Component* c1, Component* c2)
{
	Component* flag = NULL;
	flag = c1;
	c1 = c2;
	c2 = flag;
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void ApplicationManager::set_copied_list(Component* c1)
{
	CopiedList[Copiedcount++] = c1; // de b3ml array lel 7agat el copied w a5znhom feha

	//mana tlama zwdt element lazm azwd el counter aked
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

Component** ApplicationManager::Get_CopiedList()
{
	return CopiedList;
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

int ApplicationManager::get_CopiedCount()
{
	return Copiedcount;
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void ApplicationManager::setCopiedCount(int i)
{
	Copiedcount = i;
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

int ApplicationManager::GetCompCount()
{
	return CompCount;
}

////////////////////////////////////////////////////////////////////

int ApplicationManager::GetConnCount()
{
	return ConnectionCount;
}

////////////////////////////////////////////////////////////////////

void ApplicationManager::IncrementConn()
{
	ConnectionCount++;
}

////////////////////////////////////////////////////////////////////

Component* ApplicationManager::GetCmp(int index)
{

	return CompList[index];
}

////////////////////////////////////////////////////////////////////

void ApplicationManager::DeleteComponent(int v)
{
	CompList[v]->Delete(OutputInterface);
	fix(v);
	CompCount--;
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

int ApplicationManager::getUndoCount()
{
	return Undocount;
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void ApplicationManager::SetUndoCount(int i)
{
	Undocount = i;
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

void ApplicationManager::fix(int index)
{
	delete CompList[index];
	for (int i = index; i < CompCount - 1; i++)
	{
		CompList[i] = CompList[i + 1];
	}
	CompList[CompCount - 1] = NULL;
}

////////////////////////////////////////////////////////////////////

void ApplicationManager::save(ofstream& file)
{
	for (int i = 0; i < CompCount; i++)
		CompList[i]->save(file, false);

	file << "Connections" << endl;

	for (int i = 0; i < CompCount; i++)
		CompList[i]->save(file, true);
}

////////////////////////////////////////////////////////////////////

Component* ApplicationManager::SelectedCmp(int x, int y)
{
	for (int i = 0; i < CompCount; i++)
	{
		bool Inside = CompList[i]->InsideArea(x, y);
		TYPE type = CompList[i]->GetType();
		if (Inside && type != _CONNECTION)
		{
			return CompList[i];
		}
	}
	return NULL;
}

////////////////////////////////////////////////////////////////////

Component* ApplicationManager::selectedConn(int x, int y)
{
	for (int i = 0; i < CompCount; i++)
	{
		TYPE type = CompList[i]->GetType();
		if (type == _CONNECTION)
		{
			bool Inside = CompList[i]->InsideConnection(x, y);

			if ((Inside))
			{
				return CompList[i];
			}
		}
	}
	return NULL;
}

////////////////////////////////////////////////////////////////////

int ApplicationManager::getLEDScount()
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->GetType() == _LED)
		{
			LedCount++;
		}

	}
	return LedCount;
}

////////////////////////////////////////////////////////////////////

int ApplicationManager::getSWITCHEScount()
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i]->GetType() == _SWITCH)
		{
			SwitchCount++;

		}

	}
	return SwitchCount;
}
Component* ApplicationManager::InValidCmp()
{
	for (int i = 0; i < CompCount; i++)
	{
		Gate* PG = dynamic_cast<Gate*>(CompList[i]);
		if (PG != NULL)
		{
			InputPin* INPUT;
			OutputPin* OUTPUt;
			bool IsConnected;
			//checking input pins of all gates
			int InputsNum = PG->GetNumInputs();
			SWITCH* PS = dynamic_cast<SWITCH*>(PG);
			if (PS == NULL)
			{
				int InputsNum = PG->GetNumInputs();
				for (int j = 0; j < InputsNum; j++)
				{
					INPUT = PG->GetInPin(j);
					IsConnected = INPUT->Connected();
					if (IsConnected == false)
						return CompList[i];
				}
			}

			//checking output pins of all gates
			LED* PLED = dynamic_cast<LED*>(PG);
			if (PLED == NULL)
			{
				OUTPUt = PG->GetOutPin();
				IsConnected = OUTPUt->getconnected();
				if (IsConnected == false)
					return CompList[i];
			}
		}

	}
	return NULL;
}

Component* ApplicationManager::FirstLevel()
{
	int X_Min;
	X_Min = CompList[0]->GetGInfo().x1;
	TYPE type;
	for (int i = 1; i < CompCount; i++)
	{
		type = CompList[i]->GetType();
		if (type != _CONNECTION)
		{
			if (X_Min > CompList[i]->GetGInfo().x1)
				X_Min = CompList[i]->GetGInfo().x1;
		}
	}
	for (int i = 0; i < CompCount; i++)
	{
		type = CompList[i]->GetType();
		if (type != _CONNECTION)
		{
			if (CompList[i]->GetGInfo().x1 == X_Min)
			{
				return CompList[i];
			}
		}
	}
	return NULL;
}

Component* ApplicationManager::lastLevel()
{
	int X_Max;
	X_Max = CompList[0]->GetGInfo().x2;
	TYPE type;
	for (int i = 1; i < CompCount; i++)
	{
		type = CompList[i]->GetType();
		if (type != _CONNECTION)
		{
			if (X_Max < CompList[i]->GetGInfo().x1)
				X_Max = CompList[i]->GetGInfo().x1;
		}
	}
	for (int i = 0; i < CompCount; i++)
	{
		type = CompList[i]->GetType();
		if (type != _CONNECTION)
		{
			if (CompList[i]->GetGInfo().x1 == X_Max)
			{
				return CompList[i];
			}
		}
	}
	return NULL;
}
