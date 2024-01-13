#ifndef BITCOINEXCHANGE_H
#define BITCOINEXCHANGE_H

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <fstream>
#include <iomanip>
#include <sstream>

class BitcoinExchange
{
public:
	BitcoinExchange();
	~BitcoinExchange();
	BitcoinExchange(const std::string& inputPath);
   BitcoinExchange(const BitcoinExchange& src);
   BitcoinExchange& operator=(const BitcoinExchange& src);
	const std::map<std::string, std::string>& getDataBase() const;
private:
	std::map<std::string, std::string> dataBase;
	std::map<std::string, std::string> amounts;
	std::ifstream csv;
	std::ifstream input;
	
	//check csvPath
	void mapContent(std::ifstream& file, std::map<std::string, std::string>& map, const std::string& split, void (BitcoinExchange::*checkValue)(const std::string& str));
	void openFile(std::ifstream& file, const std::string& path);
	void checkDate(const std::string& str);
	void checkPrice(const std::string& str);
	void checkAmount(const std::string& str);
	//check inputPath
	//save csvData
	//search Amount
	//search fil
};
std::ostream& operator<<(std::ostream& os, const BitcoinExchange& src);

#endif     //BITCOINEXCHANGE_H
