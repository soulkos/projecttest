// SaisieEssaisView.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "logiciel_similitude_1-a2.h"
#include "logiciel_similitude_1-a2Doc.h"
#include "Protocoles_OLEDB_EXCEL.h"
#include "SaisieEssaisView.h"
#include "DialogRefDejaPresente.h"

// CSaisieEssaisView

IMPLEMENT_DYNCREATE(CSaisieEssaisView, CFormView)

CSaisieEssaisView::CSaisieEssaisView()
	: CFormView(CSaisieEssaisView::IDD)
	, m_strCheminFichier(_T(""))
{
	//CoInitializeEx(NULL, COINIT_MULTITHREADED);
	EnableAutomation();

}

CSaisieEssaisView::~CSaisieEssaisView()
{
}

void CSaisieEssaisView::OnFinalRelease()
{
	// Lorsque la dernière référence pour un objet automation est libérée
	// OnFinalRelease est appelé. La classe de base supprime automatiquement
	// l'objet. Un nettoyage supplémentaire est requis pour votre
	// objet avant d'appeler la classe de base.

	CFormView::OnFinalRelease();
}

void CSaisieEssaisView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_CHECK1, m_PilotageVitesse);
	DDX_Control(pDX, IDC_COMBO3, m_VersionFichier);
	DDX_Text(pDX, IDC_EDIT1, m_strCheminFichier);
	DDX_Control(pDX, IDC_EDIT1, m_CheminFichier);
	/*DDX_Control(pDX, IDC_EDIT3, m_Nbpts50hz);
	DDX_Control(pDX, IDC_EDIT5, m_LigneDeb50Hz);
	DDX_Control(pDX, IDC_EDIT6, m_LigneDeb60Hz);
	DDX_Control(pDX, IDC_EDIT4, m_Nbpts60Hz);*/
	DDX_Control(pDX, IDC_EDIT2, m_RefProduit);
	DDX_Control(pDX, IDC_COMBO4, m_TypeMoteur);
	DDX_Control(pDX, IDC_CHECK2, m_BlocMesure1);
	DDX_Control(pDX, IDC_CHECK3, m_BlocMesure2);
	DDX_Control(pDX, IDC_CHECK4, m_BlocMesure3);
	DDX_Control(pDX, IDC_CHECK5, m_BlocMesure4);
	DDX_Control(pDX, IDC_CHECK6, m_BlocMesure5);
	DDX_Control(pDX, IDC_CHECK7, m_BlocMesure6);
	DDX_Control(pDX, IDC_CHECK8, m_BlocMesure7);
	DDX_Control(pDX, IDC_CHECK9, m_BlocMesure8);
	DDX_Control(pDX, IDC_CHECK10, m_BlocMesure9);
	DDX_Control(pDX, IDC_CHECK11, m_BlocMesure10);
	DDX_Control(pDX, IDC_CHECK12, m_BlocMesure11);
	DDX_Control(pDX, IDC_CHECK13, m_BlocMesure12);
	DDX_Control(pDX, IDC_CHECK14, m_BlocMesure13);
	DDX_Control(pDX, IDC_CHECK15, m_BlocMesure14);
	DDX_Control(pDX, IDC_CHECK16, m_BlocMesure15);
	DDX_Control(pDX, IDC_CHECK17, m_BlocMesure16);
}

BEGIN_MESSAGE_MAP(CSaisieEssaisView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON3, &CSaisieEssaisView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CSaisieEssaisView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSaisieEssaisView::OnBnClickedButton2)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CSaisieEssaisView, CFormView)
END_DISPATCH_MAP()

// Remarque : Nous avons ajouté une prise en charge pour IID_ISaisieEssaisView afin de prendre en charge les liaisons de type sécurisé
//  à partir de VBA. Cet IID doit correspondre au GUID qui est attaché à 
//  dispinterface dans le fichier .IDL.

// {8FB47E05-3681-4802-A270-AB91240EF169}
static const IID IID_ISaisieEssaisView =
{ 0x8FB47E05, 0x3681, 0x4802, { 0xA2, 0x70, 0xAB, 0x91, 0x24, 0xE, 0xF1, 0x69 } };

BEGIN_INTERFACE_MAP(CSaisieEssaisView, CFormView)
	INTERFACE_PART(CSaisieEssaisView, IID_ISaisieEssaisView, Dispatch)
END_INTERFACE_MAP()


// Diagnostics de CSaisieEssaisView

#ifdef _DEBUG
void CSaisieEssaisView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSaisieEssaisView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// Gestionnaires de messages de CSaisieEssaisView


