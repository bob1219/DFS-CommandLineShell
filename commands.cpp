// standard library
#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>

// boost
#include <boost/filesystem.hpp>
#include <boost/format.hpp>

// header
#include "function.h"
#include "exception.h"

// using
using namespace std;
using namespace boost::filesystem;
using namespace boost;

void dfs_cls::command::mk(const wstring& filename)
{
	wofstream file{filename};
	if(file.fail())
		throw dfs_cls::exception{L"failed open file"};
}

void dfs_cls::command::rm(const wstring& filename)
{
	if(!is_regular_file(filename))
		throw dfs_cls::exception{L"it is not file"};

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

void mkdir(const wstring& dirname)
{
	if(!create_directory(dirname))
		throw dfs_cls::exception{L"failed make a directory"};
}

void rmdir(const wstring& dirname)
{
	if(!is_directory(dirname))
		throw dfs_cls::exception{L"it is not directory"};

	try
	{
		remove(dirname);
	}
	catch(filesystem_error)
	{
		throw dfs_cls::exception{L"failed remove"};
	}
}

void cpdir(const wstring& fromDirname, const wstring& toDirname)
{
	try
	{
		if(is_directory(toDirname))
			throw dfs_cls::exception{(wformat{L"exists a directory \"%1%\""} % toDirname).str()};
		if(!create_directories(toDirname))
			throw dfs_cls::exception{(wformat{L"failed make a directory \"%1%\""} % toDirname).str()};

		wstring FromDirname{begin(fromDirname), end(fromDirname)};
		wstring ToDirname{begin(toDirname), end(toDirname)};

		for_each(directory_iterator{FromDirname}, directory_iterator{}, [](const wpath& p)
		{
			if(is_directory(p))
				cpdir(p, ToDirname + PATH_BREAK_CHARACTER + p.filename().wstring());
			else
				copy_file(p, ToDirname + PATH_BREAK_CHARACTER + p.filename().wstring(), copy_option::overwrite_if_exists);
		});
	}
	catch(filesystem_error)
	{
		throw dfs_cls::exception{(wformat{L"failed copy directory \"%1%\" -> \"%2%\""} % fromDirname % toDirname).str()};
	}
}
