#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters

	UI.AppMode = DESIGN;	//Design Mode is the startup mode

	//Initilaize interface colors
	UI.DrawColor = BLACK;
	UI.SelectColor = BLUE;
	UI.ConnColor = RED;
	UI.MsgColor = BLACK;
	UI.BkGrndColor = GRAY;


	//Create the drawing window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	ChangeTitle("Simulogic");
	ClearDrawingArea();
	CreateDesignToolBar();	//Create the desgin toolbar
	CreateStatusBar();		//Create Status bar
	ClearStatusBar();
	ClearAddGateBar();

}

Input* Output::CreateInput() const
{
	//Create an Input Object & assign it to the Same Window
	Input* pIn = new Input(pWind);
	return pIn;
}


//======================================================================================//
//								Interface Functions	  									//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y) const
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::ChangeTitle(string Title) const
{
	pWind->ChangeTitle(Title);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(BLACK, 4);
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////
void Output::PrintMsg(string msg) const
{
	ClearStatusBar();	//Clear Status bar to print message on it
	// Set the Message offset from the Status Bar
	int MsgX = 25;
	int MsgY = UI.StatusBarHeight - 10;

	// Print the Message
	pWind->SetFont(20, BOLD | ITALICIZED, BY_NAME, "Arial");
	pWind->SetPen(UI.MsgColor);
	pWind->DrawString(MsgX, UI.height - MsgY, msg);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	// Set the Message offset from the Status Bar
	int MsgX = 0;
	int MsgY = UI.StatusBarHeight;

	////Overwrite using bachground color to erase the message
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(MsgX, UI.height - MsgY, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Output::clearRectangle(GraphicsInfo g)   const
{
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(g.x1, g.y1, g.x2, g.y2);

}

//zuz 
//34an lw 3auz aktb esm aw haga
void Output::SETbrush(color c)
{
	pWind->SetPen(c);
	pWind->SetBrush(c);
}

void Output::Drawname(GraphicsInfo Ginfo, string name)
{
	pWind->DrawString(Ginfo.x1, Ginfo.y1, name);
}
////////////////////////////////////////////////////////////
void Output::EditConn() const
{
	string Edit;
	Edit = "images\\Menu\\toolbar\\active\\edit-icon normal.jpg";
	pWind->DrawImage(Edit, 12.3 * UI.ToolItemWidth, 2 * UI.ToolBarHeight + 3, 50, 50);
}
window* Output::getpWind()
{
	return pWind;

}
void Output::clearEdit() const
{
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(12.3 * UI.ToolItemWidth, 2 * UI.ToolBarHeight + 3, 50, 50);

}

//Clears the drawing (desgin) area
void Output::ClearDrawingArea() const
{
	pWind->SetPen(BLACK, 3);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, 2 * UI.ToolBarHeight, UI.width - 14, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearAddGateBar() const
{
	pWind->SetBrush(UI.BkGrndColor);
	pWind->SetPen(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight + 3, UI.width, 2 * UI.ToolBarHeight);
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, 2 * UI.ToolBarHeight, UI.width, 2 * UI.ToolBarHeight);
}

void Output::ClearFirstBar() const
{
	pWind->SetBrush(UI.BkGrndColor);
	pWind->SetPen(UI.BkGrndColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight + 5);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the Design mode
void Output::CreateDesignToolBar() const
{
	UI.AppMode = DESIGN;	//Design Mode

	//First prepare List of images for each menu item
	string MenuItemImages[ITM_DSN_CNT];
	MenuItemImages[ITM_DESIGN] = "images\\Menu\\toolbar\\active\\Design2.jpg";
	MenuItemImages[ITM_SIMULATE] = "images\\Menu\\toolbar\\active\\simulation normal.jpg";
	MenuItemImages[ITM_LABEL] = "images\\Menu\\toolbar\\active\\label normal.jpg";
	MenuItemImages[ITM_CONNECT] = "images\\Menu\\toolbar\\active\\connect normal.jpg";
	MenuItemImages[ITM_DELETE] = "images\\Menu\\toolbar\\active\\delete2 normal.jpg";
	MenuItemImages[ITM_REDO] = "images\\Menu\\toolbar\\active\\redo2 normal.jpg";
	MenuItemImages[ITM_UNDO] = "images\\Menu\\toolbar\\active\\undo2 normal.jpg";
	MenuItemImages[ITM_COPY] = "images\\Menu\\toolbar\\active\\Copy normal.jpg";
	MenuItemImages[ITM_CUT] = "images\\Menu\\toolbar\\active\\cut normal.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Menu\\toolbar\\active\\paste normal.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Menu\\toolbar\\active\\save2 normal.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Menu\\toolbar\\active\\load2 normal.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Menu\\toolbar\\active\\exit2 normal.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i < ITM_DSN_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight + 3);


	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateAddGateToolBar() const //hbdaya mny 34an nshof 7war eny arsm tool bar gded awl ma ados 3ly add gate icon
{
	UI.AppMode = DESIGN;

	string GatesBarImages[ITM_ADDGATE_Dsgn];
	GatesBarImages[ITM_AND2] = "images\\Menu\\gatebar\\active\\and.jpg";
	GatesBarImages[ITM_OR2] = "images\\Menu\\gatebar\\active\\or.jpg";
	GatesBarImages[ITM_NAND2] = "images\\Menu\\gatebar\\active\\nand.jpg";
	GatesBarImages[ITM_NOR2] = "images\\Menu\\gatebar\\active\\nor.jpg";
	GatesBarImages[ITM_XOR2] = "images\\Menu\\gatebar\\active\\xor.jpg";
	GatesBarImages[ITM_XNOR2] = "images\\Menu\\gatebar\\active\\xnor.jpg";
	GatesBarImages[ITM_INV] = "images\\Menu\\gatebar\\active\\not.jpg";
	GatesBarImages[ITM_AND3] = "images\\Menu\\gatebar\\active\\and3.jpg";
	GatesBarImages[ITM_NOR3] = "images\\Menu\\gatebar\\active\\nor3.jpg";
	GatesBarImages[ITM_BUFF] = "images\\Menu\\gatebar\\active\\buffer.jpg";
	GatesBarImages[ITM_XOR3] = "images\\Menu\\gatebar\\active\\xor3.jpg";
	GatesBarImages[ITM_LED] = "images\\Menu\\gatebar\\active\\led.jpg";
	GatesBarImages[ITM_SWITCH] = "images\\Menu\\gatebar\\active\\switch.jpg";
	//GatesBarImages[ITM_CONNECTION]="images\\Menu\\gatebar\\active\\connection.jpg";
	//Draw menu item one image at a time
	for (int i = 0; i < ITM_ADDGATE_Dsgn; i++)
		pWind->DrawImage(GatesBarImages[i], i * UI.ToolItemWidth, UI.ToolBarHeight + 3, UI.ToolItemWidth, UI.ADDGateHeight);
	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ADDGateHeight, UI.width, UI.ADDGateHeight);
}


//////////////////////////////////////////////////////////////////////////////////////////
//Draws the menu (toolbar) in the simulation mode

void Output::CreateSimulationToolBar() const
{
	UI.AppMode = SIMULATION;

	string ToolBarItemImages[ITM_SIM_CNT];
	ToolBarItemImages[ITM_DSN] = "images\\Menu\\toolbar\\active\\Design2.jpg";
	ToolBarItemImages[ITM_SIM] = "images\\Menu\\toolbar\\active\\sim normal.jpg";
	ToolBarItemImages[ITM_TRUTH] = "images\\Menu\\toolbar\\active\\truth_table2 normal.jpg";
	ToolBarItemImages[ITM_PROBE] = "images\\Menu\\toolbar\\active\\probe.jpg";
	ToolBarItemImages[ITM_VALIDATE] = "images\\Menu\\toolbar\\active\\validation normal.jpg";
	//Draw menu item one image at a time
	for (int i = 0; i < ITM_SIM_CNT; i++)
		pWind->DrawImage(ToolBarItemImages[i], i * UI.ToolItemWidth, 0, UI.ToolItemWidth, UI.ToolBarHeight);
	//The IY coordinates depends on MenuBarHeight (which I assumed to be same as ToolBarHeight for now :D )

	//Draw a line under the toolbar
	pWind->SetPen(BLACK, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	//TODO: Write code to draw the simualtion toolbar (similar to that of design toolbar drawing)
}

//======================================================================================//
//								Components Drawing Functions							//
//======================================================================================//


void Output::DrawAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;

	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\and.jpg";
	else
		GateImage = "Images\\components\\active\\and.jpg";
	//	GateImage = "Images\\components\\highlighted\\and.jpg";
	//Draw AND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by AND2 Image Parameter in UI_Info
	if ((r_GfxInfo.y1 >= 160) && (r_GfxInfo.x1) > 10)
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GateWidth, UI.GateHeight);

}



void Output::DrawNAND2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;

	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\nand.jpg";
	else
		GateImage = "Images\\components\\active\\nand.jpg";

	//Draw NAND2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NAND2 Image Parameter in UI_Info
	if ((r_GfxInfo.y1 >= 160) && (r_GfxInfo.x1) > 10)
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GateWidth, UI.GateHeight);

}
//TODO: Add similar functions to draw all components
void Output::DrawOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;

	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\or.jpg";
	else
		GateImage = "Images\\components\\active\\or.jpg";

	//Draw OR2 Gate at Gfx_Info 
	//Set the Image Width & Height by OR2 Image Parameter in UI_Info
	if ((r_GfxInfo.y1 >= 160) && (r_GfxInfo.x1) > 10)
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GateWidth, UI.GateHeight);

}
void Output::DrawNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;

	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\nor.jpg";
	else
		GateImage = "Images\\components\\active\\nor.jpg";

	//Draw NOR2 Gate at Gfx_Info (1st corner)
	//Set the Image Width & Height by NOR2 Image Parameter in UI_Info
	if ((r_GfxInfo.y1 >= 160) && (r_GfxInfo.x1) > 10)
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GateWidth, UI.GateHeight);

}

