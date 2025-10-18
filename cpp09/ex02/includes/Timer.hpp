#ifndef TIMER_HPP
#define TIMER_HPP

# include <iostream>
# include <chrono>

using u_time_point = std::chrono::_V2::system_clock::time_point;
using u_time_duration = std::chrono::microseconds;

class Timer
{
	private:
		Timer() = delete;
		Timer(const Timer& other) = delete;
		Timer& operator=(const Timer& other) = delete;
		~Timer() = delete;

	public:
		template <template <typename...> class Container, typename T>
		static u_time_duration track_time( void(*func)(Container<T>&), Container<T>& container);

		static void showTimeReport(size_t size, std::string type, u_time_duration duration);
};

# include "Timer.tpp"

#endif /*  TIMER_HPP */
