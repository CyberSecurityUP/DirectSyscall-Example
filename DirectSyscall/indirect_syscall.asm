; Definition of syscall numbers
EXTERN wNtOpenFile:DWORD
EXTERN wNtClose:DWORD

.CODE  ; Start of the code section

; Procedure for the NtOpenFile syscall
NtOpenFile PROC
    mov r10, rcx               ; Move the contents of rcx to r10
    mov eax, wNtOpenFile       ; Move the syscall number into eax
    jmp [syscall address in ntdll.dll] ; Jump to the syscall address in ntdll.dll
    ret                        ; Return from the procedure
NtOpenFile ENDP

; Procedure for the NtClose syscall
NtClose PROC
    mov r10, rcx
    mov eax, wNtClose
    jmp [syscall address in ntdll.dll]
    ret
NtClose ENDP

END  ; End of the module
