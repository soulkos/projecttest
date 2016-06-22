#include "stdafx.h"
#include "Protocoles_OLEDB_EXCEL.h"

LPCOLESTR OLEDBcreationInitString(std::string file)
{
	std::stringstream stream;

	//Choix automatique du protocole suivant le type de fichier
	if(file.find(".xlsx",0)==(-1)) // fichier .xls
		stream << "Provider='Microsoft.ACE.OLEDB.12.0';Data Source=" << file << ";Extended Properties="<<'\"'<<"Excel 8.0;MAXSCANROWS=0;ImportMixedTypes=Text;IMEX=1;HDR=yes;READONLY=FALSE"<<'\"';
	else	//fichier .xlsx
		stream << "Provider='Microsoft.ACE.OLEDB.12.0';Data Source=" << file << ";Extended Properties="<<'\"'<<"Excel 12.0 Xml;MAXSCANROWS=0;ImportMixedTypes=Text;IMEX=1;HDR=yes;READONLY=FALSE"<<'\"';
	
	file = stream.str();
	USES_CONVERSION; 
	char* iniStr =const_cast<char*>(file.c_str());
	
	return A2OLE(iniStr);
 }
BOOL OLEDB_OpenDatasource(CDataSource* dataSource,std::string filepath,HRESULT* hr)
{
	(*hr)=dataSource->OpenFromInitializationString(OLEDBcreationInitString(filepath));
	if(!SUCCEEDED(hr))
	{
		CoUninitialize();
		return FALSE;
	}
	return TRUE;
}
BOOL OLEDB_OpenSession(CDataSource dataSource,CSession* session,HRESULT* hr)
{
	/*(*hr)=session->Open((dataSource));
	if(!SUCCEEDED(hr))
	{
		dataSource.Close();
		CoUninitialize();
		return FALSE;
	}*/
	return TRUE;
}