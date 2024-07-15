#ifndef _SYSCALLS_H
#define _SYSCALLS_H

#include <windows.h>
#include <winternl.h>  // Include for OBJECT_ATTRIBUTES and related types

#ifdef __cplusplus
extern "C" {
#endif

    typedef long NTSTATUS;
    typedef NTSTATUS(NTAPI* pfnNtOpenFile)(
        PHANDLE FileHandle,
        ACCESS_MASK DesiredAccess,
        POBJECT_ATTRIBUTES ObjectAttributes,
        PIO_STATUS_BLOCK IoStatusBlock,
        ULONG ShareAccess,
        ULONG OpenOptions
        );
    typedef NTSTATUS(NTAPI* pfnNtClose)(HANDLE Handle);

#ifdef __cplusplus
}
#endif

#endif // _SYSCALLS_H
