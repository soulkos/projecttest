
// logiciel_similitude_1-a2Doc.cpp : implémentation de la classe Clogiciel_similitude_1a2Doc
//

#include "stdafx.h"
// SHARED_HANDLERS peuvent être définis dans les gestionnaires d'aperçu, de miniature
// et de recherche d'implémentation de projet ATL et permettent la partage de code de document avec ce projet.
#ifndef SHARED_HANDLERS
#include "logiciel_similitude_1-a2.h"
#endif

#include "logiciel_similitude_1-a2Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Clogiciel_similitude_1a2Doc

IMPLEMENT_DYNCREATE(Clogiciel_similitude_1a2Doc, CDocument)

BEGIN_MESSAGE_MAP(Clogiciel_similitude_1a2Doc, CDocument)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(Clogiciel_similitude_1a2Doc, CDocument)
END_DISPATCH_MAP()

// Remarque : La prise en charge de IID_Ilogiciel_similitude_1a2 a été ajoutée afin de prendre en charge la liaison de type sécurisé
//  à partir de VBA. Cet IID doit correspondre au GUID qui est attaché à 
//  dispinterface dans le fichier .IDL.

// {3B3739B3-C6BE-4B05-94F5-382B0C141D1B}
static const IID IID_Ilogiciel_similitude_1a2 =
{ 0x3B3739B3, 0xC6BE, 0x4B05, { 0x94, 0xF5, 0x38, 0x2B, 0xC, 0x14, 0x1D, 0x1B } };

BEGIN_INTERFACE_MAP(Clogiciel_similitude_1a2Doc, CDocument)
	INTERFACE_PART(Clogiciel_similitude_1a2Doc, IID_Ilogiciel_similitude_1a2, Dispatch)
END_INTERFACE_MAP()


// construction ou destruction de Clogiciel_similitude_1a2Doc

Clogiciel_similitude_1a2Doc::Clogiciel_similitude_1a2Doc()
{

	char temp[1024],AppPath[1024];
	USES_CONVERSION;
	LPWSTR tmp = A2W(temp);
	//LPWSTR AppPath = A2W(temp2);
	std::string NomFichierIni = "\\initBDD.ini";
	//CString AppPath;
	std::string AppPathCmpl;
	GetCurrentDirectoryA(1024,AppPath);
	
	//wcscat(AppPath,NomFichierIni);
	AppPathCmpl = AppPath + NomFichierIni;

	GetPrivateProfileStringA("CHEMIN","Cle","err",temp,1024,AppPathCmpl.c_str());
	CString CS_tmp = A2W(temp);
	this->m_CBDDEssais_BDDLocal.SetChemin(CS_tmp);
	GetPrivateProfileStringA("TAILLE","Cle","err",temp,1024,AppPathCmpl.c_str());
	CString CS_tmp2 = A2W(temp);
	this->m_CBDDEssais_BDDLocal.SetTaille(_wtoi(CS_tmp2));


	/*char temp[1024],temp2[1024];
	USES_CONVERSION;
	LPWSTR tmp = A2W(temp);
	LPWSTR AppPath = A2W(temp2);
	LPWSTR NomFichierIni = L"\\initBDD.ini";
	//CString AppPath;
	GetCurrentDirectory(1024,AppPath);
	
	wcscat(AppPath,NomFichierIni);

	GetPrivateProfileString(L"CHEMIN",L"Cle",L"err",A2W(temp),1024,AppPath);
	CString CS_tmp = A2W(temp);
	this->m_CBDDEssais_BDDLocal.SetChemin(CS_tmp);
	GetPrivateProfileString(L"TAILLE",L"Cle",L"err",A2W(temp),1024,AppPath);
	CString CS_tmp2 = A2W(temp);
	this->m_CBDDEssais_BDDLocal.SetTaille(_wtoi(CS_tmp2));*/


	this->m_CBDDEssais_BDDLocal.Chargement_BDDfichier_to_BDDlocal();
	// TODO: ajoutez ici le code d'une construction unique

	EnableAutomation();

	AfxOleLockApp();
}

Clogiciel_similitude_1a2Doc::~Clogiciel_similitude_1a2Doc()
{
	AfxOleUnlockApp();
}

