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

	#define MMH2_INT_SPECIALIZATION(T) \
	template<> \
	struct MurmurHash2<T> { \
		uint64_t operator()(T x, uint64_t seed = 0) { \
				return detail::hash_impl()(&x, sizeof(T), seed); \
		} \
	};

	MMH2_INT_SPECIALIZATION(bool)

	MMH2_INT_SPECIALIZATION(char)
	MMH2_INT_SPECIALIZATION(short)
	MMH2_INT_SPECIALIZATION(int)
	MMH2_INT_SPECIALIZATION(long)
	MMH2_INT_SPECIALIZATION(long long)

	MMH2_INT_SPECIALIZATION(unsigned char)
	MMH2_INT_SPECIALIZATION(unsigned short)
	MMH2_INT_SPECIALIZATION(unsigned int)
	MMH2_INT_SPECIALIZATION(unsigned long)
	MMH2_INT_SPECIALIZATION(unsigned long long)

#undef MMH2_INT_SPECIALIZATION

	template <>
	struct MurmurHash2<float> {
		uint64_t operator ()(float x, uint64_t seed = 0) {
                return x == 0.0f ?
					   detail::hash_impl()(&seed, sizeof(uint64_t), 0) :
					   detail::hash_impl()(&x, sizeof(float), seed);
		}
	};

	template <>
	struct MurmurHash2<double> {
		uint64_t operator ()(double x, uint64_t seed = 0) {
			return x == 0.0 ?
				   detail::hash_impl()(&seed, sizeof(uint64_t), 0) :
				   detail::hash_impl()(&x, sizeof(double), seed);
		}
	};

	template <>
	struct MurmurHash2<long double> {
		uint64_t operator ()(long double x, uint64_t seed = 0) {
			return x == 0.0l ?
				   detail::hash_impl()(&seed, sizeof(uint64_t), 0) :
				   detail::hash_impl()(&x, sizeof(long double), seed);
		}
	};

	template <typename T>
	size_t getMurmurHash2(const T& x, uint64_t seed = 0) {
		return MurmurHash2<T>()(x, seed);
	}
}

#endif //MMH2_MURMURHASH2FUNCTOR_H
