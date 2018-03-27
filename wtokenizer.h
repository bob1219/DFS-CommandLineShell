// wtokenizer.h
// Copyright 2018 Daiki Yoshida. All rights reserved.
// This file is a header file in DFS-CommandLineShell project.
// This file and DFS-CommandLineShell project are licensed by GNU-GPL v3.0.
// You can see document of GNU-GPL v3.0 in "LICENSE" file or GNU official website(https://www.gnu.org/licenses/gpl-3.0.en.html).

#ifndef WTOKENIZER_H
#define WTOKENIZER_H

// standard library
#include <string>

// boost
#include <boost/tokenizer.hpp>

namespace dfs_cls
{
	using wseparator = boost::escaped_list_separator<wchar_t, std::char_traits<wchar_t>>;
	using wtokenizer = boost::tokenizer<wseparator, std::wstring::const_iterator, std::wstring>;
}

#endif
