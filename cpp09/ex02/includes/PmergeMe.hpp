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

		static std::vector<int>::iterator lower_bound(std::vector<int> &ints, int numb);
		static void					   changeOrder(std::vector<int> &losers);

		static std::list<int>::iterator   lower_bound(std::list<int> &ints, int numb);
		static void					   changeOrder(std::list<int> &losers);

	public:
		PmergeMe(size_t size);
		~PmergeMe();

		static void mergeIsertion(std::vector<int> &ints);
		static void mergeIsertion(std::list<int> &ints);
};

std::ostream & operator<<(std::ostream &ofs, std::vector<int> &ints);
std::ostream & operator<<(std::ostream &ofs, std::list<int> &ints);

#endif /* PMERGEME_HPP */
