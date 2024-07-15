#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange()
{
//Const
	openFile(csv, "data.csv");
	mapContent(csv, dataBase, &BitcoinExchange::checkPrice);
}

BitcoinExchange::BitcoinExchange(const std::string& dataBase)
{
//Const
	openFile(csv, dataBase.c_str());
	mapContent(csv, this->dataBase, &BitcoinExchange::checkPrice);
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
//Copy Const
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
//Dest
	csv.close();
	input.close();
}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange& src)
{
	if (this != &src)
	{
		if (csv.is_open())
			csv.close();
		if (input.is_open())
			input.close();
		this->dataBase = src.dataBase;
		this->amounts = src.amounts;
	}
	return *this;
}
const std::map<std::string, std::string>& BitcoinExchange::getDataBase() const
{
	return dataBase;
}

const std::map<std::string, std::string>& BitcoinExchange::getAmounts() const
{
	return amounts;
}

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& src)
{
std::map<std::string, std::string>::const_iterator it = src.getDataBase().begin();
    std::map<std::string, std::string>::const_iterator end = src.getDataBase().end();
std::map<std::string, std::string>::const_iterator itAmounts = src.getAmounts().begin();
    std::map<std::string, std::string>::const_iterator endAmounts= src.getAmounts().end();

	os << "DataBase csv file content" << std::endl;
    for (; it != end; ++it) {
        os << "Key: " << it->first << ", Value: " << it->second << '\n';
    }
	os << "input file content" << std::endl;
    for (; itAmounts != endAmounts; ++itAmounts) {
        os << "Key: " << itAmounts->first << ", Value: " << itAmounts->second <<  std::endl;
	}
	return os;
}

void BitcoinExchange::openFile(std::ifstream& file, const std::string& path)
{
	file.open(path.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open file.");
}

void BitcoinExchange::mapContent(std::ifstream& file, std::map<std::string, std::string>& map, void (BitcoinExchange::*checkValue)(const std::string& str))
{
	std::string line;
	
	std::getline(file,line);
	const std::string& split = parseHeader(line);
	while (std::getline(file, line))
		saveLineValues(split, line, map, checkValue);
}
std::map<std::string, std::string>::iterator BitcoinExchange::saveLineValues(const std::string& split, std::string& line, std::map<std::string, std::string>& map, void (BitcoinExchange::*checkValue)(const std::string& str))
{
		std::size_t splitPos = line.find_first_of(split);
		if (splitPos == std::string::npos)
			throw std::logic_error("line doesn't contain the separator => " + split);
		std::string date = line.substr(0, splitPos);
		checkDate(date);
		std::string value = line.substr(splitPos + 1);
		(this->*checkValue)(value);
		rmchr(date, ::isspace);
		rmchr(value, ::isspace);
		map[date] = value;
		return map.find(date);
}

void BitcoinExchange::printResults(const std::string& inputPath)
{
	std::string line;
	if (input.is_open())
		input.close();
	openFile(input, inputPath.c_str());
	std::getline(input, line);
	if (line == "date | value")
		std::getline(input, line);
	std::string split = "|";
	std::map<std::string, std::string>::iterator iter;
	std::string amount;
	std::string dateToSearch;
	do
	{
		try
		{ 
			iter = saveLineValues(split, line, amounts, &BitcoinExchange::checkAmount);
			amount = iter->second;
			dateToSearch = iter->first;
			iter = dataBase.find(dateToSearch);
			if (dataBase.end() == iter)
			{
				iter = dataBase.lower_bound(dateToSearch);
				if (dataBase.begin() == iter)
					throw std::logic_error("can't provide a exchange rate for the date => " + dateToSearch);
				--iter;
			}
			std::string lineResult;
			if (dateToSearch  == iter->first)
				lineResult = dateToSearch + " => " + amount + " = ";
			else
				lineResult = dateToSearch + " not found, closest is " + iter->first + " => " + amount + " = ";
			float result = std::atof(amount.c_str()) * std::atof(iter->second.c_str());
			std::ostringstream os;
			os << result;
			lineResult += os.str();
			std::cout << lineResult << std::endl;
			
		}
		catch(std::exception& e)
		{
			std::cout << "Error : " <<  e.what() << std::endl;
		}
	}
	while (std::getline(input, line));
}

void BitcoinExchange::checkDate(const std::string& str)
{
	tm tm = {};
	if (std::sscanf(str.c_str(), "%4d-%2d-%2d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday) != 3 || tm.tm_year == 0 || tm.tm_mon == 0 || tm.tm_mday == 0 || tm.tm_mday > 31 || tm.tm_mon > 12)
		throw std::logic_error("bad date => " + str);
}

void BitcoinExchange::checkPrice(const std::string& str)
{
	float value = 0.0;
	try
	{
		value = std::atof(str.c_str());
	}catch(std::exception& e)
	{
		throw std::logic_error("bad price => " + str);
	}
	if (isLess(value, 0.0000f, 0.009))
		throw std::logic_error("bad price => " + str);
}
const std::string BitcoinExchange::parseHeader(const std::string& str)
{
	std::string split;

	if("date,exchange_rate" == str)
		split = ",";
	else if ("date | value" == str)
		split = "|";
	else
		throw std::logic_error("Error : No valid header in the file.");
	return split;
}
const std::string BitcoinExchange::parseHeader(std::ifstream& input)
{
	std::string str;
	std::string split = "";

	std::getline(input, str);
	if("date,exchange_rate" == str)
		split = ",";
	else if ("date | value" == str)
		split = "|";
	return split;
}

void BitcoinExchange::checkAmount(const std::string& str)
{
	float value = 0.0;
	try
	{
		value = std::atof(str.c_str());
	}catch(std::exception& e)
	{
		throw std::logic_error("bad amount => " + str);
	}
	if (isLess(value, 0.0f, 0.009) || isMore(value, 1000.0f, 0.009) || (value == 0.0 && str != "0" && str != "0.0" && str != "0.0f"))
		throw std::logic_error("bad amount => " + str);
	for (std::size_t i = 0; i < str.size(); i++)
		if (isalpha(str[i]))
			throw std::logic_error("bad amount => " + str);
}

bool BitcoinExchange::equalFloats(const float&a, const float&b, const float& epsilon)
{
	return (a - b < epsilon);
}
bool BitcoinExchange::isMore(const float&a, const float&b, const float& epsilon)
{
	return (a - b > epsilon);
}
bool BitcoinExchange::isLess(const float&a, const float&b, const float& epsilon)
{
	return (b - a > epsilon);
}