BOOL Clogiciel_similitude_1a2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
		// initialisation de la base de donnée au démarrage de l'application

	// TODO: ajoutez ici le code de réinitialisation
	// (les documents SDI réutiliseront ce document)
	

	/*Clogiciel_similitude_1a2Doc* pDoc = dynamic_cast<Clogiciel_similitude_1a2Doc *> (GetDocument());
	
	for(int i = 0; i < pDoc->m_CBDDEssais_BDDLocal.GetTaille() ; i++)
		this->m_RefVentilateur.AddString(pDoc->m_CBDDEssais_BDDLocal.pCEssais_BDD[i].GetRefProduit());*/

	return TRUE;
}




// sérialisation de Clogiciel_similitude_1a2Doc

void Clogiciel_similitude_1a2Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: ajoutez ici le code de stockage
	}
	else
	{
		// TODO: ajoutez ici le code de chargement
	}
}

#ifdef SHARED_HANDLERS

// Prise en charge des miniatures
void Clogiciel_similitude_1a2Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modifier ce code pour dessiner les données du document
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support pour les gestionnaires de recherche
void Clogiciel_similitude_1a2Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Définir le contenu de recherche à partir des données du document. 
	// Les parties du contenu doivent être séparées par ";"

	// Par exemple :  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void Clogiciel_similitude_1a2Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// diagnostics pour Clogiciel_similitude_1a2Doc

#ifdef _DEBUG
void Clogiciel_similitude_1a2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Clogiciel_similitude_1a2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// commandes pour Clogiciel_similitude_1a2Doc

