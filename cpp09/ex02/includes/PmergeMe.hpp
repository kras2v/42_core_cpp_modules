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

		template <template <typename...> class Container, typename T>
		static void					   changeOrder(Container<T> &losers, size_t step);

		// static std::list<int>::iterator   lower_bound(std::list<int> &ints, int numb);
		// static void					   changeOrder(std::list<int> &losers);


		template <template <typename...> class Container, typename T>
		static void merge(Container<T> &pairs, uint recursionLevel);

		template <template <typename...> class Container, typename T>
		static void insertion(Container<T> &a, Container<T> &b, size_t elementsNum);

		using vectorIntIter = std::vector<int>::iterator;
		static vectorIntIter lower_bound(std::vector<int> &ints, int numb);

		using listIntIter = std::list<int>::iterator;
		static listIntIter lower_bound(std::list<int> &ints, int numb, size_t elementsNum, size_t totalGroupSize);

		template <template <typename...> class Container, typename T>
		static void compareGroupsInPair(Container<T> &pairs, size_t numberOfElementsInGroup);

		template <template <typename...> class Container, typename T>
		static void splitIntoLargerAndSmaller(Container<T> &pairs, Container<T> &larger, Container<T> &smaller, Container<T> &leftovers, size_t elementsPerPair, size_t numPairs, size_t numberOfElementsInGroup);

		template <template <typename...> class Container, typename T>
		static void insertSmallestElementInLargest(Container<T> &larger, Container<T> &smaller, size_t elementsPerPair);

	public:
		PmergeMe(size_t size);
		~PmergeMe();

		// static void mergeIsertion(std::vector<int> &ints);
		static void mergeIsertion(std::list<int> &ints);
};

// std::ostream & operator<<(std::ostream &ofs, std::vector<int> &ints);
std::ostream & operator<<(std::ostream &ofs, std::list<int> &ints);

#endif /* PMERGEME_HPP */
