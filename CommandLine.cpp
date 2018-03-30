// CommandLine.cpp
// Copyright 2018 Daiki Yoshida. All rights reserved.
// This file is a source file in DFS-CommandLineShell project.
// This file and DFS-CommandLineShell project are licensed by GNU-GPL v3.0.
// You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

// standard library
#include <string>
#include <iostream>

// boost
#include <boost/format.hpp>

// header
#include "function.h"
#include "exception.h"

// using
using namespace std;
using namespace boost;

[[noreturn]] void dfs_cls::CommandLine()
{
	wcout << L"DFS-CommandLineShell" << endl;
	wcout << L"Copyright 2018 Daiki Yoshida. All rights reserved." << endl;
	wcout << L"This program and its source files and header files are licensed by GNU-GPL v3.0." << endl;
	wcout << L"You can see document of GNU-GPL v3.0 in \"LICENSE\" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html)." << endl;
	wcout << endl;

	while(true)
	{
		wcout << L'>';
		wstring command;
		getline(wcin, command);

		try
		{
			CommandProcess(command);
		}
		catch(dfs_cls::exception& e)
		{
			wcerr << wformat{L"error: %1%."} % e.getMessage() << endl;
		}

		wcout << endl;
	}
}
