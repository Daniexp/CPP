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
	mapContent(input, amounts, &BitcoinExchange::checkPrice);
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

void BitcoinExchange::mapContent(std::ifstream& file, std::map<std::string, std::string>& map, void (BitcoinExchange::*checkValue)(const std::string& str))
{
	std::string line;
	
	std::getline(file,line);
	const std::string& split = parseHeader(line);
	while (std::getline(file, line))
		saveLineValues(split, line, map, checkValue);
}
void BitcoinExchange::saveLineValues(const std::string& split, std::string& line, std::map<std::string, std::string>& map, void (BitcoinExchange::*checkValue)(const std::string& str))
{
		std::size_t splitPos = line.find_first_of(split);
		if (splitPos == std::string::npos)
			throw std::logic_error("Error : file doesn't contain the separator");
		std::string date = line.substr(0, splitPos);
		checkDate(date);
		std::string value = line.substr(splitPos + 1, line.length());
		(this->*checkValue)(value);
		map.insert(std::make_pair(date, value));
	
}

void BitcoinExchange::printResults(const std::string& inputPath)
{
	openFile(input, inputPath);
	std::string line;
	std::getline(input, line);
	const std::string& split = parseHeader(line);
	while (std::getline(input, line))
	{
		try
		{
			saveLineValues(split, line, amounts, &BitcoinExchange::checkAmount);
			//el nodo ha sido guardado
			//entrar nodo del map
			//apartir de key ( date ) buscar en database
				//si una date no existe buscar la anterior
			//printear feccha amoont => amount * exchange_rate de ese día
		}
		catch(std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

void BitcoinExchange::checkDate(const std::string& str)
{
	std::stringstream fecha;
	std::tm tm;
	fecha << str;
	if (static_cast<bool>(fecha >> std::get_time(&tm, "%Y-%m-%d")) == false)
		throw std::logic_error("Error : bad date => " + str);
}

void BitcoinExchange::checkPrice(const std::string& str)
{
	float value = 0.0;
	try
	{
		value = std::atof(str.c_str());
	}catch(std::exception& e)
	{
		throw std::logic_error("Error : bad price format => " + str);
	}
	if (isLess(value, 0.0f, 0.009))
		throw std::logic_error("Error : bad price format => " + str);
}
const std::string BitcoinExchange::parseHeader(const std::string& str)
{
	std::string split;
	if("date,exchange_rate" == str)
		split = ",";
	else if ("date | value" == str)
		split = "|";
	else
		throw std::logic_error("Error : no valid header in the file.");
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
		throw std::logic_error("Error : bad price format => " + str);
	}
	if (isLess(value, 0.0f, 0.009) || isMore(value, 1000.0f, 0.009))
		throw std::logic_error("Error : bad price format => " + str);
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
