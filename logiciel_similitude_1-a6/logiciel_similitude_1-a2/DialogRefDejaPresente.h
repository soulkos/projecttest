#include "stdafx.h"
#include "resource.h"
#pragma once


// Bo�te de dialogue CDialogRefDejaPresente

class CDialogRefDejaPresente : public CDialog
{
	DECLARE_DYNAMIC(CDialogRefDejaPresente)

public:
	CDialogRefDejaPresente(CWnd* pParent = NULL);   // constructeur standard
	virtual ~CDialogRefDejaPresente();

	void SetString(CString sz);

// Donn�es de bo�te de dialogue
	enum { IDD = IDD_DIALOGREFDEJAPRESENTE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	// Variable de gestion du texte de la fenetre de dialogue
	CString m_StrDiag;
};
