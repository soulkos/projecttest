
// logiciel_similitude_1-a2.cpp : Définit les comportements de classe pour l'application.
//

#include "stdafx.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "logiciel_similitude_1-a2.h"
#include "MainFrm.h"

#include "logiciel_similitude_1-a2Doc.h"
#include "logiciel_similitude_1-a2View.h"
#include "SaisieEssaisView.h"
#include "InterfaceSimilitudeView.h"
#include "AffChartsView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clogiciel_similitude_1a2App

BEGIN_MESSAGE_MAP(Clogiciel_similitude_1a2App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &Clogiciel_similitude_1a2App::OnAppAbout)
	// Commandes de fichier standard
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
END_MESSAGE_MAP()


// construction Clogiciel_similitude_1a2App

Clogiciel_similitude_1a2App::Clogiciel_similitude_1a2App()
{
	// prend en charge le Gestionnaire de redémarrage
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// Si l'application est créée à l'aide de la prise en charge Common Language Runtime (/clr):
	//     1) Ce paramètre supplémentaire est nécessaire à la prise en charge du Gestionnaire de redémarrage.
	//     2) Dans votre projet, vous devez ajouter une référence à System.Windows.Forms pour la génération.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: remplacer la chaîne d'ID de l'application ci-dessous par une chaîne ID unique ; le format recommandé
	// pour la chaîne est CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("logiciel_similitude_1-a2.AppID.NoVersion"));

	// TODO: ajoutez ici du code de construction,
	// Placez toutes les initialisations significatives dans InitInstance
}

// Seul et unique objet Clogiciel_similitude_1a2App

Clogiciel_similitude_1a2App theApp;
// Cet identificateur a été généré de sorte qu'il soit unique pour votre application
// Vous pouvez le changer par un autre identificateur de votre choix

// {F6CFA656-0768-42B0-A9B6-10FC5D4083A2}
static const CLSID clsid =
{ 0xF6CFA656, 0x768, 0x42B0, { 0xA9, 0xB6, 0x10, 0xFC, 0x5D, 0x40, 0x83, 0xA2 } };