void CSaisieEssaisView::OnBnClickedButton3() // Ajout a la base de donnée 
{
	CDialogRefDejaPresente Dlg_dp;
	USES_CONVERSION;
	Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument());
	/*
	float* tab;
	float temp;
	
	
	std::string file =W2A (pDoc->m_CEssais_Temporaire.sz_CheminFichier);

	pDoc->m_CEssais_Temporaire.CDonnes_Essai50Hz.CDonnes_Importation_Excel(file,11,2010,1);
	*/
	/*
	if(ole.connectionExcel(W2A (pDoc->m_CEssais_Temporaire.sz_CheminFichier)))
	{
		std::string sheet = "sheet1$";
		tab= ole.recuperationTableauExcel(sheet,2,2,20);
		sheet = ole.recuperationCelluleExcel(sheet,1,2);
	}*/

	// reset des champs

	//pDoc->m_CBDDEssais_BDDLocal.Sauvegarde_BDDlocal_to_BDDfichier();
	
	CString temp;
	CBlockMesure* Blocs_Temp = new CBlockMesure[16];
	int nbbloc_temp = 0;

	// test si chemin de ficier null
	if(pDoc->m_CEssais_Temporaire.GetCheminFichier() != "") 
	{
		// recuperation de la reference indiqué par l'utilisateur
		this->m_RefProduit.GetWindowTextW(temp); 
		// test si ref nulle
		if(temp != "") 
		{
			//Ajout de la reference produit
			pDoc->m_CEssais_Temporaire.SetRefProduit(temp);

			

					// tout les champs necesaire sont renseigné
					/*this->m_LigneDeb50Hz.GetWindowTextW(temp);
					if(temp != "")
					{
						pDoc->m_CEssais_Temporaire.SetDebut50Hz((_ttoi(temp))-1);

						this->m_LigneDeb60Hz.GetWindowTextW(temp);
						if(temp != "")
						{
							pDoc->m_CEssais_Temporaire.SetDebut60Hz((_ttoi(temp))-1);

							this->m_Nbpts50hz.GetWindowTextW(temp);
							if(temp != "")
							{
								pDoc->m_CEssais_Temporaire.SetNbPts50Hz(_ttoi(temp));

								this->m_Nbpts60Hz.GetWindowTextW(temp);
								if(temp != "")
								{
									pDoc->m_CEssais_Temporaire.SetNbPts60Hz(_ttoi(temp));
									*/
														// ajout de l'essais aux bases de données local et fichier


			//Recuperation des series de mesure
			int j = 0;
			if(this->m_BlocMesure1.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0];
				nbbloc_temp++;
				j++;
			}
			if(this->m_BlocMesure2.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1];
				nbbloc_temp++;
				j++;
			}
			if(this->m_BlocMesure3.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[2];
				nbbloc_temp++;
				j++;
			}
			if(this->m_BlocMesure4.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[3];
				nbbloc_temp++;
				j++;
			}
			if(this->m_BlocMesure5.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[4];
				nbbloc_temp++;
				j++;
			}
			if(this->m_BlocMesure6.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[5];
				nbbloc_temp++;
				j++;
			}
			if(this->m_BlocMesure7.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[6];
				nbbloc_temp++;
				j++;
			}
			if(this->m_BlocMesure8.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[7];
				nbbloc_temp++;
				j++;
			}
			if(this->m_BlocMesure9.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[8];
				nbbloc_temp++;
				j++;
			}
			if(this->m_BlocMesure10.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[9];
				nbbloc_temp++;
				j++;
			}
			if(this->m_BlocMesure11.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[10];
				nbbloc_temp++;
				j++;
			}
			if(this->m_BlocMesure12.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[11];
				nbbloc_temp++;
				j++;
			}
			if(this->m_BlocMesure13.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[12];
				nbbloc_temp++;
				j++;
			}
			if(this->m_BlocMesure14.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[13];
				nbbloc_temp++;
				j++;
			}
			if(this->m_BlocMesure15.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[14];
				nbbloc_temp++;
				j++;
			}
			if(this->m_BlocMesure16.GetCheck())
			{
				Blocs_Temp[j] = pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[15];
				nbbloc_temp++;
				j++;
			}
			// Copie des series choisie
			pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure = new CBlockMesure[nbbloc_temp];
			for(int i = 0; i < nbbloc_temp;i++)
				pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[i] = Blocs_Temp[i];
			pDoc->m_CEssais_Temporaire.SetNbBloc(nbbloc_temp);



									// sauvegarde de l'essais dans les 2 bases de données (local et fichier)
									pDoc->m_CBDDEssais_BDDLocal.Sauvegarde_Essais_to_BDDlocal_and_BDDfichier(pDoc->m_CEssais_Temporaire);

									// Raz de l'essaie temporaire

									pDoc->m_CEssais_Temporaire.RazEssaitmp();

									// remise a zéro des champ de saisi

									this->m_RefProduit.SetWindowTextW(L"");
									this->m_CheminFichier.SetWindowTextW(L"");
									/*this->m_Nbpts50hz.SetWindowTextW(L"");
									this->m_Nbpts60Hz.SetWindowTextW(L"");
									this->m_LigneDeb50Hz.SetWindowTextW(L"");
									this->m_LigneDeb60Hz.SetWindowTextW(L"");*/
									this->m_TypeMoteur.SetCurSel(-1);
									this->m_VersionFichier.SetCurSel(-1);
									
									this->m_BlocMesure1.SetWindowTextW(L"Bloc vide");
									this->m_BlocMesure2.SetWindowTextW(L"Bloc vide");
									this->m_BlocMesure3.SetWindowTextW(L"Bloc vide");
									this->m_BlocMesure4.SetWindowTextW(L"Bloc vide");
									this->m_BlocMesure5.SetWindowTextW(L"Bloc vide");
									this->m_BlocMesure6.SetWindowTextW(L"Bloc vide");
									this->m_BlocMesure7.SetWindowTextW(L"Bloc vide");
									this->m_BlocMesure8.SetWindowTextW(L"Bloc vide");
									this->m_BlocMesure9.SetWindowTextW(L"Bloc vide");
									this->m_BlocMesure10.SetWindowTextW(L"Bloc vide");
									this->m_BlocMesure11.SetWindowTextW(L"Bloc vide");
									this->m_BlocMesure12.SetWindowTextW(L"Bloc vide");
									this->m_BlocMesure13.SetWindowTextW(L"Bloc vide");
									this->m_BlocMesure14.SetWindowTextW(L"Bloc vide");
									this->m_BlocMesure15.SetWindowTextW(L"Bloc vide");
									this->m_BlocMesure16.SetWindowTextW(L"Bloc vide");

									this->m_BlocMesure1.SetCheck(0);
									this->m_BlocMesure2.SetCheck(0);
									this->m_BlocMesure3.SetCheck(0);
									this->m_BlocMesure4.SetCheck(0);
									this->m_BlocMesure5.SetCheck(0);
									this->m_BlocMesure6.SetCheck(0);
									this->m_BlocMesure7.SetCheck(0);
									this->m_BlocMesure8.SetCheck(0);
									this->m_BlocMesure9.SetCheck(0);
									this->m_BlocMesure10.SetCheck(0);
									this->m_BlocMesure11.SetCheck(0);
									this->m_BlocMesure12.SetCheck(0);
									this->m_BlocMesure13.SetCheck(0);
									this->m_BlocMesure14.SetCheck(0);
									this->m_BlocMesure15.SetCheck(0);
									this->m_BlocMesure16.SetCheck(0);

									this->m_BlocMesure1.EnableWindow(1);
									this->m_BlocMesure2.EnableWindow(1);
									this->m_BlocMesure3.EnableWindow(1);
									this->m_BlocMesure4.EnableWindow(1);
									this->m_BlocMesure5.EnableWindow(1);
									this->m_BlocMesure6.EnableWindow(1);
									this->m_BlocMesure7.EnableWindow(1);
									this->m_BlocMesure8.EnableWindow(1);
									this->m_BlocMesure9.EnableWindow(1);
									this->m_BlocMesure10.EnableWindow(1);
									this->m_BlocMesure11.EnableWindow(1);
									this->m_BlocMesure12.EnableWindow(1);
									this->m_BlocMesure13.EnableWindow(1);
									this->m_BlocMesure14.EnableWindow(1);
									this->m_BlocMesure15.EnableWindow(1);
									this->m_BlocMesure16.EnableWindow(1);

									// Mise a jour de l'interface

									this->UpdateWindow();

									//pDoc->m_CEssais_Temporaire.RecuperationFormatExcel();
									// diag ref ajouté
								/*}
								else
								{
									//daig pb nb
									Dlg_dp.SetString(L"Veuillez saisir le nombre de points en 60Hz");
									Dlg_dp.DoModal();
								}
							}
							else
							{
								//daig pb nb
								Dlg_dp.SetString(L"Veuillez saisir le nombre de points en 50Hz");
								Dlg_dp.DoModal();
							}
						}
						else
						{
							//diag pb ligne
							Dlg_dp.SetString(L"Veuillez saisir la premiere ligne des données en 60Hz");
							Dlg_dp.DoModal();
						}
					}
					else
					{
						//diag saisie ligne
						Dlg_dp.SetString(L"Veuillez saisir la premiere ligne des données en 50Hz");
						Dlg_dp.DoModal();
					}


				}*/
		}
		else
		{
			// diag saisie ref
			Dlg_dp.SetString(L"Veuillez saisir une réference");
			Dlg_dp.DoModal();
		}
	}
	else
	{
		//diag saisie chemin
		Dlg_dp.SetString(L"Veuillez saisir un fichier");
		Dlg_dp.DoModal();
	}
	

	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}


