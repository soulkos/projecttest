#include "StdAfx.h"
#include "OLEDBExcel.h"
#include "Protocoles_OLEDB_EXCEL.h"

//#include "Essais.h"

COLEDBExcel::COLEDBExcel(void)
{
}


COLEDBExcel::~COLEDBExcel(void)
{
}


COLEDBExcel::COLEDBExcel(const COLEDBExcel & src)
{
	
	/*this->hr = src.hr;
	this->dataSource = src.dataSource;
	this->session = src.session;
	this->table = src.table;*/
}
COLEDBExcel& COLEDBExcel::operator=(const COLEDBExcel & src)
{
	
	/*this->hr = src.hr;
	this->dataSource = src.dataSource;
	this->session = src.session;*/
	/*this->table = src.table;*/

	return *this;
}

void COLEDBExcel::SetHR(HRESULT hr)
{
	this->hr = hr;
}
HRESULT COLEDBExcel::GetHR()
{
	return this->hr;
}


bool COLEDBExcel::connectionExcel(std::string filepath)
{
	hr = CoInitialize(NULL);
 
	if(!SUCCEEDED(hr))
		return FALSE;

	std::stringstream stream;

	//Choix automatique du protocole suivant le type de fichier
	if(filepath.find(".xlsx",0)==(-1)) // fichier .xls
		stream << "Provider='Microsoft.ACE.OLEDB.12.0';Data Source=" << filepath << ";Extended Properties="<<'\"'<<"Excel 8.0;MAXSCANROWS=0;ImportMixedTypes=Text;IMEX=1;HDR=YES;READONLY=FALSE"<<'\"';
	else	//fichier .xlsx
		stream << "Provider='Microsoft.ACE.OLEDB.12.0';Data Source=" << filepath << ";Extended Properties="<<'\"'<<"Excel 12.0 Xml;MAXSCANROWS=0;ImportMixedTypes=Text;IMEX=1;HDR=YES;READONLY=FALSE"<<'\"';
	
	filepath = stream.str();
	USES_CONVERSION; 
	char* iniStr =const_cast<char*>(filepath.c_str());


	hr=dataSource.OpenFromInitializationString(A2OLE(iniStr));
	if(!SUCCEEDED(hr))
	{
		CoUninitialize();
		return FALSE;
	}

	hr = session.Open(dataSource);

	if(!SUCCEEDED(hr))
	{
		dataSource.Close();
		CoUninitialize();
		return FALSE;
	}

	/*hr = table.Open(session, "Mesure$");
 
	if(!SUCCEEDED(hr))
	{
	session.Close();
	dataSource.Close();
	CoUninitialize();
	return FALSE;
	}*/

	return TRUE;

}
void COLEDBExcel::deconnectionExcel()
{

	session.Close();
	dataSource.Close();
	CoUninitialize();
}
bool COLEDBExcel::connectionExcelwithoutHeader(std::string filepath)
{
	hr = CoInitialize(NULL);
 
	if(!SUCCEEDED(hr))
		return FALSE;

	std::stringstream stream;

	//Choix automatique du protocole suivant le type de fichier
	if(filepath.find(".xlsx",0)==(-1)) // fichier .xls
		stream << "Provider='Microsoft.ACE.OLEDB.12.0';Data Source=" << filepath << ";Extended Properties="<<'\"'<<"Excel 8.0;MAXSCANROWS=0;ImportMixedTypes=Text;IMEX=1;HDR=NO;READONLY=FALSE"<<'\"';
	else	//fichier .xlsx
		stream << "Provider='Microsoft.ACE.OLEDB.12.0';Data Source=" << filepath << ";Extended Properties="<<'\"'<<"Excel 12.0 Xml;MAXSCANROWS=0;ImportMixedTypes=Text;IMEX=1;HDR=NO;READONLY=FALSE"<<'\"';
	
	filepath = stream.str();
	USES_CONVERSION; 
	char* iniStr =const_cast<char*>(filepath.c_str());


	hr=dataSource.OpenFromInitializationString(A2OLE(iniStr));
	if(!SUCCEEDED(hr))
	{
		CoUninitialize();
		return FALSE;
	}

	hr = session.Open(dataSource);

	if(!SUCCEEDED(hr))
	{
		dataSource.Close();
		CoUninitialize();
		return FALSE;
	}

	/*hr = table.Open(session,"Mesures$");
 
	if(!SUCCEEDED(hr))
	{
	session.Close();
	dataSource.Close();
	CoUninitialize();
	return FALSE;
	}*/

	return TRUE;

}
float* COLEDBExcel::recuperationTableauExcel(std::string sheet,const int colonne,const int lignedebut,const int longeurtab)
{
	// connection a la feuille
	this->hr = this->table.Open(session,sheet.c_str());
	if(!SUCCEEDED(hr))
	{
		session.Close();
		dataSource.Close();
		CoUninitialize();
		return NULL;
	}

	// initialisation
	float* tab_temp = new float[longeurtab];
	int iligne=1;
	int i;
	//CTable<CDynamicStringAccessor> tabletemp = this->table;
	
	// recuperation du tableau
	for(hr = table.MoveFirst( ); SUCCEEDED(hr) && (iligne <lignedebut);hr = table.MoveNext( ))
		iligne++;
	for(i = 0; (iligne <(lignedebut+longeurtab) && SUCCEEDED(hr));hr = table.MoveNext( ))
	{
		tab_temp[i]=_wtof(table.GetString(colonne));

		iligne++;
		i++;
	}
 
	// deconnection a la feuille et renvoi du tableau
	table.Close();
	return tab_temp;
}
std::string COLEDBExcel::recuperationCelluleExcel(std::string sheet,const int ligne,const int colonne)
{
	// connection a la feuille
	hr = table.Open(session,sheet.c_str());
	if(!SUCCEEDED(hr))
	{
		session.Close();
		dataSource.Close();
		CoUninitialize();
		return NULL;
	}
	hr = table.MoveFirst( ); 

	std::string temp;
	// initialisation
	int iligne=0;

	// recuperation du tableau
	for(hr = table.MoveFirst( ); SUCCEEDED(hr) && (iligne <(ligne-1));hr = table.MoveNext( ))
		iligne++;

	USES_CONVERSION;
	temp=W2A(table.GetString(colonne));
	// deconnection a la feuille et renvoi du tableau
	table.Close();
	return temp;
}
CString COLEDBExcel::recuperationDescriptionExcel(const int ligne,const int colonne)
{
	// connection a la feuille
	//hr = table.Open(session,sheet.c_str());
	if(!SUCCEEDED(hr))
	{
		session.Close();
		dataSource.Close();
		CoUninitialize();
		return NULL;
	}
	CString temp;
	// initialisation
	int iligne=0;

	// recuperation du tableau
	for(hr = table.MoveFirst( ); SUCCEEDED(hr) && (iligne <(ligne));hr = table.MoveNext( ))
		iligne++;

	USES_CONVERSION;
	
	// deconnection a la feuille et renvoi du tableau
	if(SUCCEEDED(hr))
		return table.GetString(colonne);
	return NULL;
}
void COLEDBExcel::ecritureCelluleExcel(std::string  text, std::string sheet,const int colonne)
{
	// connection a la feuille
	hr = table.Open(session,sheet.c_str());
	if(!SUCCEEDED(hr))
	{
		session.Close();
		dataSource.Close();
		CoUninitialize();
	}
	hr = table.MoveFirst(); 
	hr = table.MoveNext( );
	hr = table.MoveNext( );
	// initialisation
	int iligne=0;

	// recuperation du tableau
	//for(hr = table.MoveFirst( ); SUCCEEDED(hr) && (iligne <(ligne-1));hr = table.MoveNext( ))
	//	iligne++;

	USES_CONVERSION;
	if(SUCCEEDED(this->hr))
	{
		table.SetData(table.m_nAccessors);
		table._SetString(colonne,CA2W(text.c_str()));
		table.UpdateAll();
		session.Commit();
		std::string temp;

		temp=W2A(table.GetString(colonne));
	}
	// deconnection a la feuille et renvoi du tableau
	table.Close();
}
void COLEDBExcel::connectionTable()
{
	hr = table.Open(session, "sheet1$");
	
	if(!SUCCEEDED(hr))
	{
	session.Close();
	dataSource.Close();
	CoUninitialize();
	}
}
void COLEDBExcel::connectionTable(CString str)
{
	USES_CONVERSION;
	hr = table.Open(session,str);
	
	if(!SUCCEEDED(hr))
	{
	session.Close();
	dataSource.Close();
	CoUninitialize();
	}
}
int COLEDBExcel::determinationBlock2004(int* nbpts_block,int* ligne_debut1,CFormatExcel format)
{
	USES_CONVERSION;
	int iligne=1,nbpts = 0;
	//int** temp;
	float i = -1; //,j;
	CString cellule,cellule1;
	CString deb1,deb2;
	//CTable<CDynamicStringAccessor> tabletemp = this->table;
	
	// Avance jusqua la ligne de debut
	for(hr = table.MoveFirst( ); SUCCEEDED(hr) && (iligne <(*ligne_debut1));hr = table.MoveNext( ))
	{
		iligne++;
		if (hr != DB_S_ENDOFROWSET)
			cellule = table.GetString(1);
	}
	if (hr != DB_S_ENDOFROWSET)
	{
		cellule1 =table.GetString(1);
		deb1 = table.GetString(format.m_nColDebit);
	}
	// Avance jusqua la premier ligne de données
	while(SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET && cellule.Find(A2T("")) == -1 && cellule1.Find(A2T("")) != -1) 
	{	
		
		// avance dans le parcour des chaine de caractere
		cellule = cellule1;
		deb1 = deb2;
		//avance d'une ligne
		hr = table.MoveNext( );
		iligne++;
		//recuperation du contenue de la nouvelle cellule
		if (hr != DB_S_ENDOFROWSET)
		{
			cellule1 =table.GetString(1);
			deb2 = table.GetString(format.m_nColDebit);
		}
	}
	(*ligne_debut1) = iligne;
	// Decompte du nombre de points


	//avance d'une ligne
	hr = table.MoveNext( );

	//recuperation du contenue de la nouvelle cellule
	if (hr != DB_S_ENDOFROWSET)
	{	
		iligne++;
		nbpts++;
		cellule1 =table.GetString(1);
		deb2 = table.GetString(format.m_nColDebit);
	}

	while(hr != DB_S_ENDOFROWSET && SUCCEEDED(hr) &&( _wtof(deb1) != _wtof(deb2)))
	{
		// avance dans le parcour des chaine de caractere
		cellule = cellule1;
		deb1 = deb2;
		//avance d'une ligne
		hr = table.MoveNext( );
		iligne++;
		nbpts++;
		//recuperation du contenue de la nouvelle cellule
		if (hr != DB_S_ENDOFROWSET)
		{
			cellule1 =table.GetString(1);
			deb2 = table.GetString(format.m_nColDebit);
		}
	}
	(*nbpts_block)= nbpts;

	// Avance jusqua la premier ligne de données
	while(SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET && /*cellule.Find(A2T("")) != -1 && */cellule1.Find(A2T("hz")) == -1) 
	{	
		
		// avance dans le parcour des chaine de caractere
		cellule = cellule1;
		//deb1 = deb2;
		//avance d'une ligne
		hr = table.MoveNext( );
		iligne++;
		//recuperation du contenue de la nouvelle cellule
		if (hr != DB_S_ENDOFROWSET)
		{
			cellule1 =table.GetString(1);
			//deb2 = table.GetString(format.m_nColDebit);
		}
	}
	return iligne;
	return 1;
}
int COLEDBExcel::determinationBlock(int* nbpts_block,int* ligne_debut1,CFormatExcel format)
{
	USES_CONVERSION;
	int iligne=1,nbpts = 0;
	//int** temp;
	float i = -1; //,j;
	CString cellule,cellule1;
	//CTable<CDynamicStringAccessor> tabletemp = this->table;
	
	// Avance jusqua la ligne de debut
	for(hr = table.MoveFirst( ); SUCCEEDED(hr) && (iligne <(*ligne_debut1));hr = table.MoveNext( ))
	{
		iligne++;
		if (hr != DB_S_ENDOFROWSET)
			cellule = table.GetString(1);
	}
	if (hr != DB_S_ENDOFROWSET)
		cellule1 =table.GetString(1);
	// Avance jusqua la premier ligne de données
	while(SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET && cellule.Find(A2T("_")) == -1 && cellule1.Find(A2T("_")) == -1) 
	{	
		
		// avance dans le parcour des chaine de caractere
		cellule = cellule1;
		//avance d'une ligne
		hr = table.MoveNext( );
		iligne++;
		//recuperation du contenue de la nouvelle cellule
		if (hr != DB_S_ENDOFROWSET)
			cellule1 =table.GetString(1);
	}
	//Atribution de la ligne de debut
	if(cellule.Find(A2T("_")) != -1 && cellule1.Find(A2T("_")) != -1)// pas de ligne avant le debut du bloc
		(*ligne_debut1) = iligne;
	if(cellule.Find(A2T("_")) == -1 && cellule1.Find(A2T("_")) != -1) //ligne vide avant le bloc de mesure
	{
		(*ligne_debut1) = iligne;
		// avance dans le parcour des chaine de caractere
		cellule = cellule1;
		//avance d'une ligne
		hr = table.MoveNext( );
		iligne++;
		nbpts++;
		//recuperation du contenue de la nouvelle cellule
		if (hr != DB_S_ENDOFROWSET)
			cellule1 =table.GetString(1);
	}
	// Decompte du nombre de points
	while(hr != DB_S_ENDOFROWSET && SUCCEEDED(hr) && cellule.Find(A2T("_")) != -1 && cellule1.Find(A2T("_")) != -1)
	{
		// avance dans le parcour des chaine de caractere
		cellule = cellule1;
		//avance d'une ligne
		hr = table.MoveNext( );
		iligne++;
		nbpts++;
		//recuperation du contenue de la nouvelle cellule
		if (hr != DB_S_ENDOFROWSET)
			cellule1 =table.GetString(1);
	}
	(*nbpts_block)= nbpts;

	// Avance jusqu'au prochain bloc de donné
	while(SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET && ((cellule.Find(A2T("_")) == -1 && cellule1.Find(A2T("_")) == -1)||(cellule.Find(A2T("_")) != -1 && cellule1.Find(A2T("_")) == -1))) 
	{	
		// avance dans le parcour des chaine de caractere
		cellule = cellule1;
		//avance d'une ligne
		hr = table.MoveNext( );
		iligne++;
		//recuperation du contenue de la nouvelle cellule
		if (hr != DB_S_ENDOFROWSET)
			cellule1 =table.GetString(1);
	}
	if(cellule.Find(A2T("_")) == -1 && cellule1.Find(A2T("_")) != -1) //ligne vide avant le bloc de mesure
		return iligne;

	return iligne;

	
		/*if((table.GetString(format.m_nColDebit) == L"")&&(table.GetString(format.m_nColPression) == L"")&&(table.GetString(format.m_nColVitesse) == L"")&&(table.GetString(format.m_nColVitesse) == L""))
		{
			while((table.GetString(format.m_nColDebit) == L"")&&(table.GetString(format.m_nColPression) == L"")&&(table.GetString(format.m_nColVitesse) == L"")&&(table.GetString(format.m_nColVitesse) == L"")&& hr != DB_S_ENDOFROWSET)
			{
				iligne++;
				hr = table.MoveNext( );
			}
			return iligne;
		}*//*
		dfg = table.GetString(1);
		dfg.Find("_");
		j=_wtof( table.GetString(format.m_nColDebit));
		if((dfg == "")&&(i == j))
		{
			
			//dfg =  table.GetString(format.m_nColDebit);
			//j = _wtof( table.GetString(format.m_nColPression));
			while((dfg == "")&&(i == j)&& hr != DB_S_ENDOFROWSET)
			{
				iligne++;
				hr = table.MoveNext( );
				j=_wtof( table.GetString(format.m_nColDebit));
				dfg = table.GetString(1);
			}
			(*nbpts_block) = nbpts - 1 ;
			return iligne + 1;

		}
		iligne++;
		nbpts++;
		//dfg = table.GetString(1);
		i = _wtof( table.GetString(format.m_nColDebit));
	}
	(*nbpts_block)= nbpts - 1;
	return iligne + 1;
	*/
}

/*CEssais* COLEDBExcel::recuperationBDDExcel(std::string sheet, const int tailleBDD)
{
	// connection a la feuille
	hr = table.Open(session,sheet.c_str());
	if(!SUCCEEDED(hr))
	{
		session.Close();
		dataSource.Close();
		CoUninitialize();
		return NULL;
	}

	// initialisation
	CEssais* BDD_temp = (CEssais*)malloc(sizeof(CEssais)*tailleBDD);
	int i=0;

	// recuperation du tableau
	for(hr = table.MoveFirst( ); (i <(tailleBDD) && SUCCEEDED(hr));hr = table.MoveNext())
	{
		BDD_temp[i].SetRefProduit(table.GetString(2));
		BDD_temp[i].SetCheminFichier(table.GetString(3));
		BDD_temp[i].SetVersion(_wtoi(table.GetString(4)));
		//tab_temp[i]=_wtof(table.GetString(colonne));

		i++;
	}
}*/
