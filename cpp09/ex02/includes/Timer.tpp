#ifndef TIMER_TPP
# define TIMER_TPP

# include "Timer.hpp"

template <template <typename...> class Container, typename T>
u_time_duration Timer::track_time( void(*func)(Container<T>&), Container<T>& container)
{
	u_time_point start = std::chrono::high_resolution_clock::now();
	func(container);
	u_time_point end = std::chrono::high_resolution_clock::now();

	u_time_duration duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	return duration;
}

#endif /* TIMER_TPP */
