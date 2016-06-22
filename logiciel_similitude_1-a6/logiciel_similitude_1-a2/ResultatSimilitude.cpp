#include "StdAfx.h"

#include "ResultatSimilitude.h"
#include "logiciel_similitude_1-a2.h"
#include "logiciel_similitude_1-a2Doc.h"

#include "Protocole_Automation_EXCEL.h"




CResultatSimilitude::CResultatSimilitude(void)
{
	this->f_AltitudeUtili =0;
	this->f_RPMcible =0;
	this->f_Qcible =0;
	this->f_Qintersec =0;
	this->f_DPcible =0;
	this->f_RapportSimilitude =0 ;
	this->m_nUniteDebit = -1;
	this->m_nUnitePression = -1;
	this->m_nUniteVitesse = -1;
}

CResultatSimilitude::~CResultatSimilitude(void)
{
}
 CResultatSimilitude::CResultatSimilitude(const CResultatSimilitude & result)
{
	this->sz_RefProduit = result.sz_RefProduit;
	this->n_IdFreq = result.n_IdFreq;
	this->CDonnes_ResultatSimilitude = result.CDonnes_ResultatSimilitude;
	this->CDonnes_Originales = result.CDonnes_Originales;
	this->f_AltitudeUtili = result.f_AltitudeUtili;
	this->f_RPMcible = result.f_RPMcible;
	this->f_Qcible = result.f_DPcible;
	this->f_Qintersec = result.f_Qintersec;
	this->f_DPcible = result.f_DPcible;
	this->f_RapportSimilitude = result.f_RapportSimilitude;
	this->m_nUniteDebit = result.m_nUniteDebit;
	this->m_nUnitePression = result.m_nUnitePression;
	this->m_nUniteVitesse = result.m_nUniteVitesse;
}
CResultatSimilitude & CResultatSimilitude::operator =(const CResultatSimilitude & result)
{
	this->sz_RefProduit = result.sz_RefProduit;
	this->n_IdFreq = result.n_IdFreq;
	this->CDonnes_ResultatSimilitude = result.CDonnes_ResultatSimilitude;
	this->CDonnes_Originales = result.CDonnes_Originales;
	this->f_AltitudeUtili = result.f_AltitudeUtili;
	this->f_RPMcible = result.f_RPMcible;
	this->f_Qcible = result.f_DPcible;
	this->f_Qintersec = result.f_Qintersec;
	this->f_DPcible = result.f_DPcible;
	this->f_RapportSimilitude = result.f_RapportSimilitude;
	this->m_nUniteDebit = result.m_nUniteDebit;
	this->m_nUnitePression = result.m_nUnitePression;
	this->m_nUniteVitesse = result.m_nUniteVitesse;


	return *this;
}

void CResultatSimilitude::SetRefProduit(const CString sz)
{
	this->sz_RefProduit = sz;
}
CString CResultatSimilitude::GetRefProduit()
{
	return this->sz_RefProduit;
}
void CResultatSimilitude::SetDescription(const CString sz)
{
	this->m_szDescription = sz;
}
CString CResultatSimilitude::GetDescription()
{
	return this->m_szDescription ;
}

void CResultatSimilitude::SetFreq(const frequence freq)
{
	this->n_IdFreq = freq;
}
frequence CResultatSimilitude::GetFreq()
{
	return this->n_IdFreq;
}

void CResultatSimilitude::SetAltiUtili(const float alti)
{
	this->f_AltitudeUtili = alti;
}
float CResultatSimilitude::GetAltiUtili()
{
	return this->f_AltitudeUtili;
}

void CResultatSimilitude::SetRPM(const float vitesse)
{
	this->f_RPMcible = vitesse;
}
float CResultatSimilitude::GetRPM()
{
	return this->f_RPMcible;
}

void CResultatSimilitude::SetDebit(const float debit)
{
	this->f_Qcible = debit;
}
float CResultatSimilitude::GetDebit()
{
	return this->f_Qcible;
}

void CResultatSimilitude::SetPression(const float pression)
{
	this->f_DPcible = pression;
}
float CResultatSimilitude::GetPression()
{
	return this->f_DPcible;
}

float CResultatSimilitude::GetRapportSimilitude()
{
	return this->f_RapportSimilitude;
}

