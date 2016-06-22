#pragma once
#include "afxwin.h"



// Mode formulaire CAffChartsView

class CAffChartsView : public CFormView
{
	DECLARE_DYNCREATE(CAffChartsView)

public:
	CAffChartsView();           // constructeur protégé utilisé par la création dynamique
	virtual ~CAffChartsView();

public:
	enum { IDD = IDD_AFFCHARTSVIEW };

	BOOL m_nStatutExportation;
	CGraph* m_testGraph;
	BOOL m_graphComplete;

	virtual void OnFinalRelease();
#ifdef _DEBUG
	virtual void AssertValid() const;
	/*inline Clogiciel_similitude_1a2Doc* CAffChartsView::GetDocument() const
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
	afx_msg void OnButtoncalcul();
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButtonPrec();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButtonExport();

	// Affichagre du débit resultant
	CEdit m_DebitResult;
	// Afichage de la pression résultante
	CEdit m_PressionResult;
	// Affichage de la vitesse à appliqué au moteur
	CEdit m_VitesseResult;
	// Affichage de l'altitude d'utilisation
	CEdit m_AltitudeResult;
	// Affichage de la frequence d'utilisation du moteur
	CEdit m_FreqResult;
};


