/** @file murmurhash2_stl_specializations.h
 *  @brief
 *
 *  @author Viacheslav Kroilov (metopa) <slavakroilov@gmail.com>
 */

#include <string>
#include <tuple>

#include "murmurhash2functor.h"

#ifndef MURMURHASH2FUNCTOR_MURMURHASH2_STL_SPECIALIZATIONS_H
#define MURMURHASH2FUNCTOR_MURMURHASH2_STL_SPECIALIZATIONS_H

namespace mmh2 {
	namespace detail {
		template <size_t Idx>
		struct TupleHasher {
			template <typename... TupleArgs>
			static void applyToTuple(const std::tuple<TupleArgs...>& x,
									 size_t& hash) {
				TupleHasher<Idx - 1>::applyToTuple(x, hash);
				hash = getMurmurHash2(std::get<Idx - 1>(x), hash);
			}
		};

		template <>
		struct TupleHasher<0> {
			template <typename... TupleArgs>
			static void applyToTuple(const std::tuple<TupleArgs...>& x,
									 size_t& hash) {}
		};
	};

	template <typename... TupleArgs>
	struct MurmurHash2<std::tuple<TupleArgs...>> {
		uint64_t operator ()(const std::tuple<TupleArgs...>& x, uint64_t seed = 0) {
			uint64_t hash = seed;

			detail::TupleHasher<sizeof...(TupleArgs)>::applyToTuple(x, hash);
			return hash;
		}
	};

}

#endif //MURMURHASH2FUNCTOR_MURMURHASH2_STL_SPECIALIZATIONS_H