void Output::DrawINV(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;

	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\not.jpg";
	else
		GateImage = "Images\\components\\active\\not.jpg";

	//Draw INV Gate at Gfx_Info 
	//Set the Image Width & Height by INV Image Parameter in UI_Info
	if ((r_GfxInfo.y1 >= 160) && (r_GfxInfo.x1) > 10)
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GateWidth, UI.GateHeight);

}
void Output::DrawBUFFER(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;

	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\buffer.jpg";
	else
		GateImage = "Images\\components\\active\\buffer.jpg";

	//Draw BUFFER Gate at Gfx_Info 
	//Set the Image Width & Height by BUFFER Image Parameter in UI_Info
	if ((r_GfxInfo.y1 >= 160) && (r_GfxInfo.x1) > 10)
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GateWidth, UI.GateHeight);

}

void Output::DrawXOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;

	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\xor.jpg";
	else
		GateImage = "Images\\components\\active\\xor.jpg";

	//Draw XOR2 Gate at Gfx_Info 
	//Set the Image Width & Height by XOR2 Image Parameter in UI_Info
	if ((r_GfxInfo.y1 >= 160) && (r_GfxInfo.x1) > 10)
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GateWidth, UI.GateHeight);

}

void Output::DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;


	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\xnor.jpg";
	else
		GateImage = "Images\\components\\active\\xnor.jpg";

	//Draw XNOR2 Gate at Gfx_Info 
	//Set the Image Width & Height by XNOR2 Image Parameter in UI_Info
	if ((r_GfxInfo.y1 >= 160) && (r_GfxInfo.x1) > 10)
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GateWidth, UI.GateHeight);

}
void Output::DrawAND3(GraphicsInfo r_GfxInfo, bool selected) const
{

	string GateImage;

	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\and3.jpg";
	else
		GateImage = "Images\\components\\active\\and3.jpg";

	//Draw AND3 Gate at Gfx_Info 
	//Set the Image Width & Height by AND3 Image Parameter in UI_Info
	if ((r_GfxInfo.y1 >= 160) && (r_GfxInfo.x1) > 10)
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GateWidth, UI.GateHeight);

}

