#include "stdafx.h"

#pragma once
class CFormatExcel
{
public:
	int m_nColTension;
	int m_nColFreq;
	int m_nColCapa_Cmd;
	int m_nColDebit;
	int m_nColPression;
	int m_nColPuissance;
	int m_nColVitesse;
	int m_nColTemp;
public:
	CFormatExcel(void);
	virtual ~CFormatExcel(void);
	CFormatExcel(const CFormatExcel & format);
	CFormatExcel& operator=(const CFormatExcel & format);

	void SetColTension(int col);
	int GetColTension();
	void SetColFreq(int col);
	int GetColFreq();
	void SetColCapaCmd(int col);
	int GetColCapaCmd();
	void SetColDebit(int col);
	int GetColDebit();
	void SetColPression(int col);
	int GetColPression();
	void SetColPuissance(int col);
	int GetColPuissance();
	void SetColVitesse(int col);
	int GetColVitesse();
	void SetColTemperature(int col);
	int GetColTemperature();

};

