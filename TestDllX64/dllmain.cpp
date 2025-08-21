// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>

DWORD WINAPI Thr() 
{
    MessageBoxA(0, "Hello World from my new Injector!", "TestDll", MB_OK | MB_ICONWARNING);
    return TRUE;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Thr, 0, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

