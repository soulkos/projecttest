
// stdafx.h : fichier Include pour les fichiers Include système standard,
// ou les fichiers Include spécifiques aux projets qui sont utilisés fréquemment,
// et sont rarement modifiés

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclure les en-têtes Windows rarement utilisés
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // certains constructeurs CString seront explicites

// désactive le masquage MFC de certains messages d'avertissement courants et par ailleurs souvent ignorés
#define _AFX_ALL_WARNINGS

#include <afx.h>
#include <afxwin.h>         // composants MFC principaux et standard
#include <afxext.h>         // extensions MFC


#include <afxdisp.h>        // Classes MFC Automation


 // Ici, une prise en charge minimale des bases de données est demandée. Aucune vue n'est sélectionnée.

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // Prise en charge MFC pour les contrôles communs Internet Explorer 4
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // Prise en charge des MFC pour les contrôles communs Windows
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <afxcontrolbars.h>     // prise en charge des MFC pour les rubans et les barres de contrôles


enum frequence {f50Hz =1 , f60Hz , DC , Autre };//Enumeration de la frequence



#include <atlbase.h>	//Prise en charge du protocole OLEDB
#include <afxoledb.h>
#include <atlplus.h>

#include <string>

#include <atlconv.h>

#include <iostream>
#include <sstream>
#include <fstream>

#include"Graph.h"

// Prise en charge des classe excel pour l'automation
#include "CApplication.h"
#include "CChart.h"
#include "CChartFormat.h"
#include "CCharts.h"
#include "CChartTitle.h"
#include "CFont0.h"
#include "CRange.h"
#include "CSeries.h"
#include "CSeriesCollection.h"
#include "CTrendline.h"
#include "CTrendlines.h"
#include "CWorkbook.h"
#include "CWorkbooks.h"
#include "CWorksheet.h"
#include "CWorksheetFunction.h"
#include "CWorksheets.h"



#include <cmath> // utilisation pourla resolution d'equation polynomiales d'ordre 2


#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


