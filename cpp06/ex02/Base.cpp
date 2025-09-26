#include "Base.hpp"

Base::~Base()
{
	#ifdef DEBUG
		std::cout << "Base destructor" << std::endl;
	#endif
}