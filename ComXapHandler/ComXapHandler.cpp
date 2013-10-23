// ComXapHandler.cpp : Implementation of DLL Exports.


#include "stdafx.h"

#ifdef POCKETPC2003_UI_MODEL
#include "resourceppc.h"
#endif 

#include "ComXapHandler.h"


class CComXapHandlerModule : public CAtlDllModuleT< CComXapHandlerModule >
{
public :
	DECLARE_LIBID(LIBID_ComXapHandlerLib)
#ifndef _CE_DCOM
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_COMXAPHANDLER, "{CCC23C73-DA28-4F8F-AC1A-C13AE51931BE}")
#endif
};

CComXapHandlerModule _AtlModule;


// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HANDLE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	hInstance;
    return _AtlModule.DllMain(dwReason, lpReserved); 
}


// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
    return _AtlModule.DllCanUnloadNow();
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    HRESULT hr = _AtlModule.DllRegisterServer();
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer(FALSE);
	return hr;
}

