//
// Created by ckp on 18-8-29.
//
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>



// Transform A to bytes;

struct Example {
	Example():a(0),b(0),c(0) {}
	double a;
	int32_t b;
	char c;
};

template <class T>
void change_endian(T in, )
{
    char* const p = reinterpret_cast<char*>(&in);
    for (size_t i = 0; i < sizeof(T) / 2; ++i)
        std::swap(p[i], p[sizeof(T) - i - 1]);
    return in;
}





int main() {

	// Example data
	Example eg;
	// 字符串中的空格只是为了区分不同字节
	// Big endian bytes "@ $ ? 5 0x9f 0xf4 0xfd m"
	eg.a = 10.123456;
	// Big endian bytes "0x00 0x00 0x00 x"
	eg.b = 120;
	// Single byte "x"
	eg.c = 'x';
	// ***The final result we want is
	// "@ $ ? 5 0x9f 0xf4 0xfd m 0x00 0x00 0x00 x x"
	// ***

	// Transform into big endian bytes
	// 注意在C++里不要使用 int bytes_count = sizeof(eg)/sizeof(char)代替下面的表达式,
	// 因为sizeof(eg)包含了字节对齐的过程，会更大一些
	int bytes_count = sizeof(eg.a)/sizeof(uint8_t) +
			           sizeof(eg.b)/sizeof(uint8_t) + sizeof(eg.c)/sizeof(uint8_t) ;
	auto buffer = new uint8_t[bytes_count] {};

	uint8_t *ptr = buffer;
	// double to bytes
	auto a =change_endian(eg.a);
	auto big_a = reinterpret_cast<uint8_t*>(&a);
	memcpy(ptr, big_a, 8);
	ptr+=8;
	// int32_t to bytes
	auto b = change_endian(eg.b);
	auto big_b = reinterpret_cast<uint8_t*>(&b);
	memcpy(ptr, big_b, 4);
	ptr+=4;


	auto c = change_endian(eg.c);
	auto big_c = reinterpret_cast<uint8_t*>(&c);
	memcpy(ptr, big_c, 1);
	ptr+=1;


	// Test result
	delete[] buffer;

	for(int i=0;i<bytes_count;i++) {
		printf("0x%x ", buffer[i]);
	}




}

