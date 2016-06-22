#include "stdafx.h"
#include <atlconv.h>
#include <atlbase.h>
#include <sstream>

#include "Protocole_Automation_EXCEL.h"


CApplication InitApplication()
{
	CApplication app;
	// Start Excel and get an Application object.
	if(!app.CreateDispatch(TEXT("Excel.Application")))
	{
		AfxMessageBox(TEXT("Couldn't start Excel and get Application object."));
		return NULL;
	}
	return app;

}

CWorkbook CreationBook(CApplication app)
{
	// Commonly used OLE variants.
	COleVariant
      covTrue((short)TRUE),
      covFalse((short)FALSE),
      covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	//Initialisation
	CWorkbooks books;
	CWorkbook book;

	
	if(app.m_lpDispatch != NULL)
	{
		//Recuperztion du control de WorkBook et creation d'un nouveau WorkBook
		books = app.get_Workbooks();
		//book = books.Open(L"D:\\Cours ENIVL\\Stage ECOFIT\\Logiciel\\test.xls",covOptional, covOptional, covOptional, covOptional, covOptional,covOptional, covOptional, covOptional, covOptional, covOptional,covOptional, covOptional, covOptional, covOptional );
		book = books.Add (covOptional);

	//book.put_Title(nomclasseur);

		return book;
	}
	return book;
}
CWorkbook OuvertureBook(CApplication app,CString filepath)
{
	// Commonly used OLE variants.
	COleVariant
      covTrue((short)TRUE),
      covFalse((short)FALSE),
      covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	//Initialisation
	CWorkbooks books;
	CWorkbook book;

	
	if(app.m_lpDispatch != NULL)
	{
		//Recuperztion du control de WorkBook et creation d'un nouveau WorkBook L"D:\\Cours ENIVL\\Stage ECOFIT\\Logiciel\\BDDEssaisVentilateur.xlsx"
		books = app.get_Workbooks();

		book = books.Open(filepath, covOptional,covOptional, covOptional, covOptional, covOptional,covOptional, covOptional, covOptional, covOptional, covOptional,covOptional, covOptional, covOptional, covOptional );
		//book = books.Add (covOptional);

		//book.put_Title(nomclasseur);

		return book;
	}
	return book;
}
CWorksheet CreationEntete(CWorkbook book,int CvDebit,int CvPression,int CvVitesse)
{
		// Commonly used OLE variants.
	COleVariant
      covTrue((short)TRUE),
      covFalse((short)FALSE),
      covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	CFont0 font;
	//Creation de la premieres feuille
	CWorksheets sheets;
	CWorksheet sheet;

	if(book.m_lpDispatch != NULL)
	{
		sheets =book.get_Sheets();
		sheet = sheets.get_Item(COleVariant((short)1));


	//Remplissage de l'entete
		CRange range;
		COleSafeArray saPointUti;
		COleSafeArray saPointTab;

		//Remplissage de la colone D

		DWORD numElementsUti[]={4,1};   //5x1 element array
		saPointUti.Create(VT_BSTR, 2, numElementsUti);
 
		FillSafeArray(L"Point d'utilisation", 0, 0, &saPointUti);
		switch(CvVitesse)
		{
		case 0: // Rpm
			FillSafeArray(L"Vitesse de commande (RPM)", 1, 0,&saPointUti);
			break;
		/*case 1: // Rpm -> rad/s 0.10472
			FillSafeArray(L"Vitesse de commande (rad/s)", 1, 0,&saPointUti);
			break;*/
		case 1: // tr/min
			FillSafeArray(L"Vitesse de commande (tr/min)", 1, 0,&saPointUti);
			break;
		default:
			FillSafeArray(L"Vitesse de commande (tr/min)", 1, 0,&saPointUti);
			// aucune conversion
			break;
		}
			switch(CvDebit)
		{
		case 0: // m3/h -> m3/h
			FillSafeArray(L"Debit (m3/h)", 2, 0, &saPointUti);
			break;
		case 1: // m3/h -> l/s  0.277778
			FillSafeArray(L"Debit (l/s)", 2, 0, &saPointUti);
			break;
		case 2: // m3/h -> cf/m 0.588578
			FillSafeArray(L"Debit (cf/min)", 2, 0, &saPointUti);
			break;
		default:
			FillSafeArray(L"Debit (m3/h)", 2, 0, &saPointUti);
			// aucune conversion
			break;
		}

		switch(CvPression)
		{
		case 0: //Pa -> Pa
			FillSafeArray(L"Pression (Pa)", 3, 0, &saPointUti);
			break;
		case 1: // Pa-> Psi 0.000145038
			FillSafeArray(L"Pression (Psi)", 3, 0, &saPointUti);
			break;
		case 2: // Pa-> mmEau 0.101974
			FillSafeArray(L"Pression (mmEau)", 3, 0, &saPointUti);
			break;
		case 3: // Pa-> inWater 0.004014742
			FillSafeArray(L"Pression (inWater)", 3, 0, &saPointUti);
			break;
		default:
			FillSafeArray(L"Pression (Pa)", 3, 0, &saPointUti);
			// aucune conversion
			break;
		}

	
	
	
		//FillSafeArray(L"Puissance (W)", 4, 0, &saPointUti);

		range = sheet.get_Range(COleVariant(TEXT("D2")), COleVariant(TEXT("D5")));
		range.put_Value2(COleVariant(saPointUti));
		saPointUti.Detach();

		//remplissage de la ligne 11

		DWORD numElementsTab[]={1,5};   //1x5 element array
		saPointTab.Create(VT_BSTR, 2, numElementsTab);

		FillSafeArray(L"Point d'utilisation", 0, 0, &saPointTab);
	
		switch(CvDebit)
		{
		case 0: // m3/h -> m3/h
			FillSafeArray(L"Debit (m3/h)", 0, 1,&saPointTab);
			break;
		case 1: // m3/h -> l/s  0.277778
			FillSafeArray(L"Debit (l/s)", 0, 1,&saPointTab);
			break;
		case 2: // m3/h -> cf/m 0.588578
			FillSafeArray(L"Debit (cf/min)", 0, 1,&saPointTab);
			break;
		default:
			FillSafeArray(L"Debit (m3/h)", 0, 1,&saPointTab);
			// aucune conversion
			break;
		}
	
		switch(CvPression)
		{
		case 0: //Pa -> Pa
			FillSafeArray(L"Pression (Pa)", 0, 2, &saPointTab);
			break;
		case 1: // Pa-> Psi 0.000145038
			FillSafeArray(L"Pression (Psi)", 0, 2, &saPointTab);
			break;
		case 2: // Pa-> mmEau 0.101974
			FillSafeArray(L"Pression (mmEau)", 0, 2, &saPointTab);
			break;
		case 3: // Pa-> inWater 0.004014742
			FillSafeArray(L"Pression (inWater)", 0, 2, &saPointTab);
			break;
		default:
			FillSafeArray(L"Pression (Pa)", 0, 2, &saPointTab);
			// aucune conversion
			break;
		}

		switch(CvVitesse)
		{
		case 0: // Rpm
			FillSafeArray(L"Vitesse de commande (RPM)", 0, 3, &saPointTab);
			break;
		/*case 1: // Rpm -> rad/s 0.10472
			FillSafeArray(L"Vitesse de commande (rad/s)", 0, 3, &saPointTab);
			break;*/
		case 1: // tr/min
			FillSafeArray(L"Vitesse de commande (tr/min)", 0, 3, &saPointTab);
			break;
		default:
			FillSafeArray(L"Vitesse de commande (tr/min)", 0, 3, &saPointTab);
			// aucune conversion
			break;
		}

		FillSafeArray(L"Puissance (W)", 0, 4, &saPointTab);

		range = sheet.get_Range(COleVariant(TEXT("A11")), COleVariant(TEXT("E11")));
		range.put_Value2(COleVariant(saPointTab));
		range = sheet.get_Range(COleVariant(TEXT("F11")), COleVariant(TEXT("J11")));
		range.put_Value2(COleVariant(saPointTab));
		saPointTab.Detach();
  
		// remplissage de la colonne A

		range = sheet.get_Range(COleVariant(TEXT("A2")),COleVariant(TEXT("A2")));
		range.put_Value2(COleVariant(TEXT("Réfèrence ")));

		range = sheet.get_Range(COleVariant(TEXT("A4")),COleVariant(TEXT("A4")));
		range.put_Value2(COleVariant(TEXT("Désignation des mesures ")));

		range = sheet.get_Range(COleVariant(TEXT("A6")),COleVariant(TEXT("A6")));
		range.put_Value2(COleVariant(TEXT("Altitude d'utilisation")));

		range = sheet.get_Range(COleVariant(TEXT("A10")),COleVariant(TEXT("A10")));
		range.put_Value2(COleVariant(TEXT("Tableau des mesures transformé par similitudes")));
		range = sheet.get_Range(COleVariant(TEXT("A10")),COleVariant(TEXT("E10")));
		range.Merge(covOptional);

		range = sheet.get_Range(COleVariant(TEXT("F10")),COleVariant(TEXT("F10")));
		range.put_Value2(COleVariant(TEXT("Tableau des mesures initiales ")));
		range = sheet.get_Range(COleVariant(TEXT("F10")),COleVariant(TEXT("J10")));
		range.Merge(covOptional);
		/*font = range.get_Font();
		font.put_Bold(covTrue);*/

		//Format A1:C1 as bold, vertical alignment = center.
	

		range = sheet.get_Range(COleVariant(TEXT("A2")), COleVariant(TEXT("A10")));
		font = range.get_Font();
		font.put_Bold(covTrue);
		range.put_VerticalAlignment(COleVariant((short)-4108));   //xlVAlignCenter = -4108

		range = sheet.get_Range(COleVariant(TEXT("D2")), COleVariant(TEXT("D6")));
		font = range.get_Font();
		font.put_Bold(covTrue);
		range.put_VerticalAlignment(COleVariant((short)-4108));   //xlVAlignCenter = -4108


		AutoFit(sheet);
		range.ReleaseDispatch();
		return sheet;
	}
	return sheet;
}