const GUID CDECL _tlid = { 0xB71CA0F0, 0xF146, 0x4220, { 0xA4, 0x63, 0x3, 0x5A, 0xCB, 0xA, 0x68, 0xAB } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


// initialisation de Clogiciel_similitude_1a2App

BOOL Clogiciel_similitude_1a2App::InitInstance()
{

	/*{
		CSingleDocTemplate* pNewDocTemplate = new CSingleDocTemplate(
			IDR_AFFCHARTSVIEW_TMPL,
			RUNTIME_CLASS(Clogiciel_similitude_1a2Doc),
			RUNTIME_CLASS(CMainFrame),
			RUNTIME_CLASS(CAffChartsView));
		AddDocTemplate(pNewDocTemplate);
	}
	
	{
		CSingleDocTemplate* pNewDocTemplate = new CSingleDocTemplate(
			IDR_INTERFACESIMILITUDEVIEW_TMPL,
			RUNTIME_CLASS(Clogiciel_similitude_1a2Doc),
			RUNTIME_CLASS(CMainFrame),
			RUNTIME_CLASS(CInterfaceSimilitudeView));
		AddDocTemplate(pNewDocTemplate);
	}

	{
		CSingleDocTemplate* pNewDocTemplate = new CSingleDocTemplate(
			IDR_SAISIEESSAISVIEW_TMPL,
			RUNTIME_CLASS(Clogiciel_similitude_1a2Doc),
			RUNTIME_CLASS(CMainFrame),
			RUNTIME_CLASS(CSaisieEssaisView));
		AddDocTemplate(pNewDocTemplate);
	}

	*/
	// InitCommonControlsEx() est requis sur Windows XP si le manifeste de l'application
	// spécifie l'utilisation de ComCtl32.dll version 6 ou ultérieure pour activer les
	// styles visuels.  Dans le cas contraire, la création de fenêtres échouera.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// À définir pour inclure toutes les classes de contrôles communs à utiliser
	// dans votre application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();

	//CoInitializeEx(NULL, COINIT_MULTITHREADED);
	// Initialiser les bibliothèques OLE
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() est requis pour utiliser un contrôle RichEdit	
	// AfxInitRichEdit2();

	// Initialisation standard
	// Si vous n'utilisez pas ces fonctionnalités et que vous souhaitez réduire la taille
	// de votre exécutable final, vous devez supprimer ci-dessous
	// les routines d'initialisation spécifiques dont vous n'avez pas besoin.
	// Changez la clé de Registre sous laquelle nos paramètres sont enregistrés
	// TODO: modifiez cette chaîne avec des informations appropriées,
	// telles que le nom de votre société ou organisation
	SetRegistryKey(_T("Applications locales générées par AppWizard"));
	LoadStdProfileSettings(4);  // Charge les options de fichier INI standard (y compris les derniers fichiers utilisés)


	// Inscrire les modèles de document de l'application. Ces modèles
	//  lient les documents, fenêtres frame et vues entre eux
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(Clogiciel_similitude_1a2Doc),
		RUNTIME_CLASS(CMainFrame),       // fenêtre frame SDI principale
		RUNTIME_CLASS(Clogiciel_similitude_1a2View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);
	// Lier COleTemplateServer au modèle de document
	//  COleTemplateServer crée de nouveaux documents, à la demande
	//  de conteneurs OLE, en utilisant les informations
	//  spécifiées dans le modèle de document
	m_server.ConnectTemplate(clsid, pDocTemplate, TRUE);
		// Remarque : Les applications SDI inscrivent les objets serveur uniquement si le commutateur /Embedding
		//   ou /Automation figure dans la ligne de commande


	// Analyser la ligne de commande pour les commandes shell standard, DDE, ouverture de fichiers
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Activer les ouvertures d'exécution DDE
	EnableShellOpen();
	RegisterShellFileTypes(TRUE);

	// L'application a été lancée avec le commutateur /Embedding ou /Automation.
	// Exécutez-la en tant que serveur Automation.
	if (cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated)
	{
		// Inscrivez toutes les fabriques de serveur OLE comme étant en cours d'exécution. Cela permet aux bibliothèques
		//  OLE de créer des objets à partir d'autres applications.
		COleTemplateServer::RegisterAll();

		// Ne pas afficher la fenêtre principale
		return TRUE;
	}
	// L'application a été lancée avec le commutateur /Unregserver ou /Unregister. Annulez l'inscription
	// de la bibliothèque de types. Une autre annulation d'inscription est effectuée dans ProcessShellCommand().
	else if (cmdInfo.m_nShellCommand == CCommandLineInfo::AppUnregister)
	{
		UnregisterShellFileTypes();
		m_server.UpdateRegistry(OAT_DISPATCH_OBJECT, NULL, NULL, FALSE);
		AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor);
	}
	// L'application a été lancée en mode autonome ou avec d'autres commutateurs (par exemple, /Register
	// ou /Regserver). Mettez à jour les entrées du Registre, y compris typelibrary.
	else
	{
		m_server.UpdateRegistry(OAT_DISPATCH_OBJECT);
		COleObjectFactory::UpdateRegistryAll();
		AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid);
	}

	// Commandes de dispatch spécifiées sur la ligne de commande. Retournent FALSE si
	// l'application a été lancée avec /RegServer, /Register, /Unregserver ou /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	//Create and attach the new views


	
	CView* pActiveView = ((CFrameWnd*) m_pMainWnd)->GetActiveView();

	m_pViewAccueil = pActiveView;// acceuil
	m_pView1_1 = (CSaisieEssaisView*) new CSaisieEssaisView; //saisie essais
	m_pView2_1 = (CInterfaceSimilitudeView*) new CInterfaceSimilitudeView; // prepa calcul similitu
	m_pView2_2 = (CAffChartsView*) new CAffChartsView;	//  interface graph


	if ((NULL == m_pView1_1)||(NULL == m_pView2_1)||(NULL == m_pView2_2))
		return FALSE;

	CDocument* pCurrentDoc = ((CFrameWnd*)m_pMainWnd)->GetActiveDocument();

	// Initialize a CCreateContext to point to the active document.
	// With this context, the new view is added to the document
	// when the view is created in CView::OnCreate().
	CCreateContext newContext;
	newContext.m_pNewViewClass = NULL;
	newContext.m_pNewDocTemplate = NULL;
	newContext.m_pLastView = NULL;
	newContext.m_pCurrentFrame = NULL;
	newContext.m_pCurrentDoc = pCurrentDoc;

	// The ID of the initial active view is AFX_IDW_PANE_FIRST.
	// Incrementing this value by one for additional views works
	// in the standard document/view case but the technique cannot
	// be extended for the CSplitterWnd case.
	UINT viewID = AFX_IDW_PANE_FIRST + 1;
	CRect rect(0, 0, 0, 0); // Gets resized later.
	
	// Create the new view. In this example, the view persists for
	// the life of the application. The application automatically
	// deletes the view when the application is closed.
	m_pView1_1->Create(NULL, _T("AnyWindowNameEssais"), WS_CHILD, rect, m_pMainWnd, viewID, &newContext);
	m_pView2_1->Create(NULL, _T("AnyWindowNamePrepaSimi"), WS_CHILD, rect, m_pMainWnd, viewID, &newContext);
	m_pView2_2->Create(NULL, _T("AnyWindowNameGraph"), WS_CHILD, rect, m_pMainWnd, viewID, &newContext);
	
	// When a document template creates a view, the WM_INITIALUPDATE
	// message is sent automatically. However, this code must
	// explicitly send the message, as follows.
	m_pView1_1->SendMessage(WM_INITIALUPDATE, 0, 0);
	m_pView2_1->SendMessage(WM_INITIALUPDATE, 0, 0);
	m_pView2_2->SendMessage(WM_INITIALUPDATE, 0, 0);


	// La seule fenêtre a été initialisée et peut donc être affichée et mise à jour
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	// appelle DragAcceptFiles uniquement s'il y a un suffixe
	//  Dans une application SDI, cet appel doit avoir lieu juste après ProcessShellCommand
	// Activer les ouvertures via glisser-déplacer
	m_pMainWnd->DragAcceptFiles();
	return TRUE;
}

