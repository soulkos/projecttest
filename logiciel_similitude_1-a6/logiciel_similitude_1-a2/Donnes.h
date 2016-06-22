
#include "stdafx.h"

#include "Protocoles_OLEDB_EXCEL.h"
#include "OLEDBExcel.h"


#pragma once


class CDonnes
{
public:
	frequence n_freq;	//Indice de frequence
	float* af_DebitQ;	//Debit volumiquen en m3/h
	float* af_PressionDP;	//Pression aval du ventilateur en Pa
	float* af_PuissanceP;	//Puissance aéraulique en W
	float* af_VitesseRPM;	//Vitesse de rotation en tr/min
	float* af_Temperature; // temperature d'essais en °C

	int n_NbPts;

	COLEDBExcel COLEDBExcel_Instance;
	
public:
	// init

	CDonnes(void);
	virtual ~CDonnes(void);
	CDonnes(const CDonnes &);
	CDonnes& operator=(const CDonnes &);
	void Copie(const CDonnes & src);

	//Accessors

	void SetFreq(const frequence freq);
	frequence GetFreq();
	void SetDebit(float* debit);
	float* GetDebit();
	void SetPression(float* pression);
	float* GetPression();
	void SetPuissance(float* puissance);
	float* GetPuissance();
	void SetVitesse(float* vitesse);
	float* GetVitesse();
	void SetTemperature(float * temp);
	float* GetTemperature();
	void SetNbPts(const int nbpts);
	int GetNbPts();

	//Methode

	void CDonnes_Importation_Excel(const std::string filepath,CFormatExcel format,const int nbpts,int version,int lignedeb);
	void CDonnes_Calcul_Similitude(const float rapportSimi);
	void CDonnes_Calcul_Similitude_Vitesse_cible(const float f_Vitesse_Cible);
	void CDonnes_Calcul_Altitude_RPM_cst(const float AltiCible);
	void CDonnes_Calcul_Altitude_RPM_libre(const float AltiCible);
	void CDonnes_Convertion_Debit(const float rapport);
	void CDonnes_Convertion_Pression(const float rapport);
	void CDonnes_Convertion_Vitesse(const float rapport);

	
};

