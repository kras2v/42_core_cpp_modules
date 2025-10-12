#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string fileName) : _fileName(fileName)
{
	#ifdef DEBUG
		std::cout << "BitcoinExchange parameterized constructor called with fileName: " << fileName << std::endl;
	#endif
	this->validateFileName();
}

BitcoinExchange::~BitcoinExchange()
{
	#ifdef DEBUG
		std::cout << "BitcoinExchange destructor called" << std::endl;
	#endif
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _fileName(other._fileName)
{
	#ifdef DEBUG
		std::cout << "BitcoinExchange copy constructor called" << std::endl;
	#endif
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	#ifdef DEBUG
		std::cout << "BitcoinExchange assignment operator called" << std::endl;
	#endif
	if (this != &other)
	{
		this->_fileName = other._fileName;
	}
	return *this;
}

void BitcoinExchange::validateFileName()
{
	#ifdef DEBUG
		std::cout << "Checking filename validity for: " << _fileName << std::endl;
	#endif

	if (_fileName.empty())
	{
		throw FileException("Error: Filename cannot be empty");
	}
}

BitcoinExchange::FileException::FileException(const std::string& message) : _message(message)
{
	#ifdef DEBUG
		std::cout << "FileException constructor called" << std::endl;
	#endif
}

const char* BitcoinExchange::FileException::what() const throw()
{
	return this->_message.c_str();
}

void BitcoinExchange::checkValue(float value)
{
	if (value < 0)
		throw FileException("Error: not a positive number.");
	else if (value > 1000)
		throw FileException("Error: too large a number.");
}

std::vector<BitcoinExchange::Record>::iterator BitcoinExchange::findClosestDateInDB(Record &currentRecord)
{
	std::vector<Record>::iterator it = std::lower_bound(
		this->records.begin(), this->records.end(),
		currentRecord,
		[](const Record &record1, const Record &record2) {
		return record1._date <= record2._date;
	});
	if (it != this->records.begin()) {
		--it;
	}
	if (it == this->records.begin() && currentRecord._date < it->_date)
		throw FileException("Error: bad input (date before first record) => " + currentRecord._dateStr);
	return it;
}

void BitcoinExchange::readFile()
{
	std::ifstream ifs(this->_fileName);
	if (!ifs.is_open())
		throw FileException("Error: Could not open file: " + _fileName);

	std::string line;

	std::getline(ifs, line);
	if (line.compare("date | value"))
		throw FileException("Error: wrong file formating!");

	while (std::getline(ifs, line))
	{
		try
		{
			if (line.length() < 10)
				throw FileException("Error: bad input => " + line);

			Record currentRecord;
			currentRecord._dateStr = line.substr(0, 10);
			currentRecord._date = parseDate(currentRecord._dateStr, "Error: bad input => " + currentRecord._dateStr);

			if (line.length() <= 13)
				throw FileException("Error: bad input => " + line.substr(0));

			currentRecord._value = parseValue(line.substr(13), "Error: bad input => " + line.substr(13));
			checkValue(currentRecord._value);

			std::vector<Record>::iterator it = findClosestDateInDB(currentRecord);
			Record searchRecord = *it;
			std::cout << currentRecord._dateStr << " => " << currentRecord._value << " = " << searchRecord._value * currentRecord._value << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	ifs.close();
}

time_t BitcoinExchange::parseDate(std::string line, std::string errmsg)
{
	std::istringstream ss(line);

	tm tm = {};
	ss >> std::get_time(&tm, "%Y-%m-%d");

	if (ss.fail()) {
		throw FileException(errmsg);
	}

	return mktime(&tm);
}

float BitcoinExchange::parseValue(std::string line, std::string errmsg)
{
	std::istringstream ss(line);
	float value;
	ss >> value;

	if (ss.fail()) {
		throw FileException(errmsg);
	}

	return value;
}

void BitcoinExchange::getData()
{
	#ifdef DEBUG
		std::cout << "Getting data from data.csv" << std::endl;
	#endif

	std::string databaseName = "data.csv";
	std::ifstream ifs(databaseName);

	if (!ifs.is_open())
		throw FileException("Error: Could not open file: " + _fileName);

	std::string line;
	std::getline(ifs, line);
	while (std::getline(ifs, line))
	{
		if (line.length() >= 10)
		{
			Record newRecord;
			newRecord._dateStr = line.substr(0, 10);
			newRecord._date = parseDate(newRecord._dateStr, "Error: database date format is invalid.");
			if (line.length() >= 11)
			{
				newRecord._value = parseValue(line.substr(11), "Error: database value format is invalid.");
				this->records.push_back(newRecord);
			}
			else
			{
				throw FileException("Error: database format is invalid.");
			}
		}
		else
		{
			throw FileException("Error: database format is invalid.");
		}
	}
	ifs.close();
}