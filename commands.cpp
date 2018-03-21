// standard library
#include <string>
#include <iostream>
#include <fstream>

// boost
#include <boost/filesystem.hpp>

// header
#include "function.h"
#include "exception.h"

// using
using namespace std;

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
