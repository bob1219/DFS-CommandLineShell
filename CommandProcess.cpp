// CommandProcess.cpp
// Copyright 2018 Daiki Yoshida. All rights reserved.
// This file is a source file in DFS-CommandLineShell project.
// This file and DFS-CommandLineShell project are licensed by GNU-GPL v3.0.
// You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

// standard library
#include <string>
#include <vector>
#include <cstdlib>
#include <regex>

// header
#include "function.h"
#include "wtokenizer.h"
#include "exception.h"

// using
using namespace std;

void dfs_cls::CommandProcess(const wstring& command)
{
	// Tokenize
	wtokenizer Tokenizer{command, wseparator{L'\\', L' ', L'\''}};
	vector<wstring> tokens;
	for(const auto& token: Tokenizer)
		tokens.push_back(token);

	auto arg_error = [](){ throw dfs_cls::exception{L"few or many arguments"}; };

	if(tokens.at(0) == L"mk")
	{
		if(tokens.size() != 2)
			arg_error();
		command::mk(tokens.at(1));
	}
	else if(tokens.at(0) == L"rm")
	{
		if(tokens.size() != 2)
			arg_error();
		command::rm(tokens.at(1));
	}
	else if(tokens.at(0) == L"cp")
	{
		if(tokens.size() != 3)
			arg_error();
		command::cp(tokens.at(1), tokens.at(2));
	}
	else if(tokens.at(0) == L"basename")
	{
		if(tokens.size() != 2)
			arg_error();
		command::basename(tokens.at(1));
	}
	else if(tokens.at(0) == L"findf")
	{
		if(tokens.size() == 2)
			command::findf(wregex{tokens.at(1)});
		else if(tokens.size() == 3)
			command::findf(tokens.at(1), wregex{tokens.at(2)});
		else arg_error();
	}
	else if(tokens.at(0) == L"list")
	{
		if(tokens.size() == 1)
			command::list();
		else if(tokens.size() == 2)
			command::list(tokens.at(1));
		else arg_error();
	}
	else if(tokens.at(0) == L"mkdir")
	{
		if(tokens.size() != 2)
			arg_error();
		command::mkdir(tokens.at(1));
	}
	else if(tokens.at(0) == L"rmdir")
	{
		if(tokens.size() != 2)
			arg_error();
		command::rmdir(tokens.at(1));
	}
	else if(tokens.at(0) == L"cpdir")
	{
		if(tokens.size() != 3)
			arg_error();
		command::cpdir(tokens.at(1), tokens.at(2));
	}
	else if(tokens.at(0) == L"rename")
	{
		if(tokens.size() != 3)
			arg_error();
		command::rename(tokens.at(1), tokens.at(2));
	}
	else if(tokens.at(0) == L"bview")
	{
		if(tokens.size() != 2)
			arg_error();
		command::bview(tokens.at(1));
	}
	else if(tokens.at(0) == L"tview")
	{
		if(tokens.size() != 2)
			arg_error();
		command::tview(tokens.at(1));
	}
	else if(tokens.at(0) == L"cwdir")
	{
		if(tokens.size() != 1)
			arg_error();
		command::cwdir();
	}
	else if(tokens.at(0) == L"info")
	{
		if(tokens.size() != 2)
			arg_error();
		command::info(tokens.at(1));
	}
	else if(tokens.at(0) == L"findt")
	{
		if(tokens.size() != 3)
			arg_error();
		command::findt(tokens.at(1), wregex{tokens.at(2)});
	}
	else if(tokens.at(0) == L"now")
	{
		if(tokens.size() != 1)
			arg_error();
		command::now();
	}
	else if(tokens.at(0) == L"app")
	{
		if(tokens.size() == 1)
			arg_error();
		command::app(vector<wstring>{begin(tokens) + 1, end(tokens)});
	}
	else if(tokens.at(0) == L"chdir")
	{
		if(tokens.size() != 2)
			arg_error();
		command::chdir(tokens.at(1));
	}
	else if(tokens.at(0) == L"exit")
		exit(EXIT_SUCCESS);
	else throw dfs_cls::exception{L"unknown command"};
}
