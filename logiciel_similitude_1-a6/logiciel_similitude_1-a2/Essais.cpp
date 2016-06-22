#include "StdAfx.h"
#include "Essais.h"



CEssais::CEssais(void)
{
	this->m_nNbBloc = NB_BLOC;
	this->m_EnsembleBlocMesure = new CBlockMesure[this->m_nNbBloc];
}


CEssais::~CEssais(void)
{
	//delete this->m_EnsembleBlocMesure;
}

CEssais& CEssais::operator= (const CEssais & essais)
{
	//this->COLEDBExcel_Instance = essais.COLEDBExcel_Instance;
	this->sz_RefProduit = essais.sz_RefProduit;
	this->sz_CheminFichier = essais.sz_CheminFichier;
	this->n_version = essais.n_version;
	this->n_TypeMoteur = essais.n_TypeMoteur;
	this->m_FormatMesure = essais.m_FormatMesure;
	this->SetNbBloc(essais.m_nNbBloc);
	//this->m_EnsembleBlocMesure= essais.m_EnsembleBlocMesure;
	
	this->m_EnsembleBlocMesure = new CBlockMesure[this->m_nNbBloc];
	for(int i =0;i< this->m_nNbBloc;i++)
		this->m_EnsembleBlocMesure[i] = essais.m_EnsembleBlocMesure[i];
	

	return *this;
}
CEssais& CEssais::Copie_Essais_Sauf_CDonnees(const CEssais & essais)
{
	//this->COLEDBExcel_Instance = essais.COLEDBExcel_Instance;
	this->sz_RefProduit = essais.sz_RefProduit;
	this->sz_CheminFichier = essais.sz_CheminFichier;
	this->n_version = essais.n_version;
	this->n_TypeMoteur = essais.n_TypeMoteur;
	this->m_FormatMesure = essais.m_FormatMesure;
	this->SetNbBloc(essais.m_nNbBloc);
	//this->m_EnsembleBlocMesure= essais.m_EnsembleBlocMesure;
	
	this->m_EnsembleBlocMesure = new CBlockMesure[this->m_nNbBloc];
	for(int i =0;i< this->m_nNbBloc;i++)
		this->m_EnsembleBlocMesure[i] = essais.m_EnsembleBlocMesure[i];
	
	return *this;
}

BOOL CEssais::operator==(const CEssais& essais)
{
	if(this->GetRefProduit() != essais.sz_RefProduit)
		return false;
	if(this->GetCheminFichier() != essais.sz_CheminFichier)
		return false;
	if(this->GetVersion() != essais.n_version)
		return false;
	if(this->GetTypeMoteur() != essais.n_TypeMoteur)
		return false;
	if(this->GetNbBloc() != essais.m_nNbBloc)
		return false;
	return TRUE;
}

void CEssais::SetCheminFichier(CString sz)
{
	this->sz_CheminFichier = sz;
}
CString CEssais::GetCheminFichier()
{
	CString buf;
	buf = this->sz_CheminFichier;
	return buf;
}

void CEssais::SetRefProduit(CString sz)
{
	//CString RefProduit = sz;
	sz_RefProduit.SetString(sz);
}
CString CEssais::GetRefProduit()
{
	return this->sz_RefProduit;
}
	
void CEssais::SetVersion(const int vers)
{
	this->n_version = vers;
}
int CEssais::GetVersion()
{
	return this->n_version;
}
	
void CEssais::SetNbPts50Hz(const int nbpts)
{
	//this->n_NbPts50Hz = nbpts;
}
int CEssais::GetNbPts50Hz()
{
	//return this->n_NbPts50Hz;
	return 0;
}

void CEssais::SetNbPts60Hz(const int nbpts)
{
	//this->n_NbPts60Hz = nbpts;
}
int CEssais::GetNbPts60Hz()
{
	//return this->n_NbPts60Hz;
	return 0;
}

void CEssais::SetDebut50Hz(const int ligne)
{ 
	//this->n_Debut50Hz = ligne;
}
int CEssais::GetDebut50Hz()
{
	//return this->n_Debut50Hz;
	return 0;
}

void CEssais::SetDebut60Hz(const int ligne)
{
	//this->n_Debut60Hz = ligne;
}
int CEssais::GetDebut60Hz()
{
	//return this->n_Debut60Hz;
	return 0;
}

void CEssais::SetTypeMoteur(const int type)
{
	this->n_TypeMoteur = type;
}

int CEssais::GetTypeMoteur()
{
	return this->n_TypeMoteur;
}

