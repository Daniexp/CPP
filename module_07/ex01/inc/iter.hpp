#ifndef ITER_HPP
#define ITER_HPP 
# include <iostream>
typedef std::basic_string<char> str;

template<typename Type>
void iter(Type* array, const unsigned int length, void (*func)(Type))
{
	for (unsigned int i = 0; i < length; i++)
	{
		func(array[i]);
	}
}

template<typename Type>
void iter(Type* array, const unsigned int length, Type (*func)(Type))
{
	for (unsigned int i = 0; i < length; i++)
	{
		array[i] = func(array[i]);
	}
}

template<typename Type>
void printElement(const Type element)
{
	std::cout << element << " ";
}

template<typename Type>
Type doubleElement(const Type element)
{
	return element + element;
} 

#endif
