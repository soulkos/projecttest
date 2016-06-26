#include "stdafx.h"
#include "Regression.h"


CRegression::CRegression(void)
{
	this->pDegree = new int;
	this->pPolynomial = new int;
}


CRegression::~CRegression()
{
	delete[] this->pDegree;
	delete[] this->pPolynomial;
}

CRegression & CRegression::operator=(const CRegression & pCRegression)
{
	*this->pDegree = *pCRegression.pDegree;
	*this->pPolynomial = *pCRegression.pPolynomial;
	return *this;

}
void CRegression::set_pDegree(int* Degree) { *this->pDegree = *Degree; };
int CRegression::get_pDegree(void) { return *this->pDegree;};
void CRegression::set_pPolynomial(int* Polynomial) { *this->pPolynomial = *Polynomial; };
int CRegression::get_pPolynomial(void) { return *this->pPolynomial; };