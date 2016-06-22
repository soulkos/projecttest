#include "stdafx.h"
#include "Donnes.h"

#pragma once
class CBlockMesure
{
public:
	CDonnes m_Mesures;

	//CFormatExcel m_FormatMesure
	int m_nDebutMesure;
	int m_nNbPts;

	CString m_szDescription;
	
	/*CString m_fTensionAlim;
	CString m_fFrequence; //AC
	CString m_fOption; //capa (AC),tension commande (EC,DC)*/

	

public:
	CBlockMesure(void);
	virtual ~CBlockMesure(void);
	CBlockMesure(const CBlockMesure & bloc);
	CBlockMesure& operator=(const CBlockMesure & bloc);
	//Accessors
	void SetNbpts(int nbpts);
	void SetLigneDebut(int lignedeb);
	void SetDescription(CString str);
	int GetNbpts();
	int GetLigneDebut();
	CString GetDescription();

};