void Clogiciel_similitude_1a2Doc::CreationGraphique()
{
		// creation du grapique graph

	this->m_CGraph_testGraph = new CGraph(SCATTER_GRAPH);
	this->m_CGraph_testGraph->SetGraphTitle(L"Dp=f(Qv)");

	 // determination des limite d'axe
	//X
	int a = 5;
	float i,xscale = 1;
	float * temp  = this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.GetDebit();
	float * temp2  = this->m_CResltSimi_CalculSimilitude.CDonnes_Originales.GetDebit();
	int nbpts = this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.GetNbPts();

	// systéme a revoir 
	i = max(temp[nbpts - 1],temp2[nbpts - 1]);
	/*for( i = 1; (temp[nbpts - 1] > (i*5))||(temp2[nbpts - 1] > (i*5)); i++ )
	{
	}*/
	if (i<0.01)
	{
		a = 100;
		xscale = 100000;
	}
	if ( (i<0.1)&& (i>=0.01))
	{
		a = 100;
		xscale = 10000;
	}
	if ( (i<1)&& (i>=0.1))
	{
		a = 100;
		xscale = 1000;
	}
	if ( (i<5)&& (i>=1))
	{
		a = 50;
		xscale = 100;
	}
	if (i>50)
		a = 10;
	if (i>100);
		a = 25;
	if (i>200)
		a = 50;
	if (i>400)
		a = 100;
	if (i>1000)
		a = 200;
	if (i>2000)
		a = 500;
	if (i>4000)
		a = 1000;
	if (i>15000)
		a = 5000;



	//Y
	int b = 5;
	float j,yscale = 1;
	temp  = this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.GetPression();
	temp2 = this->m_CResltSimi_CalculSimilitude.CDonnes_Originales.GetPression();
	j = max(temp[0],temp2[0]);
	/*for( j = 1; (temp[0] > (j*5))||(temp2[0] > (j*5)) ; j++ )
	{
	}*/
	if (j<0.01)
	{
		b = 100;
		yscale = 100000;
	}
	if( (j<0.1)&& (j>=0.01))
	{
		b = 100;
		yscale = 10000;
	}
	if ((j<1)&&(j>=0.1))
	{
		b = 100;
		yscale = 1000;
	}
	if ((j<5)&& (j>=1))
	{
		b = 50;
		yscale = 100;
	}
	if (j>50)
		b = 10;
	if (j>100)
		b = 25;
	if (j>200)
		b = 50;
	if (j>400)
		b = 100;
	if (j>1000)
		b = 200;
	if (j>2000)
		b = 500;
	if (j>4000)
		b = 1000;
	if (j>15000)
		b = 5000;
	
	// creation des axes
	if (i<5)
	{
		if (j<5)
		{
			this->m_CGraph_testGraph->SetTickLimitsXY(0,(int((i* xscale)/a) * a)+ a,a,0,(int((j * yscale)/b) * b)+ b,b); // abscisse et ordonnée faible
			// multiplication Debit presion
			this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.CDonnes_Convertion_Debit(xscale);
			this->m_CResltSimi_CalculSimilitude.CDonnes_Originales.CDonnes_Convertion_Debit(xscale);
			this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.CDonnes_Convertion_Pression(yscale);
			this->m_CResltSimi_CalculSimilitude.CDonnes_Originales.CDonnes_Convertion_Pression(yscale);
			this->m_CGraph_testGraph->SetXYScale(xscale,yscale);
		}
		else
		{
			this->m_CGraph_testGraph->SetTickLimitsXY(0,(int((i* xscale)/a) * a)+ a,a,0,(int(j/b) * b)+ b,b);  // abscisse faible
			// multiplication debit
			this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.CDonnes_Convertion_Debit(xscale);
			this->m_CResltSimi_CalculSimilitude.CDonnes_Originales.CDonnes_Convertion_Debit(xscale);
			this->m_CGraph_testGraph->SetXYScale(xscale,-1);
		}
	}
	else
	{
		if (j<5)
		{
			this->m_CGraph_testGraph->SetTickLimitsXY(0,(int(i/a) * a)+ a,a,0,(int((j * yscale)/b) * b)+ b,b); // ordonnée faible
			// multiplication pression
			this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.CDonnes_Convertion_Pression(yscale);
			this->m_CResltSimi_CalculSimilitude.CDonnes_Originales.CDonnes_Convertion_Pression(yscale);
			this->m_CGraph_testGraph->SetXYScale(-1,yscale);
		}
		else
			this->m_CGraph_testGraph->SetTickLimitsXY(0,(int(i/a) * a)+ a,a,0,(int(j/b) * b)+ b,b); // graphique normal*/
	}
	
	//this->m_CGraph_testGraph->SetTickLimitsXY(0,((int(i/a)) * a)+ a,a,0,((int(j/b)) * b)+ b,b); // graphique normal


	switch (this->m_CResltSimi_CalculSimilitude.GetUniteDebit()) // Gestion du label de l'axe X
	{
	case 0:
		this->m_CGraph_testGraph->SetXAxisLabel(L"Qv (m3/h)");
		break;
	case 1:
		this->m_CGraph_testGraph->SetXAxisLabel(L"Qv (m3/s)");
		break;
	case 2:
		this->m_CGraph_testGraph->SetXAxisLabel(L"Qv (l/s)");
		break;
	case 3:
		this->m_CGraph_testGraph->SetXAxisLabel(L"Qv (cf/min)");
		break;
	default:
		this->m_CGraph_testGraph->SetXAxisLabel(L"Qv (m3/h)");
		break;
	}
	switch(this->m_CResltSimi_CalculSimilitude.GetUnitePression()) // Gestion du label de l'axe Y
	{
	case 0: //Pa -> Pa
		this->m_CGraph_testGraph->SetYAxisLabel(L"DP (Pa)");
		break;
	case 1: // Pa-> Psi 0.000145038
		this->m_CGraph_testGraph->SetYAxisLabel(L"DP (Psi)");
		break;
	case 2: // Pa-> mmEau 0.101974
		this->m_CGraph_testGraph->SetYAxisLabel(L"DP (mmEau)");
		break;
	case 3: // Pa-> inWater 0.004014742
		this->m_CGraph_testGraph->SetYAxisLabel(L"DP (inWater)");
		break;
	default:
		// aucune conversion
		this->m_CGraph_testGraph->SetYAxisLabel(L"DP (Pa)");
		break;
	}
	
	
	int k,l;
	//set up some series
	CGraphSeries** Points = (CGraphSeries**)malloc(sizeof(CGraphSeries*)*(2*(this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.GetNbPts())+1)); // allocation d'un tableau de serie
	

	for( k = 0; k < (nbpts) ; k++)
	{
		Points[k] = new CGraphSeries(); // allocation d'une serie
		Points[k]->SetData(this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.af_DebitQ[k],this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.af_PressionDP[k]); // ajout des valeur dans la serie (Q,Dp)
		this->m_CGraph_testGraph->AddSeries(Points[k]); //ajout de la serie au graphique
	}
	Points[nbpts] = new CGraphSeries(); // allocation d'une serie
	Points[nbpts]->SetData(-1,-1); // ajout des valeur dans la serie (Q,Dp)
	this->m_CGraph_testGraph->AddSeries(Points[nbpts]); //ajout de la serie au graphique
	l=0;
	for( k=nbpts + 1;k<(2*nbpts + 1) ; k++)
	{
		Points[k] = new CGraphSeries(); // allocation d'une serie
		Points[k]->SetData(this->m_CResltSimi_CalculSimilitude.CDonnes_Originales.af_DebitQ[l],this->m_CResltSimi_CalculSimilitude.CDonnes_Originales.af_PressionDP[l]); // ajout des valeur dans la serie (Q,Dp)
		this->m_CGraph_testGraph->AddSeries(Points[k]); //ajout de la serie au graphique
		l++;
	}
	this->m_BOOL_graphComplete = TRUE; // validation de la fin du graph
	//Invalidate(TRUE);	
	//Annulation de la mise a l'echelle des données 
	if (i<5)
	{
		if (j<5)
		{
			this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.CDonnes_Convertion_Debit((1/xscale));
			this->m_CResltSimi_CalculSimilitude.CDonnes_Originales.CDonnes_Convertion_Debit((1/xscale));
			this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.CDonnes_Convertion_Pression((1/yscale));
			this->m_CResltSimi_CalculSimilitude.CDonnes_Originales.CDonnes_Convertion_Pression((1/yscale));
		}
		else
		{
			this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.CDonnes_Convertion_Debit((1/xscale));
			this->m_CResltSimi_CalculSimilitude.CDonnes_Originales.CDonnes_Convertion_Debit((1/xscale));
		}
	}
	else
	{
		if (j<5)
		{
			
			this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.CDonnes_Convertion_Pression((1/yscale));
			this->m_CResltSimi_CalculSimilitude.CDonnes_Originales.CDonnes_Convertion_Pression((1/yscale));
		}	
	}
	// fin creation grpah
}

