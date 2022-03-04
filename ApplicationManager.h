#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"
#include <stack>

class ApplicationManager
{

	enum { MaxCompCount = 200 };

private:
	Action* AddConnection;
	int  CompCount;    //actual number of components
	int CompCount2;
	int ConnectionCount;
	int SwitchCount;
	int LedCount;
	int Copiedcount;
	int Cutcount;
	int Undocount;
	Component* comp;
	Component* CopiedList[MaxCompCount];
	Component* CompList[MaxCompCount];
	Component* CompList2[MaxCompCount];
	Output* OutputInterface;
	Input* InputInterface;
	stack<Action*> mUndoStack;	// Stack holding the done actions
	stack<Action*> mRedoStack;	// Stack holding the un-done actions

	void fix(int index); //utility function to fix the list of component after delete


public:
	ApplicationManager();
	void DeleteComponent(int v);
	int GetCompCount();
	int GetConnCount();
	void IncrementConn();
	Component* GetCmp(int index);
	ActionType GetUserAction();
	void ExecuteAction(ActionType);
	void UpdateInterface();
	Output* GetOutput();
	Input* GetInput();
	void save(ofstream& file);
	Component* SelectedCmp(int x, int y);
	void AddComponent(Component* pComp);

	//UNDOES the last Action
	void Undo();
	//Redoes the last action 
	void Redo();
	virtual ~ApplicationManager();
	////////////////////////////
	//ZUZ
	int getUndoCount();
	void SetUndoCount(int i);
	Component* GetComp2(int i);
	void AddToComp2(Component* pComp);
	void RemoveFromComp2(int i);
	void swap(Component* c1, Component* c2);
	void set_copied_list(Component* c1);
	Component** Get_CopiedList();
	int get_CopiedCount();
	void setCopiedCount(int i);
	void set_cutcount(int cc);
	int get_Cutcount();
	int GetCompcount2();
	//////////////////////////////////
	Component* lastLevel();
	Component* FirstLevel();
	Component* InValidCmp();
	//////////////////////////////
	Component* selectedConn(int x, int y);
	int getLEDScount();
	int getSWITCHEScount();
};

#endif