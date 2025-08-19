#include "Harl.hpp"

Harl::Harl()
{
	#ifdef DEBUG
		std::cout << "Harl constructor" << std::endl;
	#endif
	this->_complains[DEBUG].name = "DEBUG";
	this->_complains[DEBUG].function = &Harl::debug;
	this->_complains[INFO].name = "INFO";
	this->_complains[INFO].function = &Harl::info;
	this->_complains[WARNING].name = "WARNING";
	this->_complains[WARNING].function = &Harl::warning;
	this->_complains[ERROR].name = "ERROR";
	this->_complains[ERROR].function = &Harl::error;
}

Harl::~Harl()
{
	#ifdef DEBUG
		std::cout << "Harl destructor" << std::endl;
	#endif
}
void Harl::debug( void )
{
	std::cout << "\e[1;35m[DEBUG]\e[0;37m I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
	<< "ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "\e[1;36m[INFO]\e[0;37m I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
	<< "ketchup burger. I really do!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "\e[1;32m[WARNING]\e[0;37m I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
	<< "ketchup burger. I really do!" << std::endl;
}

void Harl::error( void )
{
	std::cout << "\e[1;33m[ERROR]\e[0;37m I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"
	<< "ketchup burger. I really do!" << std::endl;
}

void Harl::complain( std::string level )
{
	for (size_t i = DEBUG; i < NUMBER_OF_COMPLAINS; i++)
	{
		if (level == this->_complains[i].name)
		{
			(this->*_complains[i].function)();
			return;
		}
	}
	std::cerr << "\e[1;31mCouldn't find level " << level << ". Please try again." << std::endl;
}
