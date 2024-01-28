#ifndef ITER_HPP
#define ITER_HPP 
# include <iostream>

typedef std::basic_string<char> str;

template<typename Type, typename Func>
void iter(Type* array, const unsigned int length, Func func)
{
	for (unsigned int i = 0; i < length; i++)
		func(array[i]);
}
template<typename Type>
void printElement(const Type element)
{
	std::cout << element << " ";
}

template<typename Type>
void doubleElement(Type& element)
{
	element += element;
} 

#endif
