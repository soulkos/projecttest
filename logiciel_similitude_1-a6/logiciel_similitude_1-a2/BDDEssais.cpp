#include "StdAfx.h"
#include "BDDEssais.h"
#include "DialogModifBDD.h"
#include "DialogRefDejaPresente.h"


CBDDEssais::CBDDEssais(void)
{
	this->n_taille = 0;
	this->pCEssais_BDD =NULL;
}


CBDDEssais::~CBDDEssais(void)
{
	//delete this->pCEssais_BDD;
}


void CBDDEssais::SetTaille(const int taille)
{
	this->n_taille = taille;
}
int CBDDEssais::GetTaille()
{
	return this->n_taille;
}

void CBDDEssais::SetChemin(const CString sz)
{
	this->sz_CheminBDD = sz;
}
CString CBDDEssais::GetChemin()
{
	return this->sz_CheminBDD;
}

void CBDDEssais::Chargement_BDDfichier_to_BDDlocal()
{
	CEssais EssaisTemp;
	CString temp;
	USES_CONVERSION;
	//connexion à la base de données physique (fichier Excel)
	/*this->COLEDBExcel_Instance.connectionExcel(T2A(this->GetChemin()));
	this->COLEDBExcel_Instance.ecritureCelluleExcel("test","Sheet1$",2);
	this->COLEDBExcel_Instance.session.Close();
	this->COLEDBExcel_Instance.dataSource.Close();
	CoUninitialize();*/

	this->COLEDBExcel_Instance.connectionExcel(T2A(this->GetChemin()));
	// connection a la feuille
	this->COLEDBExcel_Instance.connectionTable();
	if(!SUCCEEDED(this->COLEDBExcel_Instance.GetHR()))
	{
		this->COLEDBExcel_Instance.session.Close();
		this->COLEDBExcel_Instance.dataSource.Close();
		CoUninitialize();
	}

	// initialisation
	CEssais * pCEssais_BDD_temp;
	pCEssais_BDD_temp = new CEssais[this->n_taille];
	//pCEssais_BDD_temp(this->n_taille);
	//CEssais * pCEssais_BDD_temp =  (CEssais*)malloc(sizeof(CEssais)*this->n_taille);
	//this->pCEssais_BDD = (CEssais*)malloc(sizeof(CEssais)*this->n_taille);
	int i=0;

	// recuperation du tableau
	for(this->COLEDBExcel_Instance.SetHR(this->COLEDBExcel_Instance.table.MoveFirst( )); (i <(this->n_taille) && SUCCEEDED(this->COLEDBExcel_Instance.GetHR()));this->COLEDBExcel_Instance.SetHR(this->COLEDBExcel_Instance.table.MoveNext()))
	{
		temp = this->COLEDBExcel_Instance.GetString(2);
		EssaisTemp.SetRefProduit(temp);
		temp = "";
		temp = this->COLEDBExcel_Instance.GetString(3);
		EssaisTemp.SetCheminFichier(temp);
		temp = "";
		temp = this->COLEDBExcel_Instance.GetString(4);
		EssaisTemp.SetVersion(_wtoi(temp));
		temp = "";

		temp = this->COLEDBExcel_Instance.GetString(5);
		EssaisTemp.m_FormatMesure.SetColTension(_wtoi(temp));
		temp = "";
		temp = this->COLEDBExcel_Instance.GetString(6);
		EssaisTemp.m_FormatMesure.SetColFreq(_wtoi(temp));
		temp = "";
		temp = this->COLEDBExcel_Instance.GetString(7);
		EssaisTemp.m_FormatMesure.SetColCapaCmd(_wtoi(temp));
		temp = "";
		temp = this->COLEDBExcel_Instance.GetString(8);
		EssaisTemp.m_FormatMesure.SetColTemperature(_wtoi(temp));
		temp = "";
		temp = this->COLEDBExcel_Instance.GetString(9);
		EssaisTemp.m_FormatMesure.SetColDebit(_wtoi(temp));
		temp = "";
		temp = this->COLEDBExcel_Instance.GetString(10);
		EssaisTemp.m_FormatMesure.SetColPression(_wtoi(temp));
		temp = "";
		temp = this->COLEDBExcel_Instance.GetString(11);
		EssaisTemp.m_FormatMesure.SetColPuissance(_wtoi(temp));
		temp = "";
		temp = this->COLEDBExcel_Instance.GetString(12);
		EssaisTemp.m_FormatMesure.SetColVitesse(_wtoi(temp));
		temp = "";

		temp = this->COLEDBExcel_Instance.GetString(13);
		EssaisTemp.SetTypeMoteur(_wtoi(temp));
		temp = "";
		temp = this->COLEDBExcel_Instance.GetString(14);
		EssaisTemp.SetNbBloc(_wtoi(temp));
		temp = "";
		for(int j = 0;j< EssaisTemp.GetNbBloc();j++)
		{
			temp = this->COLEDBExcel_Instance.GetString(15+j*3);
			EssaisTemp.m_EnsembleBlocMesure[j].SetDescription(temp);
			temp = "";
			temp = this->COLEDBExcel_Instance.GetString(16+j*3);
			EssaisTemp.m_EnsembleBlocMesure[j].SetLigneDebut(_wtoi(temp));
			temp = "";
			temp = this->COLEDBExcel_Instance.GetString(17+j*3);
			EssaisTemp.m_EnsembleBlocMesure[j].SetNbpts(_wtoi(temp));
		}

		/*temp = this->COLEDBExcel_Instance.GetString(7);
		EssaisTemp.SetDebut50Hz(_wtoi(temp));
		temp.Empty();
		temp = this->COLEDBExcel_Instance.GetString(8);
		EssaisTemp.SetNbPts60Hz(_wtoi(temp));
		temp.Empty();
		temp = this->COLEDBExcel_Instance.GetString(9);
		EssaisTemp.SetDebut60Hz(_wtoi(temp));*/
		//tab_temp[i]=_wtof(table.GetString(colonne));

		pCEssais_BDD_temp[i] = EssaisTemp ;

		i++;
	}
	this->pCEssais_BDD = pCEssais_BDD_temp;

	this->COLEDBExcel_Instance.table.Close();
	this->COLEDBExcel_Instance.session.Close();
	this->COLEDBExcel_Instance.dataSource.Close();
	CoUninitialize();
}

