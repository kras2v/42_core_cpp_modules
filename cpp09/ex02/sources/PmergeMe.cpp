#include "PmergeMe.hpp"

std::vector<int> PmergeMe::jacobsthalNumbers;

std::ostream & operator<<(std::ostream &ofs, std::vector<int> &ints)
{
	for (size_t i = 0; i < 5 && i < ints.size(); i++)
	{
		ofs << ints[i] << " ";
	}
	if (ints.size() > 5)
		ofs << "[...]";
	return ofs;
}

PmergeMe::PmergeMe(size_t size)
{
	#ifdef DEBUG
		std::cout << "PmergeMe: Parametrized constructor called" << std::endl;
	#endif

	uint jacobsthalN = jacobsthal(1);
	for (size_t i = 2; jacobsthalN < size; i++)
	{
		jacobsthalNumbers.push_back(jacobsthalN);
		jacobsthalN = jacobsthal(i);

		if (jacobsthalN > size) break;
	}
}

PmergeMe::~PmergeMe()
{
	#ifdef DEBUG
		std::cout << "PmergeMe: Destructor called" << std::endl;
	#endif
}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	#ifdef DEBUG
		std::cout << "PmergeMe: Copy constructor called" << std::endl;
	#endif
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	#ifdef DEBUG
		std::cout << "PmergeMe: Copy assignment operator called" << std::endl;
	#endif
	if (this != &other)
	{

	}
	return *this;
}

std::vector<int>::iterator PmergeMe::lower_bound(std::vector<int> &ints, int numb)
{
	size_t left = 0, right = ints.size(), mid = left + (right - left) / 2;
	while (left != right)
	{
		if (numb > ints[mid])
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
		mid = left + (right - left) / 2;
	}
	return ints.begin() + mid;
}

uint PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::mergeIsertion(std::vector<int> &ints)
{
	if (ints.size() == 1) return;

	std::vector<int> winners(ints.size() / 2);
	std::vector<int> losers(std::ceil(static_cast<double>(ints.size()) / 2));

	for (size_t i = 0, j = 0; i < ints.size(); i += 2, j++)
	{
		if ((i + 1) < ints.size())
		{
			losers[j] = std::min(ints[i], ints[i + 1]);
			winners[j] = std::max(ints[i], ints[i + 1]);
		}
		else
		{
			losers[j] = ints[i];
		}
	}

	mergeIsertion(winners);
	ints.assign(winners.begin(), winners.end());

	if (losers.size() == 1)
	{
		ints.insert(ints.begin(), losers[0]);
		return ;
	}
	std::vector<int>::iterator first = jacobsthalNumbers.begin();
	std::vector<int>::iterator last = std::upper_bound(jacobsthalNumbers.begin(),
		jacobsthalNumbers.end(), static_cast<int>(losers.size()));

	int amountOfGroups = last - first;
	ints.insert(lower_bound(ints, losers[1]), losers[1]);
	ints.insert(lower_bound(ints, losers[0]), losers[0]);

	for (int i = 0; i < amountOfGroups; i++)
	{
		first++;
		last = first + 1;
		size_t firstIndex = *first;
		size_t lastIndex = *last;

		if (lastIndex >= losers.size()) lastIndex = losers.size() - 1;
		while (lastIndex > firstIndex)
		{
			ints.insert(lower_bound(ints, losers[lastIndex]), losers[lastIndex]);
			lastIndex--;
		}
	}
}
