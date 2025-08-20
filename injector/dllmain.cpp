// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include <iostream>
#include <detours.h>
extern "C" {
    __declspec(dllexport) bool Inject(DWORD pid, LPCSTR* dllPath)
    {
        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
        if (!hProcess)
        {
            return false;
        }

        // Inject the DLL using Detours
        if (!DetourUpdateProcessWithDll(hProcess, dllPath, 1))
        {
            CloseHandle(hProcess);
            return false;
        }

        CloseHandle(hProcess);
        return true;
    }
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

