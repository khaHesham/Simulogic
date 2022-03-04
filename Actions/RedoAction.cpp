#include "RedoAction.h"

RedoAction::RedoAction(ApplicationManager* pAppMan) : Action(pAppMan) {

}

void RedoAction::ReadActionParameters() {

}

bool RedoAction::Execute() {

	int Undocount = pManager->getUndoCount();
	if (Undocount != 0)
	{

		pManager->Redo();
		return false;
	}

	int Size = pManager->GetCompcount2();

	mComp = pManager->GetComp2(Size - 1);

	AND2* pa2 = dynamic_cast<AND2*> (mComp);
	if (pa2 != NULL)
	{
		Ginfo = mComp->GetGInfo();
		pa2 = new AND2(Ginfo, default_FANOUT);
		pManager->AddComponent(pa2);

		pManager->Redo();
	}

	AND3* pa3 = dynamic_cast<AND3*> (mComp);
	if (pa3 != NULL)
	{
		Ginfo = mComp->GetGInfo();
		pa3 = new AND3(Ginfo, default_FANOUT);
		pManager->AddComponent(pa3);
		pManager->Redo();
		return false;
	}


	NAND2* pna2 = dynamic_cast<NAND2*> (mComp);
	if (pna2 != NULL)
	{
		Ginfo = mComp->GetGInfo();
		pna2 = new NAND2(Ginfo, default_FANOUT);
		pManager->AddComponent(pna2);
		pManager->Redo();
		return false;
	}


	OR2* po2 = dynamic_cast<OR2*> (mComp);
	if (po2 != NULL)
	{
		Ginfo = mComp->GetGInfo();
		po2 = new OR2(Ginfo, default_FANOUT);
		pManager->AddComponent(po2);
		pManager->Redo();
		return false;
	}

	XNOR2* pxn2 = dynamic_cast<XNOR2*> (mComp);
	if (pxn2 != NULL)
	{
		Ginfo = mComp->GetGInfo();
		pxn2 = new XNOR2(Ginfo, default_FANOUT);
		pManager->AddComponent(pxn2);
		pManager->Redo();
		return false;
	}

	NOR2* pn2 = dynamic_cast<NOR2*> (mComp);
	if (pn2 != NULL)
	{
		Ginfo = mComp->GetGInfo();
		pn2 = new NOR2(Ginfo, default_FANOUT);
		pManager->AddComponent(pn2);
		pManager->Redo();
		return false;
	}


	NOR3* pn3 = dynamic_cast<NOR3*> (mComp);
	if (pn3 != NULL)
	{
		Ginfo = mComp->GetGInfo();
		pn3 = new NOR3(Ginfo, default_FANOUT);
		pManager->AddComponent(pn3);
		pManager->Redo();
		return false;
	}


	XOR2* pxo2 = dynamic_cast<XOR2*> (mComp);
	if (pxo2 != NULL)
	{
		Ginfo = mComp->GetGInfo();
		pxo2 = new XOR2(Ginfo, default_FANOUT);
		pManager->AddComponent(pxo2);
		pManager->Redo();
		return false;
	}


	XOR3* pxo3 = dynamic_cast<XOR3*> (mComp);
	if (pxo3 != NULL)
	{
		Ginfo = mComp->GetGInfo();
		pxo3 = new XOR3(Ginfo, default_FANOUT);
		pManager->AddComponent(pxo3);
		pManager->Redo();
		return false;
	}


	BUFF* pb = dynamic_cast<BUFF*> (mComp);
	if (pb != NULL)
	{
		Ginfo = mComp->GetGInfo();
		pb = new BUFF(Ginfo, default_FANOUT);
		pManager->AddComponent(pb);
		pManager->Redo();
		return false;
	}
	INV* pINV = dynamic_cast<INV*> (mComp);
	if (pINV != NULL)
	{
		Ginfo = mComp->GetGInfo();
		pINV = new INV(Ginfo, default_FANOUT);
		pManager->AddComponent(pINV);
		pManager->Redo();
		return false;
	}


	LED* pL2 = dynamic_cast<LED*> (mComp);
	if (pL2 != NULL)
	{
		Ginfo = mComp->GetGInfo();
		pL2 = new LED(Ginfo, default_FANOUT);
		pManager->AddComponent(pL2);
		pManager->Redo();
		return false;
	}


	SWITCH* ps = dynamic_cast<SWITCH*> (mComp);
	if (ps != NULL)
	{
		Ginfo = mComp->GetGInfo();
		ps = new SWITCH(Ginfo, default_FANOUT);
		pManager->AddComponent(ps);
		pManager->Redo();
		return false;
	}
	return false;
}


void RedoAction::Undo() {
	return;
}

void RedoAction::Redo() {
	return;
}

RedoAction::~RedoAction() {

}