#include "Paste.h"

Paste::Paste(ApplicationManager* papp) : Action(papp)
{
	Ginfo.x1 = 0;
	Ginfo.x2 = 0;
	Ginfo.y1 = 0;
	Ginfo.y2 = 0;
	cptr = NULL;
	Pout = NULL;
	Pin = NULL;
	mComp = NULL;
	Arrsize = 0;
}

void Paste::ReadActionParameters()
{
	int sizeofcut = pManager->get_Cutcount();
	if (sizeofcut != 0)
	{
		Pout = pManager->GetOutput();
		Pout->PrintMsg("To Not forget the order of the gates , the gates will be removed after pasting them , please select the place , focus on the order");
		Pin = pManager->GetInput();
		Pin->GetPointClicked(x1, y2);
		return;
	}
	Pout = pManager->GetOutput();
	Pout->PrintMsg("select the place you want to paste at. please note that the component/s are going to be pasted in the same order of selecting...");
	Pin = pManager->GetInput();
	Pin->GetPointClicked(x1, y2);

}

bool Paste::Execute()
{

	int size = pManager->get_CopiedCount();

	ArrtoPaste = pManager->Get_CopiedList();

	for (int k = 0; k < size; k++)
	{
		ReadActionParameters();


		Ginfo.x1 = x1;
		Ginfo.y1 = y2;
		Ginfo.x2 = x1 + UI.GateWidth;
		Ginfo.y2 = y2 + UI.GateHeight;

		AND2* pa2 = dynamic_cast<AND2*> (ArrtoPaste[k]);
		if (pa2 != NULL)
		{
			pa2 = new AND2(Ginfo, default_FANOUT);
			pa2->SetLabel(ArrtoPaste[k]->GetLabel());
			pManager->AddComponent(pa2);
			pManager->UpdateInterface();

			continue;
		}


		AND3* pa3 = dynamic_cast<AND3*> (ArrtoPaste[k]);
		if (pa3 != NULL)
		{
			pa3 = new AND3(Ginfo, default_FANOUT);
			pa3->SetLabel(ArrtoPaste[k]->GetLabel());
			pManager->AddComponent(pa3);
			pManager->UpdateInterface();
			continue;
		}


		NAND2* pna2 = dynamic_cast<NAND2*> (ArrtoPaste[k]);
		if (pna2 != NULL)
		{
			pna2 = new NAND2(Ginfo, default_FANOUT);
			pna2->SetLabel(ArrtoPaste[k]->GetLabel());
			pManager->AddComponent(pna2);
			pManager->UpdateInterface();
			continue;
		}


		OR2* po2 = dynamic_cast<OR2*> (ArrtoPaste[k]);
		if (po2 != NULL)
		{
			po2 = new OR2(Ginfo, default_FANOUT);
			po2->SetLabel(ArrtoPaste[k]->GetLabel());
			pManager->AddComponent(po2);
			pManager->UpdateInterface();
			continue;
		}


		XNOR2* pxn2 = dynamic_cast<XNOR2*> (ArrtoPaste[k]);
		if (pxn2 != NULL)
		{
			pxn2 = new XNOR2(Ginfo, default_FANOUT);
			pxn2->SetLabel(ArrtoPaste[k]->GetLabel());
			pManager->AddComponent(pxn2);
			pManager->UpdateInterface();
			continue;
		}

		NOR2* pn2 = dynamic_cast<NOR2*> (ArrtoPaste[k]);
		if (pn2 != NULL)
		{
			pn2 = new NOR2(Ginfo, default_FANOUT);
			pn2->SetLabel(ArrtoPaste[k]->GetLabel());
			pManager->AddComponent(pn2);
			pManager->UpdateInterface();
			continue;
		}


		NOR3* pn3 = dynamic_cast<NOR3*> (ArrtoPaste[k]);
		if (pn3 != NULL)
		{
			pn3 = new NOR3(Ginfo, default_FANOUT);
			pn2->SetLabel(ArrtoPaste[k]->GetLabel());
			pManager->AddComponent(pn3);
			pManager->UpdateInterface();
			continue;
		}


		XOR2* pxo2 = dynamic_cast<XOR2*> (ArrtoPaste[k]);
		if (pxo2 != NULL)
		{
			pxo2 = new XOR2(Ginfo, default_FANOUT);
			pxo2->SetLabel(ArrtoPaste[k]->GetLabel());
			pManager->AddComponent(pxo2);
			pManager->UpdateInterface();
			continue;
		}


		XOR3* pxo3 = dynamic_cast<XOR3*> (ArrtoPaste[k]);
		if (pxo3 != NULL)
		{
			pxo3 = new XOR3(Ginfo, default_FANOUT);
			pxo3->SetLabel(ArrtoPaste[k]->GetLabel());
			pManager->AddComponent(pxo3);
			pManager->UpdateInterface();
			continue;
		}


		BUFF* pb = dynamic_cast<BUFF*> (ArrtoPaste[k]);
		if (pb != NULL)
		{
			pb = new BUFF(Ginfo, default_FANOUT);
			pb->SetLabel(ArrtoPaste[k]->GetLabel());
			pManager->AddComponent(pb);
			pManager->UpdateInterface();
			continue;
		}
		INV* pINV = dynamic_cast<INV*> (ArrtoPaste[k]);
		if (pINV != NULL)
		{
			pINV = new INV(Ginfo, default_FANOUT);
			pINV->SetLabel(ArrtoPaste[k]->GetLabel());
			pManager->AddComponent(pINV);
			pManager->UpdateInterface();
			continue;
		}


		LED* pL2 = dynamic_cast<LED*> (ArrtoPaste[k]);
		if (pL2 != NULL)
		{
			pL2 = new LED(Ginfo, default_FANOUT);
			pL2->SetLabel(ArrtoPaste[k]->GetLabel());
			pManager->AddComponent(pL2);
			pManager->UpdateInterface();
			continue;
		}


		SWITCH* ps = dynamic_cast<SWITCH*> (ArrtoPaste[k]);
		if (ps != NULL)
		{
			ps = new SWITCH(Ginfo, default_FANOUT);
			ps->SetLabel(ArrtoPaste[k]->GetLabel());
			pManager->AddComponent(ps);
			pManager->UpdateInterface();
			continue;
		}

	}

	// ha5azzn 3dd el copied components 34an lw 3auz ast5dmha fl Undo wl Redo
	Arrsize = pManager->get_CopiedCount();


	// da 34an ana b3d ma b3ml undo b5ly el Undo count b 0 bs ana bab2a me7tag a3rf el Undocount b kam 34an lw h3ml undo aw redo w kda


	if (pManager->Get_CopiedList() != NULL);
	{
		// bkhleh b sfr 34an abd2 baa mn awl w gded lama agy a3ml cpy tany
		pManager->setCopiedCount(0);
	}


	// b check lw howa das paste mn gher ma ykon fe haga m3molha copy aw cut
	if (Arrsize != 0)
	{
		Pout->ClearStatusBar();
		Pout->PrintMsg("Pasted");
	}
	else
	{
		Pout = pManager->GetOutput();
		Pout->ClearStatusBar();
		Pout->PrintMsg("there are no components to be pasted");
	}
	return true;

	// paste done
}