void CBDDEssais::Sauvegarde_BDDlocal_to_BDDfichier()
{
	USES_CONVERSION;
	// Commonly used OLE variants.
	COleVariant
      covTrue((short)TRUE),
      covFalse((short)FALSE),
	  xlLocalSessionChanges((short) 2),
      covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	
	CApplication app;
	app =InitApplication();

	CWorkbook book;
	book =OuvertureBook( app , this->GetChemin() );

	//Creation de la premieres feuille
	CWorksheets sheets;
	CWorksheet sheet;

	sheets =book.get_Sheets();
	sheet = sheets.get_Item(COleVariant((short)1));
	//CreationEntete(book);

	//sauvegarde
	char str[6];
	char temp[255];
	std::string cellule,cellule1,cellule2,tmp;

	cellule = "B";
	std::sprintf(str,"%d",this->GetTaille() + 2);
	cellule.insert(1,str);
	RemplissageCellule(sheet,W2A(this->pCEssais_BDD[this->GetTaille()].GetRefProduit().GetString()), cellule);

	cellule = "C";
	//std::sprintf(str,"%d",this->GetTaille() + 2);
	cellule.insert(1,str);
	RemplissageCellule(sheet,W2A(this->pCEssais_BDD[this->GetTaille()].GetCheminFichier().GetString()), cellule);

	cellule = "D";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",this->pCEssais_BDD[this->GetTaille()].GetVersion());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "E";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",this->pCEssais_BDD[this->GetTaille()].m_FormatMesure.GetColTension());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "F";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",this->pCEssais_BDD[this->GetTaille()].m_FormatMesure.GetColFreq());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "G";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",this->pCEssais_BDD[this->GetTaille()].m_FormatMesure.GetColCapaCmd());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "H";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",this->pCEssais_BDD[this->GetTaille()].m_FormatMesure.GetColTemperature());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "I";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",this->pCEssais_BDD[this->GetTaille()].m_FormatMesure.GetColDebit());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "J";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",this->pCEssais_BDD[this->GetTaille()].m_FormatMesure.GetColPression());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "K";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",this->pCEssais_BDD[this->GetTaille()].m_FormatMesure.GetColPuissance());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "L";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",this->pCEssais_BDD[this->GetTaille()].m_FormatMesure.GetColVitesse());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "M";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",this->pCEssais_BDD[this->GetTaille()].GetTypeMoteur());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "N";
	//std::sprintf(str,"%d",this->GetTaille() + 1);
	cellule.insert(1,str);
	std::sprintf(temp,"%d",this->pCEssais_BDD[this->GetTaille()].GetNbBloc());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	// switch + 3 cellule + boucle for
	for(int j=0;j < (this->pCEssais_BDD[this->GetTaille()].GetNbBloc());j++)
	{
		switch(j)
		{
		case 0:
			cellule = "O";
			cellule.insert(1,str);
			cellule1 = "P";
			cellule1.insert(1,str);
			cellule2= "Q";
			cellule2.insert(1,str);
			break;
		case 1:
			cellule = "R";
			cellule.insert(1,str);
			cellule1 = "S";
			cellule1.insert(1,str);
			cellule2= "T";
			cellule2.insert(1,str);

			break;
		case 2:
			cellule = "U";
			cellule.insert(1,str);
			cellule1 = "V";
			cellule1.insert(1,str);
			cellule2= "W";
			cellule2.insert(1,str);
			break;
		case 3:
			cellule = "X";
			cellule.insert(1,str);
			cellule1 = "Y";
			cellule1.insert(1,str);
			cellule2= "Z";
			cellule2.insert(1,str);
			break;
		case 4:
			cellule = "AA";
			cellule.insert(2,str);
			cellule1 = "AB";
			cellule1.insert(2,str);
			cellule2= "AC";
			cellule2.insert(2,str);
			break;
		case 5:
			cellule = "AD";
			cellule.insert(2,str);
			cellule1 = "AE";
			cellule1.insert(2,str);
			cellule2= "AF";
			cellule2.insert(2,str);
			break;
		case 6:
			cellule = "AG";
			cellule.insert(2,str);
			cellule1 = "AH";
			cellule1.insert(2,str);
			cellule2= "AI";
			cellule2.insert(2,str);
			break;
		case 7:
			cellule = "AJ";
			cellule.insert(2,str);
			cellule1 = "AK";
			cellule1.insert(2,str);
			cellule2= "AL";
			cellule2.insert(2,str);
			break;
		case 8:
			cellule = "AM";
			cellule.insert(2,str);
			cellule1 = "AN";
			cellule1.insert(2,str);
			cellule2= "AO";
			cellule2.insert(2,str);
			break;
		case 9:
			cellule = "AP";
			cellule.insert(2,str);
			cellule1 = "AQ";
			cellule1.insert(2,str);
			cellule2= "AR";
			cellule2.insert(2,str);
			break;
		case 10:
			cellule = "AS";
			cellule.insert(2,str);
			cellule1 = "AT";
			cellule1.insert(2,str);
			cellule2= "AU";
			cellule2.insert(2,str);
			break;
		case 11:
			cellule = "AV";
			cellule.insert(2,str);
			cellule1 = "AW";
			cellule1.insert(2,str);
			cellule2= "AX";
			cellule2.insert(2,str);
			break;
		case 12:
			cellule = "AY";
			cellule.insert(2,str);
			cellule1 = "AZ";
			cellule1.insert(2,str);
			cellule2= "BA";
			cellule2.insert(2,str);
			break;
		case 13:
			cellule = "BB";
			cellule.insert(2,str);
			cellule1 = "BC";
			cellule1.insert(2,str);
			cellule2= "BD";
			cellule2.insert(2,str);
			break;
		case 14:
			cellule = "BE";
			cellule.insert(2,str);
			cellule1 = "BF";
			cellule1.insert(2,str);
			cellule2= "BG";
			cellule2.insert(2,str);
			break;
		case 15:
			cellule = "BH";
			cellule.insert(2,str);
			cellule1 = "BI";
			cellule1.insert(2,str);
			cellule2= "BJ";
			cellule2.insert(2,str);
			break;

		default:
			cellule = "O";
			cellule.insert(1,str);
			cellule1 = "P";
			cellule1.insert(1,str);
			cellule2= "Q";
			cellule2.insert(1,str);
			break;
		}

	//std::sprintf(temp,"%s",this->pCEssais_BDD[this->GetTaille()].m_EnsembleBlocMesure[j].GetDescription());
	tmp = temp;
	RemplissageCellule(sheet,W2A (this->pCEssais_BDD[this->GetTaille()].m_EnsembleBlocMesure[j].GetDescription()), cellule);
	tmp.clear();
	

	std::sprintf(temp,"%d",this->pCEssais_BDD[this->GetTaille()].m_EnsembleBlocMesure[j].GetLigneDebut());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule1);
	tmp.clear();
	

	std::sprintf(temp,"%d",this->pCEssais_BDD[this->GetTaille()].m_EnsembleBlocMesure[j].GetNbpts());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule2);
	tmp.clear();
	}


	
	std::sprintf(str,"%d",this->GetTaille() + 1);
	std::string taille;
	taille = str;

	char temp2[1024];
	//USES_CONVERSION;
	
	LPWSTR AppPath = A2W(temp2);
	LPWSTR NomFichierIni = L"\\initBDD.ini";
	//CString AppPath;
	GetCurrentDirectory(1024,AppPath);
	
	wcscat(AppPath,NomFichierIni);
	//USES_CONVERSION;
	WritePrivateProfileString(L"TAILLE",L"Cle",A2W(taille.c_str()),AppPath);
	this->SetTaille(this->GetTaille() + 1);

	sheet.ReleaseDispatch();
	//book.SetSaved(TRUE);
	if(	book.get_ReadOnly())
		int i = 0;

	if(! book.get_Saved())
	{
		book.Save();
	//book.SaveAs(COleVariant(this->GetChemin()),covOptional,covOptional,covOptional,covOptional,covOptional,2,xlLocalSessionChanges,covOptional,covOptional,covOptional,covOptional);
	//book.SaveAs(COleVariant(TEXT("D:\test.xls")),
	}
	
	book.Close(covFalse,covOptional,covOptional);

	book.ReleaseDispatch();

	app.Quit();
	app.ReleaseDispatch();

}

