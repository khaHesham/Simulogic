#include"Exit.h"
#include<iostream>
#include"..\ApplicationManager.h"
#include"..\CMUgraphicsLib\CMUgraphics.h"
#include"SAVE_FILE.h"
#include<stdlib.h>
using namespace std;



Exit::Exit(ApplicationManager* pE) :Action(pE)
{

}


Exit::~Exit(void)
{

}

///	Reads parameters required for action to execute
void Exit::ReadActionParameters()
{


}
//	Execute action (code depends on action type)
bool Exit::Execute()
{

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	char key;
	pOut->PrintMsg("would you like to save before exit	YES-> click Y -> file name  NO->click N -> THANK U");
	key = pIn->GetKeyPress();
	if (key == 'N' || key == 'n')
	{
		exit(0);
		delete pManager;
		return false;
	}
	if (key == 'Y' || key == 'y')
	{

		Action* pAct = new SAVE_FILE(this->pManager);
		pAct->Execute();
		delete pAct;
		exit(0);
		delete pManager;
		return true;
	}
	return true;
}
void Exit::Undo()
{}
void Exit::Redo()
{}
