#include "../ApplicationManager.h"
#include"Copy.h"
#include"../Components/AND2.h"
#include"../Components/AND3.h"
#include"../Components/BUFF.h"
#include "../Components/INV.h"
#include "../Components/LED.h"
#include "../Components/NAND2.h"
#include "../Components/NOR2.h"
#include"../Components/NOR3.h"
#include"../Components/OR2.h"
#include "../Components/SWITCH.h"
#include"../Components/XNOR2.h"
#include"../Components/XOR3.h"
#include"../Components/XOR2.h"
#include"EditLabel.h"
#include "Add_Connection.h"
class Undoo :
	public Action
{
private:
	Component* mComp;
	GraphicsInfo Ginfo;
	Action* pAct;
public:
	Undoo(ApplicationManager* pApp);
	virtual ~Undoo(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();


};


