
#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0286 */
/* at Mon Jul 22 17:14:32 2013
 */
/* Compiler settings for .\ComXapHandler.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32 (32b run), ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ComXapHandler_h__
#define __ComXapHandler_h__

/* Forward Declarations */ 

#ifndef __IXapHandler_FWD_DEFINED__
#define __IXapHandler_FWD_DEFINED__
typedef interface IXapHandler IXapHandler;
#endif 	/* __IXapHandler_FWD_DEFINED__ */


#ifndef __XapHandler_FWD_DEFINED__
#define __XapHandler_FWD_DEFINED__

#ifdef __cplusplus
typedef class XapHandler XapHandler;
#else
typedef struct XapHandler XapHandler;
#endif /* __cplusplus */

#endif 	/* __XapHandler_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IXapHandler_INTERFACE_DEFINED__
#define __IXapHandler_INTERFACE_DEFINED__

/* interface IXapHandler */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IXapHandler;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("55D492CE-1269-4102-8079-5FC729F93FA3")
    IXapHandler : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE BeginDeploy( 
            BSTR path,
            BSTR productID,
            BSTR instanceID,
            BSTR offerID,
            BOOL uninstallDisabled,
            BOOL preInstall,
            DWORD license,
            DWORD licenseLength,
            /* [retval][out] */ DWORD __RPC_FAR *context) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsInstalled( 
            DWORD context,
            /* [retval][out] */ BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Install( 
            DWORD context,
            BOOL update,
            BOOL debugMode,
            /* [retval][out] */ DWORD __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Uninstall( 
            DWORD context,
            /* [retval][out] */ DWORD __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitForEvents( 
            DWORD context,
            DWORD timeout,
            /* [out] */ DWORD __RPC_FAR *state,
            /* [out] */ DWORD __RPC_FAR *progress,
            /* [out] */ DWORD __RPC_FAR *hresult,
            /* [retval][out] */ DWORD __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DecodeState( 
            DWORD data,
            DWORD __RPC_FAR *state,
            DWORD __RPC_FAR *progress,
            DWORD __RPC_FAR *error) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EncodeState( 
            DWORD state,
            DWORD progress,
            DWORD error,
            /* [retval][out] */ DWORD __RPC_FAR *newData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndDeploy( 
            DWORD context) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LaunchSessionByUri( 
            BSTR uri) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LaunchSession( 
            ULONGLONG appId,
            BSTR tokenId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LaunchCplApplet( 
            BSTR cplName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LaunchTask( 
            BSTR uri,
            BSTR arguments) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetForegroundPageUri( 
            BSTR __RPC_FAR *uri,
            BSTR __RPC_FAR *pageId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetApplicationInfo( 
            BSTR guidString,
            /* [retval][out] */ DWORD __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseApplicationInfo( 
            DWORD appInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ApplicationInfoGetGuid( 
            DWORD appInfo,
            DWORD dwIndex,
            /* [retval][out] */ BSTR __RPC_FAR *outString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ApplicationInfoGetString( 
            DWORD appInfo,
            DWORD dwIndex,
            /* [retval][out] */ BSTR __RPC_FAR *outString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ApplicationInfoGetInteger( 
            DWORD appInfo,
            DWORD dwIndex,
            /* [retval][out] */ DWORD __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ApplicationInfoGetInvocationInfo( 
            DWORD appInfo,
            BSTR __RPC_FAR *uri,
            BSTR __RPC_FAR *parameters,
            /* [retval][out] */ BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAllApplicationsIterator( 
            /* [retval][out] */ DWORD __RPC_FAR *iterator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAllVisibleApplicationsIterator( 
            /* [retval][out] */ DWORD __RPC_FAR *iterator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetApplicationsOfHubTypeIterator( 
            DWORD hubType,
            /* [retval][out] */ DWORD __RPC_FAR *iterator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextApplication( 
            DWORD iterator,
            /* [retval][out] */ DWORD __RPC_FAR *appInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseIterator( 
            DWORD iterator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReinterpreteString( 
            BSTR oldStr,
            /* [retval][out] */ BSTR __RPC_FAR *str) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateAppIconPath( 
            BSTR guidString,
            BSTR path) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TerminateApplicationProcesses( 
            BSTR guidString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLocale( 
            /* [retval][out] */ DWORD __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAssocationClass( 
            BSTR extension,
            int type,
            /* [retval][out] */ BSTR __RPC_FAR *className) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAssocationClass( 
            BSTR extension,
            BSTR className,
            /* [retval][out] */ BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BackupAssocationClass( 
            BSTR extension,
            /* [retval][out] */ BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateAssocationClass( 
            BSTR className,
            BSTR openCommand,
            /* [retval][out] */ BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAssocationClass( 
            BSTR className,
            /* [retval][out] */ BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyFileOver( 
            BSTR src,
            BSTR dest,
            /* [retval][out] */ BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveFile( 
            BSTR src,
            /* [retval][out] */ BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateProcess( 
            BSTR path,
            BSTR arguments,
            BSTR accountName,
            DWORD __RPC_FAR *outHandle,
            /* [retval][out] */ BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitForSingleObject7( 
            DWORD handle,
            DWORD dwMilliseconds,
            /* [retval][out] */ DWORD __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseHandle7( 
            DWORD handle,
            /* [retval][out] */ BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessProvxmlFile( 
            BSTR filePath,
            /* [retval][out] */ BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessProvxmlPlainText( 
            BSTR provxml,
            /* [retval][out] */ BOOL __RPC_FAR *result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileContent( 
            BSTR filePath,
            /* [out] */ DWORD __RPC_FAR *bArray,
            /* [out] */ DWORD __RPC_FAR *dwLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AllocMem( 
            DWORD dwCount,
            /* [retval][out] */ DWORD __RPC_FAR *dwResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FreeMem( 
            DWORD dwPointer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IXapHandlerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IXapHandler __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IXapHandler __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IXapHandler __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BeginDeploy )( 
            IXapHandler __RPC_FAR * This,
            BSTR path,
            BSTR productID,
            BSTR instanceID,
            BSTR offerID,
            BOOL uninstallDisabled,
            BOOL preInstall,
            DWORD license,
            DWORD licenseLength,
            /* [retval][out] */ DWORD __RPC_FAR *context);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsInstalled )( 
            IXapHandler __RPC_FAR * This,
            DWORD context,
            /* [retval][out] */ BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Install )( 
            IXapHandler __RPC_FAR * This,
            DWORD context,
            BOOL update,
            BOOL debugMode,
            /* [retval][out] */ DWORD __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Uninstall )( 
            IXapHandler __RPC_FAR * This,
            DWORD context,
            /* [retval][out] */ DWORD __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WaitForEvents )( 
            IXapHandler __RPC_FAR * This,
            DWORD context,
            DWORD timeout,
            /* [out] */ DWORD __RPC_FAR *state,
            /* [out] */ DWORD __RPC_FAR *progress,
            /* [out] */ DWORD __RPC_FAR *hresult,
            /* [retval][out] */ DWORD __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DecodeState )( 
            IXapHandler __RPC_FAR * This,
            DWORD data,
            DWORD __RPC_FAR *state,
            DWORD __RPC_FAR *progress,
            DWORD __RPC_FAR *error);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EncodeState )( 
            IXapHandler __RPC_FAR * This,
            DWORD state,
            DWORD progress,
            DWORD error,
            /* [retval][out] */ DWORD __RPC_FAR *newData);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EndDeploy )( 
            IXapHandler __RPC_FAR * This,
            DWORD context);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LaunchSessionByUri )( 
            IXapHandler __RPC_FAR * This,
            BSTR uri);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LaunchSession )( 
            IXapHandler __RPC_FAR * This,
            ULONGLONG appId,
            BSTR tokenId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LaunchCplApplet )( 
            IXapHandler __RPC_FAR * This,
            BSTR cplName);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LaunchTask )( 
            IXapHandler __RPC_FAR * This,
            BSTR uri,
            BSTR arguments);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetForegroundPageUri )( 
            IXapHandler __RPC_FAR * This,
            BSTR __RPC_FAR *uri,
            BSTR __RPC_FAR *pageId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetApplicationInfo )( 
            IXapHandler __RPC_FAR * This,
            BSTR guidString,
            /* [retval][out] */ DWORD __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseApplicationInfo )( 
            IXapHandler __RPC_FAR * This,
            DWORD appInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ApplicationInfoGetGuid )( 
            IXapHandler __RPC_FAR * This,
            DWORD appInfo,
            DWORD dwIndex,
            /* [retval][out] */ BSTR __RPC_FAR *outString);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ApplicationInfoGetString )( 
            IXapHandler __RPC_FAR * This,
            DWORD appInfo,
            DWORD dwIndex,
            /* [retval][out] */ BSTR __RPC_FAR *outString);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ApplicationInfoGetInteger )( 
            IXapHandler __RPC_FAR * This,
            DWORD appInfo,
            DWORD dwIndex,
            /* [retval][out] */ DWORD __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ApplicationInfoGetInvocationInfo )( 
            IXapHandler __RPC_FAR * This,
            DWORD appInfo,
            BSTR __RPC_FAR *uri,
            BSTR __RPC_FAR *parameters,
            /* [retval][out] */ BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllApplicationsIterator )( 
            IXapHandler __RPC_FAR * This,
            /* [retval][out] */ DWORD __RPC_FAR *iterator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllVisibleApplicationsIterator )( 
            IXapHandler __RPC_FAR * This,
            /* [retval][out] */ DWORD __RPC_FAR *iterator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetApplicationsOfHubTypeIterator )( 
            IXapHandler __RPC_FAR * This,
            DWORD hubType,
            /* [retval][out] */ DWORD __RPC_FAR *iterator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNextApplication )( 
            IXapHandler __RPC_FAR * This,
            DWORD iterator,
            /* [retval][out] */ DWORD __RPC_FAR *appInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReleaseIterator )( 
            IXapHandler __RPC_FAR * This,
            DWORD iterator);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReinterpreteString )( 
            IXapHandler __RPC_FAR * This,
            BSTR oldStr,
            /* [retval][out] */ BSTR __RPC_FAR *str);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *UpdateAppIconPath )( 
            IXapHandler __RPC_FAR * This,
            BSTR guidString,
            BSTR path);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TerminateApplicationProcesses )( 
            IXapHandler __RPC_FAR * This,
            BSTR guidString);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLocale )( 
            IXapHandler __RPC_FAR * This,
            /* [retval][out] */ DWORD __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAssocationClass )( 
            IXapHandler __RPC_FAR * This,
            BSTR extension,
            int type,
            /* [retval][out] */ BSTR __RPC_FAR *className);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAssocationClass )( 
            IXapHandler __RPC_FAR * This,
            BSTR extension,
            BSTR className,
            /* [retval][out] */ BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BackupAssocationClass )( 
            IXapHandler __RPC_FAR * This,
            BSTR extension,
            /* [retval][out] */ BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateAssocationClass )( 
            IXapHandler __RPC_FAR * This,
            BSTR className,
            BSTR openCommand,
            /* [retval][out] */ BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveAssocationClass )( 
            IXapHandler __RPC_FAR * This,
            BSTR className,
            /* [retval][out] */ BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CopyFileOver )( 
            IXapHandler __RPC_FAR * This,
            BSTR src,
            BSTR dest,
            /* [retval][out] */ BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveFile )( 
            IXapHandler __RPC_FAR * This,
            BSTR src,
            /* [retval][out] */ BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateProcess )( 
            IXapHandler __RPC_FAR * This,
            BSTR path,
            BSTR arguments,
            BSTR accountName,
            DWORD __RPC_FAR *outHandle,
            /* [retval][out] */ BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WaitForSingleObject7 )( 
            IXapHandler __RPC_FAR * This,
            DWORD handle,
            DWORD dwMilliseconds,
            /* [retval][out] */ DWORD __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CloseHandle7 )( 
            IXapHandler __RPC_FAR * This,
            DWORD handle,
            /* [retval][out] */ BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ProcessProvxmlFile )( 
            IXapHandler __RPC_FAR * This,
            BSTR filePath,
            /* [retval][out] */ BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ProcessProvxmlPlainText )( 
            IXapHandler __RPC_FAR * This,
            BSTR provxml,
            /* [retval][out] */ BOOL __RPC_FAR *result);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFileContent )( 
            IXapHandler __RPC_FAR * This,
            BSTR filePath,
            /* [out] */ DWORD __RPC_FAR *bArray,
            /* [out] */ DWORD __RPC_FAR *dwLength);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AllocMem )( 
            IXapHandler __RPC_FAR * This,
            DWORD dwCount,
            /* [retval][out] */ DWORD __RPC_FAR *dwResult);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *FreeMem )( 
            IXapHandler __RPC_FAR * This,
            DWORD dwPointer);
        
        END_INTERFACE
    } IXapHandlerVtbl;

    interface IXapHandler
    {
        CONST_VTBL struct IXapHandlerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IXapHandler_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IXapHandler_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IXapHandler_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IXapHandler_BeginDeploy(This,path,productID,instanceID,offerID,uninstallDisabled,preInstall,license,licenseLength,context)	\
    (This)->lpVtbl -> BeginDeploy(This,path,productID,instanceID,offerID,uninstallDisabled,preInstall,license,licenseLength,context)

#define IXapHandler_IsInstalled(This,context,result)	\
    (This)->lpVtbl -> IsInstalled(This,context,result)

#define IXapHandler_Install(This,context,update,debugMode,result)	\
    (This)->lpVtbl -> Install(This,context,update,debugMode,result)

#define IXapHandler_Uninstall(This,context,result)	\
    (This)->lpVtbl -> Uninstall(This,context,result)

#define IXapHandler_WaitForEvents(This,context,timeout,state,progress,hresult,result)	\
    (This)->lpVtbl -> WaitForEvents(This,context,timeout,state,progress,hresult,result)

#define IXapHandler_DecodeState(This,data,state,progress,error)	\
    (This)->lpVtbl -> DecodeState(This,data,state,progress,error)

#define IXapHandler_EncodeState(This,state,progress,error,newData)	\
    (This)->lpVtbl -> EncodeState(This,state,progress,error,newData)

#define IXapHandler_EndDeploy(This,context)	\
    (This)->lpVtbl -> EndDeploy(This,context)

#define IXapHandler_LaunchSessionByUri(This,uri)	\
    (This)->lpVtbl -> LaunchSessionByUri(This,uri)

#define IXapHandler_LaunchSession(This,appId,tokenId)	\
    (This)->lpVtbl -> LaunchSession(This,appId,tokenId)

#define IXapHandler_LaunchCplApplet(This,cplName)	\
    (This)->lpVtbl -> LaunchCplApplet(This,cplName)

#define IXapHandler_LaunchTask(This,uri,arguments)	\
    (This)->lpVtbl -> LaunchTask(This,uri,arguments)

#define IXapHandler_GetForegroundPageUri(This,uri,pageId)	\
    (This)->lpVtbl -> GetForegroundPageUri(This,uri,pageId)

#define IXapHandler_GetApplicationInfo(This,guidString,result)	\
    (This)->lpVtbl -> GetApplicationInfo(This,guidString,result)

#define IXapHandler_ReleaseApplicationInfo(This,appInfo)	\
    (This)->lpVtbl -> ReleaseApplicationInfo(This,appInfo)

#define IXapHandler_ApplicationInfoGetGuid(This,appInfo,dwIndex,outString)	\
    (This)->lpVtbl -> ApplicationInfoGetGuid(This,appInfo,dwIndex,outString)

#define IXapHandler_ApplicationInfoGetString(This,appInfo,dwIndex,outString)	\
    (This)->lpVtbl -> ApplicationInfoGetString(This,appInfo,dwIndex,outString)

#define IXapHandler_ApplicationInfoGetInteger(This,appInfo,dwIndex,result)	\
    (This)->lpVtbl -> ApplicationInfoGetInteger(This,appInfo,dwIndex,result)

#define IXapHandler_ApplicationInfoGetInvocationInfo(This,appInfo,uri,parameters,result)	\
    (This)->lpVtbl -> ApplicationInfoGetInvocationInfo(This,appInfo,uri,parameters,result)

#define IXapHandler_GetAllApplicationsIterator(This,iterator)	\
    (This)->lpVtbl -> GetAllApplicationsIterator(This,iterator)

#define IXapHandler_GetAllVisibleApplicationsIterator(This,iterator)	\
    (This)->lpVtbl -> GetAllVisibleApplicationsIterator(This,iterator)

#define IXapHandler_GetApplicationsOfHubTypeIterator(This,hubType,iterator)	\
    (This)->lpVtbl -> GetApplicationsOfHubTypeIterator(This,hubType,iterator)

#define IXapHandler_GetNextApplication(This,iterator,appInfo)	\
    (This)->lpVtbl -> GetNextApplication(This,iterator,appInfo)

#define IXapHandler_ReleaseIterator(This,iterator)	\
    (This)->lpVtbl -> ReleaseIterator(This,iterator)

#define IXapHandler_ReinterpreteString(This,oldStr,str)	\
    (This)->lpVtbl -> ReinterpreteString(This,oldStr,str)

#define IXapHandler_UpdateAppIconPath(This,guidString,path)	\
    (This)->lpVtbl -> UpdateAppIconPath(This,guidString,path)

#define IXapHandler_TerminateApplicationProcesses(This,guidString)	\
    (This)->lpVtbl -> TerminateApplicationProcesses(This,guidString)

#define IXapHandler_GetLocale(This,result)	\
    (This)->lpVtbl -> GetLocale(This,result)

#define IXapHandler_GetAssocationClass(This,extension,type,className)	\
    (This)->lpVtbl -> GetAssocationClass(This,extension,type,className)

#define IXapHandler_SetAssocationClass(This,extension,className,result)	\
    (This)->lpVtbl -> SetAssocationClass(This,extension,className,result)

#define IXapHandler_BackupAssocationClass(This,extension,result)	\
    (This)->lpVtbl -> BackupAssocationClass(This,extension,result)

#define IXapHandler_CreateAssocationClass(This,className,openCommand,result)	\
    (This)->lpVtbl -> CreateAssocationClass(This,className,openCommand,result)

#define IXapHandler_RemoveAssocationClass(This,className,result)	\
    (This)->lpVtbl -> RemoveAssocationClass(This,className,result)

#define IXapHandler_CopyFileOver(This,src,dest,result)	\
    (This)->lpVtbl -> CopyFileOver(This,src,dest,result)

#define IXapHandler_RemoveFile(This,src,result)	\
    (This)->lpVtbl -> RemoveFile(This,src,result)

#define IXapHandler_CreateProcess(This,path,arguments,accountName,outHandle,result)	\
    (This)->lpVtbl -> CreateProcess(This,path,arguments,accountName,outHandle,result)

#define IXapHandler_WaitForSingleObject7(This,handle,dwMilliseconds,result)	\
    (This)->lpVtbl -> WaitForSingleObject7(This,handle,dwMilliseconds,result)

#define IXapHandler_CloseHandle7(This,handle,result)	\
    (This)->lpVtbl -> CloseHandle7(This,handle,result)

#define IXapHandler_ProcessProvxmlFile(This,filePath,result)	\
    (This)->lpVtbl -> ProcessProvxmlFile(This,filePath,result)

#define IXapHandler_ProcessProvxmlPlainText(This,provxml,result)	\
    (This)->lpVtbl -> ProcessProvxmlPlainText(This,provxml,result)

#define IXapHandler_GetFileContent(This,filePath,bArray,dwLength)	\
    (This)->lpVtbl -> GetFileContent(This,filePath,bArray,dwLength)

#define IXapHandler_AllocMem(This,dwCount,dwResult)	\
    (This)->lpVtbl -> AllocMem(This,dwCount,dwResult)

#define IXapHandler_FreeMem(This,dwPointer)	\
    (This)->lpVtbl -> FreeMem(This,dwPointer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IXapHandler_BeginDeploy_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR path,
    BSTR productID,
    BSTR instanceID,
    BSTR offerID,
    BOOL uninstallDisabled,
    BOOL preInstall,
    DWORD license,
    DWORD licenseLength,
    /* [retval][out] */ DWORD __RPC_FAR *context);


void __RPC_STUB IXapHandler_BeginDeploy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_IsInstalled_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD context,
    /* [retval][out] */ BOOL __RPC_FAR *result);


void __RPC_STUB IXapHandler_IsInstalled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_Install_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD context,
    BOOL update,
    BOOL debugMode,
    /* [retval][out] */ DWORD __RPC_FAR *result);


void __RPC_STUB IXapHandler_Install_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_Uninstall_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD context,
    /* [retval][out] */ DWORD __RPC_FAR *result);


void __RPC_STUB IXapHandler_Uninstall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_WaitForEvents_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD context,
    DWORD timeout,
    /* [out] */ DWORD __RPC_FAR *state,
    /* [out] */ DWORD __RPC_FAR *progress,
    /* [out] */ DWORD __RPC_FAR *hresult,
    /* [retval][out] */ DWORD __RPC_FAR *result);


void __RPC_STUB IXapHandler_WaitForEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_DecodeState_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD data,
    DWORD __RPC_FAR *state,
    DWORD __RPC_FAR *progress,
    DWORD __RPC_FAR *error);


void __RPC_STUB IXapHandler_DecodeState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_EncodeState_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD state,
    DWORD progress,
    DWORD error,
    /* [retval][out] */ DWORD __RPC_FAR *newData);


void __RPC_STUB IXapHandler_EncodeState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_EndDeploy_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD context);


void __RPC_STUB IXapHandler_EndDeploy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_LaunchSessionByUri_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR uri);


void __RPC_STUB IXapHandler_LaunchSessionByUri_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_LaunchSession_Proxy( 
    IXapHandler __RPC_FAR * This,
    ULONGLONG appId,
    BSTR tokenId);


void __RPC_STUB IXapHandler_LaunchSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_LaunchCplApplet_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR cplName);


void __RPC_STUB IXapHandler_LaunchCplApplet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_LaunchTask_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR uri,
    BSTR arguments);


void __RPC_STUB IXapHandler_LaunchTask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_GetForegroundPageUri_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR __RPC_FAR *uri,
    BSTR __RPC_FAR *pageId);


void __RPC_STUB IXapHandler_GetForegroundPageUri_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_GetApplicationInfo_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR guidString,
    /* [retval][out] */ DWORD __RPC_FAR *result);


void __RPC_STUB IXapHandler_GetApplicationInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_ReleaseApplicationInfo_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD appInfo);


void __RPC_STUB IXapHandler_ReleaseApplicationInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_ApplicationInfoGetGuid_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD appInfo,
    DWORD dwIndex,
    /* [retval][out] */ BSTR __RPC_FAR *outString);


void __RPC_STUB IXapHandler_ApplicationInfoGetGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_ApplicationInfoGetString_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD appInfo,
    DWORD dwIndex,
    /* [retval][out] */ BSTR __RPC_FAR *outString);


void __RPC_STUB IXapHandler_ApplicationInfoGetString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_ApplicationInfoGetInteger_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD appInfo,
    DWORD dwIndex,
    /* [retval][out] */ DWORD __RPC_FAR *result);


void __RPC_STUB IXapHandler_ApplicationInfoGetInteger_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_ApplicationInfoGetInvocationInfo_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD appInfo,
    BSTR __RPC_FAR *uri,
    BSTR __RPC_FAR *parameters,
    /* [retval][out] */ BOOL __RPC_FAR *result);


