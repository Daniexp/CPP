#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <map>

template <class T>
class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const std::string& csvPath);
   BitcoinExchange(const BitcoinExchange<T>& src);
   BitcoinExchange& operator=(const BitcoinExchange<T>& src);
private:
	std::map<std::string, T> dataBase;
	//check csvPath
	//check inputPath
	//save csvData
	//search Amount
	//search fil
};
template <class T>
std::ostream& operator<<(std::ostream& os, const BitcoinExchange<T>& src);

#endif     //BITCOINEXCHANGE_H
