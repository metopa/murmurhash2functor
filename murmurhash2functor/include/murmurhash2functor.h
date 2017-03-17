/** @file murmurhash2functor.h
 *  @brief
 *
 *  @author Viacheslav Kroilov (metopa) <slavakroilov@gmail.com>
 */


#ifndef MMH2_MURMURHASH2FUNCTOR_H
#define MMH2_MURMURHASH2FUNCTOR_H

#include <cstdint>
#include <cstddef>

#include "MurmurHash2.h"

#ifndef MMH2_MACHINE_WORD_SIZE
#define MMH2_MACHINE_WORD_SIZE (sizeof(std::size_t))
#endif

namespace mmh2 {
	namespace detail {
		template <size_t word_size>
		struct impl {
			static_assert(word_size < 0, "MMH2: Machine word size is unknown");
		};

		template <>
		struct impl<4> {
			uint64_t operator()(const void* key, int len, uint64_t seed) {
				return MurmurHash64B(key, len, seed);
			}
		};

		template <>
		struct impl<8> {
			uint64_t operator ()(const void* key, int len, uint64_t seed) {
				return MurmurHash64A(key, len, seed);
			}
		};

		using hash_impl = impl<MMH2_MACHINE_WORD_SIZE>;
	}

	template <class T>
	class MurmurHash2 {
		static_assert(sizeof(T) < 0, "MurmurHash2 is not specialized for this type");
	};

	template<>
	struct MurmurHash2<int> {
		uint64_t operator()(int x) {
				return detail::hash_impl()(&x, sizeof(int), 0);
		}
	};
}

#endif //MMH2_MURMURHASH2FUNCTOR_H
