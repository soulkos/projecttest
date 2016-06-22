================================================================================
    BIBLIOTH�QUE MICROSOFT FOUNDATION CLASS : Vue d'ensemble du projet 
    logiciel_similitude_1-a2
================================================================================

L'Assistant Application a cr�� cette application logiciel_similitude_1-a2 pour 
vous.  Cette application d�crit les principes de base de l'utilisation de 
Microsoft Foundation Classes et vous permet de cr�er votre application.

Ce fichier contient un r�sum� du contenu de chacun des fichiers qui constituent 
votre application logiciel_similitude_1-a2.

logiciel_similitude_1-a2.vcxproj
    Il s'agit du fichier projet principal pour les projets VC++ g�n�r�s � l'aide 
    d'un Assistant Application. 
    Il contient les informations sur la version de Visual C++ qui a g�n�r� le 
    fichier et des informations sur les plates-formes, configurations et 
    fonctionnalit�s du projet s�lectionn�es avec l'Assistant Application.

logiciel_similitude_1-a2.vcxproj.filters
    Il s'agit du fichier de filtres pour les projets VC++ g�n�r�s � l'aide d'un 
    Assistant Application. 
    Il contient des informations sur l'association entre les fichiers de votre 
    projet et les filtres. Cette association est utilis�e dans l'IDE pour 
    afficher le regroupement des fichiers qui ont des extensions similares sous 
    un n�ud sp�cifique (par exemple, les fichiers ".cpp" sont associ�s au 
    filtre "Fichiers sources").

logiciel_similitude_1-a2.h
    Il s'agit du fichier d'en-t�te principal de l'application.  Il contient 
    d'autres en-t�tes de projet sp�cifiques (y compris Resource.h) et d�clare 
    la classe d'application Clogiciel_similitude_1a2App.

logiciel_similitude_1-a2.cpp
    Il s'agit du fichier source principal de l'application qui contient la 
    classe d'application Clogiciel_similitude_1a2App.

logiciel_similitude_1-a2.rc
    Il s'agit de la liste de toutes les ressources Microsoft Windows que le 
    programme utilise.  Elle comprend les ic�nes, les bitmaps et les curseurs 
    qui sont stock�s dans le sous-r�pertoire RES. Ce fichier peut �tre modifi� 
    directement dans Microsoft Visual C++. Vos ressources de projet sont dans 
    1036.

res\logiciel_similitude_1-a2.ico
    Il s'agit d'un fichier ic�ne, qui est utilis� comme ic�ne de l'application.  
    Cette ic�ne est incluse par le fichier de ressource principal 
    logiciel_similitude_1-a2.rc.

res\logiciel_similitude_1a2.rc2
    Ce fichier contient les ressources qui ne sont pas modifi�es par Microsoft  
    Visual C++. Vous devez placer toutes les ressources non modifiables par 
    l'�diteur de ressources dans ce fichier.

logiciel_similitude_1-a2.reg
    Il s'agit d'un exemple de fichier .reg qui montre le type de param�tres 
    d'enregistrement que le framework d�finit pour vous.  Vous pouvez l'utiliser 
    comme fichier .reg
    pour votre application ou le supprimer et utiliser  
    l'enregistrement par d�faut RegisterShellFileTypes.

logiciel_similitude_1a2.idl
    Ce fichier contient le code source IDL (Interface Description Language) de  
    la biblioth�que de types de votre application.

/////////////////////////////////////////////////////////////////////////////

Pour la fen�tre frame principale :
    Le projet comprend une interface MFC standard.

MainFrm.h, MainFrm.cpp
    Ces fichiers contiennent la classe de frame CMainFrame 
    d�riv�e de
    CFrameWnd et qui contr�le toutes les fonctionnalit�s des frames SDI.

/////////////////////////////////////////////////////////////////////////////

L'Assistant Application cr�e un type de document et une vue :

logiciel_similitude_1-a2Doc.h, logiciel_similitude_1-a2Doc.cpp - le document
    Ces fichiers contiennent votre classe Clogiciel_similitude_1a2Doc.  Modifiez ces 
fichiers pour 
    ajouter les donn�es de document sp�ciales et impl�menter l'enregistrement 
    et le chargement des fichiers (via Clogiciel_similitude_1a2Doc::Serialize).
    Le document contiendra les cha�nes suivantes :
        Extension de fichier :         sauvegarde_simi
        ID du type de fichier :        logicielsimilitude1a2.Document
        Titre du frame principal :     logiciel_similitude_1-a2
        Nom du type de document :      logiciel_simili
        Nom de filtre :                logiciel_similitude_1-a2 Files (*.sauvegarde_simi)
        Nom court de nouveau fichier : logiciel_simili
        Nom long du type de fichier :  logiciel_similitude_1-a2.Document

logiciel_similitude_1-a2View.h, logiciel_similitude_1-a2View.cpp - la vue du document
    Ces fichiers contiennent votre classe Clogiciel_similitude_1a2View.
    Les objets Clogiciel_similitude_1a2View servent � afficher les objets 
    Clogiciel_similitude_1a2Doc.





/////////////////////////////////////////////////////////////////////////////

Autres fonctionnalit�s :

Contr�les ActiveX
    L'application comprend la prise en charge des contr�les ActiveX.

Prise en charge des bases de donn�es
    L'Assistant Application a ajout� le niveau de base de la prise en charge 
    des bases de donn�es pour votre programme. 
    Seuls les fichiers n�cessaires sont inclus.

/////////////////////////////////////////////////////////////////////////////

Autres fichiers standard :

StdAfx.h, StdAfx.cpp
    Ces fichiers sont utilis�s pour g�n�rer un fichier d'en-t�te pr�compil� 
    (PCH) nomm� logiciel_similitude_1-a2.pch et un fichier de type pr�compil� 
    nomm� Stdafx.obj.

Resource.h
    Il s'agit du ficher d'en-t�te standard, qui d�finit les nouveaux ID de 
    ressources.
    Microsoft Visual C++ lit et met � jour ce fichier.

logiciel_similitude_1-a2.manifest
    Les fichiers manifestes d'application sont utilis�s par Windows XP pour 
    d�crire les d�pendances des applications sur des versions sp�cifiques 
    des assemblys c�te � c�te. Le chargeur utilise ces informations pour 
    charger l'assembly appropri� � partir du cache de l'assembly ou 
    directement � partir de l'application. Le manifeste de l'application peut 
    �tre inclus pour redistribution comme fichier .manifest externe install� 
    dans le m�me dossier que l'ex�cutable de l'application ou �tre inclus 
    dans l'ex�cutable sous la forme d'une ressource. 
/////////////////////////////////////////////////////////////////////////////

Autres remarques :

L'Assistant Application utilise "TODO:" pour indiquer les parties du code 
source o� vous devrez ajouter ou modifier du code.

Si votre application utilise les MFC dans une DLL partag�e vous devez 
redistribuer les DLL MFC. Si la langue de votre application n'est pas celle 
du syst�me d'exploitation, vous devez �galement redistribuer le fichier des 
ressources localis�es MFC100XXX.DLL. Pour plus d'informations, consultez la 
section relative � la redistribution des applications Visual C++ dans la 
documentation MSDN.

/////////////////////////////////////////////////////////////////////////////
