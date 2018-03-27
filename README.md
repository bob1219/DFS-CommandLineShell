DFS-CommandLineShell
=============
DFS-CommandLineShell is a command-line-shell project.

Development Environment
-----------------------
* Operating System: Microsoft Windows 10
* Programming Language: C++
* Builder: Microsoft Visual Studio 2017
* Makefile: Microsoft nmake

Usage
-----
* Boot command-line
	* `shell`
* Run script
	* `shell [filename]`

Commands
--------
* mk  
	* Description: Make a file
	* Usage: `mk [filename]`

* rm  
	* Description: Remove a file
	* Usage: `rm [filename]`

* cp  
	* Description: Copy file
	* Usage: `cp [source-filename] [destination-filename]`

* basename  
	* Description: Print basename
	* Usage: `basename [filename]`

* findf  
	* Description: Find a file
	* Usage: `findf <target-dirname> [regex]`

* list  
	* Description: Print list of files and directories
	* Usage: `list <target-dirname>`

* mkdir  
	* Description: Make a directory
	* Usage: `mkdir [dirname]`

* rmdir  
	* Description: Remove a directory
	* Usage: `rmdir [dirname]`

* cpdir  
	* Description: Copy directory
	* Usage: `cpdir [source-filename] [destination-filename]`

* rename  
	* Description: Rename a file or a directory
	* Usage: `rename [source-name] [destination-name]`

* bview  
	* Description: View binary of a file
	* Usage: `bview [filename]`

* tview  
	* Description: View text of a file
	* Usage: `tview [filename]`

* cwdir  
	* Description: Print current working directory
	* Usage: `cwdir`

* info  
	* Description: Print information of a file or a directory
	* Usage: `info [name]`

* findt  
	* Description: Find text by regex in a file
	* Usage: `findt [filename] [regex]`

* now  
	* Description: Print current date and time
	* Usage: `now`

* app  
	* Description: Execute a application
	* Usage: `app [application-name] <arguments>`

* chdir  
	* Description: Change current working directory
	* Usage: `chdir [dirname]`

* exit  
	* Description: Exit DFS-CommandLineShell
	* Usage: `exit`

Files
-----
* Source file
	* CommandLine.cpp
	* CommandProcess.cpp
	* commands.cpp
	* main.cpp
	* script.cpp

* Header file
	* constant.h
	* exception.h
	* function.h
	* wtokenizer.h

* Other
	* .gitignore
	* LICENSE
	* makefile
	* boost/

History
-------
* 1.0 (March 27th, 2018)
	* First version

License
-------
Copyright 2018 Daiki Yoshida. All rights reserved.
This program and its source file and header file are licensed by GNU-GPL v3.0.
You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).