void CEssais::Importation_Essai_from_Excel()
{
	USES_CONVERSION;
	// importation des données 50Hz
	//this->CDonnes_Essai50Hz.CDonnes_Importation_Excel("D:\\Cours ENIVL\\Stage ECOFIT\\Logiciel\\Stockage Essais\\LM23Ea.xls",this->GetNbPts50Hz(),this->GetVersion(),this->GetDebut50Hz());
	//this->CDonnes_Essai50Hz.CDonnes_Importation_Excel(W2A(this->GetCheminFichier()),this->m_FormatMesure,this->GetNbPts50Hz(),this->GetVersion(),this->GetDebut50Hz());
	// importation des données 60Hz
	//this->CDonnes_Essai60Hz.CDonnes_Importation_Excel(W2A(this->GetCheminFichier()),this->m_FormatMesure,this->GetNbPts60Hz(),this->GetVersion(),this->GetDebut60Hz());
}
void CEssais::RecuperationFormatExcel()
{
	BOOL tension_abs = TRUE;
	USES_CONVERSION;
	//Connection au fichier excel
	if (this->COLEDBExcel_Instance.connectionExcelwithoutHeader(W2A(this->sz_CheminFichier)))
	{
		for(int i = 1;(i < 24);i++) // Parcour des 24 colonnes et pour chaque colonnes recherche de la presence d'un nom identifié
		{
			std::string str;
			if(this->n_version == 2010)
				str = this->COLEDBExcel_Instance.recuperationCelluleExcel("Mesures$",1,i);
			else
				str = this->COLEDBExcel_Instance.recuperationCelluleExcel("B$",1,i);
			if((str.find("ension",0) != str.npos) && (str.find("omman",0) == str.npos))
			{
				this->m_FormatMesure.m_nColTension = i;
				tension_abs = FALSE;
			}
			if((str.find("U_Alim",0) != str.npos) && tension_abs)
				this->m_FormatMesure.m_nColTension = i;
			if(((str.find("ension",0) != str.npos) && (str.find("omman",0) != str.npos))||(str.find("apac",0) != str.npos)) // detection de la colonne tension de commande ou capacité
				this->m_FormatMesure.m_nColCapa_Cmd = i;
			if(str.find("réquen",0) != str.npos)
				this->m_FormatMesure.m_nColFreq = i;
			if((str.find("Q (m",0) != str.npos)||(str.find("DEBIT",0) != str.npos))
				this->m_FormatMesure.m_nColDebit = i;
			if((str.find("Ps (Pa",0) != str.npos)||(str.find("MOY PS",0) != str.npos))
				this->m_FormatMesure.m_nColPression = i;
			if((str.find("Waéro (",0) != str.npos)||(str.find("P aéro",0) != str.npos))
				this->m_FormatMesure.m_nColPuissance = i;
			if((str.find("RPM",0) != str.npos)||(str.find("MOY Vit",0) != str.npos))
				this->m_FormatMesure.m_nColVitesse = i;
			if(str.find("Tempé",0) != str.npos)
				this->m_FormatMesure.m_nColTemp = i;
			
		}
			//Deconnection du fichier excel
	this->COLEDBExcel_Instance.deconnectionExcel();
	}
	//Deconnection
	//this->COLEDBExcel_Instance.deconnectionExcel();
}
void CEssais::AnalyseBlockMesureExcel()
{
	USES_CONVERSION;
	//Connection au fichier
	if(this->COLEDBExcel_Instance.connectionExcel(W2A(this->GetCheminFichier())))
	{
		CString sheet;
		CString str = L"";
		// connection au fichier de l'essais
	
		if(this->n_version == 2010)
		{
			sheet = "Mesures$";
		}
		else
		{
			sheet = "B$";
		}
		// connection a la feuille
		this->COLEDBExcel_Instance.connectionTable(sheet);

		if(SUCCEEDED(this->COLEDBExcel_Instance.hr))
		{
			int lignedebut = 1;
			int temp = 1;
		
			//int* t= new int[12];
			//int* nbpts = new int[12];
		
			if(this->n_version == 2010)
				(this->COLEDBExcel_Instance.determinationBlock(&(this->m_EnsembleBlocMesure[0].m_nNbPts),&lignedebut,this->m_FormatMesure));
			else
				(this->COLEDBExcel_Instance.determinationBlock2004(&(this->m_EnsembleBlocMesure[0].m_nNbPts),&lignedebut,this->m_FormatMesure));
			//(this->COLEDBExcel_Instance.determinationBlock(&(this->m_EnsembleBlocMesure[0].m_nNbPts),&lignedebut,this->m_FormatMesure));
			this->m_EnsembleBlocMesure[0].SetLigneDebut(lignedebut);
			// creation description
			if(this->n_version == 2010)
			{
				if (lignedebut == 1)
				{
					if (this->COLEDBExcel_Instance.recuperationDescriptionExcel(1,1) != A2W(""))
					{
						str= this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,1);
						if(str.Find(A2W("_")) == -1) // test si récuperation des heuress
							str = str + L" ";
						else
							str = L"";
					}
				}
				else
				{
					if (this->COLEDBExcel_Instance.recuperationDescriptionExcel(lignedebut-1,1) != A2W("")) // recuperation description deja presente dans excel
					{
						str= this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,1);
						if(str.Find(A2W("_")) == -1)
							str = str + L" ";
						else
							str = L"";
					}
				}
				if (this->m_FormatMesure.m_nColTension != 0 )
					if(this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,this->m_FormatMesure.m_nColTension) != A2W(""))
				{
					str = str + L"Un ";
					str= str + this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,this->m_FormatMesure.m_nColTension);
					str = str + L"V ";
				}
				if (this->m_FormatMesure.m_nColFreq != 0)
					if( this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,this->m_FormatMesure.m_nColFreq) != A2W(""))
				{
					str = str + L"Fréq ";
					str = str + this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,this->m_FormatMesure.m_nColFreq);
					str = str + L"Hz ";
				}
				if(this->m_FormatMesure.m_nColCapa_Cmd != 0 )
					if(this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,this->m_FormatMesure.m_nColCapa_Cmd) != A2W(""))
				{
					switch(this->GetTypeMoteur())
					{
					case 0:
						str = str + L"Capa ";
						break;
					case 1:
						str = (str + L"Ucmd ");
						break;
					case 2:
						str = (str + L"Ucmd ");
						break;
					default:
						break;
					}
					str = str + this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,this->m_FormatMesure.m_nColCapa_Cmd);
					switch(this->GetTypeMoteur())
					{
					case 0:
						str = str + L"µF";
						break;
					case 1:
						str = (str + L"V");
						break;
					case 2:
						str = (str + L"V");
						break;
					default:
						break;
					}
				}
			}
			else
			{
				str= this->COLEDBExcel_Instance.recuperationDescriptionExcel(lignedebut-1,1);
			}

			this->m_EnsembleBlocMesure[0].SetDescription(str); // sauvegarde de la description du premier bloc de mesure

			BOOL fin = FALSE;

			for(int i =0; (i< (this->m_nNbBloc -1)) && (fin == FALSE);i++)
			{
				if(this->n_version == 2010) // recuperation de bloc de mesure i et saisi de la decription du bloc de mesure i+1
					temp = (this->COLEDBExcel_Instance.determinationBlock(&(this->m_EnsembleBlocMesure[i].m_nNbPts),&lignedebut,this->m_FormatMesure));
				else
					temp = (this->COLEDBExcel_Instance.determinationBlock2004(&(this->m_EnsembleBlocMesure[i].m_nNbPts),&lignedebut,this->m_FormatMesure));

				if(lignedebut == temp)
				{
					fin = TRUE;
					this->SetNbBloc(i);
				}
				else
				{
					lignedebut = temp;

					this->m_EnsembleBlocMesure[i+1].SetLigneDebut(temp);
					// creation description
					if(this->n_version == 2010)
					{
						if (this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,1) != A2W(""))
						{
							str= this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,1);
							if(str.Find(A2W("_")) == -1) // recherche si description deja donnée dans le fichier
							str = str + L" ";
							else
							str = L"";
						}
						if (this->m_FormatMesure.m_nColTension != 0 )
							if(this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,this->m_FormatMesure.m_nColTension) != A2W(""))
						{
							str = str + L"Un "; // recuperation de la tension d'alimentation
							str= str + this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,this->m_FormatMesure.m_nColTension);
							str = str + L"V ";
						}
						if (this->m_FormatMesure.m_nColFreq != 0)
							if( this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,this->m_FormatMesure.m_nColFreq) != A2W(""))
						{
							str = str + L"Fréq "; // recuperation de la frequence
							str = str + this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,this->m_FormatMesure.m_nColFreq);
							str = str + L"Hz ";
						}
						if(this->m_FormatMesure.m_nColCapa_Cmd != 0 )
							if(this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,this->m_FormatMesure.m_nColCapa_Cmd) != A2W(""))
						{
							switch(this->GetTypeMoteur()) // recuperation de la colonne suplementaire 
							{
							case 0:
								str = str + L"Capa ";  // capacite en AC
								break;
							case 1:
								str = (str + L"Ucmd "); // Tension de commande en DC
								break;
							case 2:
								str = (str + L"UCmd ");	// Tension de commande en EC
								break;
							default: // Pas de recuperation
								break;
							}
							str = str + this->COLEDBExcel_Instance.recuperationDescriptionExcel(temp,this->m_FormatMesure.m_nColCapa_Cmd);
							switch(this->GetTypeMoteur())
							{
							case 0:
								str = str + L"µF";
								break;
							case 1:
								str = (str + L"V");
								break;
							case 2:
								str = (str + L"V");
								break;
							default:
								break;
							}
						}
					}
					else
						str= this->COLEDBExcel_Instance.recuperationDescriptionExcel(lignedebut-1,1);

					this->m_EnsembleBlocMesure[i+1].SetDescription(str);

				}
			}

			// Deconnection du fichier
			this->COLEDBExcel_Instance.table.Close();
			this->COLEDBExcel_Instance.deconnectionExcel();
		}
	}
}

void CEssais::RazEssaitmp()
{
	// remise a zero des champs de l'essais
	this->n_TypeMoteur = -1;
	this->n_version = 0;
	this->sz_CheminFichier = "";
	this->sz_RefProduit = "";
	this->m_nNbBloc = NB_BLOC;
	this->m_EnsembleBlocMesure = new CBlockMesure[this->m_nNbBloc];
}