void Paste::Undo()
{
	int index = pManager->GetCompCount() - 1;
	for (int i = 0; i < Arrsize; i++)
	{

		mComp = pManager->GetCmp(index - i);

		AND2* pa2 = dynamic_cast<AND2*> (mComp);
		if (pa2 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pa2 = new AND2(Ginfo, default_FANOUT);
			pManager->AddToComp2(pa2);
			pManager->DeleteComponent(index - i);
			//pManager->Undo();
			continue;
		}

		AND3* pa3 = dynamic_cast<AND3*> (mComp);
		if (pa3 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pa3 = new AND3(Ginfo, default_FANOUT);
			pManager->AddToComp2(pa3);
			pManager->DeleteComponent(index - i);
			//pManager->Undo();
			continue;
		}

		NAND2* pna2 = dynamic_cast<NAND2*> (mComp);
		if (pna2 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pna2 = new NAND2(Ginfo, default_FANOUT);
			pManager->AddToComp2(pna2);
			pManager->DeleteComponent(index - i);
			continue;
		}

		OR2* po2 = dynamic_cast<OR2*> (mComp);
		if (po2 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			po2 = new OR2(Ginfo, default_FANOUT);
			pManager->AddToComp2(po2);
			pManager->DeleteComponent(index - i);
			continue;
		}

		XNOR2* pxn2 = dynamic_cast<XNOR2*> (mComp);
		if (pxn2 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pxn2 = new XNOR2(Ginfo, default_FANOUT);
			pManager->AddToComp2(pxn2);
			pManager->DeleteComponent(index - i);
			continue;
		}

		NOR2* pn2 = dynamic_cast<NOR2*> (mComp);
		if (pn2 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pn2 = new NOR2(Ginfo, default_FANOUT);
			pManager->AddToComp2(pn2);
			pManager->DeleteComponent(index - i);
			continue;
		}


		NOR3* pn3 = dynamic_cast<NOR3*> (mComp);
		if (pn3 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pn3 = new NOR3(Ginfo, default_FANOUT);
			pManager->AddToComp2(pn3);
			pManager->DeleteComponent(index - i);
			continue;
		}


		XOR2* pxo2 = dynamic_cast<XOR2*> (mComp);
		if (pxo2 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pxo2 = new XOR2(Ginfo, default_FANOUT);
			pManager->AddToComp2(pxo2);
			pManager->DeleteComponent(index - i);
			continue;
		}


		XOR3* pxo3 = dynamic_cast<XOR3*> (mComp);
		if (pxo3 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pxo3 = new XOR3(Ginfo, default_FANOUT);
			pManager->AddToComp2(pxo3);
			pManager->DeleteComponent(index - i);
			continue;
		}


		BUFF* pb = dynamic_cast<BUFF*> (mComp);
		if (pb != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pb = new BUFF(Ginfo, default_FANOUT);
			pManager->AddToComp2(pb);
			pManager->DeleteComponent(index - i);
			continue;
		}
		INV* pINV = dynamic_cast<INV*> (mComp);
		if (pINV != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pINV = new INV(Ginfo, default_FANOUT);
			pManager->AddToComp2(pINV);
			pManager->DeleteComponent(index - i);
			continue;
		}


		LED* pL2 = dynamic_cast<LED*> (mComp);
		if (pL2 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pL2 = new LED(Ginfo, default_FANOUT);
			pManager->AddToComp2(pL2);
			pManager->DeleteComponent(index - i);
			continue;
		}


		SWITCH* ps = dynamic_cast<SWITCH*> (mComp);
		if (ps != NULL)
		{
			Ginfo = mComp->GetGInfo();
			ps = new SWITCH(Ginfo, default_FANOUT);
			pManager->AddToComp2(ps);
			pManager->DeleteComponent(index - i);
			continue;
		}
	}

}

