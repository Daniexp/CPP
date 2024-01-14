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
	void printResults();
	void printResults(const std::string& inputPath);
private:
	std::map<std::string, std::string> dataBase;
	std::map<std::string, std::string> amounts;
	std::ifstream csv;
	std::ifstream input;
	
	//check csvPath
	void mapContent(std::ifstream& file, std::map<std::string, std::string>& map, void (BitcoinExchange::*checkValue)(const std::string& str));
	std::map<std::string, std::string>::iterator saveLineValues(const std::string& split, std::string& line, std::map<std::string, std::string>& map, void (BitcoinExchange::*checkValue)(const std::string& str));
	void openFile(std::ifstream& file, const std::string& path);
	void checkDate(const std::string& str);
	void checkPrice(const std::string& str);
	void checkAmount(const std::string& str);
	const std::string parseHeader(const std::string& str);
	float searchPriceByDate(const std::string& date);	
	std::map<std::string, std::string>::iterator searchNearestDate(const std::string& date);
	bool equalFloats(const float& a, const float& b, const float& epsilon);
	bool isLess(const float& a, const float& b, const float& epsilon);
	bool isMore(const float& a, const float& b, const float& epsilon);
	//check inputPath
	//save csvData
	//search Amount
	//search fil
};
std::ostream& operator<<(std::ostream& os, const BitcoinExchange& src);

#endif     //BITCOINEXCHANGE_H