void CSaisieEssaisView::OnBnClickedButton1() // Ouverture du fichier excel
{
	//CoInitializeEx(NULL, COINIT_MULTITHREADED);

	CDialogRefDejaPresente Dlg_dp;
	USES_CONVERSION;
	Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument());

	pDoc->m_CEssais_Temporaire.RazEssaitmp();

	//char strFilter[] = {  };
    //CFileDialog FileDlg(TRUE, L"xls", NULL, OFN_ENABLESIZING, L"Worksheet Files 97-2003 (*.xls)|*.xls|Worksheet Files 2007-2010-2012 (*.xlsx)|*.xlsx|Data Files (*.xlsx;*.xls)|*.xlsx; *.xls|");
	//int e;
	CFileDialog FileDlg(TRUE, L"xls", NULL, OFN_ENABLESIZING, L"Worksheet Files 97-2012 (*.xlsx;*.xls)|*.xlsx; *.xls|");
    CString str;
    int nMaxFiles = 1;
    int nBufferSz = nMaxFiles*256 + 1;
    FileDlg.GetOFN().lpstrFile = str.GetBuffer(nBufferSz);
	

	// test de la version de fichier renseigné par l'utilisauteur
			
	if(this->m_VersionFichier.GetCurSel() != -1)
	{
		switch(this->m_VersionFichier.GetCurSel()) // definition de la version de fichier
		{
		case 0:
			pDoc->m_CEssais_Temporaire.SetVersion(2004);
			break;
		case 1:
			pDoc->m_CEssais_Temporaire.SetVersion(2010);
			break;
		default:
			pDoc->m_CEssais_Temporaire.SetVersion(2010);
			break;
		}
				// test si le type de moteur est renseigné
		if(this->m_TypeMoteur.GetCurSel() != -1)
		{
			switch(this->m_TypeMoteur.GetCurSel()) // Definition du type de moteur
			{
			case 0:
				pDoc->m_CEssais_Temporaire.SetTypeMoteur(0);
				break;
			case 1:
				pDoc->m_CEssais_Temporaire.SetTypeMoteur(1);
				break;
			case 2:
				pDoc->m_CEssais_Temporaire.SetTypeMoteur(2);
				break;
			default:
				pDoc->m_CEssais_Temporaire.SetTypeMoteur(0);
				break;
			}
			
			if( FileDlg.DoModal() == IDOK ) // ouverture de l'interface de selection de fichier
			{
				//CoInitialize(0);
				CString FilePath = FileDlg.GetPathName();
				delete FileDlg;
				//CoUninitialize();
				//pDoc->m_FilePathTemp = FilePath;
				//pDoc->ajoutfilepath();

				pDoc->m_CEssais_Temporaire.SetCheminFichier(FilePath); // sauvegarde du chemin de l'essais

				this->m_CheminFichier.SetWindowTextW(FilePath);	//affichage du chemin sur l'interface utilisateur

				//pDoc->m_CEssais_Temporaire.CDonnes_Essai50Hz.SetFreq(f50Hz);
				//this->m_CheminFichier.SetWindowTextW(FilePath);	//affichage du chemin sur l'interface utilisateur


				pDoc->m_CEssais_Temporaire.RecuperationFormatExcel(); //Analyse du fichier pour determiner la disposition des colonnes
				

				pDoc->m_CEssais_Temporaire.AnalyseBlockMesureExcel(); // Recuperation des blocs de mesures contenu dans le fichier 


				// Mise en pages des checkbox
				
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 1)
				{
					//this->m_BlocMesure1;
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.EnableWindow(0);
					this->m_BlocMesure3.EnableWindow(0);
					this->m_BlocMesure4.EnableWindow(0);
					this->m_BlocMesure5.EnableWindow(0);
					this->m_BlocMesure6.EnableWindow(0);
					this->m_BlocMesure7.EnableWindow(0);
					this->m_BlocMesure8.EnableWindow(0);
					this->m_BlocMesure9.EnableWindow(0);
					this->m_BlocMesure10.EnableWindow(0);
					this->m_BlocMesure11.EnableWindow(0);
					this->m_BlocMesure12.EnableWindow(0);
					this->m_BlocMesure13.EnableWindow(0);
					this->m_BlocMesure14.EnableWindow(0);
					this->m_BlocMesure15.EnableWindow(0);
					this->m_BlocMesure16.EnableWindow(0);
				}
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 2)
				{
					
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.SetCheck(1);
					this->m_BlocMesure2.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1].m_szDescription);
					this->m_BlocMesure3.EnableWindow(0);
					this->m_BlocMesure4.EnableWindow(0);
					this->m_BlocMesure5.EnableWindow(0);
					this->m_BlocMesure6.EnableWindow(0);
					this->m_BlocMesure7.EnableWindow(0);
					this->m_BlocMesure8.EnableWindow(0);
					this->m_BlocMesure9.EnableWindow(0);
					this->m_BlocMesure10.EnableWindow(0);
					this->m_BlocMesure11.EnableWindow(0);
					this->m_BlocMesure12.EnableWindow(0);
					this->m_BlocMesure13.EnableWindow(0);
					this->m_BlocMesure14.EnableWindow(0);
					this->m_BlocMesure15.EnableWindow(0);
					this->m_BlocMesure16.EnableWindow(0);
				}
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 3)
				{
					
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.SetCheck(1);
					this->m_BlocMesure2.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1].m_szDescription);
					this->m_BlocMesure3.SetCheck(1);
					this->m_BlocMesure3.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[2].m_szDescription);
					this->m_BlocMesure4.EnableWindow(0);
					this->m_BlocMesure5.EnableWindow(0);
					this->m_BlocMesure6.EnableWindow(0);
					this->m_BlocMesure7.EnableWindow(0);
					this->m_BlocMesure8.EnableWindow(0);
					this->m_BlocMesure9.EnableWindow(0);
					this->m_BlocMesure10.EnableWindow(0);
					this->m_BlocMesure11.EnableWindow(0);
					this->m_BlocMesure12.EnableWindow(0);
					this->m_BlocMesure13.EnableWindow(0);
					this->m_BlocMesure14.EnableWindow(0);
					this->m_BlocMesure15.EnableWindow(0);
					this->m_BlocMesure16.EnableWindow(0);
				}
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 4)
				{
					
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.SetCheck(1);
					this->m_BlocMesure2.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1].m_szDescription);
					this->m_BlocMesure3.SetCheck(1);
					this->m_BlocMesure3.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[2].m_szDescription);
					this->m_BlocMesure4.SetCheck(1);
					this->m_BlocMesure4.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[3].m_szDescription);
					this->m_BlocMesure5.EnableWindow(0);
					this->m_BlocMesure6.EnableWindow(0);
					this->m_BlocMesure7.EnableWindow(0);
					this->m_BlocMesure8.EnableWindow(0);
					this->m_BlocMesure9.EnableWindow(0);
					this->m_BlocMesure10.EnableWindow(0);
					this->m_BlocMesure11.EnableWindow(0);
					this->m_BlocMesure12.EnableWindow(0);
					this->m_BlocMesure13.EnableWindow(0);
					this->m_BlocMesure14.EnableWindow(0);
					this->m_BlocMesure15.EnableWindow(0);
					this->m_BlocMesure16.EnableWindow(0);
				}
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 5)
				{
					
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.SetCheck(1);
					this->m_BlocMesure2.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1].m_szDescription);
					this->m_BlocMesure3.SetCheck(1);
					this->m_BlocMesure3.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[2].m_szDescription);
					this->m_BlocMesure4.SetCheck(1);
					this->m_BlocMesure4.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[3].m_szDescription);
					this->m_BlocMesure5.SetCheck(1);
					this->m_BlocMesure5.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[4].m_szDescription);
					this->m_BlocMesure6.EnableWindow(0);
					this->m_BlocMesure7.EnableWindow(0);
					this->m_BlocMesure8.EnableWindow(0);
					this->m_BlocMesure9.EnableWindow(0);
					this->m_BlocMesure10.EnableWindow(0);
					this->m_BlocMesure11.EnableWindow(0);
					this->m_BlocMesure12.EnableWindow(0);
					this->m_BlocMesure13.EnableWindow(0);
					this->m_BlocMesure14.EnableWindow(0);
					this->m_BlocMesure15.EnableWindow(0);
					this->m_BlocMesure16.EnableWindow(0);
				}
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 6)
				{
					
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.SetCheck(1);
					this->m_BlocMesure2.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1].m_szDescription);
					this->m_BlocMesure3.SetCheck(1);
					this->m_BlocMesure3.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[2].m_szDescription);
					this->m_BlocMesure4.SetCheck(1);
					this->m_BlocMesure4.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[3].m_szDescription);
					this->m_BlocMesure5.SetCheck(1);
					this->m_BlocMesure5.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[4].m_szDescription);
					this->m_BlocMesure6.SetCheck(1);
					this->m_BlocMesure6.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[5].m_szDescription);
					this->m_BlocMesure7.EnableWindow(0);
					this->m_BlocMesure8.EnableWindow(0);
					this->m_BlocMesure9.EnableWindow(0);
					this->m_BlocMesure10.EnableWindow(0);
					this->m_BlocMesure11.EnableWindow(0);
					this->m_BlocMesure12.EnableWindow(0);
					this->m_BlocMesure13.EnableWindow(0);
					this->m_BlocMesure14.EnableWindow(0);
					this->m_BlocMesure15.EnableWindow(0);
					this->m_BlocMesure16.EnableWindow(0);
				}
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 7)
				{
					
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.SetCheck(1);
					this->m_BlocMesure2.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1].m_szDescription);
					this->m_BlocMesure3.SetCheck(1);
					this->m_BlocMesure3.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[2].m_szDescription);
					this->m_BlocMesure4.SetCheck(1);
					this->m_BlocMesure4.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[3].m_szDescription);
					this->m_BlocMesure5.SetCheck(1);
					this->m_BlocMesure5.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[4].m_szDescription);
					this->m_BlocMesure6.SetCheck(1);
					this->m_BlocMesure6.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[5].m_szDescription);
					this->m_BlocMesure7.SetCheck(1);
					this->m_BlocMesure7.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[6].m_szDescription);
					this->m_BlocMesure8.EnableWindow(0);
					this->m_BlocMesure9.EnableWindow(0);
					this->m_BlocMesure10.EnableWindow(0);
					this->m_BlocMesure11.EnableWindow(0);
					this->m_BlocMesure12.EnableWindow(0);
					this->m_BlocMesure13.EnableWindow(0);
					this->m_BlocMesure14.EnableWindow(0);
					this->m_BlocMesure15.EnableWindow(0);
					this->m_BlocMesure16.EnableWindow(0);
				}
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 8)
				{
					
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.SetCheck(1);
					this->m_BlocMesure2.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1].m_szDescription);
					this->m_BlocMesure3.SetCheck(1);
					this->m_BlocMesure3.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[2].m_szDescription);
					this->m_BlocMesure4.SetCheck(1);
					this->m_BlocMesure4.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[3].m_szDescription);
					this->m_BlocMesure5.SetCheck(1);
					this->m_BlocMesure5.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[4].m_szDescription);
					this->m_BlocMesure6.SetCheck(1);
					this->m_BlocMesure6.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[5].m_szDescription);
					this->m_BlocMesure7.SetCheck(1);
					this->m_BlocMesure7.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[6].m_szDescription);
					this->m_BlocMesure8.SetCheck(1);
					this->m_BlocMesure8.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[7].m_szDescription);
					this->m_BlocMesure9.EnableWindow(0);
					this->m_BlocMesure10.EnableWindow(0);
					this->m_BlocMesure11.EnableWindow(0);
					this->m_BlocMesure12.EnableWindow(0);
					this->m_BlocMesure13.EnableWindow(0);
					this->m_BlocMesure14.EnableWindow(0);
					this->m_BlocMesure15.EnableWindow(0);
					this->m_BlocMesure16.EnableWindow(0);
				}
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 9)
				{
					
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.SetCheck(1);
					this->m_BlocMesure2.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1].m_szDescription);
					this->m_BlocMesure3.SetCheck(1);
					this->m_BlocMesure3.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[2].m_szDescription);
					this->m_BlocMesure4.SetCheck(1);
					this->m_BlocMesure4.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[3].m_szDescription);
					this->m_BlocMesure5.SetCheck(1);
					this->m_BlocMesure5.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[4].m_szDescription);
					this->m_BlocMesure6.SetCheck(1);
					this->m_BlocMesure6.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[5].m_szDescription);
					this->m_BlocMesure7.SetCheck(1);
					this->m_BlocMesure7.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[6].m_szDescription);
					this->m_BlocMesure8.SetCheck(1);
					this->m_BlocMesure8.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[7].m_szDescription);
					this->m_BlocMesure9.SetCheck(1);
					this->m_BlocMesure9.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[8].m_szDescription);
					this->m_BlocMesure10.EnableWindow(0);
					this->m_BlocMesure11.EnableWindow(0);
					this->m_BlocMesure12.EnableWindow(0);
					this->m_BlocMesure13.EnableWindow(0);
					this->m_BlocMesure14.EnableWindow(0);
					this->m_BlocMesure15.EnableWindow(0);
					this->m_BlocMesure16.EnableWindow(0);
				}
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 10)
				{
					
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.SetCheck(1);
					this->m_BlocMesure2.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1].m_szDescription);
					this->m_BlocMesure3.SetCheck(1);
					this->m_BlocMesure3.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[2].m_szDescription);
					this->m_BlocMesure4.SetCheck(1);
					this->m_BlocMesure4.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[3].m_szDescription);
					this->m_BlocMesure5.SetCheck(1);
					this->m_BlocMesure5.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[4].m_szDescription);
					this->m_BlocMesure6.SetCheck(1);
					this->m_BlocMesure6.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[5].m_szDescription);
					this->m_BlocMesure7.SetCheck(1);
					this->m_BlocMesure7.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[6].m_szDescription);
					this->m_BlocMesure8.SetCheck(1);
					this->m_BlocMesure8.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[7].m_szDescription);
					this->m_BlocMesure9.SetCheck(1);
					this->m_BlocMesure9.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure10.SetCheck(1);
					this->m_BlocMesure10.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[9].m_szDescription);
					this->m_BlocMesure11.EnableWindow(0);
					this->m_BlocMesure12.EnableWindow(0);
					this->m_BlocMesure13.EnableWindow(0);
					this->m_BlocMesure14.EnableWindow(0);
					this->m_BlocMesure15.EnableWindow(0);
					this->m_BlocMesure16.EnableWindow(0);
				}
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 11)
				{
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.SetCheck(1);
					this->m_BlocMesure2.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1].m_szDescription);
					this->m_BlocMesure3.SetCheck(1);
					this->m_BlocMesure3.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[2].m_szDescription);
					this->m_BlocMesure4.SetCheck(1);
					this->m_BlocMesure4.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[3].m_szDescription);
					this->m_BlocMesure5.SetCheck(1);
					this->m_BlocMesure5.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[4].m_szDescription);
					this->m_BlocMesure6.SetCheck(1);
					this->m_BlocMesure6.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[5].m_szDescription);
					this->m_BlocMesure7.SetCheck(1);
					this->m_BlocMesure7.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[6].m_szDescription);
					this->m_BlocMesure8.SetCheck(1);
					this->m_BlocMesure8.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[7].m_szDescription);
					this->m_BlocMesure9.SetCheck(1);
					this->m_BlocMesure9.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[8].m_szDescription);
					this->m_BlocMesure10.SetCheck(1);
					this->m_BlocMesure10.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[9].m_szDescription);
					this->m_BlocMesure11.SetCheck(1);
					this->m_BlocMesure11.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[10].m_szDescription);
					this->m_BlocMesure12.EnableWindow(0);
					this->m_BlocMesure13.EnableWindow(0);
					this->m_BlocMesure14.EnableWindow(0);
					this->m_BlocMesure15.EnableWindow(0);
					this->m_BlocMesure16.EnableWindow(0);
				}
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 12)
				{
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.SetCheck(1);
					this->m_BlocMesure2.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1].m_szDescription);
					this->m_BlocMesure3.SetCheck(1);
					this->m_BlocMesure3.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[2].m_szDescription);
					this->m_BlocMesure4.SetCheck(1);
					this->m_BlocMesure4.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[3].m_szDescription);
					this->m_BlocMesure5.SetCheck(1);
					this->m_BlocMesure5.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[4].m_szDescription);
					this->m_BlocMesure6.SetCheck(1);
					this->m_BlocMesure6.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[5].m_szDescription);
					this->m_BlocMesure7.SetCheck(1);
					this->m_BlocMesure7.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[6].m_szDescription);
					this->m_BlocMesure8.SetCheck(1);
					this->m_BlocMesure8.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[7].m_szDescription);
					this->m_BlocMesure9.SetCheck(1);
					this->m_BlocMesure9.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[8].m_szDescription);
					this->m_BlocMesure10.SetCheck(1);
					this->m_BlocMesure10.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[9].m_szDescription);
					this->m_BlocMesure11.SetCheck(1);
					this->m_BlocMesure11.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[10].m_szDescription);
					this->m_BlocMesure12.SetCheck(1);
					this->m_BlocMesure12.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[11].m_szDescription);
					this->m_BlocMesure13.EnableWindow(0);
					this->m_BlocMesure14.EnableWindow(0);
					this->m_BlocMesure15.EnableWindow(0);
					this->m_BlocMesure16.EnableWindow(0);
				}
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 13)
				{
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.SetCheck(1);
					this->m_BlocMesure2.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1].m_szDescription);
					this->m_BlocMesure3.SetCheck(1);
					this->m_BlocMesure3.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[2].m_szDescription);
					this->m_BlocMesure4.SetCheck(1);
					this->m_BlocMesure4.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[3].m_szDescription);
					this->m_BlocMesure5.SetCheck(1);
					this->m_BlocMesure5.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[4].m_szDescription);
					this->m_BlocMesure6.SetCheck(1);
					this->m_BlocMesure6.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[5].m_szDescription);
					this->m_BlocMesure7.SetCheck(1);
					this->m_BlocMesure7.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[6].m_szDescription);
					this->m_BlocMesure8.SetCheck(1);
					this->m_BlocMesure8.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[7].m_szDescription);
					this->m_BlocMesure9.SetCheck(1);
					this->m_BlocMesure9.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[8].m_szDescription);
					this->m_BlocMesure10.SetCheck(1);
					this->m_BlocMesure10.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[9].m_szDescription);
					this->m_BlocMesure11.SetCheck(1);
					this->m_BlocMesure11.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[10].m_szDescription);
					this->m_BlocMesure12.SetCheck(1);
					this->m_BlocMesure12.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[11].m_szDescription);
					this->m_BlocMesure13.SetCheck(1);
					this->m_BlocMesure13.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[12].m_szDescription);
					this->m_BlocMesure14.EnableWindow(0);
					this->m_BlocMesure15.EnableWindow(0);
					this->m_BlocMesure16.EnableWindow(0);
				}
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 14)
				{
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.SetCheck(1);
					this->m_BlocMesure2.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1].m_szDescription);
					this->m_BlocMesure3.SetCheck(1);
					this->m_BlocMesure3.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[2].m_szDescription);
					this->m_BlocMesure4.SetCheck(1);
					this->m_BlocMesure4.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[3].m_szDescription);
					this->m_BlocMesure5.SetCheck(1);
					this->m_BlocMesure5.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[4].m_szDescription);
					this->m_BlocMesure6.SetCheck(1);
					this->m_BlocMesure6.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[5].m_szDescription);
					this->m_BlocMesure7.SetCheck(1);
					this->m_BlocMesure7.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[6].m_szDescription);
					this->m_BlocMesure8.SetCheck(1);
					this->m_BlocMesure8.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[7].m_szDescription);
					this->m_BlocMesure9.SetCheck(1);
					this->m_BlocMesure9.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[8].m_szDescription);
					this->m_BlocMesure10.SetCheck(1);
					this->m_BlocMesure10.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[9].m_szDescription);
					this->m_BlocMesure11.SetCheck(1);
					this->m_BlocMesure11.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[10].m_szDescription);
					this->m_BlocMesure12.SetCheck(1);
					this->m_BlocMesure12.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[11].m_szDescription);
					this->m_BlocMesure13.SetCheck(1);
					this->m_BlocMesure13.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[12].m_szDescription);
					this->m_BlocMesure14.SetCheck(1);
					this->m_BlocMesure14.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[13].m_szDescription);
					this->m_BlocMesure15.EnableWindow(0);
					this->m_BlocMesure16.EnableWindow(0);
				}
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 15)
				{
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.SetCheck(1);
					this->m_BlocMesure2.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1].m_szDescription);
					this->m_BlocMesure3.SetCheck(1);
					this->m_BlocMesure3.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[2].m_szDescription);
					this->m_BlocMesure4.SetCheck(1);
					this->m_BlocMesure4.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[3].m_szDescription);
					this->m_BlocMesure5.SetCheck(1);
					this->m_BlocMesure5.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[4].m_szDescription);
					this->m_BlocMesure6.SetCheck(1);
					this->m_BlocMesure6.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[5].m_szDescription);
					this->m_BlocMesure7.SetCheck(1);
					this->m_BlocMesure7.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[6].m_szDescription);
					this->m_BlocMesure8.SetCheck(1);
					this->m_BlocMesure8.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[7].m_szDescription);
					this->m_BlocMesure9.SetCheck(1);
					this->m_BlocMesure9.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[8].m_szDescription);
					this->m_BlocMesure10.SetCheck(1);
					this->m_BlocMesure10.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[9].m_szDescription);
					this->m_BlocMesure11.SetCheck(1);
					this->m_BlocMesure11.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[10].m_szDescription);
					this->m_BlocMesure12.SetCheck(1);
					this->m_BlocMesure12.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[11].m_szDescription);
					this->m_BlocMesure13.SetCheck(1);
					this->m_BlocMesure13.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[12].m_szDescription);
					this->m_BlocMesure14.SetCheck(1);
					this->m_BlocMesure14.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[13].m_szDescription);
					this->m_BlocMesure15.SetCheck(1);
					this->m_BlocMesure15.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[14].m_szDescription);
					this->m_BlocMesure16.EnableWindow(0);
				}
				if(pDoc->m_CEssais_Temporaire.GetNbBloc() == 16)
				{
					this->m_BlocMesure1.SetCheck(1);
					this->m_BlocMesure1.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[0].m_szDescription);
					this->m_BlocMesure2.SetCheck(1);
					this->m_BlocMesure2.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[1].m_szDescription);
					this->m_BlocMesure3.SetCheck(1);
					this->m_BlocMesure3.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[2].m_szDescription);
					this->m_BlocMesure4.SetCheck(1);
					this->m_BlocMesure4.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[3].m_szDescription);
					this->m_BlocMesure5.SetCheck(1);
					this->m_BlocMesure5.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[4].m_szDescription);
					this->m_BlocMesure6.SetCheck(1);
					this->m_BlocMesure6.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[5].m_szDescription);
					this->m_BlocMesure7.SetCheck(1);
					this->m_BlocMesure7.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[6].m_szDescription);
					this->m_BlocMesure8.SetCheck(1);
					this->m_BlocMesure8.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[7].m_szDescription);
					this->m_BlocMesure9.SetCheck(1);
					this->m_BlocMesure9.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[8].m_szDescription);
					this->m_BlocMesure10.SetCheck(1);
					this->m_BlocMesure10.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[9].m_szDescription);
					this->m_BlocMesure11.SetCheck(1);
					this->m_BlocMesure11.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[10].m_szDescription);
					this->m_BlocMesure12.SetCheck(1);
					this->m_BlocMesure12.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[11].m_szDescription);
					this->m_BlocMesure13.SetCheck(1);
					this->m_BlocMesure13.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[12].m_szDescription);
					this->m_BlocMesure14.SetCheck(1);
					this->m_BlocMesure14.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[13].m_szDescription);
					this->m_BlocMesure15.SetCheck(1);
					this->m_BlocMesure15.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[14].m_szDescription);
					this->m_BlocMesure16.SetCheck(1);
					this->m_BlocMesure16.SetWindowTextW(pDoc->m_CEssais_Temporaire.m_EnsembleBlocMesure[15].m_szDescription);
				}



				this->UpdateWindow();
			}
		}
		else
		{
		// diag saisie type moteur
			Dlg_dp.SetString(L"Veuillez saisir le type de moteur");
			Dlg_dp.DoModal();
		}
	}	
	else
	{
//diag saisie version fichier
		Dlg_dp.SetString(L"Veuillez saisir la version du banc de mesure");
		Dlg_dp.DoModal();
	}
		
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
	//CoUninitialize();
}


