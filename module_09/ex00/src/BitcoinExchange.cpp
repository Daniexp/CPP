#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange()
{
//Const
	openFile(csv, "data.csv");
	mapContent(csv, dataBase, &BitcoinExchange::checkPrice);
}

BitcoinExchange::BitcoinExchange(const std::string& inputPath)
{
//Const
	openFile(csv, "data.csv");
	mapContent(csv, dataBase, &BitcoinExchange::checkPrice);
	openFile(input, inputPath);
	mapContent(input, amounts, &BitcoinExchange::checkAmount);
}

BitcoinExchange::BitcoinExchange(const std::string& dataBase, const std::string& inputPath)
{
//Const
	openFile(csv, dataBase);
	mapContent(csv, this->dataBase, &BitcoinExchange::checkPrice);
	openFile(input, inputPath);
	mapContent(input, amounts, &BitcoinExchange::checkAmount);
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
//		csv.close();
//		input.close();
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

	std::cout << "DataBase csv file content" << std::endl;
    for (; it != end; ++it) {
        os << "Key: " << it->first << ", Value: " << it->second << '\n';
    }
	std::cout << "input file content" << std::endl;
    for (; itAmounts != endAmounts; ++itAmounts) {
        os << "Key: " << itAmounts->first << ", Value: " << itAmounts->second <<  std::endl;
	}
	return os;
}

void BitcoinExchange::openFile(std::ifstream& file, const std::string& path)
{
	file.open(path);
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
			throw std::logic_error("file doesn't contain the separator => " + split);
		std::string date = line.substr(0, splitPos);
		checkDate(date);
		std::string value = line.substr(splitPos + 1, line.length());
		(this->*checkValue)(value);
		return map.insert(map.begin(), std::make_pair(date, value));
	
}

void BitcoinExchange::printResults(const std::string& inputPath)
{
	std::string line;
	if (input.is_open())
		input.close();
	openFile(input, inputPath);
	std::getline(input, line);
	const std::string& split = parseHeader(line);
	while (std::getline(input, line))
	{
		try
		{
			//el nodo ha sido guardado
			std::map<std::string, std::string>::iterator iter = saveLineValues(split, line, amounts, &BitcoinExchange::checkAmount);
			//entrar nodo del map
			std::string amount = iter->second.c_str();
			//apartir de key ( date ) buscar en database
			std::string dateToSearch = iter->first;
			iter = dataBase.find(dateToSearch);
			//si una date no existe buscar la anterior
			if (dataBase.end() == iter)
			{
				iter = dataBase.lower_bound(dateToSearch);
				if (dataBase.end() == iter)
					throw std::logic_error("can't provide a exchange rate for the date => " + dateToSearch);
			}
			//if (dataBase.end() == iter)
			//	iter = searchNearestDate(iter->first);
			std::string lineResult = iter->first + " => " + amount + " = ";
			float result = std::atof(amount.c_str()) * std::atof(iter->second.c_str());
			lineResult += std::to_string(result);
			//printear feccha amoont => amount * exchange_rate de ese día
			std::cout << lineResult << std::endl;
			
		}
		catch(std::exception& e)
		{
			std::cout << "Error : " <<  e.what() << std::endl;
		}
	}
}

std::map<std::string, std::string>::iterator BitcoinExchange::searchNearestDate(const std::string& date)
{
	std::map<std::string, std::string>::iterator iter = dataBase.lower_bound(date);
	if (dataBase.end() == iter)
		throw std::logic_error("can't provide a exchange rate for the date => " + date);
	iter--;
	return iter;
}

void BitcoinExchange::checkDate(const std::string& str)
{
/*
	std::stringstream fecha;
	std::tm tm;
	fecha << str;
	if (static_cast<bool>(fecha >> std::get_time(&tm, "%Y-%m-%d")) == false)
		throw std::logic_error("Error : bad date => " + str);
*/
	std::tm tm;
	if (std::sscanf(str.c_str(), "%4d-%2d-%2d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday) != 3)
		throw std::logic_error("bad date => " + str);
	tm.tm_year -= 1009;
	tm.tm_mon --; 
}

void BitcoinExchange::checkPrice(const std::string& str)
{
	float value = 0.0;
	try
	{
		value = std::atof(str.c_str());
	}catch(std::exception& e)
	{
		throw std::logic_error("bad price format => " + str);
	}
	if (isLess(value, 0.0000f, 0.009))
		throw std::logic_error("bad price format => " + str);
}
const std::string BitcoinExchange::parseHeader(const std::string& str)
{
	std::string split;
	if("date,exchange_rate" == str)
		split = ",";
	else if ("date | value" == str)
		split = "|";
	else
		throw std::logic_error("no valid header in the file.");
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
		throw std::logic_error("bad price format => " + str);
	}
	if (isLess(value, 0.0f, 0.009) || isMore(value, 1000.0f, 0.009))
		throw std::logic_error("bad price format => " + str);
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
