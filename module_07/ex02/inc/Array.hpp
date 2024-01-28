#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstddef>
#include <string>
#include <exception>
template <typename T> class Array
{
public:
	Array();
	Array(const unsigned int n);
	~Array();
   	Array(const Array& src);
   	Array& operator=(const Array& src);
	T& operator[](std::size_t index);
	std::size_t size(void) const;
private:
	T* elements;
	std::size_t *_size;
};
#include <Array.tpp>
#endif     //ARRAY_H
