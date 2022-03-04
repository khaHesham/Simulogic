#include "Input.h"
#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
	AddGate = false;
}



clicktype Input::GetPointClicked(int& x, int& y)
{
	clicktype click = pWind->WaitMouseClick(x, y);	//Wait for mouse click
	mLastX = x;
	mLastY = y;
	return click;
}

bool Input::GetMousePosition(int& x, int& y)
{
	pWind->GetMouseCoord(x, y);
	if (pWind->GetButtonState(LEFT_BUTTON, x, y) == BUTTON_DOWN)
		return true;
	return false;
}

void Input::GetLastClick(int& x, int& y)
{
	x = mLastX;
	y = mLastY;
}

string Input::GetSrting(Output* pOut)
{
	pWind->FlushKeyQueue();
	keytype key_type; //The keytype is defined in CMU
	char key; //The ASCII value
	string text = "";
	while (true)
	{
		key_type = pWind->WaitKeyPress(key);

		if (key_type == ESCAPE)
			return "";

		if (key == 13) //The user hits enter when he finishes typing
			return text;

		if (key == 8) //In case of hitting backspace
		{
			if (text != "") //To handle the error If the user tried to use backspace on an empty string
				text.pop_back();
		}

		else
			text += key;

		pOut->ClearStatusBar();
		pOut->PrintMsg(text);
	}
}
char Input::GetKeyPress()
{
	char key;
	keytype key_type; //The keytype is defined in CMU
	key_type = pWind->WaitKeyPress(key);

	return key;
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction()
{
	int x, y;
	clicktype Click = Highlight(x, y);
	mLastX = x;
	mLastY = y;

	int ClickedItemOrder = (x / UI.ToolItemWidth);

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{

			switch (ClickedItemOrder)
			{
			case ITM_DESIGN: {AddGate = true; return ADD_DESIGN; }
			case ITM_SIMULATE: return SIM_MODE;
			case ITM_LABEL: return ADD_Label;
			case ITM_PASTE: return PASTE;
			case ITM_COPY:return COPY;
			case ITM_CUT: return CUT;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD:return LOAD;
			case ITM_CONNECT: return ADD_CONNECTION;
			case ITM_DELETE: return DEL;
			case ITM_EXIT: return EXIT;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}
		//[2] if user clicked on toolbar 2

		if (y >= UI.ToolBarHeight && y < 2 * UI.ToolBarHeight)
		{

			switch (ClickedItemOrder)
			{
			case ITM_AND2:		 return ADD_AND_GATE_2;
			case ITM_OR2:		 return ADD_OR_GATE_2;
			case ITM_NAND2:		 return ADD_NAND_GATE_2;
			case ITM_NOR2:		 return ADD_NOR_GATE_2;
			case ITM_XOR2:		 return ADD_XOR_GATE_2;
			case ITM_XNOR2:		 return ADD_XNOR_GATE_2;
			case ITM_INV:		 return ADD_INVERTER;
			case ITM_AND3:		 return ADD_AND_GATE_3;
			case ITM_NOR3:		 return ADD_NOR_GATE_3;
			case ITM_BUFF:		 return ADD_Buff;
			case ITM_XOR3:		 return ADD_XOR_GATE_3;
			case ITM_LED:		 return ADD_led;
			case ITM_SWITCH:	 return ADD_Switch;

			default: return DSN_TOOL;  //if user clicked on empty area
			}
		}
		if (y >= 2 * UI.ToolBarHeight && y < 2 * UI.ToolBarHeight + UI.ADDGateHeight && x >= UI.width - UI.ADDGATEDWidth && x <= UI.width)
		{
			return EDIT;
		}

		//[3] User clicks on the drawing area
		if (y >= 2 * UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (Click == RIGHT_CLICK)
				return MOVE;
			return SELECT;	//user want to select/unselect a component
		}

		//[4] User clicks on the status bar
		return STATUS_BAR;
	}
	else	//Application is in Simulation mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{

			switch (ClickedItemOrder)
			{
			case ITM_DSN: {AddGate = false; return DSN_MODE; }
			case ITM_SIMULATE:return SIMULATE;
			case ITM_TRUTH: return Create_TruthTable;
			case ITM_PROBE:return PROBING;
			case ITM_VALIDATE: return Validation;

			default: return DSN_TOOL;	//A click on empty place in desgin toolbar
			}
		}

		if (y >= 2 * UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return CHANGE_SWITCH;
		}
		return SIM_MODE;
	}
}