void RemplissageTableau(CWorksheet sheet,float* tab,int taille_tab,char* cellule_dep)
{
	// Commonly used OLE variants.
	COleVariant
      covTrue((short)TRUE),
      covFalse((short)FALSE),
      covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	//Definition des 	
	if(sheet.m_lpDispatch != NULL)
	{
		CRange range;
		COleSafeArray saBuffer;
		char str[20];
		std::string cellule_fin;

		cellule_fin.insert(0,cellule_dep,1);
		std::sprintf(str,"%d",(12+taille_tab-1));
		cellule_fin.insert(1,str);

		DWORD numElementsTab[]={taille_tab,1};   //taile tab x 1 element array
		saBuffer.Create(VT_BSTR, 2, numElementsTab);

		USES_CONVERSION;

		for(int i=0;i<taille_tab;i++)
		{
			std::sprintf(str,"%f", tab[i]);

			FillSafeArray(A2W(str),i,0,&saBuffer);
		}
	

		range = sheet.get_Range(COleVariant(A2W(cellule_dep)), COleVariant(A2W(cellule_fin.c_str())));
		range.put_Value2(COleVariant(saBuffer));

		AutoFit(sheet);
			
		saBuffer.Detach();
		range.ReleaseDispatch();
	}
}

void RemplissageCellule(CWorksheet sheet,float cell,char* cellule)
{
	// Commonly used OLE variants.
	COleVariant
      covTrue((short)TRUE),
      covFalse((short)FALSE),
      covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	if(sheet.m_lpDispatch != NULL)
	{
	//Definition des 
	CRange range;

	USES_CONVERSION;


	range = sheet.get_Range(COleVariant(A2W(cellule)), COleVariant(A2W(cellule)));
	range.put_Value2(COleVariant(cell));
	
	range.ReleaseDispatch();
	}
}
void RemplissageCellule(CWorksheet sheet,std::string cell,std::string cellule)
{
	// Commonly used OLE variants.
	COleVariant
      covTrue((short)TRUE),
      covFalse((short)FALSE),
      covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	if(sheet.m_lpDispatch != NULL)
	{
	//Definition des 
	CRange range;

	USES_CONVERSION;


	range = sheet.get_Range(COleVariant(A2W(cellule.c_str())), COleVariant(A2W(cellule.c_str())));
	range.put_Value2(COleVariant(A2W(cell.c_str())));
	
	range.ReleaseDispatch();
	}
}
void AddChart(CWorkbook *book,int type_char)
{
	// Commonly used OLE variants.
	COleVariant
      covTrue((short)TRUE),
      covFalse((short)FALSE),
      covOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR);

	//Intialisation
	CCharts charts;
	CChart chart;

	//Recuperztion du control de Chart et creation d'un nouveau Chart
	charts = book->get_Charts();
	chart = charts.Add(covOptional, covOptional, covOptional);

