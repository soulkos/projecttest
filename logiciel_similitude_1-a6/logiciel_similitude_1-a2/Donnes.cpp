#include "StdAfx.h"
#include "Donnes.h"

#include "logiciel_similitude_1-a2.h"
#include "logiciel_similitude_1-a2Doc.h"

CDonnes::CDonnes(void)
{
	this->n_NbPts = 0;
	this->af_DebitQ = NULL;
	this->af_PressionDP = NULL;
	this->af_PuissanceP = NULL;
	this->af_VitesseRPM = NULL;
	this->af_Temperature = NULL;
}


CDonnes::~CDonnes(void)
{
	/*if( this->af_DebitQ != NULL)
		delete this->af_DebitQ;
	if( this->af_PressionDP != NULL)
		delete this->af_PressionDP;
	if(  this->af_PuissanceP != NULL)
		delete this->af_PuissanceP;
	if( this->af_VitesseRPM != NULL)
		delete this->af_VitesseRPM;
	if( this->af_Temperature != NULL)
		delete this->af_Temperature;*/

}


CDonnes::CDonnes(const CDonnes & src)
{
	this->COLEDBExcel_Instance = src.COLEDBExcel_Instance;
	this->n_freq = src.n_freq;
	this->n_NbPts = src.n_NbPts;

	(this->af_DebitQ = new float[this->n_NbPts]);
	(this->af_PressionDP = new float[this->n_NbPts]);
	(this->af_PuissanceP = new float[this->n_NbPts]);
	(this->af_VitesseRPM = new float[this->n_NbPts]);
	if( src.af_Temperature != NULL)
		(this->af_Temperature = new float[this->n_NbPts]);

	for(int i=0;i<n_NbPts;i++)
	{
		(this->af_DebitQ[i] = src.af_DebitQ[i]);
		(this->af_PressionDP[i] = src.af_PressionDP[i]) ;
		(this->af_PuissanceP[i]  = src.af_PuissanceP[i]) ;
		(this->af_VitesseRPM[i]  = src.af_VitesseRPM[i] );
		if( src.af_Temperature != NULL)
			(this->af_Temperature[i]  = src.af_Temperature[i] );
	}

}
CDonnes& CDonnes::operator=(const CDonnes & src)
{
	this->COLEDBExcel_Instance = src.COLEDBExcel_Instance;
	this->n_freq = src.n_freq;
	this->n_NbPts = src.n_NbPts;

	(this->af_DebitQ = new float[this->n_NbPts]);
	(this->af_PressionDP = new float[this->n_NbPts]);
	(this->af_PuissanceP = new float[this->n_NbPts]);
	(this->af_VitesseRPM = new float[this->n_NbPts]);
	if( src.af_Temperature != NULL)
		(this->af_Temperature = new float[this->n_NbPts]);

	for(int i=0;i<n_NbPts;i++)
	{
		(this->af_DebitQ[i] = src.af_DebitQ[i]);
		(this->af_PressionDP[i] = src.af_PressionDP[i]) ;
		(this->af_PuissanceP[i]  = src.af_PuissanceP[i]) ;
		(this->af_VitesseRPM[i]  = src.af_VitesseRPM[i] );
		if( src.af_Temperature != NULL)
			(this->af_Temperature[i]  = src.af_Temperature[i] );
	}

	return *this;
}
void CDonnes::Copie(const CDonnes & src)
{
	this->COLEDBExcel_Instance = src.COLEDBExcel_Instance;
	this->n_freq = src.n_freq;
	this->n_NbPts = src.n_NbPts;

	(this->af_DebitQ = new float[this->n_NbPts]);
	(this->af_PressionDP = new float[this->n_NbPts]);
	(this->af_PuissanceP = new float[this->n_NbPts]);
	(this->af_VitesseRPM = new float[this->n_NbPts]);
	if( src.af_Temperature != NULL)
		(this->af_Temperature = new float[this->n_NbPts]);

	for(int i=0;i<n_NbPts;i++)
	{
		(this->af_DebitQ[i] = src.af_DebitQ[i]);
		(this->af_PressionDP[i] = src.af_PressionDP[i]) ;
		(this->af_PuissanceP[i]  = src.af_PuissanceP[i]) ;
		(this->af_VitesseRPM[i]  = src.af_VitesseRPM[i] );
		if( src.af_Temperature != NULL)
			(this->af_Temperature[i]  = src.af_Temperature[i] );
	}
}