int Clogiciel_similitude_1a2App::ExitInstance()
{
	//TODO: gérez les ressources supplémentaires que vous avez ajoutées
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// gestionnaires de messages pour Clogiciel_similitude_1a2App


// boîte de dialogue CAboutDlg utilisée pour la boîte de dialogue 'À propos de' pour votre application

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Données de boîte de dialogue
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Implémentation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// Commande App pour exécuter la boîte de dialogue
void Clogiciel_similitude_1a2App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// gestionnaires de messages pour Clogiciel_similitude_1a2App
// Fonction de changement de vue
CView* Clogiciel_similitude_1a2App::SwitchViewSaisie( )
{
   CView* pActiveView = ((CFrameWnd*) m_pMainWnd)->GetActiveView();

   CView* pNewView = NULL;
   if(pActiveView == m_pViewAccueil)
   {
      pNewView = m_pView1_1;
   }

   // Exchange view window IDs so RecalcLayout() works.
   #ifndef _WIN32
   UINT temp = ::GetWindowWord(pActiveView->m_hWnd, GWW_ID);
   ::SetWindowWord(pActiveView->m_hWnd, GWW_ID, ::GetWindowWord(pNewView->m_hWnd, GWW_ID));
   ::SetWindowWord(pNewView->m_hWnd, GWW_ID, temp);
   #else
   UINT temp = ::GetWindowLong(pActiveView->m_hWnd, GWL_ID);
   ::SetWindowLong(pActiveView->m_hWnd, GWL_ID, ::GetWindowLong(pNewView->m_hWnd, GWL_ID));
   ::SetWindowLong(pNewView->m_hWnd, GWL_ID, temp);
   #endif

   pActiveView->ShowWindow(SW_HIDE);
   pNewView->ShowWindow(SW_SHOW);
   ((CFrameWnd*) m_pMainWnd)->SetActiveView(pNewView);
   ((CFrameWnd*) m_pMainWnd)->RecalcLayout();
   pNewView->Invalidate();
   return pActiveView;
} 



CView* Clogiciel_similitude_1a2App::SwitchViewSimilitude( )
{
	   CView* pActiveView = ((CFrameWnd*) m_pMainWnd)->GetActiveView();

   CView* pNewView = NULL;
   if(pActiveView == m_pViewAccueil)
   {
      pNewView = m_pView2_1;
   }
   else
   {
	   if(pActiveView== m_pView2_1)
		   pNewView = m_pView2_2;
   }

   // Exchange view window IDs so RecalcLayout() works.
   #ifndef _WIN32
   UINT temp = ::GetWindowWord(pActiveView->m_hWnd, GWW_ID);
   ::SetWindowWord(pActiveView->m_hWnd, GWW_ID, ::GetWindowWord(pNewView->m_hWnd, GWW_ID));
   ::SetWindowWord(pNewView->m_hWnd, GWW_ID, temp);
   #else
   UINT temp = ::GetWindowLong(pActiveView->m_hWnd, GWL_ID);
   ::SetWindowLong(pActiveView->m_hWnd, GWL_ID, ::GetWindowLong(pNewView->m_hWnd, GWL_ID));
   ::SetWindowLong(pNewView->m_hWnd, GWL_ID, temp);
   #endif

   pActiveView->ShowWindow(SW_HIDE);
   pNewView->ShowWindow(SW_SHOW);
   ((CFrameWnd*) m_pMainWnd)->SetActiveView(pNewView);
   ((CFrameWnd*) m_pMainWnd)->RecalcLayout();
   pNewView->Invalidate();
   return pActiveView;
}
CView* Clogiciel_similitude_1a2App::SwitchViewPrec( )
{
	CView* pActiveView = ((CFrameWnd*) m_pMainWnd)->GetActiveView();

   CView* pNewView = NULL;
   if(pActiveView == m_pView2_2)
   {
      pNewView = m_pView2_1;
   }
   else
   {
	   if(pActiveView== m_pView2_1)
		   pNewView = m_pViewAccueil;
	   else
	   {
		   if(pActiveView == m_pView1_1)
			{
				pNewView = m_pViewAccueil;
			}
	   }

   }


   // Exchange view window IDs so RecalcLayout() works.
   #ifndef _WIN32
   UINT temp = ::GetWindowWord(pActiveView->m_hWnd, GWW_ID);
   ::SetWindowWord(pActiveView->m_hWnd, GWW_ID, ::GetWindowWord(pNewView->m_hWnd, GWW_ID));
   ::SetWindowWord(pNewView->m_hWnd, GWW_ID, temp);
   #else
   UINT temp = ::GetWindowLong(pActiveView->m_hWnd, GWL_ID);
   ::SetWindowLong(pActiveView->m_hWnd, GWL_ID, ::GetWindowLong(pNewView->m_hWnd, GWL_ID));
   ::SetWindowLong(pNewView->m_hWnd, GWL_ID, temp);
   #endif

   pActiveView->ShowWindow(SW_HIDE);
   pNewView->ShowWindow(SW_SHOW);
   ((CFrameWnd*) m_pMainWnd)->SetActiveView(pNewView);
   ((CFrameWnd*) m_pMainWnd)->RecalcLayout();
   pNewView->Invalidate();
   return pActiveView;
}
