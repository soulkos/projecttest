
// logiciel_similitude_1-a2View.h : interface de la classe Clogiciel_similitude_1a2View
//

#pragma once

#include "resource.h"


class Clogiciel_similitude_1a2View : public CFormView
{
protected: // cr�ation � partir de la s�rialisation uniquement
	Clogiciel_similitude_1a2View();
	DECLARE_DYNCREATE(Clogiciel_similitude_1a2View)

public:
	enum{ IDD = IDD_LOGICIEL_SIMILITUDE_1A2_FORM };

// Attributs
public:
	Clogiciel_similitude_1a2Doc* GetDocument() const;

// Op�rations
public:

// Substitutions
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV
	virtual void OnInitialUpdate(); // premier appel apr�s la construction

// Impl�mentation
public:
	virtual ~Clogiciel_similitude_1a2View();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Fonctions g�n�r�es de la table des messages
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // version debug dans logiciel_similitude_1-a2View.cpp
inline Clogiciel_similitude_1a2Doc* Clogiciel_similitude_1a2View::GetDocument() const
   { return reinterpret_cast<Clogiciel_similitude_1a2Doc*>(m_pDocument); }
#endif

