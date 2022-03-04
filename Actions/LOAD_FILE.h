#ifndef _LOAD_FILE_H
#define _LOAD_FILE_H

#include "Action.h"
#include <string>
using namespace std;

class LOAD_FILE : public Action
{
	string FileName;
public:
	LOAD_FILE(ApplicationManager* pApp);
	virtual ~LOAD_FILE(void);

	virtual void ReadActionParameters();
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();
};

#endif