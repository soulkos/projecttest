#include "stdafx.h"

#pragma once

LPCOLESTR OLEDBcreationInitString(std::string filepath);
BOOL OLEDB_OpenDatasource(CDataSource* dataSource,std::string filepath,HRESULT* hr);
BOOL OLEDB_OpenSession(CDataSource dataSource,CSession* session,HRESULT* hr);