int CResultatSimilitude::GetUniteDebit()
{
	return this->m_nUniteDebit;
}
void CResultatSimilitude::SetUniteDebit(int u)
{
	this->m_nUniteDebit = u;
}
int CResultatSimilitude::GetUnitePression()
{
	return this->m_nUnitePression;
}
void CResultatSimilitude::SetUnitePression(int u)
{
	this->m_nUnitePression = u;
}
int CResultatSimilitude::GetUniteVitesse()
{
	return this->m_nUniteVitesse;
}
void CResultatSimilitude::SetUniteVitesse(int u)
{
	this->m_nUniteVitesse = u;
}



void CResultatSimilitude::Exportation_Excel()
{
	
// Commonly used OLE variants.
	COleVariant
      covTrue((short)TRUE),
      covFalse((short)FALSE),
      covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);
	
	CApplication app;
	app =InitApplication();

	CWorkbook book;
	book =CreationBook(app);

	CWorksheet sheet;
	sheet = CreationEntete(book,this->m_nUniteDebit,this->m_nUnitePression,this->m_nUniteVitesse);
 
	// remplissage
	
	//resultat similitude
	RemplissageTableau(sheet,this->CDonnes_ResultatSimilitude.GetDebit(),this->CDonnes_ResultatSimilitude.GetNbPts(),"B12"); // tab debit resultant

	RemplissageTableau(sheet,this->CDonnes_ResultatSimilitude.GetPression(),this->CDonnes_ResultatSimilitude.GetNbPts(),"C12"); // tab pression resultant

	RemplissageTableau(sheet,this->CDonnes_ResultatSimilitude.GetVitesse(),this->CDonnes_ResultatSimilitude.GetNbPts(),"D12");	// tab vitesse resultante

	RemplissageTableau(sheet,this->CDonnes_ResultatSimilitude.GetPuissance(),this->CDonnes_ResultatSimilitude.GetNbPts(),"E12");	// tab puissance resultante

	//resultat originaux
	RemplissageTableau(sheet,this->CDonnes_Originales.GetDebit(),this->CDonnes_Originales.GetNbPts(),"G12"); // tab debit resultant

	RemplissageTableau(sheet,this->CDonnes_Originales.GetPression(),this->CDonnes_Originales.GetNbPts(),"H12"); // tab pression resultant

	RemplissageTableau(sheet,this->CDonnes_Originales.GetVitesse(),this->CDonnes_Originales.GetNbPts(),"I12");	// tab vitesse resultante

	RemplissageTableau(sheet,this->CDonnes_Originales.GetPuissance(),this->CDonnes_Originales.GetNbPts(),"J12");	// tab puissance resultante


	RemplissageCellule(sheet,this->f_RPMcible,"E3"); // vitesse de commande

	RemplissageCellule(sheet,this->f_Qcible,"E4");	//Debit cible

	RemplissageCellule(sheet,this->f_DPcible,"E5"); // Pression cible

	RemplissageCellule(sheet,"","E6"); // puissance resultante option
	USES_CONVERSION;
	RemplissageCellule(sheet,W2A(this->sz_RefProduit),"B2"); // reference produit

	RemplissageCellule(sheet,W2A(this->m_szDescription),"B4");

	/*if (this->n_IdFreq == f50Hz)	// frequence d'utilisation
		RemplissageCellule(sheet,"50Hz","B4");
	else
		RemplissageCellule(sheet,"60Hz","B4");*/

	RemplissageCellule(sheet,this->f_AltitudeUtili,"B6"); // altitude d'utilisation

	
   app.put_Visible(TRUE);
   app.put_UserControl(TRUE);
   sheet.ReleaseDispatch();
   //app.Quit();
// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}

