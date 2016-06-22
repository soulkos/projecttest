
#include "stdafx.h"

//#include "Donnes.h"
#include "BlockMesure.h"
#include "FormatExcel.h"

#define NB_BLOC 16

#pragma once
class CEssais
{
public:
	CString sz_RefProduit;
	CString sz_CheminFichier;
	int n_version;
	int m_nNbBloc;
	int n_TypeMoteur;
	/*int n_NbPts50Hz;
	int n_NbPts60Hz;
	int n_Debut50Hz;
	int n_Debut60Hz;
	CDonnes CDonnes_Essai50Hz;
	CDonnes CDonnes_Essai60Hz;*/
	COLEDBExcel COLEDBExcel_Instance;

	CFormatExcel m_FormatMesure;
	
	CBlockMesure* m_EnsembleBlocMesure;

public:
	//***	init

	//constructeur & destructeur
	CEssais(void);
	virtual ~CEssais(void);

	//Surcharge du constructeur
	CEssais(const CEssais &); 
	CEssais(char*,char*,int);
	
	//Surcharge de l'operateur =
	CEssais & operator= (const CEssais &);
	CEssais& Copie_Essais_Sauf_CDonnees(const CEssais & essais);
	BOOL operator ==(const CEssais & essais);
	//Accessors
	void SetCheminFichier(CString sz);
	CString GetCheminFichier();
	void SetRefProduit(CString sz);
	CString GetRefProduit();
	void SetVersion(const int vers);
	int GetVersion();
	void SetNbPts50Hz(const int nbpts);
	int GetNbPts50Hz();
	void SetNbPts60Hz(const int nbpts);
	int GetNbPts60Hz();
	void SetDebut50Hz(const int ligne);
	int GetDebut50Hz();
	void SetDebut60Hz(const int ligne);
	int GetDebut60Hz();
	void SetTypeMoteur(const int type);
	int GetTypeMoteur();
	void SetNbBloc (int nb){this->m_nNbBloc = nb;};
	int GetNbBloc(){return this->m_nNbBloc;};

		
	//***	Methodes
	void RecuperationFormatExcel();
	void Importation_Essai_from_Excel();
	void AnalyseBlockMesureExcel();
	void RazEssaitmp();
};

