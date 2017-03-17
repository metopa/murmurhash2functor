/** @file main.cpp
 *  @brief
 *
 *  @author Viacheslav Kroilov (metopa) <slavakroilov@gmail.com>
 */

#include <iostream>
#include "murmurhash2functor.h"

int main() {
	mmh2::MurmurHash2<int> h;
	std::cout << h(700) << std::endl;
	return 0;
}
