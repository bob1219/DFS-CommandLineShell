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
