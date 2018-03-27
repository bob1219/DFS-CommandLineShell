// script.cpp
// Copyright 2018 Daiki Yoshida All rights reserved.
// This file is a source file in DFS-CommandLineShell project.
// This file and DFS-CommandLineShell project are licensed by GNU-GPL v3.0.
// You can document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

// standard library
#include <string>
#include <iostream>
#include <fstream>

// header
#include "function.h"
#include "exception.h"

// using
using namespace std;

void dfs_cls::script(const wstring& filename)
{
	wifstream file;
	file.imbue(locale{""});
	file.open(filename);
	if(file.fail())
		throw dfs_cls::exception{L"failed open file"};

	wstring line;
	while(getline(file, line))
		CommandProcess(line);
}
