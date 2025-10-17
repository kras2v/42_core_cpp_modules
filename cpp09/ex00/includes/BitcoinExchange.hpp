#ifndef BITCOINTEXCHANGE_HPP
#define BITCOINTEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <iomanip>
# include <ctime>
# include <algorithm>

class BitcoinExchange
{
	struct Date
	{
		time_t _date;
		std::string _dateStr;

		bool operator<(const Date &other) const {
			return _date < other._date;
		}
	};

	private:
		std::string _fileName;
		std::map<Date, float> records;

		void checkValue(float value);
		std::map<Date, float>::iterator findClosestDateInDB(Date &currentRecord);

	public:
		BitcoinExchange() = delete;
		BitcoinExchange(std::string fileName);
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		//MAKE PRIVATE
		void readFile();
		void validateFileName();

		void getData();
		time_t parseDate(std::string line, std::string errmsg);
		float parseValue(std::string line, std::string errmsg);

		class FileException : public std::exception
		{
			private:
				std::string _message;
			
			public:
				FileException(const std::string& message);
				virtual const char* what() const throw();
		};
};

#endif /*  BITCOINTEXCHANGE_HPP */
