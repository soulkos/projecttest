// DialogAffichageCourbeOriginal.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "DialogAffichageCourbeOriginal.h"
#include "logiciel_similitude_1-a2.h"
#include "logiciel_similitude_1-a2Doc.h"
#include "afxdialogex.h"


// Boîte de dialogue CDialogAffichageCourbeOriginal

IMPLEMENT_DYNAMIC(CDialogAffichageCourbeOriginal, CDialog)

CDialogAffichageCourbeOriginal::CDialogAffichageCourbeOriginal(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogAffichageCourbeOriginal::IDD, pParent)
{
	


}

CDialogAffichageCourbeOriginal::~CDialogAffichageCourbeOriginal()
{
}

void CDialogAffichageCourbeOriginal::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}
/*BOOL CDialogAffichageCourbeOriginal::OnInitDialog()
{
	

	return TRUE;
}*/


BEGIN_MESSAGE_MAP(CDialogAffichageCourbeOriginal, CDialog)
END_MESSAGE_MAP()


// Gestionnaires de messages de CDialogAffichageCourbeOriginal
void CDialogAffichageCourbeOriginal::CopieGraph(CGraph* m_CGraph,BOOL graphComplete)
{
	m_CGraph_CourbeOriginal = m_CGraph;
	m_graphComplete = graphComplete;
	if(this->m_graphComplete)
		this->m_CGraph_CourbeOriginal->DrawGraph(pDC,0,0,480,380);
	UpdateWindow();

}