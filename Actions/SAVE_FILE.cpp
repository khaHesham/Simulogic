#include "SAVE_FILE.h"
#include "..\ApplicationManager.h"
#include "fstream"


SAVE_FILE::SAVE_FILE(ApplicationManager* pApp) :Action(pApp)
{
}

SAVE_FILE::~SAVE_FILE(void)
{
}

void SAVE_FILE::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("File name: ");
	FileName = pIn->GetSrting(pOut);
}

bool SAVE_FILE::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();

	ofstream file;
	string path = "circuits/" + FileName + ".txt";
	file.open(path);

	if (!file.is_open())
	{
		pOut->PrintMsg("File couldn't be created");
		return true;
	}

	file << pManager->GetCompCount() - pManager->GetConnCount() << endl;
	pManager->save(file);

	file << -1;
	file.close();

	pOut->PrintMsg("File saved successfully");
	return true;
}

void SAVE_FILE::Undo()
{}

void SAVE_FILE::Redo()
{}
