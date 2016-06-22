
// logiciel_similitude_1-a2.h : fichier d'en-tête principal pour l'application logiciel_similitude_1-a2
//
#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"       // symboles principaux


// Clogiciel_similitude_1a2App:
// Consultez logiciel_similitude_1-a2.cpp pour l'implémentation de cette classe
//

class Clogiciel_similitude_1a2App : public CWinApp
{
public:
	CView* m_pViewAccueil;
	CView* m_pView1_1;
	CView* m_pView2_1;
	CView* m_pView2_2;

	CView* SwitchViewSaisie( );
	CView* SwitchViewSimilitude( );
	CView* SwitchViewPrec( );
	CView* SwitchViewAssociationMT( );

	Clogiciel_similitude_1a2App();


// Substitutions
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implémentation
	COleTemplateServer m_server;
		// Objet serveur pour la création de document
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Clogiciel_similitude_1a2App theApp;
