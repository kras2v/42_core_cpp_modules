#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>
# include <string>

class Data
{
	private:
		const std::string _name;

	public:
		Data() = delete;
		Data(std::string _name);
		Data &operator=(const Data &other);
		~Data();

		Data(const Data &other);
		const std::string &getName();
};

#endif /* DATA_HPP */
