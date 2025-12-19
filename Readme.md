About
=====

This is a fork of an updated Reflective DLL PoC tested to work on Visual Studio 2022 (instead of old 2012 version) v143 Windows 10 system.

Works for x32 (windows/shell_reverse_tcp) and x64 (windows/x64/shell_reverse_tcp)

Cautions
=====

Do not mix windows/shell_reverse_tcp, windows/x64/meterpreter/reverse_tcp and windows/x64/shell_reverse_tcp, use a simple x64/shell_reverse_tcp with netcat or any other listener.

Original Old Repo
========

https://github.com/stephenfewer/ReflectiveDLLInjection

Build
=====

x64
=====

Open the 'rdi.sln' file in Visual Studio C++ (from 2022, 2019 will not work) and build the solution in Release (x64) mode to make inject.x64.exe and reflective_dll.x64.dll

x32
=====

Open the 'rdi.sln' file in Visual Studio C++ (from 2022, 2019 will not work) and build the solution in Release (Win32) mode to make inject.exe and reflective_dll.dll

Usage
=====

To test use the inject.x64.exe (or inject.exe for x32) to inject reflective_dll.x64.dll into a host process via a process id, e.g.:

> inject.x64.exe 1234
> inject.exe 6084
	
License
=======

Licensed under a 3 clause BSD license, please see LICENSE.txt for details.
