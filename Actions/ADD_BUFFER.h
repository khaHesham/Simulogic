#include"Action.h"
#include"..\Components\BUFF.h"

class ADD_BUFFER : public Action
{
private:
	GraphicsInfo GInfo;
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	ADD_BUFFER(ApplicationManager* pBpp);
	virtual ~ADD_BUFFER(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual bool Execute();

	virtual void Undo();
	virtual void Redo();

};