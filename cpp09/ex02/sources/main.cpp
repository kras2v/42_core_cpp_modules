#include <iostream>
#include <algorithm>
#include <chrono>

#include "PmergeMe.hpp"

using u_time_point = std::chrono::_V2::system_clock::time_point;
using u_time_duration = std::chrono::microseconds;

// void merge(std::vector<int> &ints)
template <template <typename...> class Container, typename T>
u_time_duration track_time( void(*func)(Container<T>&), Container<T>& container)
{
	u_time_point start = std::chrono::high_resolution_clock::now();
	func(container);
	u_time_point end = std::chrono::high_resolution_clock::now();

	u_time_duration duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	return duration;
}

void showTimeReport(size_t size, std::string type, u_time_duration duration)
{
	std::cout << "Time to process a range of " << size << " elements "
	<< "with "<< type << " : "
	<< duration.count() <<" us" << std::endl;
}

int main(int argc, char *argv[])
{
	if (argc == 1) {
		std::cerr << "Error: Expected a single argument (sequence of positive integers)." << std::endl;
		return 1;
	}

	std::vector<int> vector_ints(argc - 1);
	std::list<int> list_ints;

	for (size_t i = 1; argv[i]; i++)
	{
		try
		{
			size_t pos;
			int numb = std::stoi(argv[i], &pos);

			if (argv[i][pos] != '\0')
				throw std::invalid_argument("not a number");

			if (numb < 0)
				throw std::out_of_range("number cannot be negative");

			vector_ints[i - 1] = numb;
			list_ints.push_back(numb);
		}
		catch(const std::out_of_range& e)
		{
			if (std::string(e.what()).compare("stoi") == 0)
				std::cerr << "Error: " << "number is out of range" << " => " << argv[i] << '\n';
			else
				std::cerr << "Error: " << e.what() << " => " << argv[i] << '\n';
			return 1;
		}
		catch (const std::invalid_argument& e)
		{
			if (std::string(e.what()).compare("stoi") == 0)
				std::cerr << "Error: " << "not a number." << " => " << argv[i] << '\n';
			else
				std::cerr << "Error: " << e.what() << " => " << argv[i] << '\n';
			return 1;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << argv[i] << '\n';
			return 1;
		}
	}

	PmergeMe sorter(vector_ints.size());

	std::cout << "Before: " << vector_ints << std::endl;
	u_time_duration durationVector = track_time(&PmergeMe::mergeIsertion, vector_ints);
	std::cout << "After: " << vector_ints << std::endl;

	u_time_duration durationList = track_time(&PmergeMe::mergeIsertion, list_ints);

	showTimeReport(vector_ints.size(), "std::vector<int>", durationVector);
	showTimeReport(list_ints.size(), "std::list<int>", durationList);

	#ifdef DEBUG
		std::cout << "is vector sorted: " << std::boolalpha << std::is_sorted(vector_ints.begin(), vector_ints.end()) << std::endl;
		std::cout << "is list sorted: " << std::boolalpha << std::is_sorted(list_ints.begin(), list_ints.end()) << std::endl;
	#endif
	return 0;
}
