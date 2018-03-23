#ifndef WTOKENIZER_H
#define WTOKENIZER_H

// standard library
#include <string>

// boost
#include <boost/filesystem.hpp>

namespace dfs_cls
{
	using wseparator = escaped_list_separator<wchar_t, std::char_traits<wchar_t>>;
	using wtokenizer = tokenizer<wseparator, std::wstring::const_iterator, std::wstring>;
}

#endif
