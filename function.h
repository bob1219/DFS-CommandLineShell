// function.h
// Copyright 2018 Daiki Yoshida All rights reserved.
// This file is a header file in DFS-CommandLineShell project.
// This file and DFS-CommandLineShell project are licensed by GNU-GPL v3.0.
// You can document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

#ifndef FUNCTION_H
#define FUNCTION_H

// standard library
#include <string>
#include <iostream>
#include <regex>
#include <vector>
#include <fstream>

// boost
#include <boost/filesystem.hpp>

// header
#include "exception.h"

namespace dfs_cls
{
	[[noreturn]] void CommandLine();
	void script(const std::wstring& filename);
	inline void welcome() { std::wcout << L"welcome to DFS-CommandLineShell" << std::endl; }
	void CommandProcess(const std::wstring& command);

	namespace command
	{
		void rm(const std::wstring& filename);
		void cp(const std::wstring& SourceFilename, const std::wstring& DestFilename);
		inline void basename(const std::wstring& filename) { std::wcout << boost::filesystem::wpath{filename}.filename().wstring() << std::endl; }
		void findf(const std::wstring& dirname, const std::wregex& r);
		inline void findf(const std::wregex& r) { findf(L".", r); }
		void list(const std::wstring& dirname);
		inline void list() { list(L"."); }
		void rmdir(const std::wstring& dirname);
		void cpdir(const std::wstring& sourceFilename, const std::wstring& destFilename);
		void rename(const std::wstring& SourceName, const std::wstring& DestName);
		void bview(const std::wstring& filename);
		void tview(const std::wstring& filename);
		inline void cwdir() { std::wcout << boost::filesystem::current_path().wstring() << std::endl; }
		void info(const std::wstring& name);
		void findt(const std::wstring& filename, const std::wregex& r);
		void now();
		void app(const std::vector<std::wstring>& args);
		inline void chdir(const std::wstring& dirname) { boost::filesystem::current_path(dirname); }

		inline void mk(const std::wstring& filename)
		{
			std::wofstream file{filename};
			if(file.fail())
				throw dfs_cls::exception{L"failed open file"};
		}

		inline void mkdir(const std::wstring& dirname)
		{
			if(!boost::filesystem::create_directory(dirname))
				throw dfs_cls::exception{L"failed make a directory"};
		}
	}
}

#endif
