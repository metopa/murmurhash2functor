/** @file main.cpp
 *  @brief
 *
 *  @author Viacheslav Kroilov (metopa) <slavakroilov@gmail.com>
 */

#include <iostream>
#include "murmurhash2/functor.h"
#include "murmurhash2/stl_specializations.h"

int main() {
	std::cout << mmh2::getMurmurHash2(std::string("")) << std::endl;
	std::cout << mmh2::getMurmurHash2(std::string("AB")) << std::endl;
	std::cout << mmh2::getMurmurHash2(std::string("BA")) << std::endl;
	std::cout << mmh2::getMurmurHash2(std::make_pair(0.f, 0.)) << std::endl;
	std::cout << mmh2::getMurmurHash2(std::make_tuple(0., 0.)) << std::endl;
	std::cout << mmh2::getMurmurHash2(std::make_tuple(-0., 0.)) << std::endl;
	std::cout << mmh2::getMurmurHash2(std::make_tuple(0.)) << std::endl;
	std::cout << mmh2::getMurmurHash2(std::make_tuple(0., 0., 0.)) << std::endl;
	std::cout << mmh2::getMurmurHash2(std::make_tuple(1., 0.)) << std::endl;
	std::cout << mmh2::getMurmurHash2(std::make_tuple(0., 1.)) << std::endl;
	std::cout << mmh2::getMurmurHash2(std::make_tuple(1., 1.)) << std::endl;
	std::cout << mmh2::getMurmurHash2(std::make_tuple(-1., 1.)) << std::endl;
	return 0;
}