void Output::DrawXOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;

	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\xor3.jpg";
	else
		GateImage = "Images\\components\\active\\xor3.jpg";

	//Draw XOR3 Gate at Gfx_Info 
	//Set the Image Width & Height by XOR3 Image Parameter in UI_Info
	if ((r_GfxInfo.y1 >= 160) && (r_GfxInfo.x1) > 10)
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GateWidth, UI.GateHeight);

}

void Output::DrawNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;

	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\nor3.jpg";
	else
		GateImage = "Images\\components\\active\\nor3.jpg";

	//Draw NOR3 Gate at Gfx_Info 
	//Set the Image Width & Height by NOR3 Image Parameter in UI_Info
	if ((r_GfxInfo.y1 >= 160) && (r_GfxInfo.x1) > 10)
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GateWidth, UI.GateHeight);

}

void Output::DrawOR3(GraphicsInfo r_GfxInfo, bool selected) const
{
	string GateImage;

	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\or3.jpg";
	else
		GateImage = "Images\\components\\active\\or3.jpg";

	//Draw OR3 Gate at Gfx_Info 
	//Set the Image Width & Height by OR3 Image Parameter in UI_Info
	if ((r_GfxInfo.y1 >= 160) && (r_GfxInfo.x1) > 10)
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GateWidth, UI.GateHeight);

}
void Output::DrawXNOR3(GraphicsInfo r_GfxInfo, bool selected) const
{

	string GateImage;
	if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\xor3.jpg";
	else
		GateImage = "Images\\components\\active\\xor3.jpg";

	//Draw XNOR3 Gate at Gfx_Info 
	//Set the Image Width & Height by XNOR3 Image Parameter in UI_Info
	if ((r_GfxInfo.y1 >= 160) && (r_GfxInfo.x1) > 10)
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GateWidth, UI.GateHeight);

}

