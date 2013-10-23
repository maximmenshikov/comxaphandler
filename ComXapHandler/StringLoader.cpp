/*
	File: stringloader.cpp
	Project: ComXapHandler
	State: internal
	Purpose: loading localized data from 
			 specially formatted input string
*/
#include "stdafx.h"
#pragma comment (lib, "StringLoader.lib")

extern "C" 
HRESULT ReadResourceString(wchar_t* Dll, DWORD ResourceID, wchar_t** Result);

wchar_t *GetLocalizedString(wchar_t *s)
{
	__try
	{
		if (s == NULL)
			return NULL;

		if (wcslen(s) > 4)
		{
			if (*s == L'@')
			{
				wchar_t libName[500];
				wcscpy_s(libName, 500, s);
				wchar_t *ln = wcsrchr(libName, L',');
				if (ln)
				{
					*ln = 0;
					ln++;
					ln = wcsrchr(ln, L'-');
					if (ln)
					{
						ln++;
						wchar_t *hz;
						int n = wcstoul(ln, &hz, 10);

						wchar_t *goodLibName = libName;
						goodLibName++;

						DWORD locale = GetUserDefaultLCID();
						wchar_t muiName[500];
						swprintf(muiName, L"%ls.%04X.mui", goodLibName, locale);

						BSTR str = NULL;
						ReadResourceString(muiName, n, &str);
						if (str == NULL)
						{
							ReadResourceString(goodLibName, n, &str);
						}
						return str;
					}
				}
			}
		}
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		
	}
	return SysAllocString(s);
}