void CResultatSimilitude::Recuperation_Donnes_Pour_Calcul(CDonnes Essai)  // a suppr  ????
{
	//Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument());
	this->CDonnes_ResultatSimilitude = (Essai);
	this->CDonnes_Originales = (Essai);
}
void CResultatSimilitude::Conversion_des_donnees(int CvDebit,int CvPression,int CvVitesse)
{
	switch(CvDebit)
	{
	case 0: // m3/h -> m3/h
		//this->CDonnes_ResultatSimilitude.CDonnes_Convertion_Debit(1);
		//this->CDonnes_Originales.CDonnes_Convertion_Debit(1);
		break;
	case 1: // m3/h -> m3/s 0.0002777778
		this->CDonnes_ResultatSimilitude.CDonnes_Convertion_Debit(0.0002777778);
		this->CDonnes_Originales.CDonnes_Convertion_Debit(0.0002777778);
		break;
	case 2: // m3/h -> l/s  0.277778
		this->CDonnes_ResultatSimilitude.CDonnes_Convertion_Debit(0.277778);
		this->CDonnes_Originales.CDonnes_Convertion_Debit(0.277778);
		break;
	case 3: // m3/h -> cf/m 0.588578
		this->CDonnes_ResultatSimilitude.CDonnes_Convertion_Debit(0.588578);
		this->CDonnes_Originales.CDonnes_Convertion_Debit(0.588578);
		break;
	default:
		// aucune conversion
		break;
	}

	switch(CvPression)
	{
	case 0: //Pa -> Pa
		//this->CDonnes_ResultatSimilitude.CDonnes_Convertion_Pression(1);
		//this->CDonnes_Originales.CDonnes_Convertion_Pression(1);
		break;
	case 1: // Pa-> Psi 0.000145038
		this->CDonnes_ResultatSimilitude.CDonnes_Convertion_Pression(0.000145038);
		this->CDonnes_Originales.CDonnes_Convertion_Pression(0.000145038);
		break;
	case 2: // Pa-> mmEau 0.101974
		this->CDonnes_ResultatSimilitude.CDonnes_Convertion_Pression(0.101974);
		this->CDonnes_Originales.CDonnes_Convertion_Pression(0.101974);
		break;
	case 3: // Pa-> inWater 0.004014742
		this->CDonnes_ResultatSimilitude.CDonnes_Convertion_Pression(0.004014742);
		this->CDonnes_Originales.CDonnes_Convertion_Pression(0.004014742);
		break;
	default:
		// aucune conversion
		break;
	}
	switch(CvVitesse)
	{
	case 0: // Rpm
		//this->CDonnes_ResultatSimilitude.CDonnes_Convertion_Vitesse(1);
		//this->CDonnes_Originales.CDonnes_Convertion_Vitesse(1);
		break;
	/*case 1: // Rpm -> rad/s 0.10472
		this->CDonnes_ResultatSimilitude.CDonnes_Convertion_Vitesse(0.10472);
		this->CDonnes_Originales.CDonnes_Convertion_Vitesse(0.10472);
		break;*/
	case 1: // tr/min
		this->CDonnes_ResultatSimilitude.CDonnes_Convertion_Vitesse(1);
		this->CDonnes_Originales.CDonnes_Convertion_Vitesse(1);
		break;
	default:
		// aucune conversion
		break;
	}

}


float CResultatSimilitude::Calcul_Debit_Intersec()
{

// calcul du coefficient c de l'equation DP = c* Qv²

	float f_c = this->f_DPcible / (this->f_Qcible * this->f_Qcible);

// recherche de l'intersection entre la courbe DP = c * Qv² et la courbe experimental DPventi = f(Qv) etre les abcisse A et  B

	float f_a; // a =( Yb-Ya) /(Xa -Xb)
	float f_b; // b= (Yb- a*Xb)
	float f_xa,f_xb,f_ya,f_yb,f_yc,f_yd; // Yc= c * Xa² | Yd = c * Xb²

	float f_delta; // = a²+4*c*b
	float f_root1,f_root2;// = (-a +- sqrt(delta)) / -2c

	for(int i = 0; i <( this->CDonnes_ResultatSimilitude.GetNbPts() - 1) ; i++)
	{
		// recuperation des x
		f_xa=this->CDonnes_ResultatSimilitude.af_DebitQ[i];
		f_xb=this->CDonnes_ResultatSimilitude.af_DebitQ[i+1];

		// reucperation est calcul des y
		f_ya = this->CDonnes_ResultatSimilitude.af_PressionDP[i];
		f_yb = this->CDonnes_ResultatSimilitude.af_PressionDP[i+1];

		f_yc = f_xa* f_xa * f_c ;
		f_yd = f_xb * f_xb *f_c;
		
		f_a = (f_yb-f_ya) / (f_xb-f_xa);
		f_b = f_yb -( f_a * f_xb);
		// test de l'intersection des deux courbes
		if(((f_ya >= f_yc) && (f_yd >= f_yb))||((f_yc >= f_ya) && (f_yb >= f_yd)))
		{
			// resolution de l'equation ax+b-cx² = 0

			// calcul du delta
			f_delta = f_a * f_a + (4 * f_b* f_c);
			
			// calcul des racines
			f_root1 = (- f_a + sqrt(f_delta)) /( -2 * f_c);
			f_root2 = (- f_a - sqrt(f_delta)) /( -2 * f_c);

			// test de la racine a renvoyé

			if( (f_xa < f_root1) && (f_xb > f_root1))
			{
				this->f_Qintersec = f_root1;
				return (f_root1) ;
			}
			else
			{
				this->f_Qintersec = f_root2;
				return (f_root2) ;
			}
		}

	}
	return 0;

}

