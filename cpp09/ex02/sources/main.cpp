#include <iostream>
#include <algorithm>
#include <chrono>

#include "PmergeMe.hpp"
#include "Validator.hpp"
#include "Timer.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1) {
		std::cerr << "Error: Expected a single argument (sequence of positive integers)." << std::endl;
		return 1;
	}

	std::vector<int> vector_ints(argc - 1);
	std::list<int> list_ints;

	if (!Validator::validateInput(argv, vector_ints, list_ints))
		return 1;

	PmergeMe sorter(argc - 1);

	std::cout << "Before: " << vector_ints << std::endl;

	u_time_duration durationVector = Timer::track_time(&PmergeMe::mergeIsertion, vector_ints);
	u_time_duration durationList = Timer::track_time(&PmergeMe::mergeIsertion, list_ints);

	std::cout << "After: " << vector_ints << std::endl;

	Timer::showTimeReport(vector_ints.size(), "std::vector<int>", durationVector);
	Timer::showTimeReport(list_ints.size(), "std::list<int>", durationList);

	#ifdef DEBUG
		std::cout << vector_ints.size() << " is vector sorted: " << std::boolalpha << std::is_sorted(vector_ints.begin(), vector_ints.end()) << std::endl;
		std::cout << list_ints.size() << " is list sorted: " << std::boolalpha << std::is_sorted(list_ints.begin(), list_ints.end()) << std::endl;
	#endif
	return 0;
}
