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
		inline void chdir(const std::wstring& dirname) { current_path(dirname); }

		inline void mk(const std::wstring& filename);
		{
			std::wofstream file{filename};
			if(file.fail())
				throw dfs_cls::exception{L"failed open file"};
		}

		inline void mkdir(const std::wstring& dirname);
		{
			if(!create_directory(dirname))
				throw dfs_cls::exception{L"failed make a directory"};
		}
	}
}

#endif
