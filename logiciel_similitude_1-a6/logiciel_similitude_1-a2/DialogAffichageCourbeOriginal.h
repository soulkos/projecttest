#include "stdafx.h"
#include "resource.h"
#include "Graph.h"

#pragma once


// Boîte de dialogue CDialogAffichageCourbeOriginal

class CDialogAffichageCourbeOriginal : public CDialog
{
	DECLARE_DYNAMIC(CDialogAffichageCourbeOriginal)
public:
	CGraph* m_CGraph_CourbeOriginal;
	BOOL m_graphComplete;
	CDC* pDC;

public:
	CDialogAffichageCourbeOriginal(CWnd* pParent = NULL);   // constructeur standard
	virtual ~CDialogAffichageCourbeOriginal();

	void CopieGraph(CGraph* m_CGraph,BOOL graphComplete);
	//BOOL OnInitDialog();
// Données de boîte de dialogue
	enum { IDD = IDD_DIALOGAFFICHAGECOURBEORIGINAL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
};
