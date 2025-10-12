#ifndef BITCOINTEXCHANGE_HPP
#define BITCOINTEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <list>
# include <iomanip>
# include <ctime>
# include <algorithm>

class BitcoinExchange
{
	struct s_record
	{
		time_t _date;
		std::string _dateStr;
		float _value;
	};
	using Record = struct s_record;

	private:
		std::string _fileName;
		std::vector<Record> records;

		void checkValue(float value);
		std::vector<Record>::iterator findClosestDateInDB(Record &currentRecord);

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