/*	chart.ChartWizard(var,                    // Source.
                        COleVariant((short)11),  // Gallery: 3d Column.
                        covOptional,             // Format, use default.
                        COleVariant((short)1),   // PlotBy: xlRows.
                        COleVariant((short)0),   // CategoryLabels.
                        COleVariant((short)1),   // SeriesLabels.
                        COleVariant((short)TRUE),  // HasLegend.
                        COleVariant("Use by Month"),  // Title.
                        COleVariant("Month"),    // CategoryTitle.
                        COleVariant("Usage in Thousands"),  // ValueTitles.
                        covOptional              // ExtraTitle.
                        );
						*/
}
void AutoFit(CWorksheet sheet)
{
	//AutoFit columns A:E.
	CRange range;
	range = sheet.get_Range(COleVariant(TEXT("A1")), COleVariant(TEXT("J1")));
	CRange cols;
	cols = range.get_EntireColumn();
	cols.AutoFit();
}
void FillSafeArray(OLECHAR FAR* sz, int iRow, int iCol,
                   COleSafeArray* sa)
{

   VARIANT v;
   long index[2];

   index[0] = iRow;
   index[1] = iCol;

   VariantInit(&v);
   v.vt = VT_BSTR;
   v.bstrVal = SysAllocString(sz);
   sa->PutElement(index, v.bstrVal);
   SysFreeString(v.bstrVal);
   VariantClear(&v);

}