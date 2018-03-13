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
	while(true)
	{
		wstring command;
		wcout << L'>';
		getline(wcin, command);

		try
		{
			CommandProcess(command);
		}
		catch(dfs_cls::exception& e)
		{
			wcerr << wformat(L"error: %1%.") % e.getMessage() << endl;
		}

		wcout << endl;
	}
}
