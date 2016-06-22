
#include "stdafx.h"



#include "Donnes.h"




#pragma once


class CResultatSimilitude
{
public:
	CString sz_RefProduit;
	CString m_szDescription;
	frequence n_IdFreq;
	CDonnes CDonnes_ResultatSimilitude;
	CDonnes CDonnes_Originales;
	float f_AltitudeUtili;
	float f_RPMcible;
	float f_Qcible;
	float f_Qintersec;
	float f_DPcible;
	float f_RapportSimilitude;
	int m_nUniteDebit;
	int m_nUnitePression;
	int m_nUniteVitesse;
	
public:
	//init

	CResultatSimilitude(void);
	virtual ~CResultatSimilitude(void);
	CResultatSimilitude(const CResultatSimilitude &);
	CResultatSimilitude &operator =(const CResultatSimilitude &);

	//Accessors

	void SetRefProduit(const CString sz);
	CString GetRefProduit();
	void SetDescription(const CString sz);
	CString GetDescription();
	void SetFreq(const frequence freq);
	frequence GetFreq();
	void SetAltiUtili(const float alti);
	float GetAltiUtili();
	void SetRPM(const float vitesse);
	float GetRPM();
	void SetDebit(const float debit);
	float GetDebit();
	void SetPression(const float pression);
	float GetPression();
	float GetRapportSimilitude();
	int GetUniteDebit();
	void SetUniteDebit(int u);
	int GetUnitePression();
	void SetUnitePression(int u);
	int GetUniteVitesse();
	void SetUniteVitesse(int u);



	//Methodes

	float Calcul_Debit_Intersec();
	float Calcul_Vitesse_Commande();
	float Calcul_Rapport_Simi();
	float Calcul_Rapport_Simi_Debit_Nul();
	float Calcul_Rapport_Simi_Pression_Nulle();
	void Calcul_Simi();
	void Calcul_Simi_RPM();
	void Calcul_Altitude_RPMcst();
	void Calcul_Altitude_RPMvar();
	void Exportation_Excel();
	void Recuperation_Donnes_Pour_Calcul(CDonnes Essai);
	void Conversion_des_donnees(int CvDebit,int CvPression,int CvVitesse);

};

