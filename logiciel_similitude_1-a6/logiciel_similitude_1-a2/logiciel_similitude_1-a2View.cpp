
// logiciel_similitude_1-a2View.cpp : implémentation de la classe Clogiciel_similitude_1a2View
//

#include "stdafx.h"
// SHARED_HANDLERS peuvent être définis dans les gestionnaires d'aperçu, de miniature
// et de recherche d'implémentation de projet ATL et permettent la partage de code de document avec ce projet.
#ifndef SHARED_HANDLERS
#include "logiciel_similitude_1-a2.h"
#endif

#include "logiciel_similitude_1-a2Doc.h"
#include "logiciel_similitude_1-a2View.h"
#include "InterfaceSimilitudeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clogiciel_similitude_1a2View

IMPLEMENT_DYNCREATE(Clogiciel_similitude_1a2View, CFormView)

BEGIN_MESSAGE_MAP(Clogiciel_similitude_1a2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &Clogiciel_similitude_1a2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Clogiciel_similitude_1a2View::OnBnClickedButton2)
END_MESSAGE_MAP()

// construction ou destruction de Clogiciel_similitude_1a2View

Clogiciel_similitude_1a2View::Clogiciel_similitude_1a2View()
	: CFormView(Clogiciel_similitude_1a2View::IDD)
{
	// TODO: ajoutez ici du code de construction

}

Clogiciel_similitude_1a2View::~Clogiciel_similitude_1a2View()
{
}

void Clogiciel_similitude_1a2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL Clogiciel_similitude_1a2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: changez ici la classe ou les styles Window en modifiant
	//  CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void Clogiciel_similitude_1a2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// diagnostics pour Clogiciel_similitude_1a2View

#ifdef _DEBUG
void Clogiciel_similitude_1a2View::AssertValid() const
{
	CFormView::AssertValid();
}

void Clogiciel_similitude_1a2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Clogiciel_similitude_1a2Doc* Clogiciel_similitude_1a2View::GetDocument() const // la version non Debug est inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clogiciel_similitude_1a2Doc)));
	return (Clogiciel_similitude_1a2Doc*)m_pDocument;
}
#endif //_DEBUG


// gestionnaires de messages pour Clogiciel_similitude_1a2View


void Clogiciel_similitude_1a2View::OnBnClickedButton1()// ouverture de l'interface d'ajout d'essais
{
	/*Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument());
	pDoc->m_CBDDEssais_BDDLocal.Chargement_BDDfichier_to_BDDlocal();*/

	theApp.SwitchViewSaisie();
	// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}

void Clogiciel_similitude_1a2View::OnBnClickedButton2() // ouverture du l'interface de calcul de similitude
{
	Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument());
	
	/*char temp[256];
	USES_CONVERSION;
	LPWSTR tmp = A2W(temp);

	GetPrivateProfileString(L"CHEMIN",L"Cle",L"err",tmp,255,L"D:\\Cours ENIVL\\Stage ECOFIT\\Logiciel\\initBDD.ini");
	pDoc->m_CBDDEssais_BDDLocal.SetChemin(CString(tmp));
	GetPrivateProfileString(L"TAILLE",L"Cle",L"err",tmp,255,L"D:\\Cours ENIVL\\Stage ECOFIT\\Logiciel\\initBDD.ini");
	pDoc->m_CBDDEssais_BDDLocal.SetTaille(_wtoi(CString(tmp)));
	this->m_CBDDEssais_BDDLocal.Chargement_BDDfichier_to_BDDlocal();
	*/
	//Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument());

	//pDoc->m_CBDDEssais_BDDLocal.SetChemin(L"D:\\Cours ENIVL\\Stage ECOFIT\\Logiciel\\BDDEssaisVentilateur.xls");
	//pDoc->m_CBDDEssais_BDDLocal.SetTaille(10);
	pDoc->m_CBDDEssais_BDDLocal.Chargement_BDDfichier_to_BDDlocal();

	theApp.SwitchViewSimilitude();// TODO: ajoutez ici le code de votre gestionnaire de notification de contrôle
}
