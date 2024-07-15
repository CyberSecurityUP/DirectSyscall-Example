# DirectSyscall-Example

Example of how to use direct syscalls in a Windows environment. The example demonstrates opening and closing a file using the NtOpenFile and NtClose syscalls defined in assembly and called from C.

## Overview

The project consists of the following components:

- Assembly Code (direct_syscalls.asm): Defines the syscall procedures for NtOpenFile and NtClose.
- Header File (syscalls.h): Declares the external syscall numbers and function prototypes.
- C Code (DirectSyscall.cpp): Implements the main logic to get syscall numbers, initialize structures, and call the syscalls to open and close a file.

References:

[Configure your Setup Assembly](https://programminghaven.home.blog/2020/02/16/setup-an-assembly-project-on-visual-studio-2019/)

[Others Example Code Direct Syscall by VirtualAlllocEx](https://github.com/VirtualAlllocEx/Direct-Syscalls-vs-Indirect-Syscalls)


## TO-DO
- Indirect Syscall Example
