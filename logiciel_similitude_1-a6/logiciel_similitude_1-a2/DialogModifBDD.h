#include "stdafx.h"
#include "resource.h"
#pragma once


// Boîte de dialogue CDialogModifBDD

class CDialogModifBDD : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogModifBDD)

public:
	CDialogModifBDD(CWnd* pParent = NULL);   // constructeur standard
	virtual ~CDialogModifBDD();

// Données de boîte de dialogue
	enum { IDD = IDD_DIALOGMODIFBDD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
};
