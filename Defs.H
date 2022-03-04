#ifndef CONST_H
#define CONST_H

//This header file contains some defenitions to be used all over the application

//All possible actions
enum ActionType
{
	ADD_DESIGN,			//add gate
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INVERTER, 		//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	ADD_led,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection
	ADD_TOOLBOX,

	ADD_Label,			//Add Label to a Component, a Connection
	EDIT_Label,			//Edit Label of a Component, a Connection

	Create_TruthTable,	//Create Truth Table of the Circuit

	CHANGE_SWITCH,		//Change Switch Status in Simulation Mode
	SIMULATE,
	PROBING,
	SELECT,		//Select a Component, a Connection
	DEL,		//Delete a Component, a Connection
	MOVE,		//Move a Component, a Connection
	COPY,		//copy comp	
	CUT,		//Cut comp
	PASTE,		//paste comp
	SAVE,		//Save the whole Circuit to a file       
	LOAD,		//Load a Circuit from a file

	UNDO,		//Undo the last Action preformed
	REDO,		//Redo the last Action canceled

	DSN_MODE,	//Switch to Design mode
	SIM_MODE,	//Switch to Simulatiom mode
	Validation,
	EXIT,		//Exit the application
	EDIT,
	STATUS_BAR,		//A click on the status bar
	DSN_TOOL,	//A click on an empty place in the design tool bar

};

//Possible Status for the pin
enum STATUS
{
	LOW,
	HIGH
};

enum  MODE	//Modes of operation
{
	DESIGN,
	SIMULATION
};



enum DsgnMenuItem //The items of the design menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_DESIGN,     //add gate icon
	ITM_SIMULATE,
	ITM_LABEL,
	ITM_CONNECT,
	ITM_DELETE,
	ITM_REDO,
	ITM_UNDO,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_SAVE,
	ITM_LOAD,
	ITM_EXIT,

	ITM_DSN_CNT,	//no. of design menu items ==> This should be the last line in this enum

};
enum DsgnADDGateBar
{
	ITM_AND2,		//AND gate item in menu
	ITM_OR2,		//OR gate item in menu
	ITM_NAND2,		//NAND 2 INPUTS   
	ITM_NOR2,		//NOR GATE 2 INPUTS
	ITM_XOR2,		//XOR 2 INPUTS
	ITM_XNOR2,		//XNOR 2 INPUTS   
	ITM_INV,		//INVEROR                             
	ITM_AND3,		//AND GATE 3 INPUTS                 
	ITM_NOR3,		//NOR GATE 3 INPUTS                  
	ITM_BUFF,		//BUFFER                          
	ITM_XOR3,		//XOR 3 INPUTS                            
	ITM_LED,		//led
	ITM_SWITCH,		//switch  
	ITM_ADDGATE_Dsgn     //counter for items in add gate
};
enum SimMenuItem //The items of the simulation menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	ITM_DSN,
	ITM_SIM,
	ITM_TRUTH,
	ITM_PROBE,
	ITM_VALIDATE,
	ITM_SIM_CNT		//no. of simulation menu items ==> This should be the last line in this enum

};

//Maximum number of input pins that can be connected to any output pin
#define MAX_CONNS 20

//assume fan out is 5 for now it can be read from the user or can be predefined as const
enum FANOUT
{
	default_FANOUT = 5	//Default fan out of 2-input AND gate
};

enum TYPE
{
	_GATE,
	_SWITCH,
	_LED,
	_CONNECTION
};
//A structure to contain drawing parameters for each component
//Each component occupies a rectangluar area so it needs 2 points to represent that area
//this structure can be extended if desired
struct GraphicsInfo
{
	int x1, y1, x2, y2;
};

#ifndef NULL
#define NULL 0
#endif

#endif