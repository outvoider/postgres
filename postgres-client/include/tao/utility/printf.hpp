// The Art of C++ / Utility
// Copyright (c) 2016 Daniel Frey

#ifndef TAOCPP_INCLUDE_UTILITY_PRINTF_HPP
#define TAOCPP_INCLUDE_UTILITY_PRINTF_HPP

#include <string>

namespace tao
{
	namespace utility
	{
		std::string printf(const char* format, ...);
		std::string vprintf(const char* format, va_list ap);
	}
}

#endif // TAOCPP_INCLUDE_UTILITY_PRINTF_HPP
