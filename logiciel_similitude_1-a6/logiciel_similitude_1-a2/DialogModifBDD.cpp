// DialogModifBDD.cpp�: fichier d'impl�mentation
//

#include "stdafx.h"
#include "DialogModifBDD.h"
#include "afxdialogex.h"


// Bo�te de dialogue CDialogModifBDD

IMPLEMENT_DYNAMIC(CDialogModifBDD, CDialogEx)

CDialogModifBDD::CDialogModifBDD(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialogModifBDD::IDD, pParent)
{

}

CDialogModifBDD::~CDialogModifBDD()
{
}

void CDialogModifBDD::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogModifBDD, CDialogEx)
END_MESSAGE_MAP()


// Gestionnaires de messages de CDialogModifBDD
