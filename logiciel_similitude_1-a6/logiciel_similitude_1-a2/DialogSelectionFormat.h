#include "stdafx.h"
#include "resource.h"

#pragma once


// Bo�te de dialogue CDialogSelectionFormat

class CDialogSelectionFormat : public CDialog
{
	DECLARE_DYNAMIC(CDialogSelectionFormat)

public:
	CDialogSelectionFormat(CWnd* pParent = NULL);   // constructeur standard
	virtual ~CDialogSelectionFormat();

// Donn�es de bo�te de dialogue
	enum { IDD = IDD_DIALOGSELECTIONFORMAT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

	DECLARE_MESSAGE_MAP()
};
