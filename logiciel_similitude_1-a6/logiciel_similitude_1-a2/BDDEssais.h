
#include "stdafx.h"

#include "Essais.h"
#include "Protocoles_OLEDB_EXCEL.h"
#include "Protocole_Automation_EXCEL.h"


#pragma once
class CBDDEssais
{
public:
	int n_taille;
	CEssais* pCEssais_BDD;
	CString sz_CheminBDD;
	COLEDBExcel COLEDBExcel_Instance;

public:
	// init

	//constructeur & destructeur
	CBDDEssais(void);
	virtual ~CBDDEssais(void);

	//Surcharge du constructeur
	CBDDEssais(const CBDDEssais &);
	CBDDEssais(const char *);

	//Surcharge operateur =
	 CBDDEssais & operator=(const CBDDEssais &);

	 //Accessors

	 void SetTaille(const int taille);
	 int GetTaille();
	 void SetChemin(const CString sz);
	 CString GetChemin();

	 void SetRefProduit(int i, CString temp){ this->pCEssais_BDD[i].SetRefProduit(temp);};

	// Methodes

	BOOL Sauvegarde_Essais_to_BDDlocal_and_BDDfichier(const CEssais & essais);
	void Sauvegarde_BDDlocal_to_BDDfichier();
	void MajRef_BDDfichier(int id_ref,CEssais & essais); 
	void Chargement_BDDfichier_to_BDDlocal();


};