void Output::DrawLED(GraphicsInfo r_GfxInfo, bool selected, bool on) const
{
	string GateImage;

	if (on)	//use image in the highlighted case
		GateImage = "Images\\components\\active\\led_on.jpg";
	else if (selected)	//use image in the highlighted case
		GateImage = "Images\\components\\highlighted\\led_off.jpg";
	else
		GateImage = "Images\\components\\active\\led_off.jpg";
	//Draw LED at Gfx_Info 
	//Set the Image Width & Height by LED Image Parameter in UI_Info
	if ((r_GfxInfo.y1 >= 160) && (r_GfxInfo.x1) > 10)
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GateHeight, UI.GateHeight);


}


void Output::DrawSwitch(GraphicsInfo r_GfxInfo, bool selected, bool on) const
{
	string GateImage;
	if (on)	//use image in the highlighted case
		GateImage = "Images\\components\\active\\switch_on.jpg";
	else if (selected)
		GateImage = "Images\\components\\highlighted\\switch_off.jpg";
	else
		GateImage = "Images\\components\\active\\switch_off.jpg";

	//Draw Switch at Gfx_Info 
	//Set the Image Width & Height by Switch Image Parameter in UI_Info
	if ((r_GfxInfo.y1 >= 160) && (r_GfxInfo.x1) > 10)
		pWind->DrawImage(GateImage, r_GfxInfo.x1, r_GfxInfo.y1, UI.GateHeight, UI.GateHeight);

}


