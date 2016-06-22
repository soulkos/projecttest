#include "stdafx.h"

#pragma once

CApplication InitApplication();
CWorkbook CreationBook(CApplication app);
CWorkbook OuvertureBook(CApplication app, CString filepath );
CWorksheet CreationEntete(CWorkbook book,int CvDebit,int CvPression,int CvVitesse);
void RemplissageTableau(CWorksheet sheet,float* tab,int taille_tab,char* cellule_dep);
void RemplissageCellule(CWorksheet sheet,float cell,char* cellule);
void RemplissageCellule(CWorksheet sheet,std::string cell,std::string cellule);
void AddChart(CWorkbook book,int type_char);
void AutoFit(CWorksheet sheet);


void FillSafeArray(OLECHAR FAR* sz, int iRow, int iCol,COleSafeArray* sa);
