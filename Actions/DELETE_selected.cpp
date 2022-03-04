#include"DELETE_selected.h"



DELETE_selected::DELETE_selected(ApplicationManager* papp) :Action(papp)
{
	noOfDletedComp = 0;
}


void DELETE_selected::ReadActionParameters()
{
}


bool DELETE_selected::Execute()
{

	Output* pOut = pManager->GetOutput();
	//////// Delete selected components
	for (int k = 0; k < pManager->GetCompCount(); k++)
	{
		mdeletedcomp = pManager->GetCmp(k);
		//////// Delete selected components
		if (mdeletedcomp->selected())
		{
			if (mdeletedcomp->GetType() != _CONNECTION)  //As long as the component is not connection will enter tis code to delete input and output connections if it is gate
			{
				if (mdeletedcomp->GetType() != _LED) //since leds has no outputpin
				{
					OutputPin* out = ((Gate*)mdeletedcomp)->GetOutPin();
					if (out->getConnNumber() != 0) //----------->>>>>If it has  connections connected in outputPins
					{
						out->selectConn();  //-->make the ouputpin connections selected to be easily deleted
					}
				}
				if (mdeletedcomp->GetType() != _SWITCH) //since switch has no input pin
				{
					for (int i = 0; i < ((Gate*)mdeletedcomp)->GetNumInputs(); i++) //make the input pin connnections selected to be easily deleted
					{
						InputPin* in = ((Gate*)mdeletedcomp)->GetInPin(i);
						if (in->Connected() == true) ///->>>>>>>>>>>> if it has at least one connection connected in input pin
						{
							Connection* co = in->get_conn();
							if (co != NULL)
							{
								co->setselected(true);  //make connections selected
							}
						}
					}
				}
			}

			//for deleting the label
			GraphicsInfo GI = mdeletedcomp->GetGInfo();
			string label = mdeletedcomp->GetLabel();
			GI.x1 = GI.x1 - 30;
			GI.y1 = GI.y1 - 30;
			GI.x2 = GI.x1 + label.size() * 8;
			GI.y2 = GI.y1 + 30;
			pOut->Drawremove(GI);

			///////UNDO & REDO Code Starts From Here////////
			if (mdeletedcomp->GetType() != _CONNECTION)
			{
				AND2* pa2 = dynamic_cast<AND2*> (mdeletedcomp);
				if (pa2 != NULL)
				{
					Ginfo = mdeletedcomp->GetGInfo();
					pa2 = new AND2(Ginfo, default_FANOUT);
					pManager->AddToComp2(pa2);
					pManager->DeleteComponent(k);    //delete selected component(s) or connection(s)
					noOfDletedComp++;
					k--;  //loop again to check the index before
					//pManager->Undo();
					continue;
				}

				AND3* pa3 = dynamic_cast<AND3*> (mdeletedcomp);
				if (pa3 != NULL)
				{
					Ginfo = mdeletedcomp->GetGInfo();
					pa3 = new AND3(Ginfo, default_FANOUT);
					pManager->AddToComp2(pa3);
					pManager->DeleteComponent(k);    //delete selected component(s) or connection(s)
					noOfDletedComp++;
					k--;  //loop again to check the index before
					//pManager->Undo();
					continue;
				}

				NAND2* pna2 = dynamic_cast<NAND2*> (mdeletedcomp);
				if (pna2 != NULL)
				{
					Ginfo = mdeletedcomp->GetGInfo();
					pna2 = new NAND2(Ginfo, default_FANOUT);
					pManager->AddToComp2(pna2);
					pManager->DeleteComponent(k);    //delete selected component(s) or connection(s)
					noOfDletedComp++;
					k--;  //loop again to check the index before
					continue;
				}

				OR2* po2 = dynamic_cast<OR2*> (mdeletedcomp);
				if (po2 != NULL)
				{
					Ginfo = mdeletedcomp->GetGInfo();
					po2 = new OR2(Ginfo, default_FANOUT);
					pManager->AddToComp2(po2);
					pManager->DeleteComponent(k);    //delete selected component(s) or connection(s)
					noOfDletedComp++;
					k--;  //loop again to check the index before
					continue;
				}

				XNOR2* pxn2 = dynamic_cast<XNOR2*> (mdeletedcomp);
				if (pxn2 != NULL)
				{
					Ginfo = mdeletedcomp->GetGInfo();
					pxn2 = new XNOR2(Ginfo, default_FANOUT);
					pManager->AddToComp2(pxn2);
					pManager->DeleteComponent(k);    //delete selected component(s) or connection(s)
					noOfDletedComp++;
					k--;  //loop again to check the index before
					continue;
				}

				NOR2* pn2 = dynamic_cast<NOR2*> (mdeletedcomp);
				if (pn2 != NULL)
				{
					Ginfo = mdeletedcomp->GetGInfo(); // bgeb el Graphics info bta3ha w ba3ml mnha nos5a w ashtghl 3l noskha de baa
					pn2 = new NOR2(Ginfo, default_FANOUT);
					pManager->AddToComp2(pn2);
					pManager->DeleteComponent(k);    //delete selected component(s) or connection(s)
					noOfDletedComp++;
					k--;  //loop again to check the index before
					continue;
				}


				NOR3* pn3 = dynamic_cast<NOR3*> (mdeletedcomp);
				if (pn3 != NULL)
				{
					Ginfo = mdeletedcomp->GetGInfo();
					pn3 = new NOR3(Ginfo, default_FANOUT);
					pManager->AddToComp2(pn3);
					pManager->DeleteComponent(k);    //delete selected component(s) or connection(s)
					noOfDletedComp++;
					k--;  //loop again to check the index before
					continue;
				}


				XOR2* pxo2 = dynamic_cast<XOR2*> (mdeletedcomp);
				if (pxo2 != NULL)
				{
					Ginfo = mdeletedcomp->GetGInfo();
					pxo2 = new XOR2(Ginfo, default_FANOUT);
					pManager->AddToComp2(pxo2);
					pManager->DeleteComponent(k);    //delete selected component(s) or connection(s)
					noOfDletedComp++;
					k--;  //loop again to check the index before
					continue;
				}


				XOR3* pxo3 = dynamic_cast<XOR3*> (mdeletedcomp);
				if (pxo3 != NULL)
				{
					Ginfo = mdeletedcomp->GetGInfo();
					pxo3 = new XOR3(Ginfo, default_FANOUT);
					pManager->AddToComp2(pxo3);
					pManager->DeleteComponent(k);    //delete selected component(s) or connection(s)
					noOfDletedComp++;
					k--;  //loop again to check the index before
					continue;
				}


				BUFF* pb = dynamic_cast<BUFF*> (mdeletedcomp);
				if (pb != NULL)
				{
					Ginfo = mdeletedcomp->GetGInfo();
					pb = new BUFF(Ginfo, default_FANOUT);
					pManager->AddToComp2(pb);
					pManager->DeleteComponent(k);    //delete selected component(s) or connection(s)
					noOfDletedComp++;
					k--;  //loop again to check the index before
					continue;
				}
				INV* pINV = dynamic_cast<INV*> (mdeletedcomp);
				if (pINV != NULL)
				{
					Ginfo = mdeletedcomp->GetGInfo();
					pINV = new INV(Ginfo, default_FANOUT);
					pManager->AddToComp2(pINV);
					pManager->DeleteComponent(k);    //delete selected component(s) or connection(s)
					noOfDletedComp++;
					k--;  //loop again to check the index before
					continue;
				}


				LED* pL2 = dynamic_cast<LED*> (mdeletedcomp);
				if (pL2 != NULL)
				{
					Ginfo = mdeletedcomp->GetGInfo();
					pL2 = new LED(Ginfo, default_FANOUT);
					pManager->AddToComp2(pL2);
					pManager->DeleteComponent(k);    //delete selected component(s) or connection(s)
					noOfDletedComp++;
					k--;  //loop again to check the index before
					continue;
				}


				SWITCH* ps = dynamic_cast<SWITCH*> (mdeletedcomp);
				if (ps != NULL)
				{
					Ginfo = mdeletedcomp->GetGInfo();
					ps = new SWITCH(Ginfo, default_FANOUT);
					pManager->AddToComp2(ps);
					pManager->DeleteComponent(k);    //delete selected component(s) or connection(s)
					noOfDletedComp++;
					k--;  //loop again to check the index before
					continue;
				}
			}
			pManager->DeleteComponent(k);    //delete selected component(s) or connection(s)
			k--;  //loop again to check the index before
		}

	}


	pOut->PrintMsg("Deleted");
	return true;    //the component(s) is seccessifully Deleted :D

}

