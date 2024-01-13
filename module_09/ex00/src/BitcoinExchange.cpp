#include <BitcoinExchange.hpp>

BitcoinExchange::BitcoinExchange()
{
//Const
	openFile(csv, "data.csv");
	mapContent(csv, dataBase, ",", &BitcoinExchange::checkPrice);
}

BitcoinExchange::BitcoinExchange(const std::string& inputPath)
{
//Const
	openFile(csv, "data.csv");
	openFile(input, inputPath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
//Copy Const
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
//Dest
}

BitcoinExchange& BitcoinExchange::operator = (const BitcoinExchange& src)
{
	if (this != &src)
	{
		csv.close();
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

std::ostream& operator<<(std::ostream& os, const BitcoinExchange& src)
{
std::map<std::string, std::string>::const_iterator it = src.getDataBase().begin();
    std::map<std::string, std::string>::const_iterator end = src.getDataBase().end();

    for (; it != end; ++it) {
        os << "Key: " << it->first << ", Value: " << it->second << '\n';
    }
	return os;
}

void BitcoinExchange::openFile(std::ifstream& file, const std::string& path)
{
	file.open(path);
	if (!file.is_open())
		throw std::runtime_error("Error : could not open file.");
}

void BitcoinExchange::mapContent(std::ifstream& file, std::map<std::string, std::string>& map, const std::string& split, void (BitcoinExchange::*checkValue)(const std::string& str))
{
	std::string line;
	
	std::string date;
	std::string value;
	std::size_t splitPos;

	while (std::getline(file, line))
	{
		splitPos = line.find_first_of(split);
		if (splitPos == std::string::npos)
			throw std::logic_error("Error : file doesn't contain the separator");
		date = line.substr(0, splitPos);
		checkDate(date);
		value = line.substr(splitPos, line.length());
		(this->*checkValue)(value);
		map.insert(std::make_pair(date, value));
	}
}

void BitcoinExchange::checkDate(const std::string& str)
{
	std::stringstream fecha;
	std::tm tm;
	fecha << str;
	if (static_cast<bool>(fecha >> std::get_time(&tm, "%Y/%m/%d")) == false)
		throw std::logic_error("Error : bad date => " + str);
}

void BitcoinExchange::checkPrice(const std::string& str)
{
	try
	{
		std::atof(str.c_str());
	}catch(std::exception& e)
	{
		throw std::logic_error("Error : bad price format => " + str);
	}
}
/*
void BitcoinExchange::checkAmount(const std::string& str)
{
	try
	{
	}catch(std::exception& e)
	{
		throw std::logic_error("Error : bad amount format => " + str);
	}
}
	
}
*/