BOOL CBDDEssais::Sauvegarde_Essais_to_BDDlocal_and_BDDfichier(const CEssais & essais)
{
	CDialogRefDejaPresente Dlg_dp;
	// parcour de la base de donnée
	for(int i = 0;	i<(this->n_taille);i++)
	{
		// test si ref presente
		if ((essais.sz_RefProduit) == this->pCEssais_BDD[i].GetRefProduit())
		{
			//oui	
			//test essai identique
			if( this->pCEssais_BDD[i] == essais )
			{//oui
				
				Dlg_dp.SetString(L"Réference déja présente");
				Dlg_dp.DoModal();
				return FALSE;
			}	
			else
			{//non
				CDialogModifBDD Dlg;
				// diag utilisaiteur ref deja presente : modification ref ? 
				if(Dlg.DoModal() == IDOK)
				{// oui
					//modification
					this->pCEssais_BDD[i].RazEssaitmp();
					this->pCEssais_BDD[i] = essais;
					//delete temp;

					this->MajRef_BDDfichier(i,this->pCEssais_BDD[i]);

					Dlg_dp.SetString(L"Réference modifié");
					Dlg_dp.DoModal();
					return TRUE;
				}
				else
				{//non
					return FALSE;
				}

				
			}
		}	
	}
	//non
			//ajout
	CEssais * temp = new CEssais[this->GetTaille()+1];
	for(int j = 0;j < (this->GetTaille());j++)
		temp[j] = (this->pCEssais_BDD[j]);
	//delete this->pCEssais_BDD;
	temp[this->GetTaille()] = essais;

	this->pCEssais_BDD = temp;
	//delete temp;

	this->Sauvegarde_BDDlocal_to_BDDfichier();

	Dlg_dp.SetString(L"Réference ajouté");
	Dlg_dp.DoModal();
	
	return TRUE;
		
}

