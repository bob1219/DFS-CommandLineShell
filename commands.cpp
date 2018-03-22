// standard library
#include <string>
#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>
#include <cstdlib>

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

void dfs_cls::command::basename(const wstring& filename)
{
	wcout << wpath{filename}.filename().wstring() << endl;
}

void dfs_cls::command::findf(const wstring& dirname, const wregex& r)
{
	for_each(directory_iterator{dirname}, directory_iterator{}, [](const wpath& p)
	{
		if(regex_match(p.wstring(), r))
			wcout << p.wstring() << endl;
	});
}

void dfs_cls::command::list(const wstring& dirname)
{
	for_each(directory_iterator{dirname}, directory_iterator{}, [](const wpath& p)
	{
		if(is_regular_file(p))
			wcout << L"file:\t" << p.wstring() << endl;
		else
			wcout << L"dir:\t" << p.wstring() << endl;
	});
}

void dfs_cls::command::mkdir(const wstring& dirname)
{
	if(!create_directory(dirname))
		throw dfs_cls::exception{L"failed make a directory"};
}

void dfs_cls::command::rmdir(const wstring& dirname)
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

void dfs_cls::command::cpdir(const wstring& fromDirname, const wstring& toDirname)
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

void dfs_cls::command::rename(const wstring& FromName, const wstring& ToName)
{
	try
	{
		rename(FromName, ToName);
	}
	catch(filesystem_error)
	{
		throw dfs_cls::exception{L"failed rename"};
	}
}

void dfs_cls::command::bview(const wstring& filename)
{
	ifstream file{filename, ios::binary};
	if(file.fail())
		throw dfs_cls::exception{L"failed open file"};

	vector<char> data;
	for(; !file.eof(); ++i)
	{
		char buf;
		file.read(&buf, 1);
		data.push_back(buf);
	}

	wcout << L"\t+0 +1 +2 +3 +4 +5 +6 +7 +8 +9 +A +B +C +D +E +F 0123456789ABCDEF" << endl;

	vector<vector<char>> DataLines;
	auto BaseIter = begin(data);
	while(true)
	{
		auto start = BaseIter;
		auto end = BaseIter;
		for(unsigned int i{1};; ++i)
		{
			++end;
			if(i == 0x11 || end = end(data))
			{
				--end;
				break;
			}
		}

		DataLines.push_back(vector<char>{start, end});
		if((end + 1) == end(data))
			break;

		BaseIter = end;
	}

	for(const auto& DataLine: DataLines)
	{
		for(auto byte: DataLine)
			wcout << static_cast<unsigned int>(byte) << L' ' << endl;

		for(auto byte: DataLine)
		{
			wchar_t c;
			mbtowc(&c, &byte, 1);
			wcout << c;
		}

		wcout << endl;
	}
}

void dfs_cls::command::tview(const wstring& filename)
{
	wifstream file;
	file.imbue(locale{""});
	file.open(filename);
	if(file.fail())
		throw dfs_cls::exception{L"failed open file"};

	wstring line;
	for(unsigned int i{1}; getline(file, line); ++line)
		wcout << wformat{L"%1%:\t%2%"} % i % line << endl;
}
