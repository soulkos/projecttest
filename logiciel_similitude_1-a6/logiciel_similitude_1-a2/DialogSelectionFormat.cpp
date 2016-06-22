// DialogSelectionFormat.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "DialogSelectionFormat.h"
#include "afxdialogex.h"


// Boîte de dialogue CDialogSelectionFormat

IMPLEMENT_DYNAMIC(CDialogSelectionFormat, CDialog)

CDialogSelectionFormat::CDialogSelectionFormat(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogSelectionFormat::IDD, pParent)
{

}

CDialogSelectionFormat::~CDialogSelectionFormat()
{
}

void CDialogSelectionFormat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogSelectionFormat, CDialog)
END_MESSAGE_MAP()


// Gestionnaires de messages de CDialogSelectionFormat
