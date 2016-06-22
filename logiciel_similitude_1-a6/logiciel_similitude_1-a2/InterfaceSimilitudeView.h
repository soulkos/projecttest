#pragma once
#include "afxwin.h"



// Mode formulaire CInterfaceSimilitudeView

class CInterfaceSimilitudeView : public CFormView
{
	DECLARE_DYNCREATE(CInterfaceSimilitudeView)
public:
	CGraph* m_testGraph;
	BOOL m_graphComplete;
public:
	CInterfaceSimilitudeView();           // constructeur protégé utilisé par la création dynamique
	virtual ~CInterfaceSimilitudeView();
	void InitListRef();
	void OnDraw(CDC* pDC);

public:
	enum { IDD = IDD_INTERFACESIMILITUDEVIEW };

	virtual void OnFinalRelease();
#ifdef _DEBUG
	virtual void AssertValid() const;
	/*inline Clogiciel_similitude_1a2Doc* CInterfaceSimilitudeView::GetDocument() const
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButtoncalcul();
	// defini le type du calcul en fonction de l'etape du groupe de pRadio
	int m_nTypeCalcul;
	// initialisation de la combobak
	BOOL m_nInitCombo;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio3();

	// permet l'application d'un variation d'altitude en plus d'une variation par point cible ou vitesse cible
	CButton m_VariationAlti_RPM;
	// Recuperation du débit cible entré par l'utilisateur
	CEdit m_DebitCible;
	// Recuperation de la pression cible defini par l'utilisateur
	CEdit m_PressionCible;
	// Recuperation de la commande de vitesse defini par l'utilisateur
	CEdit m_VitesseCible;
	// Recyuperzation de l'altitude cible pour la variation simple defini par l'utilisateur
	CEdit m_AltitudeCible;
	// Recuperation de l'altitude cible definbi par l'utilisateur dans une variation composé 
	CEdit m_AltitudeCible_RPM;
	// recuperation de la frequence d'utilisation du moteur
	CComboBox m_FreqUtili;
	// Recuperation de la reference du ventilateur a extrapolé
	CComboBox m_RefVentilateur;
	// option de variation d'altitude pour le choix d'un pts d'utilisation donné
	CButton m_VariationAlti_Pts;
	// valeur de l'altitude cible dans l'option Pts utli + altitude
	CEdit m_AltitudeCible_Pts;
	// recherche d'un pts cible apres lissage en vitesse du ventilateur
	CButton m_PtsUtili_RPM;
	CEdit m_DebitCible_RPM;
	CEdit m_PressionCible_RPM;
	afx_msg void OnCbnSetfocusCombo1();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnKillfocusCombo1();
	afx_msg void OnCbnSelchangeCombo2();
	CComboBox m_UniteDebit1;
	CComboBox m_UniteDebitRPM;
	CComboBox m_UnitePression1;
	CComboBox m_UnitePressionRPM;
	CComboBox m_UniteRPM;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};


