#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <array>
# include <list>
# include <cmath>

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
		static listIntIter lower_bound(std::list<int> &ints, int numb, size_t elementsNum, bool isSameIndex);

	public:
		PmergeMe(size_t size);
		~PmergeMe();

		// static void mergeIsertion(std::vector<int> &ints);
		static void mergeIsertion(std::list<int> &ints);
};

// std::ostream & operator<<(std::ostream &ofs, std::vector<int> &ints);
std::ostream & operator<<(std::ostream &ofs, std::list<int> &ints);

#endif /* PMERGEME_HPP */
