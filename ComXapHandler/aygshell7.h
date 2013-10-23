/*
	Header: aygshell7.h
	Project: ComXapHandler
	State: internal
*/
#pragma once
#ifndef __AYGSHELL7_H__
#define __AYGSHELL7_H__

typedef struct _PAGEINFO
{
    DWORD task;
    DWORD session;
    DWORD processId;
    HANDLE hPage;
    HWND  hWnd;
    DWORD supportedOrientations; 
    WCHAR uri[1024];
    WCHAR pageId[256];
} PAGEINFO;

extern "C" 
{
	HRESULT SHLaunchSessionByUri(LPCWSTR uri, HANDLE* hSession);
	HRESULT SHLaunchSession(ULONGLONG appId, LPWSTR tokenId, HANDLE* hSession);
	HRESULT LaunchCpl(LPCTSTR cplName);
	HRESULT SHLaunchTask(LPWSTR uri, LPWSTR arguments, HANDLE* hSession);
	HRESULT SHGetForegroundPageInfo(PAGEINFO* info);
}

#endif