float CResultatSimilitude::Calcul_Vitesse_Commande()
{
// recherche de l'intersection entre la courbe experimental RPMventi = f(Qv) et le debit initiale etre les abcisse A et  B

	float f_a; // a =( Yb-Ya) /(Xa -Xb)
	float f_b; // b= (Yb- a*Xb)

	float f_xa,f_xb,f_ya,f_yb;

	for(int i = 0; i <( this->CDonnes_ResultatSimilitude.GetNbPts() - 1) ; i++)
	{
		// recuperation des x
		f_xa=this->CDonnes_ResultatSimilitude.af_DebitQ[i] * this->f_RapportSimilitude;
		f_xb=this->CDonnes_ResultatSimilitude.af_DebitQ[i+1] * this->f_RapportSimilitude;
		// reucperation est calcul des y
		f_ya = this->CDonnes_ResultatSimilitude.af_VitesseRPM[i] * this->f_RapportSimilitude ;
		f_yb = this->CDonnes_ResultatSimilitude.af_VitesseRPM[i+1] * this->f_RapportSimilitude ;

		if ( (f_xa <= this->f_Qintersec) && (f_xb >= this->f_Qintersec))
		{
			f_a = (f_yb-f_ya) / (f_xb-f_xa);
			f_b = f_yb -( f_a * f_xb);
			
			this->f_RPMcible = (((f_a * this->f_Qintersec) + f_b)/**(this->f_Qcible / this->f_Qintersec))*/);
			return (((f_a * this->f_Qintersec) + f_b)*(this->f_Qcible / this->f_Qintersec));

		}
	}
	return 0;
}
float CResultatSimilitude::Calcul_Rapport_Simi()
{
	this->f_RapportSimilitude = (this->f_Qcible / this->f_Qintersec);
	return (this->f_Qcible / this->f_Qintersec);
}
float CResultatSimilitude::Calcul_Rapport_Simi_Debit_Nul()
{
	this->f_RapportSimilitude = sqrt(this->f_DPcible / this->CDonnes_ResultatSimilitude.af_PressionDP[0]);
	this->f_Qintersec = 0;
	return sqrt(this->f_DPcible / this->CDonnes_ResultatSimilitude.af_PressionDP[0]);
}
float CResultatSimilitude::Calcul_Rapport_Simi_Pression_Nulle()
{
	this->f_RapportSimilitude = (this->f_Qcible / this->CDonnes_ResultatSimilitude.af_DebitQ[this->CDonnes_ResultatSimilitude.GetNbPts() - 1 ]);
	this->f_Qintersec = this->CDonnes_ResultatSimilitude.af_DebitQ[this->CDonnes_ResultatSimilitude.GetNbPts() - 1 ];
	return (this->f_Qcible / this->CDonnes_ResultatSimilitude.af_DebitQ[this->CDonnes_ResultatSimilitude.GetNbPts() - 1 ]);
}

void CResultatSimilitude::Calcul_Altitude_RPMcst()
{
	this->CDonnes_ResultatSimilitude.CDonnes_Calcul_Altitude_RPM_cst(this->GetAltiUtili());
}

void CResultatSimilitude::Calcul_Altitude_RPMvar()
{
	this->CDonnes_ResultatSimilitude.CDonnes_Calcul_Altitude_RPM_libre(this->GetAltiUtili());
}

void CResultatSimilitude::Calcul_Simi()
{
	this->CDonnes_ResultatSimilitude.CDonnes_Calcul_Similitude(this->GetRapportSimilitude());
}
void CResultatSimilitude::Calcul_Simi_RPM()
{
	this->CDonnes_ResultatSimilitude.CDonnes_Calcul_Similitude_Vitesse_cible(this->GetRPM());
}