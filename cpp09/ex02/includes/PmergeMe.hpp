#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <array>
# include <list>
# include <cmath>

# define TWO_IN_POWER_OF(x) (1 << (x))

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& other) = delete;
		PmergeMe& operator=(const PmergeMe& other) = delete;

		static std::vector<size_t> jacobsthalNumbers;
		void 					   assignJacobsthal(size_t size);
		uint 					   jacobsthal(int n);

		static void					   changeOrder(std::list<int> &losers, size_t step);
		static void merge(std::list<int> &pairs, uint recursionLevel);
		static void insertion(std::list<int> &a, std::list<int> &b, size_t elementsNum);
		static typename std::list<int>::iterator lower_bound(std::list<int> &ints, int numb, size_t elementsNum, size_t totalGroupSize);
		static void compareGroupsInPair(std::list<int> &pairs, size_t numberOfElementsInGroup);
		static void splitIntoLargerAndSmaller(std::list<int> &pairs, std::list<int> &larger, std::list<int> &smaller, std::list<int> &leftovers, size_t elementsPerPair, size_t numPairs, size_t numberOfElementsInGroup);
		static void insertSmallestElementInLargest(std::list<int> &larger, std::list<int> &smaller, size_t elementsPerPair);

		static void					   changeOrder(std::vector<int> &losers, size_t step);
		static void merge(std::vector<int> &pairs, uint recursionLevel);
		static void insertion(std::vector<int> &a, std::vector<int> &b, size_t elementsNum);
		static typename std::vector<int>::iterator lower_bound(std::vector<int> &ints, int numb, size_t elementsNum, size_t totalGroupSize);
		static void compareGroupsInPair(std::vector<int> &pairs, size_t numberOfElementsInGroup);
		static void splitIntoLargerAndSmaller(std::vector<int> &pairs, std::vector<int> &larger, std::vector<int> &smaller, std::vector<int> &leftovers, size_t elementsPerPair, size_t numPairs, size_t numberOfElementsInGroup);
		static void insertSmallestElementInLargest(std::vector<int> &larger, std::vector<int> &smaller, size_t elementsPerPair);

	public:
		PmergeMe(size_t size);
		~PmergeMe();

		static void mergeIsertion(std::list<int> &ints);
		static void mergeIsertion(std::vector<int> &ints);
};

#include "PmergeMe.tpp"

// std::ostream & operator<<(std::ostream &ofs, std::vector<int> &ints);
std::ostream & operator<<(std::ostream &ofs, std::list<int> &ints);

#endif /* PMERGEME_HPP */
