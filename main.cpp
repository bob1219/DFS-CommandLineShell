// main.cpp
// Copyright 2018 Daiki Yoshida. All rights reserved.
// This file is a source file in DFS-CommandLineShell project.
// This file and DFS-CommandLineShell project are licensed by GNU-GPL v3.0.
// You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

// standard library
#include <iostream>
#include <clocale>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <exception>

// boost
#include <boost/format.hpp>
#include <boost/system/system_error.hpp>

// header
#include "function.h"
#include "exception.h"

// using
using namespace std;
using namespace dfs_cls;
using namespace boost;

int wmain(int argc, wchar_t** argv)
{
	try
	{
		// setting locale
		wcout.imbue(locale{""});
		wcerr.imbue(locale{""});
		wcin.imbue(locale{""});
		setlocale(LC_ALL, "");

		if(argc == 1)
		{
			welcome();
			wcout << endl;
			CommandLine();
		}
		else if(argc == 2)
			script(argv[1]);
		else
		{
			wcerr << wformat{L"usage: %1% <script-filename>"} % argv[0] << endl;
			return EXIT_FAILURE;
		}

		return EXIT_SUCCESS;
	}
	catch(boost::system::system_error& e)
	{
		const auto		mess_c		= e.what();
		const auto		mess_len	= strlen(mess_c);
		unique_ptr<wchar_t[]>	mess{new wchar_t[mess_len + 1]};
		mbstowcs(mess.get(), mess_c, mess_len + 1);

		wcerr << L"error:" << endl;
		wcerr << mess.get() << endl;
		wcerr << wformat{L"(error code: %1%)"} % e.code().value() << endl;
	}
	catch(std::exception& e)
	{
		const auto		mess_c		= e.what();
		const auto		mess_len	= strlen(mess_c);
		unique_ptr<wchar_t[]>	mess{new wchar_t[mess_len + 1]};
		mbstowcs(mess.get(), mess_c, mess_len + 1);

		wcerr << L"error:" << endl;
		wcerr << mess.get() << endl;
	}
	catch(dfs_cls::exception& e)
	{
		wcerr << L"error:" << endl;
		wcerr << e.getMessage() << endl;
	}

	return EXIT_FAILURE;
}
