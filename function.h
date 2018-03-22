#ifndef FUNCTION_H
#define FUNCTION_H

// standard library
#include <string>
#include <iostream>
#include <regex>
#include <vector>

namespace dfs_cls
{
	[[noreturn]] void CommandLine();
	void script(const std::wstring& filename);
	inline void welcome() { std::wcout << L"welcome to DFS-CommandLineShell" << endl; }
	void CommandProcess(const std::wstring& command);

	namespace command
	{
		void mk(const std::wstring& filename);
		void rm(const std::wstring& filename);
		void cp(const std::wstring& FromFilename, const std::wstring& ToFilename);
		void basename(const std::wstring& filename);
		inline void findf(const std::wregex& r) { findf(L".", r); }
		void findf(const std::wstring& dirname, const std::wregex& r);
		inline void list() { list(L"."); }
		void list(const std::wstring& dirname);
		void mkdir(const std::wstring& dirname);
		void rmdir(const std::wstring& dirname);
		void cpdir(const std::wstring& fromDirname, const std::wstring& toDirname);
		void rename(const std::wstring& FromName, const std::wstring& ToName);
		void bview(const std::wstring& filename);
		void tview(const std::wstring& filename);
		void cwdir();
		void info(const std::wstring& filename);
		void findt(const std::wstring& filename, const wregex& r);
		void date();
		void time();
		void app(const std::vector<std::wstring>& args);
	}
}

#endif