void Paste::Redo()
{
	int index = pManager->GetCompcount2() - 1;
	for (int i = 0; i < Arrsize; i++)
	{

		mComp = pManager->GetComp2(index - i);

		AND2* pa2 = dynamic_cast<AND2*> (mComp);
		if (pa2 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pa2 = new AND2(Ginfo, default_FANOUT);
			pManager->AddComponent(pa2);
			pManager->RemoveFromComp2(index - i);
			continue;
		}

		AND3* pa3 = dynamic_cast<AND3*> (mComp);
		if (pa3 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pa3 = new AND3(Ginfo, default_FANOUT);
			pManager->AddComponent(pa3);
			pManager->RemoveFromComp2(index - i);
			continue;
		}

		NAND2* pna2 = dynamic_cast<NAND2*> (mComp);
		if (pna2 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pna2 = new NAND2(Ginfo, default_FANOUT);
			pManager->AddComponent(pna2);
			pManager->RemoveFromComp2(index - i);
			continue;
		}

		OR2* po2 = dynamic_cast<OR2*> (mComp);
		if (po2 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			po2 = new OR2(Ginfo, default_FANOUT);
			pManager->AddComponent(po2);
			pManager->RemoveFromComp2(index - i);
			continue;
		}

		XNOR2* pxn2 = dynamic_cast<XNOR2*> (mComp);
		if (pxn2 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pxn2 = new XNOR2(Ginfo, default_FANOUT);
			pManager->AddComponent(pxn2);
			pManager->RemoveFromComp2(index - i);
			continue;
		}

		NOR2* pn2 = dynamic_cast<NOR2*> (mComp);
		if (pn2 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pn2 = new NOR2(Ginfo, default_FANOUT);
			pManager->AddComponent(pn2);
			pManager->RemoveFromComp2(index - i);
			continue;
		}


		NOR3* pn3 = dynamic_cast<NOR3*> (mComp);
		if (pn3 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pn3 = new NOR3(Ginfo, default_FANOUT);
			pManager->AddComponent(pn3);
			pManager->RemoveFromComp2(index - i);
			continue;
		}


		XOR2* pxo2 = dynamic_cast<XOR2*> (mComp);
		if (pxo2 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pxo2 = new XOR2(Ginfo, default_FANOUT);
			pManager->AddComponent(pxo2);
			pManager->RemoveFromComp2(index - i);
			continue;
		}


		XOR3* pxo3 = dynamic_cast<XOR3*> (mComp);
		if (pxo3 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pxo3 = new XOR3(Ginfo, default_FANOUT);
			pManager->AddComponent(pxo3);
			pManager->RemoveFromComp2(index - i);
			continue;
		}


		BUFF* pb = dynamic_cast<BUFF*> (mComp);
		if (pb != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pb = new BUFF(Ginfo, default_FANOUT);
			pManager->AddComponent(pb);
			pManager->RemoveFromComp2(index - i);
			continue;
		}
		INV* pINV = dynamic_cast<INV*> (mComp);
		if (pINV != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pINV = new INV(Ginfo, default_FANOUT);
			pManager->AddComponent(pINV);
			pManager->RemoveFromComp2(index - i);
			continue;
		}


		LED* pL2 = dynamic_cast<LED*> (mComp);
		if (pL2 != NULL)
		{
			Ginfo = mComp->GetGInfo();
			pL2 = new LED(Ginfo, default_FANOUT);
			pManager->AddComponent(pL2);
			pManager->RemoveFromComp2(index - i);
			continue;
		}


		SWITCH* ps = dynamic_cast<SWITCH*> (mComp);
		if (ps != NULL)
		{
			Ginfo = mComp->GetGInfo();
			ps = new SWITCH(Ginfo, default_FANOUT);
			pManager->AddComponent(ps);
			pManager->RemoveFromComp2(index - i);
			continue;
		}
	}
}
