#include "Timer.hpp"

void Timer::showTimeReport(size_t size, std::string type, u_time_duration duration)
{
	std::cout << "Time to process a range of " << size << " elements "
	<< "with "<< type << " : "
	<< duration.count() <<" us" << std::endl;
}