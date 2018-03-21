// standard library
#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>

// boost
#include <boost/filesystem.hpp>

// header
#include "function.h"
#include "exception.h"

// using
using namespace std;
using namespace boost::filesystem;

void dfs_cls::command::mk(const wstring& filename)
{
	wofstream file{filename};
	if(file.fail())
		throw dfs_cls::exception{L"failed open file"};
}

void dfs_cls::command::rm(const wstring& filename)
{
	try
	{
		remove(filename);
	}
	catch(filesystem_error)
	{
		throw dfs_cls::exception{L"failed remove"};
	}
}

void dfs_cls::command::cp(const wstring& FromFilename, const wstring& ToFilename)
{
	try
	{
		copy_file(FromFilename, ToFilename, overwrite_if_exists);
	}
	catch(filesystem_error)
	{
		throw dfs_cls::exception{L"failed copy"};
	}
}

void basename(const wstring& filename)
{
	wcout << wpath{filename}.filename().wstring() << endl;
}

void findf(const wstring& dirname, const wregex& r)
{
	for_each(directory_iterator{dirname}, directory_iterator{}, [](const wpath& p)
	{
		if(regex_match(p.wstring(), r))
			wcout << p.wstring() << endl;
	});
}

void list(const wstring& dirname)
{
	for_each(directory_iterator{dirname}, directory_iterator{}, [](const wpath& p)
	{
		if(is_regular_file(p))
			wcout << L"file:\t" << p.wstring() << endl;
		else
			wcout << L"dir:\t" << p.wstring() << endl;
	});
}