void Output::DrawConnection(GraphicsInfo r_GfxInfo, bool s, color Colour) const
{

	if (!s)
		if (r_GfxInfo.x1 < r_GfxInfo.x2)
		{
			int x_intermediate = (r_GfxInfo.x2 - r_GfxInfo.x1) / 2 + r_GfxInfo.x1;
			pWind->SetPen(Colour, 2);
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, x_intermediate, r_GfxInfo.y1);
			pWind->DrawLine(x_intermediate, r_GfxInfo.y1, x_intermediate, r_GfxInfo.y2);
			pWind->DrawLine(x_intermediate, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
		}
		else
		{
			int x_intermediate = (r_GfxInfo.x2 - r_GfxInfo.x1) / 2 + r_GfxInfo.x1;
			pWind->SetPen(Colour, 2);
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, (r_GfxInfo.x1 + 10), r_GfxInfo.y1);
			pWind->DrawLine((r_GfxInfo.x1 + 10), r_GfxInfo.y1, (r_GfxInfo.x1 + 10), r_GfxInfo.y1 - 40);
			pWind->DrawLine((r_GfxInfo.x1 + 10), r_GfxInfo.y1 - 40, (r_GfxInfo.x2 - 10), r_GfxInfo.y1 - 40);
			pWind->DrawLine(r_GfxInfo.x2 - 10, r_GfxInfo.y1 - 40, (r_GfxInfo.x2 - 10), r_GfxInfo.y2);
			pWind->DrawLine(r_GfxInfo.x2 - 10, r_GfxInfo.y2, (r_GfxInfo.x2), r_GfxInfo.y2);

		}
	else
	{
		if (r_GfxInfo.x1 < r_GfxInfo.x2)
		{
			int x_intermediate = (r_GfxInfo.x2 - r_GfxInfo.x1) / 2 + r_GfxInfo.x1;
			pWind->SetPen(ORANGE, 2);
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, x_intermediate, r_GfxInfo.y1);
			pWind->DrawLine(x_intermediate, r_GfxInfo.y1, x_intermediate, r_GfxInfo.y2);
			pWind->DrawLine(x_intermediate, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
		}
		else
		{
			int x_intermediate = (r_GfxInfo.x2 - r_GfxInfo.x1) / 2 + r_GfxInfo.x1;
			pWind->SetPen(ORANGE, 2);
			pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, (r_GfxInfo.x1 + 10), r_GfxInfo.y1);
			pWind->DrawLine((r_GfxInfo.x1 + 10), r_GfxInfo.y1, (r_GfxInfo.x1 + 10), r_GfxInfo.y1 - 40);
			pWind->DrawLine((r_GfxInfo.x1 + 10), r_GfxInfo.y1 - 40, (r_GfxInfo.x2 - 10), r_GfxInfo.y1 - 40);
			pWind->DrawLine(r_GfxInfo.x2 - 10, r_GfxInfo.y1 - 40, (r_GfxInfo.x2 - 10), r_GfxInfo.y2);
			pWind->DrawLine(r_GfxInfo.x2 - 10, r_GfxInfo.y2, (r_GfxInfo.x2), r_GfxInfo.y2);


		}
	}
}

Output::~Output()
{
	delete pWind;
}

//34an ams7 ay gate aw arsm mostatel 3la ay haga
void Output::Drawremove(GraphicsInfo r_GfxInfo) const
{
	pWind->SetBrush(UI.BkGrndColor);
	pWind->SetPen(UI.BkGrndColor);
	pWind->DrawRectangle(r_GfxInfo.x1, r_GfxInfo.y1, r_GfxInfo.x2, r_GfxInfo.y2);
}
void Output::RemoveConnection(GraphicsInfo r_GfxInfo) const
{

	if (r_GfxInfo.x1 < r_GfxInfo.x2)
	{
		int x_intermediate = (r_GfxInfo.x2 - r_GfxInfo.x1) / 2 + r_GfxInfo.x1;
		pWind->SetPen(UI.BkGrndColor, 2);
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, x_intermediate, r_GfxInfo.y1);
		pWind->DrawLine(x_intermediate, r_GfxInfo.y1, x_intermediate, r_GfxInfo.y2);
		pWind->DrawLine(x_intermediate, r_GfxInfo.y2, r_GfxInfo.x2, r_GfxInfo.y2);
	}
	else
	{
		int x_intermediate = (r_GfxInfo.x2 - r_GfxInfo.x1) / 2 + r_GfxInfo.x1;
		pWind->SetPen(UI.BkGrndColor, 2);
		pWind->DrawLine(r_GfxInfo.x1, r_GfxInfo.y1, (r_GfxInfo.x1 + 10), r_GfxInfo.y1);
		pWind->DrawLine((r_GfxInfo.x1 + 10), r_GfxInfo.y1, (r_GfxInfo.x1 + 10), r_GfxInfo.y1 - 40);
		pWind->DrawLine((r_GfxInfo.x1 + 10), r_GfxInfo.y1 - 40, (r_GfxInfo.x2 - 10), r_GfxInfo.y1 - 40);
		pWind->DrawLine(r_GfxInfo.x2 - 10, r_GfxInfo.y1 - 40, (r_GfxInfo.x2 - 10), r_GfxInfo.y2);
		pWind->DrawLine(r_GfxInfo.x2 - 10, r_GfxInfo.y2, (r_GfxInfo.x2), r_GfxInfo.y2);

	}
}
