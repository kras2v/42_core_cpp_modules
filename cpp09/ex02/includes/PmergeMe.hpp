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
		static std::vector<size_t> jacobsthalNumbers;
		uint jacobsthal(int n);

		static std::vector<int>::iterator lower_bound(std::vector<int> &ints, int numb);
		static void changeOrder(std::vector<int> &losers);

		static void changeOrder(std::list<int> &losers);
		static std::list<int>::iterator lower_bound(std::list<int> &ints, int numb);

	public:
		PmergeMe(size_t size);
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		static void mergeIsertion(std::vector<int> &ints);
		static void mergeIsertion(std::list<int> &ints);
};

std::ostream & operator<<(std::ostream &ofs, std::vector<int> &ints);
std::ostream & operator<<(std::ostream &ofs, std::list<int> &ints);

#endif /* PMERGEME_HPP */
