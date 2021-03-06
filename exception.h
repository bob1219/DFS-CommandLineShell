// exception.h
// Copyright 2018 Daiki Yoshida. All rights reserved.
// This file is a header file in DFS-CommandLineShell project.
// This file and DFS-CommandLineShell project are licensed by GNU-GPL v3.0.
// You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

#ifndef EXCEPTION_H
#define EXCEPTION_H

// standard library
#include <string>

namespace dfs_cls
{
	class exception
	{
	private:
		std::wstring message;

	public:
		// Constructors
		exception() = default;
		exception(const exception&) = default;
		exception(exception&&) = default;
		explicit exception(const std::wstring& _message) : message{_message} {}

		// Operators
		exception& operator=(const exception&) = default;
		exception& operator=(exception&&) = default;

		const auto getMessage() { return message; }
	};
}

#endif
