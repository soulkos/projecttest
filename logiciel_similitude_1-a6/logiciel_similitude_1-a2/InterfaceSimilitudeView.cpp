// InterfaceSimilitudeView.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "logiciel_similitude_1-a2.h"
#include "logiciel_similitude_1-a2Doc.h"
#include "InterfaceSimilitudeView.h"
#include "DialogRefDejaPresente.h"
#include "DialogAffichageCourbeOriginal.h"

// CInterfaceSimilitudeView

IMPLEMENT_DYNCREATE(CInterfaceSimilitudeView, CFormView)

CInterfaceSimilitudeView::CInterfaceSimilitudeView()
	: CFormView(CInterfaceSimilitudeView::IDD)
	, m_nTypeCalcul(0)
{
	m_nInitCombo = FALSE;

	EnableAutomation();
	
}

CInterfaceSimilitudeView::~CInterfaceSimilitudeView()
{
}

void CInterfaceSimilitudeView::OnFinalRelease()
{
	// Lorsque la dernière référence pour un objet automation est libérée
	// OnFinalRelease est appelé. La classe de base supprime automatiquement
	// l'objet. Un nettoyage supplémentaire est requis pour votre
	// objet avant d'appeler la classe de base.
	
	CFormView::OnFinalRelease();
}

void CInterfaceSimilitudeView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_VariationAlti_RPM);
	DDX_Control(pDX, IDC_EDIT1, m_DebitCible);
	DDX_Control(pDX, IDC_EDIT2, m_PressionCible);
	DDX_Control(pDX, IDC_EDIT3, m_VitesseCible);
	DDX_Control(pDX, IDC_EDIT4, m_AltitudeCible);
	DDX_Control(pDX, IDC_EDIT5, m_AltitudeCible_RPM);
	DDX_Control(pDX, IDC_COMBO2, m_FreqUtili);
	DDX_Control(pDX, IDC_COMBO1, m_RefVentilateur);
	DDX_Control(pDX, IDC_CHECK3, m_VariationAlti_Pts);
	DDX_Control(pDX, IDC_EDIT8, m_AltitudeCible_Pts);
	DDX_Control(pDX, IDC_CHECK2, m_PtsUtili_RPM);
	DDX_Control(pDX, IDC_EDIT6, m_DebitCible_RPM);
	DDX_Control(pDX, IDC_EDIT7, m_PressionCible_RPM);
	DDX_Control(pDX, IDC_COMBO3, m_UniteDebit1);
	DDX_Control(pDX, IDC_COMBO5, m_UniteDebitRPM);
	DDX_Control(pDX, IDC_COMBO4, m_UnitePression1);
	DDX_Control(pDX, IDC_COMBO6, m_UnitePressionRPM);
	DDX_Control(pDX, IDC_COMBO7, m_UniteRPM);
}

BEGIN_MESSAGE_MAP(CInterfaceSimilitudeView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CInterfaceSimilitudeView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CInterfaceSimilitudeView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTONCALCUL, &CInterfaceSimilitudeView::OnBnClickedButtoncalcul)
	ON_BN_CLICKED(IDC_RADIO1, &CInterfaceSimilitudeView::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CInterfaceSimilitudeView::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CInterfaceSimilitudeView::OnBnClickedRadio3)
	ON_CBN_SETFOCUS(IDC_COMBO1, &CInterfaceSimilitudeView::OnCbnSetfocusCombo1)
	ON_BN_CLICKED(IDC_CHECK3, &CInterfaceSimilitudeView::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK2, &CInterfaceSimilitudeView::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK1, &CInterfaceSimilitudeView::OnBnClickedCheck1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CInterfaceSimilitudeView::OnCbnSelchangeCombo1)
	ON_CBN_KILLFOCUS(IDC_COMBO1, &CInterfaceSimilitudeView::OnCbnKillfocusCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CInterfaceSimilitudeView::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON3, &CInterfaceSimilitudeView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CInterfaceSimilitudeView::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CInterfaceSimilitudeView::OnBnClickedButton5)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CInterfaceSimilitudeView, CFormView)
END_DISPATCH_MAP()

