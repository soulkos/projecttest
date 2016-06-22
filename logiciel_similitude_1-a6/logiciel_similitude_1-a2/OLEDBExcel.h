
#include "stdafx.h"
//#include "Essais.h"
#include "FormatExcel.h"

#ifndef OLEDBEXCEL_H_
# define OLEDBEXCEL_H_
#pragma once

class COLEDBExcel
{
public:
	//données membres
	HRESULT hr;
	CDataSource dataSource;
	CSession session;
	CTable<CDynamicStringAccessor,CRowset> table;

public:
	//init
	COLEDBExcel(void);
	virtual ~COLEDBExcel(void);
	COLEDBExcel(const COLEDBExcel &);
	COLEDBExcel& operator=(const COLEDBExcel &);

	//Accessors
	void SetHR(HRESULT hr);
	HRESULT GetHR();
	CString GetString(int colonne){ return this->table.GetString(colonne);};
	
	//methodes
	bool connectionExcel(std::string filepath);
	bool connectionExcelwithoutHeader(std::string filepath);
	std::string recuperationCelluleExcel(std::string sheet,const int ligne,const int colonne);
	CString recuperationDescriptionExcel(const int ligne,const int colonne);
	float* recuperationTableauExcel(std::string sheet,const int colonne,const int lignedebut,const int longeurtab);
	void connectionTable();
	void connectionTable(CString str);
	//int* determinationEnsembleBlock();
	int determinationBlock(int* nbpts,int* ligne_debut,CFormatExcel format);
	int determinationBlock2004(int* nbpts_block,int* ligne_debut1,CFormatExcel format);
	void ecritureCelluleExcel(std::string text, std::string sheet,const int colonne);
	void deconnectionExcel();
	/*CEssais* recuperationBDDExcel(std::string sheet, const int tailleBDD);*/

};

#endif