void CDonnes::SetFreq(const frequence freq)
{
	this->n_freq = freq;
}
frequence CDonnes::GetFreq()
{
	return this->n_freq;
}

void CDonnes::SetDebit( float* debit)
{
	this->af_DebitQ = debit;
}
float* CDonnes::GetDebit()
{
	return this->af_DebitQ;
}

void CDonnes::SetPression( float* pression)
{
	this->af_PressionDP = pression;
}
float* CDonnes::GetPression()
{ 
	return this->af_PressionDP;
}

void CDonnes::SetPuissance( float* puissance)
{
	this->af_PuissanceP = puissance;
}
float* CDonnes::GetPuissance()
{
	return this->af_PuissanceP;
}

void CDonnes::SetVitesse(float* vitesse)
{
	this->af_VitesseRPM = vitesse;
}
float* CDonnes::GetVitesse()
{
	return this->af_VitesseRPM;
}

void CDonnes::SetNbPts(const int nbpts)
{
	this->n_NbPts = nbpts;
}
int CDonnes::GetNbPts()
{
	return this->n_NbPts;
}

void CDonnes::SetTemperature(float * temp)
{
	this->af_Temperature = temp;
}
float* CDonnes::GetTemperature()
{
	return this->af_Temperature;
}

void CDonnes::CDonnes_Importation_Excel(const std::string filepath,CFormatExcel format,const int nbpts,int version,int lignedeb)
{
	BOOL i;
	//int colDebit,colPression,colPuissance,colVitesse,colTemp;
	std::string sheet;
	// connection au fichier de l'essais
	USES_CONVERSION;
	if(version == 2010)
	{
		sheet = "Mesures$";
	}
	else
	{
		sheet = "B$";
		this->SetTemperature(NULL);
	}
	this->COLEDBExcel_Instance.deconnectionExcel();
	i = this->COLEDBExcel_Instance.connectionExcel(filepath);
	if(i)
	{
		// si connection a la table recuperatipn des données
		if((version == 2010)&&(format.m_nColTemp != 0))
		{
			this->SetTemperature(COLEDBExcel_Instance.recuperationTableauExcel(sheet,format.m_nColTemp,lignedeb,nbpts));
		}
		if(format.m_nColDebit !=0)
			this->SetDebit(COLEDBExcel_Instance.recuperationTableauExcel(sheet,format.m_nColDebit,lignedeb,nbpts));
		if(format.m_nColPression !=0)
		this->SetPression(this->COLEDBExcel_Instance.recuperationTableauExcel(sheet,format.m_nColPression,lignedeb,nbpts));
		if(format.m_nColPuissance !=0)
		this->SetPuissance(this->COLEDBExcel_Instance.recuperationTableauExcel(sheet,format.m_nColPuissance,lignedeb,nbpts));
		if(format.m_nColVitesse !=0)
		this->SetVitesse(this->COLEDBExcel_Instance.recuperationTableauExcel(sheet,format.m_nColVitesse,lignedeb,nbpts));
		this->SetNbPts(nbpts);
	}
	this->COLEDBExcel_Instance.deconnectionExcel();
	
}
void CDonnes::CDonnes_Calcul_Similitude(const float rapportSimi)
{
	for(int i = 0;i < this->n_NbPts;i++)
	{
		this->af_DebitQ[i] = this->af_DebitQ[i] * rapportSimi;
		this->af_PressionDP[i] = this->af_PressionDP[i] * rapportSimi * rapportSimi;
		this->af_PuissanceP[i] = this->af_PuissanceP[i] * rapportSimi * rapportSimi * rapportSimi;
		this->af_VitesseRPM[i] = this->af_VitesseRPM[i] * rapportSimi;
	}
	
}
void CDonnes::CDonnes_Calcul_Similitude_Vitesse_cible(const float f_Vitesse_Cible)
{
	float rapportSimi;
	for(int i = 0;i < this->n_NbPts;i++)
	{
		rapportSimi = f_Vitesse_Cible / (this->af_VitesseRPM[i] ); 
		this->af_VitesseRPM[i] = f_Vitesse_Cible;		
		this->af_DebitQ[i] = this->af_DebitQ[i] * rapportSimi;
		this->af_PressionDP[i] = this->af_PressionDP[i] * rapportSimi * rapportSimi;
		this->af_PuissanceP[i] = this->af_PuissanceP[i] * rapportSimi * rapportSimi * rapportSimi;
		
	}
	
}
void CDonnes::CDonnes_Calcul_Altitude_RPM_cst(const float f_Alti_Cible)
{
	float rapportAlti;
	// Constantes
	float Lb = -0.0065; // K°/m
	float R = 8.31; // N.m/(mol.K°)
	float M = 0.0289644; // kg/mol
	float g = 9.81; // N.m
	int f_Alti_Ref = 134; // m (altitude ECOFIT)

	if(this->af_Temperature == NULL)
		rapportAlti = pow(float((20+273.15)/(20+273.15 + Lb*(f_Alti_Cible - f_Alti_Ref))),float((g*M)/(R*Lb))); // temp = 20°C
	//else
		//rapportAlti = pow(float((this->af_Temperature[i]+273.15)/((this->af_Temperature[i]+273.15) + Lb*(f_Alti_Cible - f_Alti_Ref))),float((g*M)/(R*Lb))); 

	for(int i = 0;i < this->n_NbPts;i++)
	{
		if(this->af_Temperature != NULL)
			rapportAlti = pow(float((this->af_Temperature[i]+273.15)/((this->af_Temperature[i]+273.15) + Lb*(f_Alti_Cible - f_Alti_Ref))),float((g*M)/(R*Lb))); 
		this->af_PressionDP[i] = this->af_PressionDP[i] * rapportAlti ;
		this->af_PuissanceP[i] = this->af_PuissanceP[i] * rapportAlti ;
	}
}
void CDonnes::CDonnes_Calcul_Altitude_RPM_libre(const float f_Alti_Cible)
{
	float rapportAlti2;
	// Constantes
	float Lb = -0.0065; // K°/m
	//float R = 8.31; // N.m/(mol.K°)
	//float M = 0.0289644; // kg/mol
	//float g = 9.81; // N.m
	int f_Alti_Ref = 134; // m (altitude ECOFIT)
	float Patm_ref = 101325; // Pa
	float Patm_h1; //Pa
	float temp_ref = 288.15; //°K = 15°C

	Patm_h1 = Patm_ref * pow (float(1-((Lb*f_Alti_Cible)/temp_ref)),float(5.255));

	for(int i = 0;i < this->n_NbPts;i++)
	{
		if(this->af_Temperature == NULL) // essai version 2004
			rapportAlti2 = (((293.15) + Lb * (f_Alti_Cible - f_Alti_Ref))/(293.15))*(Patm_ref / (this->af_PressionDP[i] + Patm_h1)); // temp = 20°C
		else	// essai version 2010
			rapportAlti2 = (((this->af_Temperature[i]+273.15) + Lb * (f_Alti_Cible - f_Alti_Ref))/(this->af_Temperature[i]+273.15))*(Patm_ref / (this->af_PressionDP[i] + Patm_h1));
		
		this->af_DebitQ[i] = this->af_DebitQ[i] * rapportAlti2 ;
		this->af_VitesseRPM[i] = this->af_VitesseRPM[i] * rapportAlti2 ;
		
	}
}

void CDonnes::CDonnes_Convertion_Debit(const float rapport)
{
	for(int i = 0;i < this->n_NbPts;i++)
		this->af_DebitQ[i] = this->af_DebitQ[i] * rapport;

}
void CDonnes::CDonnes_Convertion_Pression(const float rapport)
{
	for(int i = 0;i < this->n_NbPts;i++)
		this->af_PressionDP[i] = this->af_PressionDP[i] * rapport;
}
void CDonnes::CDonnes_Convertion_Vitesse(const float rapport)
{
	for(int i = 0;i < this->n_NbPts;i++)
		this->af_VitesseRPM[i] = this->af_VitesseRPM[i] * rapport;
}