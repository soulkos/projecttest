================================================================================
    BIBLIOTHÈQUE MICROSOFT FOUNDATION CLASS : Vue d'ensemble du projet 
    logiciel_similitude_1-a2
================================================================================

L'Assistant Application a créé cette application logiciel_similitude_1-a2 pour 
vous.  Cette application décrit les principes de base de l'utilisation de 
Microsoft Foundation Classes et vous permet de créer votre application.

Ce fichier contient un résumé du contenu de chacun des fichiers qui constituent 
votre application logiciel_similitude_1-a2.

logiciel_similitude_1-a2.vcxproj
    Il s'agit du fichier projet principal pour les projets VC++ générés à l'aide 
    d'un Assistant Application. 
    Il contient les informations sur la version de Visual C++ qui a généré le 
    fichier et des informations sur les plates-formes, configurations et 
    fonctionnalités du projet sélectionnées avec l'Assistant Application.

logiciel_similitude_1-a2.vcxproj.filters
    Il s'agit du fichier de filtres pour les projets VC++ générés à l'aide d'un 
    Assistant Application. 
    Il contient des informations sur l'association entre les fichiers de votre 
    projet et les filtres. Cette association est utilisée dans l'IDE pour 
    afficher le regroupement des fichiers qui ont des extensions similares sous 
    un nœud spécifique (par exemple, les fichiers ".cpp" sont associés au 
    filtre "Fichiers sources").

logiciel_similitude_1-a2.h
    Il s'agit du fichier d'en-tête principal de l'application.  Il contient 
    d'autres en-têtes de projet spécifiques (y compris Resource.h) et déclare 
    la classe d'application Clogiciel_similitude_1a2App.

logiciel_similitude_1-a2.cpp
    Il s'agit du fichier source principal de l'application qui contient la 
    classe d'application Clogiciel_similitude_1a2App.

logiciel_similitude_1-a2.rc
    Il s'agit de la liste de toutes les ressources Microsoft Windows que le 
    programme utilise.  Elle comprend les icônes, les bitmaps et les curseurs 
    qui sont stockés dans le sous-répertoire RES. Ce fichier peut être modifié 
    directement dans Microsoft Visual C++. Vos ressources de projet sont dans 
    1036.

res\logiciel_similitude_1-a2.ico
    Il s'agit d'un fichier icône, qui est utilisé comme icône de l'application.  
    Cette icône est incluse par le fichier de ressource principal 
    logiciel_similitude_1-a2.rc.

res\logiciel_similitude_1a2.rc2
    Ce fichier contient les ressources qui ne sont pas modifiées par Microsoft  
    Visual C++. Vous devez placer toutes les ressources non modifiables par 
    l'éditeur de ressources dans ce fichier.

logiciel_similitude_1-a2.reg
    Il s'agit d'un exemple de fichier .reg qui montre le type de paramètres 
    d'enregistrement que le framework définit pour vous.  Vous pouvez l'utiliser 
    comme fichier .reg
    pour votre application ou le supprimer et utiliser  
    l'enregistrement par défaut RegisterShellFileTypes.

logiciel_similitude_1a2.idl
    Ce fichier contient le code source IDL (Interface Description Language) de  
    la bibliothèque de types de votre application.

/////////////////////////////////////////////////////////////////////////////

Pour la fenêtre frame principale :
    Le projet comprend une interface MFC standard.

MainFrm.h, MainFrm.cpp
    Ces fichiers contiennent la classe de frame CMainFrame 
    dérivée de
    CFrameWnd et qui contrôle toutes les fonctionnalités des frames SDI.

/////////////////////////////////////////////////////////////////////////////

L'Assistant Application crée un type de document et une vue :

logiciel_similitude_1-a2Doc.h, logiciel_similitude_1-a2Doc.cpp - le document
    Ces fichiers contiennent votre classe Clogiciel_similitude_1a2Doc.  Modifiez ces 
fichiers pour 
    ajouter les données de document spéciales et implémenter l'enregistrement 
    et le chargement des fichiers (via Clogiciel_similitude_1a2Doc::Serialize).
    Le document contiendra les chaînes suivantes :
        Extension de fichier :         sauvegarde_simi
        ID du type de fichier :        logicielsimilitude1a2.Document
        Titre du frame principal :     logiciel_similitude_1-a2
        Nom du type de document :      logiciel_simili
        Nom de filtre :                logiciel_similitude_1-a2 Files (*.sauvegarde_simi)
        Nom court de nouveau fichier : logiciel_simili
        Nom long du type de fichier :  logiciel_similitude_1-a2.Document

logiciel_similitude_1-a2View.h, logiciel_similitude_1-a2View.cpp - la vue du document
    Ces fichiers contiennent votre classe Clogiciel_similitude_1a2View.
    Les objets Clogiciel_similitude_1a2View servent à afficher les objets 
    Clogiciel_similitude_1a2Doc.





/////////////////////////////////////////////////////////////////////////////

Autres fonctionnalités :

Contrôles ActiveX
    L'application comprend la prise en charge des contrôles ActiveX.

Prise en charge des bases de données
    L'Assistant Application a ajouté le niveau de base de la prise en charge 
    des bases de données pour votre programme. 
    Seuls les fichiers nécessaires sont inclus.

/////////////////////////////////////////////////////////////////////////////

Autres fichiers standard :

StdAfx.h, StdAfx.cpp
    Ces fichiers sont utilisés pour générer un fichier d'en-tête précompilé 
    (PCH) nommé logiciel_similitude_1-a2.pch et un fichier de type précompilé 
    nommé Stdafx.obj.

Resource.h
    Il s'agit du ficher d'en-tête standard, qui définit les nouveaux ID de 
    ressources.
    Microsoft Visual C++ lit et met à jour ce fichier.

logiciel_similitude_1-a2.manifest
    Les fichiers manifestes d'application sont utilisés par Windows XP pour 
    décrire les dépendances des applications sur des versions spécifiques 
    des assemblys côte à côte. Le chargeur utilise ces informations pour 
    charger l'assembly approprié à partir du cache de l'assembly ou 
    directement à partir de l'application. Le manifeste de l'application peut 
    être inclus pour redistribution comme fichier .manifest externe installé 
    dans le même dossier que l'exécutable de l'application ou être inclus 
    dans l'exécutable sous la forme d'une ressource. 
/////////////////////////////////////////////////////////////////////////////

Autres remarques :

L'Assistant Application utilise "TODO:" pour indiquer les parties du code 
source où vous devrez ajouter ou modifier du code.

Si votre application utilise les MFC dans une DLL partagée vous devez 
redistribuer les DLL MFC. Si la langue de votre application n'est pas celle 
du système d'exploitation, vous devez également redistribuer le fichier des 
ressources localisées MFC100XXX.DLL. Pour plus d'informations, consultez la 
section relative à la redistribution des applications Visual C++ dans la 
documentation MSDN.

/////////////////////////////////////////////////////////////////////////////