void Clogiciel_similitude_1a2Doc::CreationGraphiqueOriginal()
{
	// creation du grapique graph

	this->m_CGraph_AffcourbeinitialeGraph = new CGraph(SCATTER_GRAPH);
	this->m_CGraph_AffcourbeinitialeGraph->SetGraphTitle(L"Dp=f(Qv)");

	 // determination des limite d'axe
	//X
	int i,a = 5;
	float * temp  = this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.GetDebit();
	float * temp2  = this->m_CResltSimi_CalculSimilitude.CDonnes_Originales.GetDebit();
	int nbpts = this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.GetNbPts();

	// systéme a revoir 
	i = max(temp[nbpts - 1],temp2[nbpts - 1]);
	/*for( i = 1; (temp[nbpts - 1] > (i*5))||(temp2[nbpts - 1] > (i*5)); i++ )
	{
	}*/

	if (i>50)
		a = 10;
	if (i>100);
		a = 25;
	if (i>200)
		a = 50;
	if (i>400)
		a = 100;
	if (i>1000)
		a = 200;
	if (i>2000)
		a = 500;
	if (i>4000)
		a = 1000;



	//Y
	int j,b = 5;
	temp  = this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.GetPression();
	temp2 = this->m_CResltSimi_CalculSimilitude.CDonnes_Originales.GetPression();
	j = max(temp[0],temp2[0]);
	/*for( j = 1; (temp[0] > (j*5))||(temp2[0] > (j*5)) ; j++ )
	{
	}*/
	if (j>50)
		b = 10;
	if (j>100)
		b = 25;
	if (j>200)
		b = 50;
	if (j>400)
		b = 100;
	if (j>1000)
		b = 200;
	if (j>2000)
		b = 500;
	if (j>4000)
		b = 1000;
	
	

	this->m_CGraph_AffcourbeinitialeGraph->SetTickLimitsXY(0,((i/a) * a)+ a,a,0,((j/b) * b)+ b,b); // creation des axes


	this->m_CGraph_AffcourbeinitialeGraph->SetYAxisLabel(L"DP (Pa)");
	this->m_CGraph_AffcourbeinitialeGraph->SetXAxisLabel(L"Qv (m3/h)");

	//set up some series
	CGraphSeries** Points = (CGraphSeries**)malloc(sizeof(CGraphSeries*)*((this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.GetNbPts()))); // allocation d'un tableau de serie
	// possiblilité reduction utilisation memoire

	for( i = 0; i < (nbpts) ; i++)
	{
		Points[i] = new CGraphSeries(); // allocation d'une serie
		Points[i]->SetData(this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.af_DebitQ[i],this->m_CResltSimi_CalculSimilitude.CDonnes_ResultatSimilitude.af_PressionDP[i]); // ajout des valeur dans la serie (Q,Dp)
		this->m_CGraph_AffcourbeinitialeGraph->AddSeries(Points[i]); //ajout de la serie au graphique
	}

	this->m_BOOL_graphComplete2 = TRUE; // validation de la fin du graph

	// fin creation grpah
}