// Remarque : Nous avons ajouté une prise en charge pour IID_IInterfaceSimilitudeView afin de prendre en charge les liaisons de type sécurisé
//  à partir de VBA. Cet IID doit correspondre au GUID qui est attaché à 
//  dispinterface dans le fichier .IDL.

// {D23D4262-3148-4E58-8EE5-2D85040B0877}
static const IID IID_IInterfaceSimilitudeView =
{ 0xD23D4262, 0x3148, 0x4E58, { 0x8E, 0xE5, 0x2D, 0x85, 0x4, 0xB, 0x8, 0x77 } };

BEGIN_INTERFACE_MAP(CInterfaceSimilitudeView, CFormView)
	INTERFACE_PART(CInterfaceSimilitudeView, IID_IInterfaceSimilitudeView, Dispatch)
END_INTERFACE_MAP()


// Diagnostics de CInterfaceSimilitudeView

#ifdef _DEBUG
void CInterfaceSimilitudeView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CInterfaceSimilitudeView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// Gestionnaires de messages de CInterfaceSimilitudeView


void CInterfaceSimilitudeView::OnBnClickedButton1() // precedent
{
	// netoyage de la fenetre
	this->m_RefVentilateur.SetCurSel(-1);
	this->m_FreqUtili.SetCurSel(-1);
	this->m_AltitudeCible_Pts.SetReadOnly(TRUE);
	this->m_AltitudeCible_Pts.SetWindowTextW(L"");
	this->m_DebitCible_RPM.SetReadOnly(TRUE);
	this->m_DebitCible_RPM.SetWindowTextW(L"");
	this->m_PressionCible_RPM.SetReadOnly(TRUE);
	this->m_PressionCible_RPM.SetWindowTextW(L"");
	this->m_AltitudeCible_RPM.SetReadOnly(TRUE);
	this->m_AltitudeCible_RPM.SetWindowTextW(L"");
	this->m_AltitudeCible.SetWindowTextW(L"");
	this->m_DebitCible.SetWindowTextW(L"");
	this->m_PressionCible.SetWindowTextW(L"");
	this->m_VitesseCible.SetWindowTextW(L"");
	this->m_VariationAlti_Pts.SetCheck(BST_UNCHECKED);
	this->m_VariationAlti_RPM.SetCheck(BST_UNCHECKED);
	this->m_PtsUtili_RPM.SetCheck(BST_UNCHECKED);

	m_graphComplete = FALSE;

	theApp.SwitchViewPrec();// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void CInterfaceSimilitudeView::OnBnClickedButton2() // Ajout virgule debit cible
{
	CString str;
	this->m_DebitCible.GetWindowTextW(str);
	if( str.Find(L".") == -1)
		str = str + L".";
	this->m_DebitCible.SetWindowTextW(str);// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void CInterfaceSimilitudeView::OnBnClickedButtoncalcul()
{
	// connection au document
	Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument());
	CDialogRefDejaPresente Dlg_dp;
	
	CString temp;
	std::string s;

	int CvDebit = -1;
	int CvPression = -1;
	int CvRPM = -1;


	// recuperation du fichier de mesure
	//CEssais m_CEssais_Temporaire;
	int t = m_RefVentilateur.GetCurSel(); // recupertion de la reference choisi
	if (t != -1)
		if(m_FreqUtili.GetCurSel() != -1)
		{

			pDoc->m_CEssais_Temporaire =  pDoc->m_CBDDEssais_BDDLocal.pCEssais_BDD[t];
			//pDoc->m_CEssais_Temporaire.Copie_Essais_Sauf_CDonnees( pDoc->m_CBDDEssais_BDDLocal.pCEssais_BDD[0]);
			//pDoc->m_CEssais_Temporaire.RecuperationFormatExcel();

			USES_CONVERSION;
			s=W2A(pDoc->m_CEssais_Temporaire.GetCheminFichier());
			pDoc->m_CResltSimi_CalculSimilitude.SetRefProduit(pDoc->m_CEssais_Temporaire.GetRefProduit());

			//pDoc->m_CEssais_Temporaire.Importation_Essai_from_Excel();
		//m_CEssais_Temporaire.SetCheminFichier(pDoc->m_CBDDEssais_BDDLocal.pCEssais_BDD[0].GetCheminFichier());
		//pDoc->m_CBDDEssais_BDDLocal.pCEssais_BDD[0].Importation_Essai_from_Excel();
			//USES_CONVERSION;
		//std::string file =W2A (pDoc->m_CEssais_Temporaire.sz_CheminFichier);

		//pDoc->m_CBDDEssais_BDDLocal.pCEssais_BDD[0].CDonnes_Essai50Hz.CDonnes_Importation_Excel(file,19,2010,1);


		// recuperation de champs saisie sur l'interface
			switch (m_nTypeCalcul) 
			{
				case 0: // utilisation du Pts Cible

					//Recuperation du debit
					m_DebitCible.GetWindowTextW(temp);
					pDoc->m_CResltSimi_CalculSimilitude.SetDebit(_ttof(temp));
					//Recuperation de la pression
					m_PressionCible.GetWindowTextW(temp);
					pDoc->m_CResltSimi_CalculSimilitude.SetPression(_ttof(temp));
					pDoc->m_CResltSimi_CalculSimilitude.SetAltiUtili(134);
					pDoc->m_CResltSimi_CalculSimilitude.SetRPM(0);
					if (m_VariationAlti_Pts.GetCheck() == BST_CHECKED) // si variation d'altitude selectionnné
					{
						m_AltitudeCible_Pts.GetWindowTextW(temp);		//Recuperation de l'altitude
						pDoc->m_CResltSimi_CalculSimilitude.SetAltiUtili(_ttof(temp));
					}
					CvDebit = m_UniteDebit1.GetCurSel();
					CvPression = m_UnitePression1.GetCurSel();
					CvRPM = -1;
					break;

				case 1: // utilisation de la vitesse cible
					//Reucperation de la vitesse
					m_VitesseCible.GetWindowTextW(temp);
					pDoc->m_CResltSimi_CalculSimilitude.SetRPM(_ttof(temp));
					pDoc->m_CResltSimi_CalculSimilitude.SetAltiUtili(134);
					pDoc->m_CResltSimi_CalculSimilitude.SetDebit(0);
					pDoc->m_CResltSimi_CalculSimilitude.SetPression(0);

					if (m_VariationAlti_RPM.GetCheck() == BST_CHECKED) // si variation d'altitude selectionnné
					{
						m_AltitudeCible_RPM.GetWindowTextW(temp); //Recuperation de l'altitude
						pDoc->m_CResltSimi_CalculSimilitude.SetAltiUtili(_ttof(temp));
					}

					if (m_PtsUtili_RPM.GetCheck() == BST_CHECKED) // si point d'utilisation selectionné
					{
					//Recuperation du debit
						m_DebitCible_RPM.GetWindowTextW(temp);
						pDoc->m_CResltSimi_CalculSimilitude.SetDebit(_ttof(temp));
						//Recuperation de la pression
						m_PressionCible_RPM.GetWindowTextW(temp);
						pDoc->m_CResltSimi_CalculSimilitude.SetPression(_ttof(temp));
					}

					CvDebit = m_UniteDebitRPM.GetCurSel();
					CvPression = m_UnitePressionRPM.GetCurSel();
					CvRPM = m_UniteRPM.GetCurSel();
					break;
	
				case 2: // utilisation de l'altitude cible
					//Reucperation de l'altitude
					pDoc->m_CResltSimi_CalculSimilitude.SetDebit(0);
					pDoc->m_CResltSimi_CalculSimilitude.SetPression(0);
					pDoc->m_CResltSimi_CalculSimilitude.SetRPM(0);
					m_AltitudeCible.GetWindowTextW(temp);
					pDoc->m_CResltSimi_CalculSimilitude.SetAltiUtili(_ttof(temp));

					CvDebit = -1;
					CvPression = -1;
					CvRPM = -1;
					break;

				default :
				//Recuperation du debit
					//m_DebitCible.GetWindowTextW(temp);
					pDoc->m_CResltSimi_CalculSimilitude.SetDebit(0);
					//Recuperation de la pression
					//m_PressionCible.GetWindowTextW(temp);
					pDoc->m_CResltSimi_CalculSimilitude.SetPression(0);
					//
					pDoc->m_CResltSimi_CalculSimilitude.SetRPM(0);

					CvDebit = m_UniteDebit1.GetCurSel();
					CvPression = m_UnitePression1.GetCurSel();
					CvRPM = -1;
					break;

			}
			pDoc->m_CResltSimi_CalculSimilitude.SetUniteDebit(CvDebit);
			pDoc->m_CResltSimi_CalculSimilitude.SetUnitePression(CvPression);
			pDoc->m_CResltSimi_CalculSimilitude.SetUniteVitesse(CvRPM);

			// recuperation des données pour le calcul et selection de la frequence
			pDoc->m_CResltSimi_CalculSimilitude.SetFreq(f50Hz);//
			pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[m_FreqUtili.GetCurSel()].m_Mesures.CDonnes_Importation_Excel(s,pDoc->m_CEssais_Temporaire.m_FormatMesure,pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[m_FreqUtili.GetCurSel()].GetNbpts(),pDoc->m_CEssais_Temporaire.GetVersion(),pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[m_FreqUtili.GetCurSel()].GetLigneDebut());
			//pDoc->m_CEssais_Temporaire.CDonnes_Essai50Hz.CDonnes_Importation_Excel(s,pDoc->m_CEssais_Temporaire.m_FormatMesure,pDoc->m_CEssais_Temporaire.GetNbPts50Hz(),pDoc->m_CEssais_Temporaire.GetVersion(),pDoc->m_CEssais_Temporaire.GetDebut50Hz());
			//pDoc->m_CEssais_Temporaire.CDonnes_Essai50Hz.SetNbPts(pDoc->m_CEssais_Temporaire.GetNbPts50Hz());
			pDoc->m_CResltSimi_CalculSimilitude.Recuperation_Donnes_Pour_Calcul(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[m_FreqUtili.GetCurSel()].m_Mesures);
			pDoc->m_CResltSimi_CalculSimilitude.Conversion_des_donnees(CvDebit,CvPression,CvRPM);

			pDoc->m_CResltSimi_CalculSimilitude.SetDescription(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[m_FreqUtili.GetCurSel()].GetDescription());

	
			// selection des procedure de calculs
			switch(m_nTypeCalcul)
			{
				case 0:
					if (m_VariationAlti_Pts.GetCheck() == BST_CHECKED) // si variation d'altitude selectionnné
					{
						pDoc->m_CResltSimi_CalculSimilitude.Calcul_Altitude_RPMcst();
						//pDoc->m_CResltSimi_CalculSimilitude.Calcul_Altitude_RPMvar();
					}
					else
						this->m_AltitudeCible_Pts.SetWindowTextW(L"");


					if(pDoc->m_CResltSimi_CalculSimilitude.GetDebit() == 0)
					{
						pDoc->m_CResltSimi_CalculSimilitude.Calcul_Rapport_Simi_Debit_Nul();
					}
					else
					{
						if(pDoc->m_CResltSimi_CalculSimilitude.GetPression() == 0)
						{
							pDoc->m_CResltSimi_CalculSimilitude.Calcul_Rapport_Simi_Pression_Nulle();
						}
						else
						{
							pDoc->m_CResltSimi_CalculSimilitude.Calcul_Debit_Intersec();
							pDoc->m_CResltSimi_CalculSimilitude.Calcul_Rapport_Simi();
						}
					}
					pDoc->m_CResltSimi_CalculSimilitude.Calcul_Vitesse_Commande();
					pDoc->m_CResltSimi_CalculSimilitude.Calcul_Simi();
				
					// netoyage
					this->m_DebitCible_RPM.SetReadOnly(TRUE);
					this->m_DebitCible_RPM.SetWindowTextW(L"");
					this->m_PressionCible_RPM.SetReadOnly(TRUE);
					this->m_PressionCible_RPM.SetWindowTextW(L"");
					this->m_AltitudeCible_RPM.SetReadOnly(TRUE);
					this->m_AltitudeCible_RPM.SetWindowTextW(L"");
					this->m_AltitudeCible.SetWindowTextW(L"");
					this->m_VitesseCible.SetWindowTextW(L"");
					this->m_VariationAlti_RPM.SetCheck(BST_UNCHECKED);
					this->m_PtsUtili_RPM.SetCheck(BST_UNCHECKED);

					break;
				case 1:
					pDoc->m_CResltSimi_CalculSimilitude.Calcul_Simi_RPM();
					if (m_VariationAlti_RPM.GetCheck() == BST_CHECKED) // si variation d'altitude selectionnné
						pDoc->m_CResltSimi_CalculSimilitude.Calcul_Altitude_RPMcst();
					else
						this->m_AltitudeCible_RPM.SetWindowTextW(L"");

					if (m_PtsUtili_RPM.GetCheck() == BST_CHECKED) // si point d'utilisation selectionné
					{
						if(pDoc->m_CResltSimi_CalculSimilitude.GetDebit() == 0)
						{
							pDoc->m_CResltSimi_CalculSimilitude.Calcul_Rapport_Simi_Debit_Nul();
						}
						else
						{
							if(pDoc->m_CResltSimi_CalculSimilitude.GetPression() == 0)
							{
								pDoc->m_CResltSimi_CalculSimilitude.Calcul_Rapport_Simi_Pression_Nulle();
							}
							else
							{
								pDoc->m_CResltSimi_CalculSimilitude.Calcul_Debit_Intersec();
								pDoc->m_CResltSimi_CalculSimilitude.Calcul_Rapport_Simi();
							}
						}
						pDoc->m_CResltSimi_CalculSimilitude.Calcul_Vitesse_Commande();
						pDoc->m_CResltSimi_CalculSimilitude.Calcul_Simi();
					}
					else
					{
						this->m_DebitCible_RPM.SetWindowTextW(L"");
						this->m_PressionCible_RPM.SetWindowTextW(L"");
					}
					//if ((m_VariationAlti_RPM.GetCheck() == BST_CHECKED)||(m_PtsUtili_RPM.GetCheck() == BST_CHECKED))
						//pDoc->m_CResltSimi_CalculSimilitude.Calcul_Altitude_RPMcst();

			
					this->m_AltitudeCible_Pts.SetWindowTextW(L"");
					this->m_AltitudeCible.SetWindowTextW(L"");
					this->m_DebitCible.SetWindowTextW(L"");
					this->m_PressionCible.SetWindowTextW(L"");
					this->m_VariationAlti_Pts.SetCheck(BST_UNCHECKED);

					break;
				case 2:
					pDoc->m_CResltSimi_CalculSimilitude.Calcul_Altitude_RPMcst();
					//pDoc->m_CResltSimi_CalculSimilitude.Calcul_Altitude_RPMvar();


					this->m_AltitudeCible_Pts.SetReadOnly(TRUE);
					this->m_AltitudeCible_Pts.SetWindowTextW(L"");
					this->m_DebitCible_RPM.SetReadOnly(TRUE);
					this->m_DebitCible_RPM.SetWindowTextW(L"");
					this->m_PressionCible_RPM.SetReadOnly(TRUE);
					this->m_PressionCible_RPM.SetWindowTextW(L"");
					this->m_AltitudeCible_RPM.SetReadOnly(TRUE);
					this->m_AltitudeCible_RPM.SetWindowTextW(L"");
					this->m_DebitCible.SetWindowTextW(L"");
					this->m_PressionCible.SetWindowTextW(L"");
					this->m_VitesseCible.SetWindowTextW(L"");
					this->m_VariationAlti_Pts.SetCheck(BST_UNCHECKED);
					this->m_VariationAlti_RPM.SetCheck(BST_UNCHECKED);
					this->m_PtsUtili_RPM.SetCheck(BST_UNCHECKED);

					break;
				default :
					///pDoc->m_CResltSimi_CalculSimilitude.Calcul_Debit_Intersec();
					//pDoc->m_CResltSimi_CalculSimilitude.Calcul_Rapport_Simi();
					//pDoc->m_CResltSimi_CalculSimilitude.Calcul_Vitesse_Commande();
					//pDoc->m_CResltSimi_CalculSimilitude.Calcul_Simi();
					break;
			}

		// creation du graphique

		pDoc->CreationGraphique();
		// netoyage de la fenetre
		theApp.SwitchViewSimilitude();// DO: lance protocole de calcule et changmeent de vue
		}	
		else
		{
			Dlg_dp.SetString(L"Veuillez sélectionné un bloc de mesure");
			Dlg_dp.DoModal();
		}
	else // do Diag erreur
	{
		Dlg_dp.SetString(L"Veuillez sélectionné une réference");
		Dlg_dp.DoModal();
	}
}


void CInterfaceSimilitudeView::OnBnClickedRadio1()
{
	m_nTypeCalcul = 0;// Calcul par point cible

}

void CInterfaceSimilitudeView::OnBnClickedRadio2()
{
	m_nTypeCalcul = 1;// Calcul par vitesse de commande
}

void CInterfaceSimilitudeView::OnBnClickedRadio3()
{
	m_nTypeCalcul = 2; // Calcul par variation d'altitude
}

void CInterfaceSimilitudeView::InitListRef()
{

	Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument());

		/*char temp[256];
	USES_CONVERSION;
	LPWSTR tmp = A2W(temp);

	GetPrivateProfileString(L"CHEMIN",L"Cle",L"err",tmp,255,L"D:\\Cours ENIVL\\Stage ECOFIT\\Logiciel\\initBDD.ini");
	pDoc->m_CBDDEssais_BDDLocal.SetChemin(CString(tmp));
	GetPrivateProfileString(L"TAILLE",L"Cle",L"err",tmp,255,L"D:\\Cours ENIVL\\Stage ECOFIT\\Logiciel\\initBDD.ini");
	pDoc->m_CBDDEssais_BDDLocal.SetTaille(_wtoi(CString(tmp)));
	pDoc->m_CBDDEssais_BDDLocal.Chargement_BDDfichier_to_BDDlocal();*/

	CString temp2;
	for(int i = 0; i < pDoc->m_CBDDEssais_BDDLocal.GetTaille() ; i++)
	{
		temp2 = pDoc->m_CBDDEssais_BDDLocal.pCEssais_BDD[i].GetRefProduit();
		this->m_RefVentilateur.AddString( temp2 );
		temp2 ="";
	}
}



