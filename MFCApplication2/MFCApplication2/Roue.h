#pragma once
#include "Regression.h"

class CRoue
{
public:
	//membre
	CRegression Regression;

	// int
	CRoue();
	virtual ~CRoue();
	CRoue& operator=(CRoue const&);
};