void __RPC_STUB IXapHandler_ApplicationInfoGetInvocationInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_GetAllApplicationsIterator_Proxy( 
    IXapHandler __RPC_FAR * This,
    /* [retval][out] */ DWORD __RPC_FAR *iterator);


void __RPC_STUB IXapHandler_GetAllApplicationsIterator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_GetAllVisibleApplicationsIterator_Proxy( 
    IXapHandler __RPC_FAR * This,
    /* [retval][out] */ DWORD __RPC_FAR *iterator);


void __RPC_STUB IXapHandler_GetAllVisibleApplicationsIterator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_GetApplicationsOfHubTypeIterator_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD hubType,
    /* [retval][out] */ DWORD __RPC_FAR *iterator);


void __RPC_STUB IXapHandler_GetApplicationsOfHubTypeIterator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_GetNextApplication_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD iterator,
    /* [retval][out] */ DWORD __RPC_FAR *appInfo);


void __RPC_STUB IXapHandler_GetNextApplication_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_ReleaseIterator_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD iterator);


void __RPC_STUB IXapHandler_ReleaseIterator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_ReinterpreteString_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR oldStr,
    /* [retval][out] */ BSTR __RPC_FAR *str);


void __RPC_STUB IXapHandler_ReinterpreteString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_UpdateAppIconPath_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR guidString,
    BSTR path);


