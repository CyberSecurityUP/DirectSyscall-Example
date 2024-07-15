; Definition of syscall numbers
EXTERN wNtOpenFile:DWORD
EXTERN wNtClose:DWORD

PUBLIC NtOpenFile
PUBLIC NtClose

.CODE  ; Start of the code section

; Procedure for the NtOpenFile syscall
NtOpenFile PROC
    mov r10, rcx               ; Move the contents of rcx to r10, necessary for the syscall in 64-bit Windows
    mov eax, wNtOpenFile       ; Move the syscall number into eax
    syscall                    ; Execute the syscall
    ret                        ; Return from the procedure
NtOpenFile ENDP

; Procedure for the NtClose syscall
NtClose PROC
    mov r10, rcx
    mov eax, wNtClose
    syscall
    ret
NtClose ENDP

END  ; End of the module
