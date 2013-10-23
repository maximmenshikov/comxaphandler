/*
	Header: XapHandler
	Project: ComXapHandler
	State: public
	Purpose: declaration of CXapHandler class
*/
#pragma once
#ifdef STANDARDSHELL_UI_MODEL
#include "resource.h"
#endif
#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif
#ifdef SMARTPHONE2003_UI_MODEL
#include "resourcesp.h"
#endif
#ifdef AYGSHELL_UI_MODEL
#include "resourceayg.h"
#endif

#include "ComXapHandler.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CXapHandler

class ATL_NO_VTABLE CXapHandler :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CXapHandler, &CLSID_XapHandler>,
	public IDispatchImpl<IXapHandler, &IID_IXapHandler, &LIBID_ComXapHandlerLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CXapHandler()
	{
		
	}

#ifndef _CE_DCOM
DECLARE_REGISTRY_RESOURCEID(IDR_XAPHANDLER)
#endif


BEGIN_COM_MAP(CXapHandler)
	COM_INTERFACE_ENTRY(IXapHandler)
END_COM_MAP()

	HRESULT BeginDeploy(BSTR path, 
						BSTR productID, 
						BSTR instanceID, 
						BSTR offerID,
						BOOL uninstallDisabled, 
						BOOL preInstall,
						DWORD license,
						DWORD licenseLength,
						DWORD *context);
	HRESULT IsInstalled(DWORD context, BOOL *result);
	HRESULT Install(DWORD context, BOOL update, BOOL debugMode, DWORD *result);
	HRESULT Uninstall(DWORD context, DWORD *result);
	HRESULT WaitForEvents(DWORD context, DWORD timeout, DWORD *state, DWORD *progress, DWORD *hresult, DWORD *result);
	HRESULT DecodeState(DWORD data, DWORD *state, DWORD *progress, DWORD *error);
	HRESULT EncodeState(DWORD state, DWORD progress, DWORD error, DWORD *newData);
	HRESULT EndDeploy(DWORD context);
	HRESULT LaunchSessionByUri(BSTR uri);
	HRESULT LaunchSession(ULONGLONG appId, BSTR tokenId);
	HRESULT LaunchCplApplet(BSTR cplName);
	HRESULT LaunchTask(BSTR uri, BSTR arguments);
	HRESULT GetForegroundPageUri(BSTR *uri, BSTR *pageId);

	HRESULT GetApplicationInfo(BSTR guidString, DWORD *result);
	HRESULT ReleaseApplicationInfo(DWORD appInfo);
	HRESULT ApplicationInfoGetGuid(DWORD appInfo, DWORD dwIndex, BSTR *outString);
	HRESULT ApplicationInfoGetString(DWORD appInfo, DWORD dwIndex, BSTR *outString);
	HRESULT ApplicationInfoGetInteger(DWORD appInfo, DWORD dwIndex, DWORD *result);
	HRESULT ApplicationInfoGetInvocationInfo(DWORD appInfo, BSTR *uri, BSTR *parameters, BOOL *result);
	HRESULT GetAllApplicationsIterator(DWORD *iterator);
	HRESULT GetAllVisibleApplicationsIterator(DWORD *iterator);
	HRESULT GetApplicationsOfHubTypeIterator(DWORD hubType, DWORD *iterator);
	HRESULT GetNextApplication(DWORD iterator, DWORD *appInfo);
	HRESULT ReleaseIterator(DWORD iterator);
	HRESULT ReinterpreteString(BSTR oldStr, BSTR *str);

	HRESULT UpdateAppIconPath(BSTR guidString, BSTR path);
	HRESULT TerminateApplicationProcesses(BSTR guidString);
	HRESULT GetLocale(DWORD *result);

	HRESULT GetAssocationClass(BSTR extension, int type, BSTR *className);
	HRESULT SetAssocationClass(BSTR extension, BSTR className, BOOL *result);
	HRESULT BackupAssocationClass(BSTR extension, BOOL *result);
	HRESULT CreateAssocationClass(BSTR className, BSTR openCommand, BOOL *result);
	HRESULT RemoveAssocationClass(BSTR className, BOOL *result);
	HRESULT CopyFileOver(BSTR src, BSTR dest, BOOL *result);
	HRESULT RemoveFile(BSTR src, BOOL *result);

	HRESULT CreateProcess(BSTR path, BSTR arguments, BSTR accountName, DWORD *outHandle, BOOL *result);
	HRESULT WaitForSingleObject7(DWORD handle, DWORD dwMilliseconds, DWORD *result);
	HRESULT CloseHandle7(DWORD handle, BOOL *result);

	HRESULT ProcessProvxmlFile(BSTR filePath, BOOL *result);
	HRESULT ProcessProvxmlPlainText(BSTR provxml, BOOL *result);
	HRESULT GetFileContent(BSTR filePath, DWORD* bArray, DWORD *dwLength);
	HRESULT AllocMem(DWORD dwCount, DWORD *result);
	HRESULT FreeMem(DWORD dwPointer);

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

};

OBJECT_ENTRY_AUTO(__uuidof(XapHandler), CXapHandler)
