#include "StdAfx.h"
#include "FormatExcel.h"


CFormatExcel::CFormatExcel(void)
{
	this->m_nColTension = 0;
	this->m_nColFreq = 0;
	this->m_nColCapa_Cmd = 0;
	this->m_nColDebit = 0;
	this->m_nColPression = 0;
	this->m_nColPuissance = 0;
	this->m_nColVitesse = 0;
	this->m_nColTemp = 0;
}


CFormatExcel::~CFormatExcel(void)
{
}

CFormatExcel::CFormatExcel(const CFormatExcel & format)
{
	this->m_nColTension = format.m_nColTension;
	this->m_nColFreq = format.m_nColFreq;
	this->m_nColCapa_Cmd = format.m_nColCapa_Cmd;
	this->m_nColDebit = format.m_nColDebit;
	this->m_nColPression = format.m_nColPression;
	this->m_nColPuissance = format.m_nColPuissance;
	this->m_nColVitesse = format.m_nColVitesse;
	this->m_nColTemp = format.m_nColTemp;
}
CFormatExcel& CFormatExcel::operator=(const CFormatExcel & format)
{
	this->m_nColTension = format.m_nColTension;
	this->m_nColFreq = format.m_nColFreq;
	this->m_nColCapa_Cmd = format.m_nColCapa_Cmd;
	this->m_nColDebit = format.m_nColDebit;
	this->m_nColPression = format.m_nColPression;
	this->m_nColPuissance = format.m_nColPuissance;
	this->m_nColVitesse = format.m_nColVitesse;
	this->m_nColTemp = format.m_nColTemp;

	return *this;
}
void CFormatExcel::SetColTension(int col)
{
	this->m_nColTension = col;
}
int CFormatExcel::GetColTension()
{
	return this->m_nColTension;
}
void CFormatExcel::SetColFreq(int col)
{
	this->m_nColFreq = col;
}
int CFormatExcel::GetColFreq()
{
	return this->m_nColFreq;
}
void CFormatExcel::SetColCapaCmd(int col)
{
	this->m_nColCapa_Cmd = col;
}
int CFormatExcel::GetColCapaCmd()
{
	return this->m_nColCapa_Cmd;
}
void CFormatExcel::SetColDebit(int col)
{
	this->m_nColDebit = col;
}
int CFormatExcel::GetColDebit()
{
	return this->m_nColDebit;
}
void CFormatExcel::SetColPression(int col)
{
	this->m_nColPression = col;
}
int CFormatExcel::GetColPression()
{
	return this->m_nColPression;
}
void CFormatExcel::SetColPuissance(int col)
{
	this->m_nColPuissance = col;
}
int CFormatExcel::GetColPuissance()
{
	return this->m_nColPuissance;
}
void CFormatExcel::SetColVitesse(int col)
{
	this->m_nColVitesse = col;
}
int CFormatExcel::GetColVitesse()
{
	return this->m_nColVitesse;
}
void CFormatExcel::SetColTemperature(int col)
{
	this->m_nColTemp = col;
}
int CFormatExcel::GetColTemperature()
{
	return this->m_nColTemp;
}