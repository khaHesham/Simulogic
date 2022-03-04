#include "Undo.h"

Undoo::Undoo(ApplicationManager* pApp) :Action(pApp)
{
}

Undoo::~Undoo(void)
{
}

void Undoo::ReadActionParameters()
{
}

bool Undoo::Execute()
{
	


	int undocount = pManager->getUndoCount();
	if (undocount != 0)
	{
		for (int i = 0; i < undocount ; i++)
		{
			mComp = pManager->GetCmp(pManager->GetCompCount() - i - 1);

			AND2* pa2 = dynamic_cast<AND2*> (mComp); 
			if (pa2 != NULL)
			{
				Ginfo = mComp->GetGInfo();
				pa2 = new AND2(Ginfo, default_FANOUT);
				pManager->AddToComp2(pa2);
				//pManager->Undo();
				continue;
			}

			AND3* pa3 = dynamic_cast<AND3*> (mComp);
			if (pa3 != NULL)
			{
				Ginfo = mComp->GetGInfo();
				pa3 = new AND3(Ginfo, default_FANOUT);
				pManager->AddToComp2(pa3);
				//pManager->Undo();
				continue;
			}
			
			NAND2* pna2 = dynamic_cast<NAND2*> (mComp);
			if (pna2 != NULL)
			{
				Ginfo = mComp->GetGInfo();
				pna2 = new NAND2(Ginfo, default_FANOUT);
				pManager->AddToComp2(pna2);				
				continue;
			}

			OR2* po2 = dynamic_cast<OR2*> (mComp);
			if (po2 != NULL)
			{
				Ginfo = mComp->GetGInfo();
				po2 = new OR2(Ginfo, default_FANOUT);
				pManager->AddToComp2(po2);
				continue;
			}

			XNOR2* pxn2 = dynamic_cast<XNOR2*> (mComp);
			if (pxn2 != NULL)
			{
				Ginfo = mComp->GetGInfo();
				pxn2 = new XNOR2(Ginfo, default_FANOUT);
				pManager->AddToComp2(pxn2);
				continue;
			}

			NOR2* pn2 = dynamic_cast<NOR2*> (mComp);
			if (pn2 != NULL)
			{
				Ginfo = mComp->GetGInfo(); // bgeb el Graphics info bta3ha w ba3ml mnha nos5a w ashtghl 3l noskha de baa
				pn2 = new NOR2(Ginfo, default_FANOUT);
				pManager->AddToComp2(pn2);
				continue;
			}


			NOR3* pn3 = dynamic_cast<NOR3*> (mComp);
			if (pn3 != NULL)
			{
				Ginfo = mComp->GetGInfo();
				pn3 = new NOR3(Ginfo, default_FANOUT);
				pManager->AddToComp2(pn3);
				continue;
			}


			XOR2* pxo2 = dynamic_cast<XOR2*> (mComp);
			if (pxo2 != NULL)
			{
				Ginfo = mComp->GetGInfo();
				pxo2 = new XOR2(Ginfo, default_FANOUT);
				pManager->AddToComp2(pxo2);
				continue;
			}


			XOR3* pxo3 = dynamic_cast<XOR3*> (mComp);
			if (pxo3 != NULL)
			{
				Ginfo = mComp->GetGInfo();
				pxo3 = new XOR3(Ginfo, default_FANOUT);
				pManager->AddToComp2(pxo3);
				continue;
			}


			BUFF* pb = dynamic_cast<BUFF*> (mComp);
			if (pb != NULL)
			{
				Ginfo = mComp->GetGInfo();
				pb = new BUFF(Ginfo, default_FANOUT);
				pManager->AddToComp2(pb);
				continue;
			}
			INV* pINV = dynamic_cast<INV*> (mComp);
			if (pINV != NULL)
			{
				Ginfo = mComp->GetGInfo();
				pINV = new INV(Ginfo, default_FANOUT);
				pManager->AddToComp2(pINV);
				continue;
			}


			LED* pL2 = dynamic_cast<LED*> (mComp);
			if (pL2 != NULL)
			{
				Ginfo = mComp->GetGInfo();
				pL2 = new LED(Ginfo, default_FANOUT);
				pManager->AddToComp2(pL2);
				continue;
			}


			SWITCH* ps = dynamic_cast<SWITCH*> (mComp);
			if (ps != NULL)
			{
				Ginfo = mComp->GetGInfo();
				ps = new SWITCH(Ginfo, default_FANOUT);
				pManager->AddToComp2(ps);
				continue;
			}
		}
		pManager->Undo();
		return false;
	}

	//mComp = pManager->GetCmp(pManager->GetCompCount() - 1);

	//// check en el pointer mn no3 el gate l hattb3 w b3d kda acreat gate gdeda w azwdha fl component list w b3d kda a3ml update ll interface 34an yrsm el gate el gdeda
	//AND2* pa2 = dynamic_cast<AND2*> (mComp);
	//if (pa2 != NULL)
	//{
	//	Ginfo = mComp->GetGInfo();
	//	pa2 = new AND2(Ginfo, default_FANOUT);
	//	pManager->AddToComp2(pa2);
	//	pManager->Undo();
	//	return false;
	//}

	//AND3* pa3 = dynamic_cast<AND3*> (mComp);
	//if (pa3 != NULL)
	//{
	//	Ginfo = mComp->GetGInfo();
	//	pa3 = new AND3(Ginfo, default_FANOUT);
	//	pManager->AddToComp2(pa3);
	//	pManager->Undo();
	//	return false;
	//}

	//NAND2* pna2 = dynamic_cast<NAND2*> (mComp);
	//if (pna2 != NULL)
	//{
	//	Ginfo = mComp->GetGInfo();
	//	pna2 = new NAND2(Ginfo, default_FANOUT);
	//	pManager->AddToComp2(pna2);
	//	pManager->Undo();
	//	return false;
	//}

	//OR2* po2 = dynamic_cast<OR2*> (mComp);
	//if (po2 != NULL)
	//{
	//	Ginfo = mComp->GetGInfo();
	//	po2 = new OR2(Ginfo, default_FANOUT);
	//	pManager->AddToComp2(po2);
	//	pManager->Undo();
	//	return false;
	//}

	//XNOR2* pxn2 = dynamic_cast<XNOR2*> (mComp);
	//if (pxn2 != NULL)
	//{
	//	Ginfo = mComp->GetGInfo();
	//	pxn2 = new XNOR2(Ginfo, default_FANOUT);
	//	pManager->AddToComp2(pxn2);
	//	pManager->Undo();
	//	return false;
	//}

	//NOR2* pn2 = dynamic_cast<NOR2*> (mComp);
	//if (pn2 != NULL)
	//{
	//	Ginfo = mComp->GetGInfo(); // bgeb el Graphics info bta3ha w ba3ml mnha nos5a w ashtghl 3l noskha de baa
	//	pn2 = new NOR2(Ginfo, default_FANOUT);
	//	pManager->AddToComp2(pn2);
	//	pManager->Undo();
	//	return false;
	//}

	//NOR3* pn3 = dynamic_cast<NOR3*> (mComp);
	//if (pn3 != NULL)
	//{
	//	Ginfo = mComp->GetGInfo();
	//	pn3 = new NOR3(Ginfo, default_FANOUT);
	//	pManager->AddToComp2(pn3);
	//	pManager->Undo();
	//	return false;
	//}

	//XOR2* pxo2 = dynamic_cast<XOR2*> (mComp);
	//if (pxo2 != NULL)
	//{
	//	Ginfo = mComp->GetGInfo();
	//	pxo2 = new XOR2(Ginfo, default_FANOUT);
	//	pManager->AddToComp2(pxo2);
	//	pManager->Undo();
	//	return false;
	//}

	//XOR3* pxo3 = dynamic_cast<XOR3*> (mComp);
	//if (pxo3 != NULL)
	//{
	//	Ginfo = mComp->GetGInfo();
	//	pxo3 = new XOR3(Ginfo, default_FANOUT);
	//	pManager->AddToComp2(pxo3);
	//	pManager->Undo();
	//	return false;
	//}

	//BUFF* pb = dynamic_cast<BUFF*> (mComp);
	//if (pb != NULL)
	//{
	//	Ginfo = mComp->GetGInfo();
	//	pb = new BUFF(Ginfo, default_FANOUT);
	//	pManager->AddToComp2(pb);
	//	pManager->Undo();
	//	return false;
	//}

	//INV* pINV = dynamic_cast<INV*> (mComp);
	//if (pINV != NULL)
	//{
	//	Ginfo = mComp->GetGInfo();
	//	pINV = new INV(Ginfo, default_FANOUT);
	//	pManager->AddToComp2(pINV);
	//	pManager->Undo();
	//	return false;
	//}


	//LED* pL2 = dynamic_cast<LED*> (mComp);
	//if (pL2 != NULL)
	//{
	//	Ginfo = mComp->GetGInfo();
	//	pL2 = new LED(Ginfo, default_FANOUT);
	//	pManager->AddToComp2(pL2);
	//	pManager->Undo();
	//	return false;
	//}


	//SWITCH* ps = dynamic_cast<SWITCH*> (mComp);
	//if (ps != NULL)
	//{
	//	Ginfo = mComp->GetGInfo();
	//	ps = new SWITCH(Ginfo, default_FANOUT);
	//	pManager->AddToComp2(ps);
	//	pManager->Undo();
	//	return false;
	//}


	return false; //34an m7othash fl stack tany
}

void Undoo::Undo()
{
	//EMPTY
}

void Undoo::Redo()
{
	//EMPTY
}