void CBDDEssais::MajRef_BDDfichier(int id_ref,CEssais & essais)
{
	USES_CONVERSION;
	// Commonly used OLE variants.
	COleVariant
      covTrue((short)TRUE),
      covFalse((short)FALSE),
	  xlLocalSessionChanges((short) 2),
      covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	
	CApplication app;
	app =InitApplication();

	CWorkbook book;
	book =OuvertureBook( app , this->GetChemin() );

	//Creation de la premieres feuille
	CWorksheets sheets;
	CWorksheet sheet;

	sheets =book.get_Sheets();
	sheet = sheets.get_Item(COleVariant((short)1));
	//CreationEntete(book);

	//sauvegarde
	char str[6];
	char temp[255];
	std::string cellule,cellule1,cellule2,tmp;

	cellule = "B";
	std::sprintf(str,"%d",id_ref + 2);
	cellule.insert(1,str);
	RemplissageCellule(sheet,W2A(essais.GetRefProduit().GetString()), cellule);

	cellule = "C";
	//std::sprintf(str,"%d",this->GetTaille() + 2);
	cellule.insert(1,str);
	RemplissageCellule(sheet,W2A(essais.GetCheminFichier().GetString()), cellule);

	cellule = "D";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",essais.GetVersion());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "E";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",essais.m_FormatMesure.GetColTension());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "F";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",essais.m_FormatMesure.GetColFreq());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "G";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",essais.m_FormatMesure.GetColCapaCmd());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "H";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",essais.m_FormatMesure.GetColTemperature());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "I";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",essais.m_FormatMesure.GetColDebit());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "J";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",essais.m_FormatMesure.GetColPression());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "K";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",essais.m_FormatMesure.GetColPuissance());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "L";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",essais.m_FormatMesure.GetColVitesse());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "M";
	cellule.insert(1,str);
	std::sprintf(temp,"%d",essais.GetTypeMoteur());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	cellule = "N";
	//std::sprintf(str,"%d",this->GetTaille() + 1);
	cellule.insert(1,str);
	std::sprintf(temp,"%d",essais.GetNbBloc());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule);
	tmp.clear();

	// switch + 3 cellule + boucle for
	for(int j=0;j < (essais.GetNbBloc());j++)
	{
		switch(j)
		{
		case 0:
			cellule = "O";
			cellule.insert(1,str);
			cellule1 = "P";
			cellule1.insert(1,str);
			cellule2= "Q";
			cellule2.insert(1,str);
			break;
		case 1:
			cellule = "R";
			cellule.insert(1,str);
			cellule1 = "S";
			cellule1.insert(1,str);
			cellule2= "T";
			cellule2.insert(1,str);

			break;
		case 2:
			cellule = "U";
			cellule.insert(1,str);
			cellule1 = "V";
			cellule1.insert(1,str);
			cellule2= "W";
			cellule2.insert(1,str);
			break;
		case 3:
			cellule = "X";
			cellule.insert(1,str);
			cellule1 = "Y";
			cellule1.insert(1,str);
			cellule2= "Z";
			cellule2.insert(1,str);
			break;
		case 4:
			cellule = "AA";
			cellule.insert(2,str);
			cellule1 = "AB";
			cellule1.insert(2,str);
			cellule2= "AC";
			cellule2.insert(2,str);
			break;
		case 5:
			cellule = "AD";
			cellule.insert(2,str);
			cellule1 = "AE";
			cellule1.insert(2,str);
			cellule2= "AF";
			cellule2.insert(2,str);
			break;
		case 6:
			cellule = "AG";
			cellule.insert(2,str);
			cellule1 = "AH";
			cellule1.insert(2,str);
			cellule2= "AI";
			cellule2.insert(2,str);
			break;
		case 7:
			cellule = "AJ";
			cellule.insert(2,str);
			cellule1 = "AK";
			cellule1.insert(2,str);
			cellule2= "AL";
			cellule2.insert(2,str);
			break;
		case 8:
			cellule = "AM";
			cellule.insert(2,str);
			cellule1 = "AN";
			cellule1.insert(2,str);
			cellule2= "AO";
			cellule2.insert(2,str);
			break;
		case 9:
			cellule = "AP";
			cellule.insert(2,str);
			cellule1 = "AQ";
			cellule1.insert(2,str);
			cellule2= "AR";
			cellule2.insert(2,str);
			break;
		case 10:
			cellule = "AS";
			cellule.insert(2,str);
			cellule1 = "AT";
			cellule1.insert(2,str);
			cellule2= "AU";
			cellule2.insert(2,str);
			break;
		case 11:
			cellule = "AV";
			cellule.insert(2,str);
			cellule1 = "AW";
			cellule1.insert(2,str);
			cellule2= "AX";
			cellule2.insert(2,str);
			break;
		case 12:
			cellule = "AY";
			cellule.insert(2,str);
			cellule1 = "AZ";
			cellule1.insert(2,str);
			cellule2= "BA";
			cellule2.insert(2,str);
			break;
		case 13:
			cellule = "BB";
			cellule.insert(2,str);
			cellule1 = "BC";
			cellule1.insert(2,str);
			cellule2= "BD";
			cellule2.insert(2,str);
			break;
		case 14:
			cellule = "BE";
			cellule.insert(2,str);
			cellule1 = "BF";
			cellule1.insert(2,str);
			cellule2= "BG";
			cellule2.insert(2,str);
			break;
		case 15:
			cellule = "BH";
			cellule.insert(2,str);
			cellule1 = "BI";
			cellule1.insert(2,str);
			cellule2= "BJ";
			cellule2.insert(2,str);
			break;

		default:
			cellule = "O";
			cellule.insert(1,str);
			cellule1 = "P";
			cellule1.insert(1,str);
			cellule2= "Q";
			cellule2.insert(1,str);
			break;
		}

	//std::sprintf(temp,"%s",this->pCEssais_BDD[this->GetTaille()].m_EnsembleBlocMesure[j].GetDescription());
	tmp = temp;
	RemplissageCellule(sheet,W2A (essais.m_EnsembleBlocMesure[j].GetDescription()), cellule);
	tmp.clear();
	

	std::sprintf(temp,"%d",essais.m_EnsembleBlocMesure[j].GetLigneDebut());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule1);
	tmp.clear();
	

	std::sprintf(temp,"%d",essais.m_EnsembleBlocMesure[j].GetNbpts());
	tmp = temp;
	RemplissageCellule(sheet,tmp, cellule2);
	tmp.clear();
	}


	sheet.ReleaseDispatch();
	//book.SetSaved(TRUE);
	if(	book.get_ReadOnly())
		int i = 0;

	if(! book.get_Saved())
	{
		book.Save();
	//book.SaveAs(COleVariant(this->GetChemin()),covOptional,covOptional,covOptional,covOptional,covOptional,2,xlLocalSessionChanges,covOptional,covOptional,covOptional,covOptional);
	//book.SaveAs(COleVariant(TEXT("D:\test.xls")),
	}
	
	book.Close(covFalse,covOptional,covOptional);

	book.ReleaseDispatch();

	app.Quit();
	app.ReleaseDispatch();

}