void DELETE_selected::Undo()
{
	//TODO
	int index = pManager->GetCompcount2() - 1;
	for (int i = 0; i < noOfDletedComp; i++)
	{

		mdeletedcomp = pManager->GetComp2(index - i);

		AND2* pa2 = dynamic_cast<AND2*> (mdeletedcomp);
		if (pa2 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pa2 = new AND2(Ginfo, default_FANOUT);
			pManager->AddComponent(pa2);
			pManager->RemoveFromComp2(index - i);
			//pManager->Undo();
			continue;
		}

		AND3* pa3 = dynamic_cast<AND3*> (mdeletedcomp);
		if (pa3 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pa3 = new AND3(Ginfo, default_FANOUT);
			pManager->AddComponent(pa3);
			pManager->RemoveFromComp2(index - i);
			//pManager->Undo();
			continue;
		}

		NAND2* pna2 = dynamic_cast<NAND2*> (mdeletedcomp);
		if (pna2 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pna2 = new NAND2(Ginfo, default_FANOUT);
			pManager->AddComponent(pna2);
			pManager->RemoveFromComp2(index - i);
			continue;
		}

		OR2* po2 = dynamic_cast<OR2*> (mdeletedcomp);
		if (po2 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			po2 = new OR2(Ginfo, default_FANOUT);
			pManager->AddComponent(po2);
			pManager->RemoveFromComp2(index - i);
			continue;
		}

		XNOR2* pxn2 = dynamic_cast<XNOR2*> (mdeletedcomp);
		if (pxn2 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pxn2 = new XNOR2(Ginfo, default_FANOUT);
			pManager->AddComponent(pxn2);
			pManager->RemoveFromComp2(index - i);
			continue;
		}

		NOR2* pn2 = dynamic_cast<NOR2*> (mdeletedcomp);
		if (pn2 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo(); // bgeb el Graphics info bta3ha w ba3ml mnha nos5a w ashtghl 3l noskha de baa
			pn2 = new NOR2(Ginfo, default_FANOUT);
			pManager->AddComponent(pn2);
			pManager->RemoveFromComp2(index - i);
			continue;
		}


		NOR3* pn3 = dynamic_cast<NOR3*> (mdeletedcomp);
		if (pn3 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pn3 = new NOR3(Ginfo, default_FANOUT);
			pManager->AddComponent(pn3);
			pManager->RemoveFromComp2(index - i);
			continue;
		}


		XOR2* pxo2 = dynamic_cast<XOR2*> (mdeletedcomp);
		if (pxo2 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pxo2 = new XOR2(Ginfo, default_FANOUT);
			pManager->AddComponent(pxo2);
			pManager->RemoveFromComp2(index - i);
			continue;
		}


		XOR3* pxo3 = dynamic_cast<XOR3*> (mdeletedcomp);
		if (pxo3 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pxo3 = new XOR3(Ginfo, default_FANOUT);
			pManager->AddComponent(pxo3);
			pManager->RemoveFromComp2(index - i);
			continue;
		}


		BUFF* pb = dynamic_cast<BUFF*> (mdeletedcomp);
		if (pb != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pb = new BUFF(Ginfo, default_FANOUT);
			pManager->AddComponent(pb);
			pManager->RemoveFromComp2(index - i);
			continue;
		}
		INV* pINV = dynamic_cast<INV*> (mdeletedcomp);
		if (pINV != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pINV = new INV(Ginfo, default_FANOUT);
			pManager->AddComponent(pINV);
			pManager->RemoveFromComp2(index - i);
			continue;
		}


		LED* pL2 = dynamic_cast<LED*> (mdeletedcomp);
		if (pL2 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pL2 = new LED(Ginfo, default_FANOUT);
			pManager->AddComponent(pL2);
			pManager->RemoveFromComp2(index - i);
			continue;
		}


		SWITCH* ps = dynamic_cast<SWITCH*> (mdeletedcomp);
		if (ps != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			ps = new SWITCH(Ginfo, default_FANOUT);
			pManager->AddComponent(ps);
			pManager->RemoveFromComp2(index - i);
			continue;
		}
	}
}


