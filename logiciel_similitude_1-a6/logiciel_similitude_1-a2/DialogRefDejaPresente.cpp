// DialogRefDejaPresente.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "DialogRefDejaPresente.h"
#include "afxdialogex.h"


// Boîte de dialogue CDialogRefDejaPresente

IMPLEMENT_DYNAMIC(CDialogRefDejaPresente, CDialog)

CDialogRefDejaPresente::CDialogRefDejaPresente(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogRefDejaPresente::IDD, pParent)
	, m_StrDiag(_T(""))
{

}

CDialogRefDejaPresente::~CDialogRefDejaPresente()
{
}

void CDialogRefDejaPresente::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_DIAG, m_StrDiag);
}


BEGIN_MESSAGE_MAP(CDialogRefDejaPresente, CDialog)
END_MESSAGE_MAP()


// Gestionnaires de messages de CDialogRefDejaPresente

void CDialogRefDejaPresente::SetString(CString sz)
{
	this->m_StrDiag = sz;
}
