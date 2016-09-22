// The Art of C++ / Sequences
// Copyright (c) 2015 Daniel Frey

#ifndef TAOCPP_SEQUENCES_INCLUDE_EXCLUSIVE_SCAN_HPP
#define TAOCPP_SEQUENCES_INCLUDE_EXCLUSIVE_SCAN_HPP

#include <utility>

#include "make_integer_sequence.hpp"
#include "partial_sum.hpp"

namespace tao
{
	namespace seq
	{
		// Changed the original implementation of exclusive_scan, because it crashes the VS2015's compiler.

		//namespace impl
		//{
		//  template< typename S, typename = make_index_sequence< S::size() > >
		//  struct exclusive_scan;

		//  template< typename S, std::size_t... Is >
		//  struct exclusive_scan< S, index_sequence< Is... > >
		//  {
		//    using type = integer_sequence< typename S::value_type, partial_sum< Is, S >::value... >;
		//  };
		//}

		//template< typename T, T... Ns >
		//struct exclusive_scan
		//  : impl::exclusive_scan< integer_sequence< T, Ns... > >
		//{};

		//template< typename T, T... Ns >
		//struct exclusive_scan< integer_sequence< T, Ns... > >
		//  : impl::exclusive_scan< integer_sequence< T, Ns... > >
		//{};

		//template< typename T, T... Ns >
		//using exclusive_scan_t = typename exclusive_scan< T, Ns... >::type;

		namespace impl
		{
			template <typename Numbers, typename Sums, typename Accumulator>
			struct exclusive_scan;

			template <typename T, T N, T... Ns, T S, T... Ss>
			struct exclusive_scan<integer_sequence<T, N, Ns...>, integer_sequence<T, Ss...>, integer_sequence<T, S>>
				: exclusive_scan<integer_sequence<T, Ns...>, integer_sequence<T, Ss..., S + N>, integer_sequence<T, S + N>>
			{};

			template <typename T, T N, T S, T... Ss>
			struct exclusive_scan<integer_sequence<T, N>, integer_sequence<T, Ss...>, integer_sequence<T, S>>
			{
				using type = integer_sequence<T, Ss...>;
			};
		}

		template <typename T, T... Ns>
		struct exclusive_scan
			: impl::exclusive_scan<integer_sequence<T, Ns...>, integer_sequence<T, 0>, integer_sequence<T, 0>>
		{};

		template <typename T, T... Ns>
		using exclusive_scan_t = typename exclusive_scan<T, Ns...>::type;
	}
}

#endif // TAOCPP_SEQUENCES_INCLUDE_EXCLUSIVE_SCAN_HPP
