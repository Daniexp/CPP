#include <BitcoinExchange.hpp>

template <class T>
BitcoinExchange<T>::BitcoinExchange()
{
//Const
}

template <class T>
BitcoinExchange<T>::BitcoinExchange(const BitcoinExchange<T>& src)
{
//Copy Const
	*this = src;
}

template <class T>
BitcoinExchange<T>::~BitcoinExchange()
{
//Dest
}

template <class T>
BitcoinExchange<T>& BitcoinExchange<T>::operator = (const BitcoinExchange<T>& src)
{
	if (*this != src)
		this->dataBase = src.dataBase;
	return *this;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const BitcoinExchange<T>& src)
{
	os << src.dataBase;
	return os;
}
