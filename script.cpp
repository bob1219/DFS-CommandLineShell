// standard library
#include <string>
#include <iostream>
#include <fstream>

// header
#include "function.h"
#include "exception.h"

// using
using namespace std;

void dfs_cls::script(const wstring& filename)
{
	wifstream file;
	file.imbue(locale{""});
	file.open(filename);
	if(file.fail())
		throw dfs_cls::exception{L"failed open file"};

	wstring line;
	while(getline(file, line))
		CommandProcess(line);
}