void DELETE_selected::Redo()
{
	//TODO
	int index = pManager->GetCompCount() - 1;
	for (int i = 0; i < noOfDletedComp; i++)
	{

		mdeletedcomp = pManager->GetCmp(index - i);

		AND2* pa2 = dynamic_cast<AND2*> (mdeletedcomp);
		if (pa2 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pa2 = new AND2(Ginfo, default_FANOUT);
			pManager->AddToComp2(pa2);
			pManager->DeleteComponent(index - i);
			//pManager->Undo();
			continue;
		}

		AND3* pa3 = dynamic_cast<AND3*> (mdeletedcomp);
		if (pa3 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pa3 = new AND3(Ginfo, default_FANOUT);
			pManager->AddToComp2(pa3);
			pManager->DeleteComponent(index - i);
			//pManager->Undo();
			continue;
		}

		NAND2* pna2 = dynamic_cast<NAND2*> (mdeletedcomp);
		if (pna2 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pna2 = new NAND2(Ginfo, default_FANOUT);
			pManager->AddToComp2(pna2);
			pManager->DeleteComponent(index - i);
			continue;
		}

		OR2* po2 = dynamic_cast<OR2*> (mdeletedcomp);
		if (po2 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			po2 = new OR2(Ginfo, default_FANOUT);
			pManager->AddToComp2(po2);
			pManager->DeleteComponent(index - i);
			continue;
		}

		XNOR2* pxn2 = dynamic_cast<XNOR2*> (mdeletedcomp);
		if (pxn2 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pxn2 = new XNOR2(Ginfo, default_FANOUT);
			pManager->AddToComp2(pxn2);
			pManager->DeleteComponent(index - i);
			continue;
		}

		NOR2* pn2 = dynamic_cast<NOR2*> (mdeletedcomp);
		if (pn2 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo(); // bgeb el Graphics info bta3ha w ba3ml mnha nos5a w ashtghl 3l noskha de baa
			pn2 = new NOR2(Ginfo, default_FANOUT);
			pManager->AddToComp2(pn2);
			pManager->DeleteComponent(index - i);
			continue;
		}


		NOR3* pn3 = dynamic_cast<NOR3*> (mdeletedcomp);
		if (pn3 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pn3 = new NOR3(Ginfo, default_FANOUT);
			pManager->AddToComp2(pn3);
			pManager->DeleteComponent(index - i);
			continue;
		}


		XOR2* pxo2 = dynamic_cast<XOR2*> (mdeletedcomp);
		if (pxo2 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pxo2 = new XOR2(Ginfo, default_FANOUT);
			pManager->AddToComp2(pxo2);
			pManager->DeleteComponent(index - i);
			continue;
		}


		XOR3* pxo3 = dynamic_cast<XOR3*> (mdeletedcomp);
		if (pxo3 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pxo3 = new XOR3(Ginfo, default_FANOUT);
			pManager->AddToComp2(pxo3);
			pManager->DeleteComponent(index - i);
			continue;
		}


		BUFF* pb = dynamic_cast<BUFF*> (mdeletedcomp);
		if (pb != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pb = new BUFF(Ginfo, default_FANOUT);
			pManager->AddToComp2(pb);
			pManager->DeleteComponent(index - i);
			continue;
		}
		INV* pINV = dynamic_cast<INV*> (mdeletedcomp);
		if (pINV != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pINV = new INV(Ginfo, default_FANOUT);
			pManager->AddToComp2(pINV);
			pManager->DeleteComponent(index - i);
			continue;
		}


		LED* pL2 = dynamic_cast<LED*> (mdeletedcomp);
		if (pL2 != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			pL2 = new LED(Ginfo, default_FANOUT);
			pManager->AddToComp2(pL2);
			pManager->DeleteComponent(index - i);
			continue;
		}


		SWITCH* ps = dynamic_cast<SWITCH*> (mdeletedcomp);
		if (ps != NULL)
		{
			Ginfo = mdeletedcomp->GetGInfo();
			ps = new SWITCH(Ginfo, default_FANOUT);
			pManager->AddToComp2(ps);
			pManager->DeleteComponent(index - i);
			continue;
		}
	}





}

DELETE_selected::~DELETE_selected()
{}