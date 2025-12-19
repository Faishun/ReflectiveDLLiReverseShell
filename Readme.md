About
=====

This is a fork of an updated Reflective DLL PoC tested to work on Visual Studio 2022 (instead of old 2012 version) v143 Windows 10 system.

Currently tested only for x64 and only Windows to Linux reverse shell.

Original Old Repo
========

https://github.com/stephenfewer/ReflectiveDLLInjection

Build
=====

Open the 'rdi.sln' file in Visual Studio C++ (from 2022, 2019 will not work) and build the solution in Release mode to make inject.exe and reflective_dll.dll

Usage
=====

To test use the inject.x64.exe to inject reflective_dll.x64.dll into a host process via a process id, e.g.:

> inject.x64.exe 1234
	
License
=======

Licensed under a 3 clause BSD license, please see LICENSE.txt for details.
