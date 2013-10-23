/*
	File: XapHandler.cpp
	Project: ComXapHandler
	State: internal
	Purpose: implementation of exported CXapHandler class
*/
#include "stdafx.h"
#include "XapHandler.h"

#include "XapDeployer.h"
#pragma comment (lib, "XapDeployer.lib")

#include "aygshell7.h"
#pragma comment (lib, "aygshell7.lib")

#include "ComXapApi.h"
#include "..\..\common\PacmanClient.h"

#include "StringLoader.h"
#include "GuidConverter.h"

#include "shlwapi.h"
#pragma comment (lib, "shlwapi.lib")

#include "cfgmgrapi.h"
#include "..\..\common\ProcessFunctions_Common.h"

// CXapHandler

STDMETHODIMP CXapHandler::BeginDeploy(BSTR path, 
									  BSTR productID, 
									  BSTR instanceID, 
									  BSTR offerID,
									  BOOL uninstallDisabled, 
									  BOOL preInstall,
									  DWORD license, /*LPBYTE in fact. IntPtr in managed code*/
									  DWORD licenseLength,
									  DWORD *context)
{
	if (context == NULL)
		return E_INVALIDARG;

	__try
	{
		XAPINSTALLCONTEXT *xcontext = Xap_BeginDeploy(path, productID, instanceID, offerID, uninstallDisabled, preInstall, (LPBYTE)license, licenseLength);
		*context = (DWORD)xcontext;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::IsInstalled(DWORD context, BOOL *result)
{
	XAPINSTALLCONTEXT *xcontext = (XAPINSTALLCONTEXT*)context;
	if (xcontext == NULL || result == NULL)
		return E_INVALIDARG;

	__try
	{
		*result = Xap_IsInstalled(xcontext);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		*result = FALSE;
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::Install(DWORD context, BOOL update, BOOL debugMode, DWORD *result)
{
	XAPINSTALLCONTEXT *xcontext = (XAPINSTALLCONTEXT*)context;

	if (xcontext == NULL || result == NULL)
		return E_INVALIDARG;

	__try
	{
		*result = Xap_Install(xcontext, update, debugMode);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		*result = FALSE;
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::Uninstall(DWORD context, DWORD *result)
{
	XAPINSTALLCONTEXT *xcontext = (XAPINSTALLCONTEXT*)context;

	if (xcontext == NULL || result == NULL)
		return E_INVALIDARG;

	__try
	{
		*result = Xap_Uninstall(xcontext);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::WaitForEvents(DWORD context, DWORD timeout, DWORD *state, DWORD *progress, DWORD *hresult, DWORD *result)
{
	XAPINSTALLCONTEXT *xcontext = (XAPINSTALLCONTEXT*)context;

	if (xcontext == NULL || state == NULL || progress == NULL || hresult == NULL)
		return E_INVALIDARG;

	__try
	{
		*result = Xap_WaitForEvents(xcontext, timeout, (InstallationState*)state, progress, (HRESULT*)hresult);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::DecodeState(DWORD data, DWORD *state, DWORD *progress, DWORD *error)
{
	return S_OK;
}

STDMETHODIMP CXapHandler::EncodeState(DWORD state, DWORD progress, DWORD error, DWORD *newData)
{
	return S_OK;
}

STDMETHODIMP CXapHandler::EndDeploy(DWORD context)
{
	XAPINSTALLCONTEXT *xcontext = (XAPINSTALLCONTEXT*)context;

	if (xcontext == NULL)
		return E_INVALIDARG;

	__try
	{
		Xap_EndDeploy(xcontext);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::LaunchSessionByUri(BSTR uri)
{
	if (uri == NULL)
		return E_INVALIDARG;

	__try
	{
		HANDLE session = NULL;
		HRESULT hresult = SHLaunchSessionByUri(uri, &session);
		if (session != INVALID_HANDLE_VALUE)
			CloseHandle(session);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::LaunchSession(ULONGLONG appId, BSTR tokenId)
{
	if (appId == 0 || tokenId == NULL)
		return E_INVALIDARG;

	HANDLE session = NULL;
	HRESULT hresult = SHLaunchSession(appId, tokenId, &session);
	if (session)
		CloseHandle(session);
	return hresult;
}

STDMETHODIMP CXapHandler::LaunchCplApplet(BSTR cplName)
{
	if (cplName == NULL)
		return E_INVALIDARG;
	return LaunchCpl(cplName);
}

STDMETHODIMP CXapHandler::LaunchTask(BSTR uri, BSTR arguments)
{
	if (uri)
	{
		HANDLE session = NULL;
		SHLaunchTask(uri, arguments, &session);
		if (session)
			CloseHandle(session);
		return S_OK;
	}
	return E_INVALIDARG;
}

STDMETHODIMP CXapHandler::GetForegroundPageUri(BSTR *uri, BSTR *pageId)
{
	if (uri == NULL || pageId == NULL)
		return E_INVALIDARG;

	PAGEINFO pageinfo;
	if (SHGetForegroundPageInfo(&pageinfo) == S_OK)
	{
		*uri = SysAllocString(pageinfo.uri);
		*pageId = SysAllocString(pageinfo.pageId);
	}
	else
	{
		*uri = NULL;
		*pageId = NULL;
		return HRESULT_FROM_WIN32(GetLastError());
	}

	return S_OK;
}

STDMETHODIMP CXapHandler::GetApplicationInfo(BSTR guidString, DWORD *result)
{
	if (guidString == NULL || result == NULL)
		return E_INVALIDARG;

	*result = 0;

	__try
	{
		GUID guid;
		String2GUID(guidString, &guid);
		DWORD *dw = (DWORD*)&guid;

		IApplicationInfo *info = NULL;
		if (GetApplicationInfoByProductID(guid, &info) == S_OK)
		{
			*result = (DWORD)info;
		}
		else
		{
			*result = 0;
			return HRESULT_FROM_WIN32(GetLastError());
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		*result = NULL;
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::ReleaseApplicationInfo(DWORD appInfo)
{
	IApplicationInfo *info = (IApplicationInfo*)appInfo;
	if (info == NULL)
		return E_INVALIDARG;

	__try
	{
		delete info;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::ApplicationInfoGetGuid(DWORD appInfo, DWORD dwIndex, BSTR *outString)
{
	if (appInfo == NULL || outString == NULL)
		return E_INVALIDARG;

	__try
	{
		IApplicationInfo *inf = (IApplicationInfo*)appInfo;
		GUID *guid = NULL;
		switch (dwIndex)
		{
		case ProductID:
			guid = inf->get_ProductID();
			break;
		case InstanceID:
			guid = inf->get_InstanceID();
			break;
		case OfferID:
			guid = inf->get_OfferID();
			break;
		}
		bool outStringReady = false;

		if (guid)
		{
			LPOLESTR pStr;
			GUID2String(guid, &pStr);
			if (pStr)
			{
				*outString = SysAllocString(pStr);
				outStringReady = true;
				CoTaskMemFree(pStr);
			}
		}
		if (!outStringReady)
		{
			*outString = SysAllocString(L"\0");
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		*outString = NULL;
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::ApplicationInfoGetString(DWORD appInfo, DWORD dwIndex, BSTR *outString) //LPTSTR string, int length, DWORD *result)
{
	if (appInfo == NULL || outString == NULL)
		return E_INVALIDARG;

	__try
	{
		IApplicationInfo *inf = (IApplicationInfo*)appInfo;

		wchar_t *str = NULL;
		switch (dwIndex)
		{
		case DefaultTask:
			str = (wchar_t*)inf->get_DefaultTask();
			break;
		case Title:
			str = (wchar_t*)inf->get_AppTitle();
			break;
		case ApplicationIcon:
			str = (wchar_t*)inf->get_AppIconPath();
			break;
		case InstallFolder:
			str = (wchar_t*)inf->get_InstallPath();
			break;
		case DataFolder:
			str = (wchar_t*)inf->get_IsolatedStorageRoot();
			break;
		case Publisher:
			str = (wchar_t*)inf->get_Publisher();
			break;
		case Author:
			str = (wchar_t*)inf->get_Author();
			break;
		case Description:
			str = (wchar_t*)inf->get_Description();
			break;
		case Version:
			str = (wchar_t*)inf->get_Version();
			break;
		case ImagePath:
			str = (wchar_t*)inf->get_ImagePath();
			break;
		default:
			return E_INVALIDARG;
		}
		if (str)
		{
			*outString = SysAllocString(str);
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		*outString = NULL;
		return E_UNEXPECTED;
	}
	return S_OK;
}



STDMETHODIMP CXapHandler::ApplicationInfoGetInteger(DWORD appInfo, DWORD dwIndex, DWORD *result)
{
	if (appInfo == 0 || result == NULL)
		return E_INVALIDARG;
	__try
	{
		IApplicationInfo *inf = (IApplicationInfo*)appInfo;
		switch (dwIndex)
		{
		case AppId:
			{
				unsigned long long r = inf->get_AppID();

				*result = r & 0xFFFFFFFF;
				break;
			}
		case AppId2:
			{
				unsigned long long r = inf->get_AppID();

				*result = (r >> 32) & 0xFFFFFFFF; 
				break;
			}
		case IsNotified:
			*result = inf->get_IsNotified();
			break;
		case AppInstallType:
			*result = inf->get_AppInstallType();
			break;
		case AppState:
			*result = inf->get_State();
			break;
		case IsRevoked:
			*result = inf->get_IsRevoked();
			break;
		case IsUpdateAvailable:
			*result = inf->get_IsUpdateAvailable();
			break;
		case IsThemable:
			*result = inf->get_IsThemable();
			break;
		case Rating:
			*result = inf->get_Rating();
			break;
		case Genre:
			*result = inf->get_Genre();
			break;
		default:
			*result = 0;
			return E_INVALIDARG;
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		*result = NULL;
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::ApplicationInfoGetInvocationInfo(DWORD appInfo, 
														   BSTR *uri, 
														   BSTR *parameters, 
														   BOOL *result)
{
	if (appInfo == 0 || uri == NULL || 
		parameters == NULL || result == NULL)
		return E_INVALIDARG;

	__try
	{
		IApplicationInfo *inf = (IApplicationInfo*)appInfo;

		*result = FALSE;
		*uri = NULL;
		*parameters = NULL;

		wchar_t *str1 = NULL;
		wchar_t *str2 = NULL;
		if (inf->GetInvocationInfo(&str1, &str2) == S_OK)
		{
			if (str1)
			{
				*result = TRUE;
				*uri = SysAllocString(str1);
				delete[] str1;
			}
			if (str2)
			{
				*result = TRUE;
				*parameters = SysAllocString(str2);
				delete[] str2;
			}
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		*result = FALSE;
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::GetAllApplicationsIterator(DWORD *iterator)
{
	if (iterator == NULL)
		return E_INVALIDARG;

	HRESULT hresult = S_OK;
	__try
	{
		IApplicationInfoEnumerator *di = NULL;
		hresult = GetAllApplications(&di);
		*iterator = (hresult == S_OK) ? (DWORD)di : 0;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return hresult;
}

STDMETHODIMP CXapHandler::GetAllVisibleApplicationsIterator(DWORD *iterator)
{
	if (iterator == NULL)
		return E_INVALIDARG;
	
	HRESULT hresult = S_OK;
	__try
	{
		IApplicationInfoEnumerator* di = NULL;
		hresult = GetAllVisibleApplications(&di);
		*iterator = (hresult == S_OK) ? (DWORD)di : 0;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return hresult;
}

STDMETHODIMP CXapHandler::GetApplicationsOfHubTypeIterator(DWORD hubType, DWORD *iterator)
{
	if (iterator == NULL)
		return E_INVALIDARG;

	HRESULT hresult = S_OK;
	__try
	{
		IApplicationInfoEnumerator *di = NULL;
		hresult = GetApplicationsOfHubType(hubType, &di);
		*iterator = (hresult == S_OK) ? (DWORD)di : 0;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return hresult;
}

STDMETHODIMP CXapHandler::GetNextApplication(DWORD iterator, DWORD *appInfo)
{
	if (iterator == NULL || appInfo == NULL)
		return E_INVALIDARG;

	__try
	{
		IApplicationInfoEnumerator *di = (IApplicationInfoEnumerator*)iterator;

		IApplicationInfo *ai = (IApplicationInfo*)(*appInfo);
		if (di->get_Next(&ai) == S_OK)
			*appInfo = (DWORD)ai; 
		else
			*appInfo = 0;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::ReleaseIterator(DWORD iterator)
{
	if (iterator == NULL)
		return E_INVALIDARG;

	__try
	{
		IApplicationInfoEnumerator *di = (IApplicationInfoEnumerator*)iterator;
		delete di;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::ReinterpreteString(BSTR oldStr, BSTR *str)
{
	if (oldStr == NULL || str == NULL)
		return E_INVALIDARG;
	__try
	{
		*str = NULL;
		wchar_t *nstr = GetLocalizedString(oldStr);
		if (nstr)
			*str = nstr;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::UpdateAppIconPath(BSTR guidString, BSTR path)
{
	if (guidString == NULL || path == NULL)
		return E_INVALIDARG;

	__try
	{
		GUID guid;
		String2GUID(guidString, &guid);
		return PMUpdateAppIconPath(guid, path);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::TerminateApplicationProcesses(BSTR guidString)
{
	if (guidString == NULL)
		return E_INVALIDARG;

	__try
	{
		GUID guid;
		String2GUID(guidString, &guid);
		return PMTerminateApplicationProcesses(guid);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
}

STDMETHODIMP CXapHandler::GetLocale(DWORD *result)
{
	__try
	{
		DWORD locale = GetUserDefaultLCID();
		*result = locale;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::GetAssocationClass(BSTR extension, int type, BSTR *className)
{
	if (extension == NULL || className == NULL)
		return E_INVALIDARG;

	__try
	{
		*className = NULL;

		HKEY hKey = NULL;
		if (RegOpenKeyEx(HKEY_CLASSES_ROOT, extension, 0, NULL, &hKey) == S_OK)
		{
			wchar_t str[500];
			DWORD dwType = 0;
			DWORD dwDataSize = sizeof(str);

			wchar_t *valueName = NULL;
			if (type == 1)
				valueName = L"Default_bkp";

			if (RegQueryValueEx(hKey, valueName, NULL, &dwType, (LPBYTE)str, &dwDataSize) == S_OK && dwType == REG_SZ)
			{
				*className = SysAllocString(str);
			}
			RegCloseKey(hKey);
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::SetAssocationClass(BSTR extension, BSTR className, BOOL *result)
{
	if (extension == NULL || className == NULL || result == NULL)
		return E_INVALIDARG;

	__try
	{
		*result = FALSE;

		HKEY hKey = NULL;
		if (RegCreateKeyEx(HKEY_CLASSES_ROOT, extension, 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hKey, NULL) == S_OK)
		{
			if (RegSetValueEx(hKey, NULL, 0, REG_SZ, (LPBYTE)className, sizeof(wchar_t) * (wcslen(className) + 1)) == S_OK)
			{
				*result = TRUE;
			}
			RegCloseKey(hKey);
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}


STDMETHODIMP CXapHandler::BackupAssocationClass(BSTR extension, BOOL *result)
{
	if (extension == NULL || result == NULL)
		return E_INVALIDARG;

	__try
	{
		*result = FALSE;

		HKEY hKey = NULL;
		if (RegOpenKeyEx(HKEY_CLASSES_ROOT, extension, 0, NULL, &hKey) == S_OK)
		{
			wchar_t str[50];
			DWORD dwType = 0;
			DWORD dwDataSize = sizeof(str);
			if (RegQueryValueEx(hKey, NULL, NULL, &dwType, (LPBYTE)str, &dwDataSize) == S_OK && dwType == REG_SZ)
			{
				if (RegSetValueEx(hKey, L"Default_bkp", 0, REG_SZ, (LPBYTE)str, sizeof(str)) == S_OK)
				{
					*result = TRUE;
				}
			}
			RegCloseKey(hKey);
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::CreateAssocationClass(BSTR className, BSTR openCommand, BOOL *result)
{
	if (className == NULL || openCommand == NULL || result == NULL)
		return E_INVALIDARG;

	__try
	{
		*result = FALSE;

		HKEY hKey = NULL;
		if (RegCreateKeyEx(HKEY_CLASSES_ROOT, className, 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hKey, NULL) == S_OK)
		{
			DWORD dwEditFlags = 0x10000;
			if (RegSetValueEx(hKey, L"EditFlags", 0, REG_DWORD, (LPBYTE)&dwEditFlags, sizeof(DWORD)) != S_OK)
			{
				RegCloseKey(hKey);
				return S_OK;
			}

			HKEY hCommandKey = NULL;
			if (RegCreateKeyEx(hKey, L"Shell\\Open\\Command", 0, NULL, 0, KEY_ALL_ACCESS, NULL, &hCommandKey, NULL) == S_OK)
			{
				if (RegSetValueEx(hCommandKey, NULL, 0, REG_SZ, (LPBYTE)openCommand, sizeof(wchar_t) * (wcslen(openCommand) + 1)) == S_OK)
				{
					*result = TRUE;
				}
				RegCloseKey(hCommandKey);
			}
			RegCloseKey(hKey);
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::RemoveAssocationClass(BSTR className, BOOL *result)
{
	if (className == NULL || result == NULL)
		return E_INVALIDARG;

	__try
	{
		*result = (SHDeleteKey(HKEY_CLASSES_ROOT, className) == ERROR_SUCCESS) ? TRUE : FALSE;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}


STDMETHODIMP CXapHandler::CopyFileOver(BSTR src, BSTR dest, BOOL *result)
{
	if (src == NULL || dest == NULL || result == NULL)
		return E_INVALIDARG;

	__try
	{
		*result = FALSE;
		if (GetFileAttributes(dest) != INVALID_FILE_ATTRIBUTES)
		{
			SetFileAttributes(dest, FILE_ATTRIBUTE_NORMAL);
			DeleteFile(dest);
		}
		*result = CopyFile(src, dest, FALSE);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::RemoveFile(BSTR src, BOOL *result)
{
	if (src == NULL || result == NULL)
		return E_INVALIDARG;

	__try
	{
		*result = FALSE;
		if (GetFileAttributes(src) != INVALID_FILE_ATTRIBUTES)
		{
			SetFileAttributes(src, FILE_ATTRIBUTE_NORMAL);
			*result = DeleteFile(src);
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return E_UNEXPECTED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::CreateProcess(BSTR path, 
										BSTR arguments, 
										BSTR accountName,
										DWORD *outHandle,
										BOOL *result)
{
	if (path == NULL || outHandle == NULL || result == NULL)
		return E_INVALIDARG;

	__try
	{
		*outHandle = NULL;
		*result = FALSE;

		if (accountName == NULL || wcslen(accountName) == 0)
			accountName = L"S-1-5-112-0-0-1"; //SYSTEM_USER_NAME - TCB

		CE_PROCESS_INFORMATION cepi;
		memset(&cepi, 0, sizeof(cepi));
		cepi.cbSize = sizeof(cepi);
		cepi.lpwszAccountName = accountName;

		if (CeCreateProcessEx(path, arguments, &cepi) == TRUE)
		{
			*result = TRUE;
			*outHandle = (DWORD)cepi.ProcInfo.hProcess;
			CloseHandle(cepi.ProcInfo.hThread);
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		*result = FALSE;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::WaitForSingleObject7(DWORD handle, DWORD dwMilliseconds, DWORD *result)
{
	if (handle == NULL || result == NULL)
		return E_INVALIDARG;

	__try
	{
		*result = WaitForSingleObject((HANDLE)handle, dwMilliseconds);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		*result = WAIT_FAILED;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::CloseHandle7(DWORD handle, BOOL *result)
{
	if (handle == NULL || result == NULL)
		return E_INVALIDARG;

	__try
	{
		*result = CloseHandle((HANDLE)handle);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		*result = FALSE;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::ProcessProvxmlFile(BSTR filePath, BOOL *result)
{
	if (filePath == NULL || result == NULL)
		return E_INVALIDARG;
	__try
	{
		*result = FALSE;
		DWORD	dwFileSize, dwBytesRead = 0;
		HANDLE	hFile = CreateFile(filePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		if (hFile != INVALID_HANDLE_VALUE)
		{
			dwFileSize = GetFileSize(hFile, NULL);
			if (dwFileSize > 0)
			{
				char *cBuffer = new char[dwFileSize];
				if (cBuffer)
				{
					ReadFile(hFile, cBuffer, dwFileSize, &dwBytesRead, NULL);
					if (dwBytesRead == dwFileSize)
					{
						DWORD dwLength = mbstowcs(NULL, cBuffer, strlen(cBuffer));
						wchar_t *wBuffer = new wchar_t[dwLength + 1];
						if (wBuffer)
						{
							if (dwLength != -1)
								mbstowcs(wBuffer, cBuffer, strlen(cBuffer));
							LPWSTR pszXmlOut = NULL;
							if (DMProcessConfigXML(wBuffer, CFGFLAG_PROCESS, &pszXmlOut) == S_OK)
								*result = TRUE;
							if (pszXmlOut)
								delete[] pszXmlOut;
							delete[] wBuffer;
						}
					}
					delete[] cBuffer;
				}
			}
			CloseHandle(hFile);
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		*result = FALSE;
	}
	return S_OK;
}


STDMETHODIMP CXapHandler::ProcessProvxmlPlainText(BSTR provxml, BOOL *result)
{
	if (provxml == NULL || result == NULL)
		return E_INVALIDARG;
	__try
	{
		*result = FALSE;

		LPWSTR pszXmlOut = NULL;
		if (DMProcessConfigXML(provxml, CFGFLAG_PROCESS, &pszXmlOut) == S_OK)
			*result = TRUE;
		if (pszXmlOut)
			delete[] pszXmlOut;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		*result = FALSE;
	}
	return S_OK;
}

STDMETHODIMP CXapHandler::GetFileContent(BSTR filePath, DWORD* bArray, DWORD *dwLength)
{
	if (filePath == NULL || bArray == NULL || dwLength == NULL)
		return E_INVALIDARG;
	__try
	{
		*bArray = NULL;
		*dwLength = 0;
		HANDLE	hFile = CreateFile(filePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		if (hFile != INVALID_HANDLE_VALUE)
		{
			DWORD dwFileSize = GetFileSize(hFile, NULL);
			*dwLength = dwFileSize;
			DWORD dwBytesRead = 0;
			if (bArray)
			{
				char *b = new char[dwFileSize];
				ReadFile(hFile, b, dwFileSize, &dwBytesRead, NULL);
				*bArray = (DWORD)b;
			}
			CloseHandle(hFile);
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		*dwLength = 0;
		*bArray = NULL;
	}
	return S_OK;
}
STDMETHODIMP CXapHandler::AllocMem(DWORD dwCount, DWORD *dwResult)
{
	if (dwCount == 0 || dwResult == NULL)
		return E_INVALIDARG;
	__try
	{
		*dwResult = (DWORD)(new char[dwCount]);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
	}
	return S_OK;
}
STDMETHODIMP CXapHandler::FreeMem(DWORD dw)
{
	if (dw == NULL)
		return E_INVALIDARG;
	__try
	{
		delete[] ((DWORD*)dw);
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
	}
	return S_OK;
}