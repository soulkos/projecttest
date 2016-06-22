#include "StdAfx.h"
#include "BlockMesure.h"


CBlockMesure::CBlockMesure(void)
{
	this->m_nNbPts = 0;
}


CBlockMesure::~CBlockMesure(void)
{
	this->m_szDescription.Empty();
}
CBlockMesure::CBlockMesure(const CBlockMesure & bloc)
{
	this->m_nNbPts = bloc.m_nNbPts;
	this->m_nDebutMesure = bloc.m_nDebutMesure;
	this->m_szDescription = bloc.m_szDescription;
	this->m_Mesures = bloc.m_Mesures;

}
CBlockMesure& CBlockMesure::operator=(const CBlockMesure & bloc)
{
	this->m_nNbPts = bloc.m_nNbPts;
	this->m_nDebutMesure = bloc.m_nDebutMesure;
	this->m_szDescription = bloc.m_szDescription;
	this->m_Mesures = bloc.m_Mesures;

	return *this;
}
void CBlockMesure::SetNbpts(int nbpts)
{
	this->m_nNbPts = nbpts;
}
void CBlockMesure::SetLigneDebut(int lignedeb)
{
	this->m_nDebutMesure = lignedeb;
}
void CBlockMesure::SetDescription(CString str)
{
	this->m_szDescription = str;
}
int CBlockMesure::GetNbpts()
{
	return this->m_nNbPts;
}
int CBlockMesure::GetLigneDebut()
{
	return this->m_nDebutMesure;
}
CString CBlockMesure::GetDescription()
{
	return this->m_szDescription;
}