clicktype Input::Highlight(int& x, int& y)
{
	pWind->FlushMouseQueue();

	//Highlighted images

	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_DESIGN] = "images\\Menu\\toolbar\\active\\Design2 high.jpg";
	MenuItemImages[ITM_SIMULATE] = "images\\Menu\\toolbar\\active\\simulation high.jpg";
	MenuItemImages[ITM_LABEL] = "images\\Menu\\toolbar\\active\\label high.jpg";
	MenuItemImages[ITM_CONNECT] = "images\\Menu\\toolbar\\active\\connect high.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Menu\\toolbar\\active\\delete2 high.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\toolbar\\active\\redo2 high.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\toolbar\\active\\undo2 high.jpg";
	MenuItemImages[ITM_COPY] = "images\\Menu\\toolbar\\active\\Copy high.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\toolbar\\active\\cut high.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\toolbar\\active\\paste high.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\toolbar\\active\\save2 high.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\toolbar\\active\\load2 high.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\toolbar\\active\\exit2 high.jpg";

	string GatesBarImages[ITM_ADDGATE_Dsgn];
	GatesBarImages[ITM_AND2] = "images\\Menu\\gatebar\\highlighted\\and.jpg";
	GatesBarImages[ITM_OR2] = "images\\Menu\\gatebar\\highlighted\\or.jpg";
	GatesBarImages[ITM_NAND2] = "images\\Menu\\gatebar\\highlighted\\nand.jpg";
	GatesBarImages[ITM_NOR2] = "images\\Menu\\gatebar\\highlighted\\nor.jpg";
	GatesBarImages[ITM_XOR2] = "images\\Menu\\gatebar\\highlighted\\xor.jpg";
	GatesBarImages[ITM_XNOR2] = "images\\Menu\\gatebar\\highlighted\\xnor.jpg";
	GatesBarImages[ITM_INV] = "images\\Menu\\gatebar\\highlighted\\not.jpg";
	GatesBarImages[ITM_AND3] = "images\\Menu\\gatebar\\highlighted\\and3.jpg";
	GatesBarImages[ITM_NOR3] = "images\\Menu\\gatebar\\highlighted\\nor3.jpg";
	GatesBarImages[ITM_BUFF] = "images\\Menu\\gatebar\\highlighted\\buffer.jpg";
	GatesBarImages[ITM_XOR3] = "images\\Menu\\gatebar\\highlighted\\xor3.jpg";
	GatesBarImages[ITM_LED] = "images\\Menu\\gatebar\\highlighted\\led.jpg";
	GatesBarImages[ITM_SWITCH] = "images\\Menu\\gatebar\\highlighted\\switch.jpg";

	string ToolBarItemImages[ITM_SIM_CNT];
	ToolBarItemImages[ITM_DSN] = "images\\Menu\\toolbar\\active\\design2 high.jpg";
	ToolBarItemImages[ITM_SIM] = "images\\Menu\\toolbar\\active\\sim high.jpg";
	ToolBarItemImages[ITM_TRUTH] = "images\\Menu\\toolbar\\active\\truth_table2 high.jpg";
	ToolBarItemImages[ITM_PROBE] = "images\\Menu\\toolbar\\active\\probe high.jpg";
	ToolBarItemImages[ITM_VALIDATE] = "images\\Menu\\toolbar\\active\\validation high.jpg";




	//Active images
	string MenuItemImagesActive[ITM_DSN_CNT];
	MenuItemImagesActive[ITM_DESIGN] = "images\\Menu\\toolbar\\active\\Design2.jpg";
	MenuItemImagesActive[ITM_SIMULATE] = "images\\Menu\\toolbar\\active\\simulation normal.jpg";
	MenuItemImagesActive[ITM_LABEL] = "images\\Menu\\toolbar\\active\\label normal.jpg";
	MenuItemImagesActive[ITM_CONNECT] = "images\\Menu\\toolbar\\active\\connect normal.jpg";
	MenuItemImagesActive[ITM_DELETE] = "images\\Menu\\toolbar\\active\\delete2 normal.jpg";
	MenuItemImagesActive[ITM_REDO] = "images\\Menu\\toolbar\\active\\redo2 normal.jpg";
	MenuItemImagesActive[ITM_UNDO] = "images\\Menu\\toolbar\\active\\undo2 normal.jpg";
	MenuItemImagesActive[ITM_COPY] = "images\\Menu\\toolbar\\active\\Copy normal.jpg";
	MenuItemImagesActive[ITM_CUT] = "images\\Menu\\toolbar\\active\\cut normal.jpg";
	MenuItemImagesActive[ITM_PASTE] = "images\\Menu\\toolbar\\active\\paste normal.jpg";
	MenuItemImagesActive[ITM_SAVE] = "images\\Menu\\toolbar\\active\\save2 normal.jpg";
	MenuItemImagesActive[ITM_LOAD] = "images\\Menu\\toolbar\\active\\load2 normal.jpg";
	MenuItemImagesActive[ITM_EXIT] = "images\\Menu\\toolbar\\active\\exit2 normal.jpg";

	string GatesBarImagesActive[ITM_ADDGATE_Dsgn];
	GatesBarImagesActive[ITM_AND2] = "images\\Menu\\gatebar\\active\\and.jpg";
	GatesBarImagesActive[ITM_OR2] = "images\\Menu\\gatebar\\active\\or.jpg";
	GatesBarImagesActive[ITM_NAND2] = "images\\Menu\\gatebar\\active\\nand.jpg";
	GatesBarImagesActive[ITM_NOR2] = "images\\Menu\\gatebar\\active\\nor.jpg";
	GatesBarImagesActive[ITM_XOR2] = "images\\Menu\\gatebar\\active\\xor.jpg";
	GatesBarImagesActive[ITM_XNOR2] = "images\\Menu\\gatebar\\active\\xnor.jpg";
	GatesBarImagesActive[ITM_INV] = "images\\Menu\\gatebar\\active\\not.jpg";
	GatesBarImagesActive[ITM_AND3] = "images\\Menu\\gatebar\\active\\and3.jpg";
	GatesBarImagesActive[ITM_NOR3] = "images\\Menu\\gatebar\\active\\nor3.jpg";
	GatesBarImagesActive[ITM_BUFF] = "images\\Menu\\gatebar\\active\\buffer.jpg";
	GatesBarImagesActive[ITM_XOR3] = "images\\Menu\\gatebar\\active\\xor3.jpg";
	GatesBarImagesActive[ITM_LED] = "images\\Menu\\gatebar\\active\\led.jpg";
	GatesBarImagesActive[ITM_SWITCH] = "images\\Menu\\gatebar\\active\\switch.jpg";


	string ToolBarItemImagesActive[ITM_SIM_CNT];
	ToolBarItemImagesActive[ITM_DSN] = "images\\Menu\\toolbar\\active\\Design2.jpg";
	ToolBarItemImagesActive[ITM_SIM] = "images\\Menu\\toolbar\\active\\sim normal.jpg";
	ToolBarItemImagesActive[ITM_TRUTH] = "images\\Menu\\toolbar\\active\\truth_table2 normal.jpg";
	ToolBarItemImagesActive[ITM_PROBE] = "images\\Menu\\toolbar\\active\\probe.jpg";
	ToolBarItemImages[ITM_VALIDATE] = "images\\Menu\\toolbar\\active\\validation normal.jpg";
	int NewPositionX, OldPositionX = 0, NewPositionY, OldPositionY = 0;
	while (true)
	{
		clicktype click = pWind->GetMouseClick(x, y);
		if (click != NO_CLICK)
		{
			if (UI.AppMode == DESIGN)
			{
				if (AddGate)pWind->DrawImage(GatesBarImagesActive[OldPositionX], OldPositionX * UI.ToolItemWidth, UI.ToolBarHeight + 3, UI.ToolItemWidth, UI.ADDGateHeight);
				pWind->DrawImage(MenuItemImagesActive[OldPositionX], OldPositionX * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
			}
			return click;
		}

		pWind->GetMouseCoord(x, y);
		NewPositionX = (x / UI.ToolItemWidth);
		NewPositionY = (y / UI.ToolBarHeight);
		if ((NewPositionX == OldPositionX && NewPositionY == OldPositionY) || NewPositionX > 12)
			continue;

		if (UI.AppMode == SIMULATION)
		{
			if (NewPositionY == 0 && NewPositionX < 4)
			{
				pWind->DrawImage(ToolBarItemImagesActive[OldPositionX], OldPositionX * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
				pWind->DrawImage(ToolBarItemImages[NewPositionX], NewPositionX * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
			}
			else continue;
		}

		else
		{
			if (AddGate)pWind->DrawImage(GatesBarImagesActive[OldPositionX], OldPositionX * UI.ToolItemWidth, UI.ToolBarHeight + 3, UI.ToolItemWidth, UI.ADDGateHeight);
			pWind->DrawImage(MenuItemImagesActive[OldPositionX], OldPositionX * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);

			if (NewPositionY == 0)
			{
				pWind->DrawImage(MenuItemImages[NewPositionX], NewPositionX * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
			}

			else if (NewPositionY == 1 && AddGate)
			{
				pWind->DrawImage(GatesBarImages[NewPositionX], NewPositionX * UI.ToolItemWidth, UI.ToolBarHeight + 3, UI.ToolItemWidth, UI.ADDGateHeight);
			}
		}

		OldPositionX = NewPositionX;
		OldPositionY = NewPositionY;
	}
}


Input::~Input()
{
}