void CSaisieEssaisView::OnBnClickedButton2() // Bouton precedent
{
	Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument());

	// RAZ de l'interface 

	//this->m_PilotageVitesse.EnableWindow(0);
	this->m_RefProduit.SetWindowTextW(L"");
	this->m_CheminFichier.SetWindowTextW(L"");
	/*this->m_Nbpts50hz.SetWindowTextW(L"");
	this->m_Nbpts60Hz.SetWindowTextW(L"");
	this->m_LigneDeb50Hz.SetWindowTextW(L"");
	this->m_LigneDeb60Hz.SetWindowTextW(L"");*/
	this->m_TypeMoteur.SetCurSel(-1);
	this->m_VersionFichier.SetCurSel(-1);

	this->m_BlocMesure1.SetWindowTextW(L"Bloc vide");
	this->m_BlocMesure2.SetWindowTextW(L"Bloc vide");
	this->m_BlocMesure3.SetWindowTextW(L"Bloc vide");
	this->m_BlocMesure4.SetWindowTextW(L"Bloc vide");
	this->m_BlocMesure5.SetWindowTextW(L"Bloc vide");
	this->m_BlocMesure6.SetWindowTextW(L"Bloc vide");
	this->m_BlocMesure7.SetWindowTextW(L"Bloc vide");
	this->m_BlocMesure8.SetWindowTextW(L"Bloc vide");
	this->m_BlocMesure9.SetWindowTextW(L"Bloc vide");
	this->m_BlocMesure10.SetWindowTextW(L"Bloc vide");
	this->m_BlocMesure11.SetWindowTextW(L"Bloc vide");
	this->m_BlocMesure12.SetWindowTextW(L"Bloc vide");
	this->m_BlocMesure13.SetWindowTextW(L"Bloc vide");
	this->m_BlocMesure14.SetWindowTextW(L"Bloc vide");
	this->m_BlocMesure15.SetWindowTextW(L"Bloc vide");
	this->m_BlocMesure16.SetWindowTextW(L"Bloc vide");

	this->m_BlocMesure1.SetCheck(0);
	this->m_BlocMesure2.SetCheck(0);
	this->m_BlocMesure3.SetCheck(0);
	this->m_BlocMesure4.SetCheck(0);
	this->m_BlocMesure5.SetCheck(0);
	this->m_BlocMesure6.SetCheck(0);
	this->m_BlocMesure7.SetCheck(0);
	this->m_BlocMesure8.SetCheck(0);
	this->m_BlocMesure9.SetCheck(0);
	this->m_BlocMesure10.SetCheck(0);
	this->m_BlocMesure11.SetCheck(0);
	this->m_BlocMesure12.SetCheck(0);
	this->m_BlocMesure13.SetCheck(0);
	this->m_BlocMesure14.SetCheck(0);
	this->m_BlocMesure15.SetCheck(0);
	this->m_BlocMesure16.SetCheck(0);

	this->m_BlocMesure1.EnableWindow(1);
	this->m_BlocMesure2.EnableWindow(1);
	this->m_BlocMesure3.EnableWindow(1);
	this->m_BlocMesure4.EnableWindow(1);
	this->m_BlocMesure5.EnableWindow(1);
	this->m_BlocMesure6.EnableWindow(1);
	this->m_BlocMesure7.EnableWindow(1);
	this->m_BlocMesure8.EnableWindow(1);
	this->m_BlocMesure9.EnableWindow(1);
	this->m_BlocMesure10.EnableWindow(1);
	this->m_BlocMesure11.EnableWindow(1);
	this->m_BlocMesure12.EnableWindow(1);
	this->m_BlocMesure13.EnableWindow(1);
	this->m_BlocMesure14.EnableWindow(1);
	this->m_BlocMesure15.EnableWindow(1);
	this->m_BlocMesure16.EnableWindow(1);

	// RAZ de l'essais temporaire
	pDoc->m_CEssais_Temporaire.RazEssaitmp();

	// chagement de vue

	theApp.SwitchViewPrec();// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}
