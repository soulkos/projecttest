// AffChartsView.cpp : fichier d'implémentation
//

#include "stdafx.h"
#include "logiciel_similitude_1-a2.h"
#include "logiciel_similitude_1-a2Doc.h"
#include "AffChartsView.h"


#include "Graph.h"
#include "GraphSeries.h"




// CAffChartsView

IMPLEMENT_DYNCREATE(CAffChartsView, CFormView)

CAffChartsView::CAffChartsView()
	: CFormView(CAffChartsView::IDD)
{
	m_nStatutExportation = TRUE;
	m_graphComplete = FALSE;
	EnableAutomation();
}

CAffChartsView::~CAffChartsView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CTestdrawView drawing

void CAffChartsView::OnDraw(CDC* pDC)
{
	Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument());
	m_testGraph = pDoc->m_CGraph_testGraph;
	m_graphComplete = pDoc->m_BOOL_graphComplete;

	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	
	
	if(m_graphComplete)
	{
		CString temp;

		temp.Format(_T("%f"),( pDoc->m_CResltSimi_CalculSimilitude.GetDebit()));
		this->m_DebitResult.SetWindowTextW(temp);
		temp.Format(_T("%f"),( pDoc->m_CResltSimi_CalculSimilitude.GetPression()));
		this->m_PressionResult.SetWindowTextW(temp);
		temp.Format(_T("%f"),( pDoc->m_CResltSimi_CalculSimilitude.GetRPM()));
		this->m_VitesseResult.SetWindowTextW(temp);
		temp.Format(_T("%d"),int( pDoc->m_CResltSimi_CalculSimilitude.GetAltiUtili()));
		this->m_AltitudeResult.SetWindowTextW(temp);
		m_testGraph->DrawGraph(pDC,25,35,730,500); //480;380
		UpdateWindow();
	}

}



void CAffChartsView::OnFinalRelease()
{
	// Lorsque la dernière référence pour un objet automation est libérée
	// OnFinalRelease est appelé. La classe de base supprime automatiquement
	// l'objet. Un nettoyage supplémentaire est requis pour votre
	// objet avant d'appeler la classe de base.

	CFormView::OnFinalRelease();
}

void CAffChartsView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT1, m_strDebitResult);
	//  DDX_Text(pDX, IDC_EDIT3, m_strPressionResult);
	//  DDX_Text(pDX, IDC_EDIT4, m_strVitesseResult);
	//  DDX_Text(pDX, IDC_EDIT5, m_strAltitudeResult);
	//  DDX_Text(pDX, IDC_EDIT2, m_strFreqResult);
	DDX_Control(pDX, IDC_EDIT1, m_DebitResult);
	DDX_Control(pDX, IDC_EDIT3, m_PressionResult);
	DDX_Control(pDX, IDC_EDIT4, m_VitesseResult);
	DDX_Control(pDX, IDC_EDIT5, m_AltitudeResult);
	DDX_Control(pDX, IDC_EDIT2, m_FreqResult);
}

BEGIN_MESSAGE_MAP(CAffChartsView, CFormView)
	ON_COMMAND(IDC_BUTTONCALCUL, &CAffChartsView::OnButtoncalcul)
	ON_BN_CLICKED(IDC_BUTTON1, &CAffChartsView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CAffChartsView::OnBnClickedButtonPrec)
	ON_BN_CLICKED(IDC_BUTTON4, &CAffChartsView::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CAffChartsView::OnBnClickedButtonExport)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CAffChartsView, CFormView)
END_DISPATCH_MAP()

// Remarque : Nous avons ajouté une prise en charge pour IID_IAffChartsView afin de prendre en charge les liaisons de type sécurisé
//  à partir de VBA. Cet IID doit correspondre au GUID qui est attaché à 
//  dispinterface dans le fichier .IDL.

// {F2E4D3F7-0ED5-4E2C-A516-02E3A87C5D27}
static const IID IID_IAffChartsView =
{ 0xF2E4D3F7, 0xED5, 0x4E2C, { 0xA5, 0x16, 0x2, 0xE3, 0xA8, 0x7C, 0x5D, 0x27 } };

BEGIN_INTERFACE_MAP(CAffChartsView, CFormView)
	INTERFACE_PART(CAffChartsView, IID_IAffChartsView, Dispatch)
END_INTERFACE_MAP()


// Diagnostics de CAffChartsView

#ifdef _DEBUG
void CAffChartsView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAffChartsView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// Gestionnaires de messages de CAffChartsView


void CAffChartsView::OnButtoncalcul()
{
	//Invalidate(TRUE);// TODO: ajoutez ici le code de votre gestionnaire de commande
}


void CAffChartsView::OnBnClickedButton1()// bouton suppr
{
	// bouton suppr
}


void CAffChartsView::OnBnClickedButtonPrec()
{
		// diag donné non exporté 
	//vidange object ResultSImi
	Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument()); //Connexion au document

	m_graphComplete = FALSE;
	m_nStatutExportation=TRUE;

	pDoc->m_CGraph_testGraph->SetXYScale(-1,-1);

	theApp.SwitchViewPrec();// DO: affichage de la fenetre precedante
}
void CAffChartsView::OnBnClickedButton4()
{
	
}


void CAffChartsView::OnBnClickedButtonExport()
{
	//DO: lancer le protocole d'exportation

	Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument()); //Connexion au document

	if(m_nStatutExportation == TRUE)
	{
		pDoc->m_CResltSimi_CalculSimilitude.Exportation_Excel(); //appel de la fonction d'exportation
		m_nStatutExportation = FALSE;

		//vidange object ResultSImi
	}
	
	
}
