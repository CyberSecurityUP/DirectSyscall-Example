#include <windows.h>
#include <winternl.h>
#include <stdio.h>
#include "syscalls.h"

#pragma comment(lib, "ntdll.lib")

// Define the syscall numbers
DWORD wNtOpenFile;
DWORD wNtClose;

// Declare the RtlInitUnicodeString function
extern "C" void RtlInitUnicodeString(PUNICODE_STRING DestinationString, PCWSTR SourceString);

int wmain(int argc, wchar_t* argv[]) {
    if (argc != 2) {
        wprintf(L"Usage: %s <file-path>\n", argv[0]);
        return -1;
    }

    // Get handle to ntdll.dll and cast it to HMODULE
    HMODULE hNtdll = (HMODULE)GetModuleHandleA("ntdll.dll");

    // Get syscall numbers
    UINT_PTR pNtOpenFile = (UINT_PTR)GetProcAddress(hNtdll, "NtOpenFile");
    if (!pNtOpenFile) {
        printf("Failed to get address of NtOpenFile\n");
        return -1;
    }
    wNtOpenFile = ((unsigned char*)(pNtOpenFile + 4))[0];

    UINT_PTR pNtClose = (UINT_PTR)GetProcAddress(hNtdll, "NtClose");
    if (!pNtClose) {
        printf("Failed to get address of NtClose\n");
        return -1;
    }
    wNtClose = ((unsigned char*)(pNtClose + 4))[0];

    HANDLE fileHandle;
    OBJECT_ATTRIBUTES objAttr;
    IO_STATUS_BLOCK ioStatusBlock;

    // Define the file path and initialize the OBJECT_ATTRIBUTES
    UNICODE_STRING filePath;
    wchar_t fullPath[MAX_PATH];
    swprintf(fullPath, MAX_PATH, L"\\??\\%s", argv[1]);
    wprintf(L"Full Path: %s\n", fullPath);

    RtlInitUnicodeString(&filePath, fullPath);
    InitializeObjectAttributes(&objAttr, &filePath, OBJ_CASE_INSENSITIVE, NULL, NULL);

    // Call NtOpenFile
    NTSTATUS status = NtOpenFile(&fileHandle, GENERIC_READ, &objAttr, &ioStatusBlock, FILE_SHARE_READ, FILE_NON_DIRECTORY_FILE);
    if (status != 0) {
        printf("NtOpenFile failed with status: 0x%lx\n", status);
        return -1;
    }

    // Call NtClose
    status = NtClose(fileHandle);
    if (status != 0) {
        printf("NtClose failed with status: 0x%lx\n", status);
        return -1;
    }

    printf("NtOpenFile and NtClose executed successfully\n");
    return 0;
}
