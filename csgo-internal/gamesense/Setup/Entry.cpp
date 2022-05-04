#include "../Include.h"

BOOL APIENTRY Entry( HMODULE hModule, DWORD ulReasonForCall, LPVOID lpReserved )
{
    switch ( ulReasonForCall )
    {
    case DLL_PROCESS_ATTACH:

    case DLL_THREAD_ATTACH:

    case DLL_THREAD_DETACH:

    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}