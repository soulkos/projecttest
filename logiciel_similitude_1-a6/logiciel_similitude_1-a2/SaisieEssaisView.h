#pragma once
#include "afxwin.h"
#include "stdafx.h"
#include "OLEDBExcel.h"




// Mode formulaire CSaisieEssaisView

class CSaisieEssaisView : public CFormView
{
	DECLARE_DYNCREATE(CSaisieEssaisView)

public:
	CSaisieEssaisView();           // constructeur protégé utilisé par la création dynamique
	virtual ~CSaisieEssaisView();
	COLEDBExcel ole;

public:
	enum { IDD = IDD_SAISIEESSAISVIEW };

	virtual void OnFinalRelease();
#ifdef _DEBUG
	virtual void AssertValid() const;
	/*inline Clogiciel_similitude_1a2Doc* CSaisieEssaisView::GetDocument() const
   { return reinterpret_cast<Clogiciel_similitude_1a2Doc*>(m_pDocument); }*/
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
public:
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	// recuperation de la possibilité de pilotage en vitesse du moteur
	CButton m_PilotageVitesse;
	// recuperation du nom de la feuille de reference
	CComboBox m_NomFeuilleRef;
	// recuperation du nom de la feuille contenant les mesurs
	CComboBox m_NomFeuilleMesure;
	// Recuperation de la version du fichier pour l'extraction des données
	CComboBox m_VersionFichier;
	// affichage du chemin apres slection 
	CString m_strCheminFichier;
	// gestion de la editbox pour le nom de fichier
	CEdit m_CheminFichier;
	CEdit m_Nbpts50hz;
	CEdit m_LigneDeb50Hz;
	CEdit m_LigneDeb60Hz;
	CEdit m_Nbpts60Hz;
	// // recuperation de le reference du produit
	CEdit m_RefProduit;
	// Liste de selection du type de moteur
	CComboBox m_TypeMoteur;
	// Boutons de selection des series de mesures
	CButton m_BlocMesure1;
	CButton m_BlocMesure2;
	CButton m_BlocMesure3;
	CButton m_BlocMesure4;
	CButton m_BlocMesure5;
	CButton m_BlocMesure6;
	CButton m_BlocMesure7;
	CButton m_BlocMesure8;
	CButton m_BlocMesure9;
	CButton m_BlocMesure10;
	CButton m_BlocMesure11;
	CButton m_BlocMesure12;
	CButton m_BlocMesure13;
	CButton m_BlocMesure14;
	CButton m_BlocMesure15;
	CButton m_BlocMesure16;
};


