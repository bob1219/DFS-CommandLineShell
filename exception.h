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
		explicit exception(const std::wstring& _message) : message{_message} {}
		const std::wstring getMessage() { return message; }
	};
}

#endif