void CInterfaceSimilitudeView::OnCbnSetfocusCombo1()
{
	if (m_nInitCombo == FALSE)
	{
		this->m_nInitCombo = TRUE;
		this->InitListRef();// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
	}
}


void CInterfaceSimilitudeView::OnBnClickedCheck3() // gestion de l'autorisation d'ecriture 
{
	if (m_VariationAlti_Pts.GetCheck() == BST_CHECKED)
		this->m_AltitudeCible_Pts.SetReadOnly(FALSE);
	else
	{
		this->m_AltitudeCible_Pts.SetReadOnly(TRUE);
		this->m_AltitudeCible_Pts.SetWindowTextW(L"");
	}
		// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void CInterfaceSimilitudeView::OnBnClickedCheck2()	// gestion de l'autorisation d'ecriture
{
	if (this->m_PtsUtili_RPM.GetCheck() == BST_CHECKED )
	{
		this->m_DebitCible_RPM.SetReadOnly(FALSE);
		this->m_PressionCible_RPM.SetReadOnly(FALSE);
	}
	else
	{
		this->m_DebitCible_RPM.SetReadOnly(TRUE);
		this->m_DebitCible_RPM.SetWindowTextW(L"");
		this->m_PressionCible_RPM.SetReadOnly(TRUE);
		this->m_PressionCible_RPM.SetWindowTextW(L"");
	}
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}

void CInterfaceSimilitudeView::OnBnClickedCheck1()	// gestion de l'autorisation d'ecriture
{
		if (m_VariationAlti_RPM.GetCheck() == BST_CHECKED)
		this->m_AltitudeCible_RPM.SetReadOnly(FALSE);
	else
	{
		this->m_AltitudeCible_RPM.SetReadOnly(TRUE);
		this->m_AltitudeCible_RPM.SetWindowTextW(L"");// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
	}
}


void CInterfaceSimilitudeView::OnCbnSelchangeCombo1()
{
	this->m_FreqUtili.ResetContent();

	Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument());
	int selec =this->m_RefVentilateur.GetCurSel();

	CString temp2;
	for(int i = 0; i < pDoc->m_CBDDEssais_BDDLocal.pCEssais_BDD[selec].GetNbBloc(); i++)
	{
		temp2 = pDoc->m_CBDDEssais_BDDLocal.pCEssais_BDD[selec].m_EnsembleBlocMesure[i].GetDescription();
		this->m_FreqUtili.AddString( temp2 );
		temp2 ="";
	}// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void CInterfaceSimilitudeView::OnCbnKillfocusCombo1()
{

}


void CInterfaceSimilitudeView::OnCbnSelchangeCombo2()
{
	CDialogAffichageCourbeOriginal CDiag;
	Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument());
	std::string s;

	if(this->m_RefVentilateur.GetCurSel() != -1)
	{
		if(this->m_FreqUtili.GetCurSel() != -1)
		{

		pDoc->m_CEssais_Temporaire =  pDoc->m_CBDDEssais_BDDLocal.pCEssais_BDD[this->m_RefVentilateur.GetCurSel()];
		//pDoc->m_CEssais_Temporaire.Copie_Essais_Sauf_CDonnees( pDoc->m_CBDDEssais_BDDLocal.pCEssais_BDD[0]);
		//pDoc->m_CEssais_Temporaire.RecuperationFormatExcel();

		USES_CONVERSION;
		s=W2A(pDoc->m_CEssais_Temporaire.GetCheminFichier());

		pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[m_FreqUtili.GetCurSel()].m_Mesures.CDonnes_Importation_Excel(s,pDoc->m_CEssais_Temporaire.m_FormatMesure,pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[m_FreqUtili.GetCurSel()].GetNbpts(),pDoc->m_CEssais_Temporaire.GetVersion(),pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[m_FreqUtili.GetCurSel()].GetLigneDebut());

		pDoc->m_CResltSimi_CalculSimilitude.Recuperation_Donnes_Pour_Calcul(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[m_FreqUtili.GetCurSel()].m_Mesures);

		pDoc->CreationGraphiqueOriginal();

		m_testGraph = pDoc->m_CGraph_AffcourbeinitialeGraph;
		m_graphComplete = pDoc->m_BOOL_graphComplete2;
		ASSERT_VALID(pDoc);
		Invalidate(TRUE);	
		//CDiag.CopieGraph((pDoc->m_CGraph_AffcourbeinitialeGraph),(pDoc->m_BOOL_graphComplete2));
		//CDiag.DoModal();
		}

		// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
	}
}
void CInterfaceSimilitudeView::OnDraw(CDC* pDC)
{
	//Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument());

	// TODO: add draw code for native data here
	
	
	if(m_graphComplete)
	{
		m_testGraph->DrawGraph(pDC,25,35,400,300); //480;380
		UpdateWindow();
	}

}

void CInterfaceSimilitudeView::OnBnClickedButton3()
{
	CString str;
	this->m_PressionCible.GetWindowTextW(str);
	if( str.Find(L".") == -1)
		str = str + L".";
	this->m_PressionCible.SetWindowTextW(str);// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void CInterfaceSimilitudeView::OnBnClickedButton4()
{
	CString str;
	this->m_DebitCible_RPM.GetWindowTextW(str);
	if( str.Find(L".") == -1)
		str = str + L".";
	this->m_DebitCible_RPM.SetWindowTextW(str);

	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void CInterfaceSimilitudeView::OnBnClickedButton5()
{
	CString str;
	this->m_PressionCible_RPM.GetWindowTextW(str);
	if( str.Find(L".") == -1)
		str = str + L".";
	this->m_PressionCible_RPM.SetWindowTextW(str);// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}
