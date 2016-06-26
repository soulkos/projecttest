
// MFCApplication2.h : fichier d'en-tête principal pour l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// CMFCApplication2App :
// Consultez MFCApplication2.cpp pour l'implémentation de cette classe
//

class CMFCApplication2App : public CWinApp
{
public:
	CMFCApplication2App();

// Substitutions
public:
	virtual BOOL InitInstance();

// Implémentation

	DECLARE_MESSAGE_MAP()
};

extern CMFCApplication2App theApp;