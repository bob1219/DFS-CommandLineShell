#ifndef FUNCTION_H
#define FUNCTION_H

// standard library
#include <string>
#include <iostream>

namespace dfs_cls
{
	[[noreturn]] void CommandLine();
	void script(const std::wstring& filename);
	inline void welcome() { std::wcout << L"welcome to DFS-CommandLineShell" << endl; }
	void CommandProcess(const std::wstring& command);
}

#endif
