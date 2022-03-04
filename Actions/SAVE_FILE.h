#ifndef _SAVE_FILE_H
#define _SAVE_FILE_H

#include "Action.h"
#include <string>
using namespace std;

class SAVE_FILE : public Action
{
	string FileName;
public:
	SAVE_FILE(ApplicationManager* pApp);
	virtual ~SAVE_FILE(void);

	virtual void ReadActionParameters();
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif