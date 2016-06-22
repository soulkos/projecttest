
// logiciel_similitude_1-a2Doc.h : interface de la classe Clogiciel_similitude_1a2Doc
//
#include "BDDEssais.h"
//#include "Essais.h"
//#include "Donnes.h"
#include "Protocoles_OLEDB_EXCEL.h"
#include "ResultatSimilitude.h"
#include "Graph.h"
#include "GraphSeries.h"

#pragma once


class Clogiciel_similitude_1a2Doc : public CDocument
{
protected: // création à partir de la sérialisation uniquement
	Clogiciel_similitude_1a2Doc();
	DECLARE_DYNCREATE(Clogiciel_similitude_1a2Doc)

// Attributs
public:
	int m_essais;

	CGraph* m_CGraph_testGraph;
	BOOL m_BOOL_graphComplete;
	CGraph* m_CGraph_AffcourbeinitialeGraph;
	BOOL m_BOOL_graphComplete2;

	CEssais m_CEssais_Temporaire;
	CBDDEssais m_CBDDEssais_BDDLocal;
	CResultatSimilitude m_CResltSimi_CalculSimilitude;

	CString m_FilePathTemp;


// Opérations
public:
	void CreationGraphique();
	void CreationGraphiqueOriginal();
	//void Chargement_BDDfichier_to_BDDlocal();

// Substitutions
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implémentation
public:
	virtual ~Clogiciel_similitude_1a2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Fonctions générées de la table des messages
protected:
	DECLARE_MESSAGE_MAP()

	// Fonctions générées de la table de dispatch OLE

	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

#ifdef SHARED_HANDLERS
	// Fonction d'assistance qui définit le contenu de recherche pour un gestionnaire de recherche
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