void __RPC_STUB IXapHandler_UpdateAppIconPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_TerminateApplicationProcesses_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR guidString);


void __RPC_STUB IXapHandler_TerminateApplicationProcesses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_GetLocale_Proxy( 
    IXapHandler __RPC_FAR * This,
    /* [retval][out] */ DWORD __RPC_FAR *result);


void __RPC_STUB IXapHandler_GetLocale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_GetAssocationClass_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR extension,
    int type,
    /* [retval][out] */ BSTR __RPC_FAR *className);


void __RPC_STUB IXapHandler_GetAssocationClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_SetAssocationClass_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR extension,
    BSTR className,
    /* [retval][out] */ BOOL __RPC_FAR *result);


void __RPC_STUB IXapHandler_SetAssocationClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_BackupAssocationClass_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR extension,
    /* [retval][out] */ BOOL __RPC_FAR *result);


void __RPC_STUB IXapHandler_BackupAssocationClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_CreateAssocationClass_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR className,
    BSTR openCommand,
    /* [retval][out] */ BOOL __RPC_FAR *result);


void __RPC_STUB IXapHandler_CreateAssocationClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_RemoveAssocationClass_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR className,
    /* [retval][out] */ BOOL __RPC_FAR *result);


void __RPC_STUB IXapHandler_RemoveAssocationClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_CopyFileOver_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR src,
    BSTR dest,
    /* [retval][out] */ BOOL __RPC_FAR *result);


