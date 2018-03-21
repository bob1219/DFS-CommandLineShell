// standard library
#include <string>
#include <iostream>
#include <fstream>

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
