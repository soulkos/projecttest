#pragma once
class CRegression
{
public:
	// member
	int* pDegree;
	int* pPolynomial;
	// init
	CRegression(void);
	virtual ~CRegression();
	CRegression& operator=(CRegression const&);
	// accessors
	void set_pDegree(int *);
	int get_pDegree(void);
	void set_pPolynomial(int *);
	int get_pPolynomial(void);

};