void __RPC_STUB IXapHandler_CopyFileOver_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_RemoveFile_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR src,
    /* [retval][out] */ BOOL __RPC_FAR *result);


void __RPC_STUB IXapHandler_RemoveFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_CreateProcess_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR path,
    BSTR arguments,
    BSTR accountName,
    DWORD __RPC_FAR *outHandle,
    /* [retval][out] */ BOOL __RPC_FAR *result);


void __RPC_STUB IXapHandler_CreateProcess_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_WaitForSingleObject7_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD handle,
    DWORD dwMilliseconds,
    /* [retval][out] */ DWORD __RPC_FAR *result);


void __RPC_STUB IXapHandler_WaitForSingleObject7_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_CloseHandle7_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD handle,
    /* [retval][out] */ BOOL __RPC_FAR *result);


void __RPC_STUB IXapHandler_CloseHandle7_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_ProcessProvxmlFile_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR filePath,
    /* [retval][out] */ BOOL __RPC_FAR *result);


void __RPC_STUB IXapHandler_ProcessProvxmlFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_ProcessProvxmlPlainText_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR provxml,
    /* [retval][out] */ BOOL __RPC_FAR *result);


void __RPC_STUB IXapHandler_ProcessProvxmlPlainText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_GetFileContent_Proxy( 
    IXapHandler __RPC_FAR * This,
    BSTR filePath,
    /* [out] */ DWORD __RPC_FAR *bArray,
    /* [out] */ DWORD __RPC_FAR *dwLength);


void __RPC_STUB IXapHandler_GetFileContent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_AllocMem_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD dwCount,
    /* [retval][out] */ DWORD __RPC_FAR *dwResult);


void __RPC_STUB IXapHandler_AllocMem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IXapHandler_FreeMem_Proxy( 
    IXapHandler __RPC_FAR * This,
    DWORD dwPointer);


void __RPC_STUB IXapHandler_FreeMem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IXapHandler_INTERFACE_DEFINED__ */



#ifndef __ComXapHandlerLib_LIBRARY_DEFINED__
#define __ComXapHandlerLib_LIBRARY_DEFINED__

/* library ComXapHandlerLib */
/* [helpstring][version][uuid] */ 




EXTERN_C const IID LIBID_ComXapHandlerLib;

EXTERN_C const CLSID CLSID_XapHandler;

#ifdef __cplusplus

class DECLSPEC_UUID("7E6418C7-C93F-4B82-947E-83FEA7A757CC")
XapHandler;
#endif
#endif /* __ComXapHandlerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


