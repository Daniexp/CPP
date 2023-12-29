#ifndef EX00_HPP
#define EX00_HPP
# include <iostream>

template <class anyType>
void swap(anyType &firstValue, anyType &secondValue)
{
	anyType temporal = firstValue;
	firstValue = secondValue;
	secondValue = temporal;
}

template <class anyType>
anyType min(anyType firstValue, anyType secondValue)
{
	return (firstValue < secondValue ? firstValue : secondValue);
}

template <class anyType>
anyType max(anyType firstValue, anyType secondValue)
{
	return (firstValue > secondValue ? firstValue : secondValue);
}
#endif
