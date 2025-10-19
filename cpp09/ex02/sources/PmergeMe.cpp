#include "PmergeMe.hpp"

std::vector<size_t> PmergeMe::jacobsthalNumbers;

void PmergeMe::assignJacobsthal(size_t size)
{
	uint jacobsthalN = jacobsthal(1);
	for (size_t i = 2; jacobsthalN < size; i++)
	{
		jacobsthalN = jacobsthal(i);
		jacobsthalNumbers.push_back(jacobsthalN);
	}
}

PmergeMe::~PmergeMe()
{
	#ifdef DEBUG
		std::cout << "PmergeMe: destructor called" << std::endl;
	#endif
}

PmergeMe::PmergeMe(size_t size)
{
	#ifdef DEBUG
		std::cout << "PmergeMe: Parametrized constructor called" << std::endl;
	#endif
	assignJacobsthal(size);
}

uint PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

using vectorIntIter = std::vector<int>::iterator;

vectorIntIter PmergeMe::lower_bound(std::vector<int> &ints, int numb)
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
	return std::next(ints.begin(), mid);
}

void PmergeMe::changeOrder(std::vector<int> &losers)
{
	std::vector<size_t>::iterator first = jacobsthalNumbers.begin();
	std::vector<size_t>::iterator last = std::upper_bound(jacobsthalNumbers.begin(),
		jacobsthalNumbers.end(), losers.size());

	size_t amountOfGroups = last - first;
	std::vector<int> losersOrdered;

	for (size_t i = 0; i < amountOfGroups; i++)
	{
		last = first + 1;
		size_t firstIndex = *first - 1;
		size_t lastIndex = *last - 1;

		if (lastIndex >= losers.size()) lastIndex = losers.size();

		for (size_t groupSize = lastIndex - firstIndex; groupSize > 0; groupSize--)
		{
			lastIndex--;
			losersOrdered.push_back(losers[lastIndex]);
			if (groupSize == 0 || lastIndex == 0) break;
		}
		first++;
	}
	losers = losersOrdered;
}

void PmergeMe::mergeIsertion(std::vector<int> &ints)
{
	if (ints.size() < 2) return;

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

	changeOrder(losers);
	for (size_t i = 0; i < losers.size(); i++)
	{
		ints.insert(lower_bound(ints, losers[i]), losers[i]);
	}
}

using listIntIter = std::list<int>::iterator;

listIntIter PmergeMe::lower_bound(std::list<int> &ints, int numb)
{
	size_t left = 0, right = ints.size(), mid = left + (right - left) / 2;
	while (left != right)
	{
		if (numb > *std::next(ints.begin(), mid))
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
		mid = left + (right - left) / 2;
	}
	return std::next(ints.begin(), mid);
}

void PmergeMe::changeOrder(std::list<int> &losers)
{
	std::vector<size_t>::iterator first = jacobsthalNumbers.begin();
	std::vector<size_t>::iterator last = std::upper_bound(jacobsthalNumbers.begin(),
		jacobsthalNumbers.end(), losers.size());

	size_t amountOfGroups = last - first;
	std::list<int> losersOrdered;

	for (size_t i = 0; i < amountOfGroups; i++)
	{
		last = first + 1;
		size_t firstIndex = *first - 1;
		size_t lastIndex = *last - 1;

		if (lastIndex >= losers.size()) lastIndex = losers.size();

		for (size_t groupSize = lastIndex - firstIndex; groupSize > 0; groupSize--)
		{
			lastIndex--;
			losersOrdered.push_back(*std::next(losers.begin(), lastIndex));
			if (groupSize == 0 || lastIndex == 0) break;
		}
		first++;
	}
	losers = losersOrdered;
}

void PmergeMe::mergeIsertion(std::list<int> &ints)
{
	if (ints.size() == 1) return;

	std::list<int> winners;
	std::list<int> losers;

	listIntIter intsEnd = ints.end();
	for (listIntIter intsBegin = ints.begin(); intsBegin != intsEnd;)
	{
		if (std::next(intsBegin) != intsEnd)
		{
			losers.push_back(std::min(*intsBegin, *std::next(intsBegin)));
			winners.push_back(std::max(*intsBegin, *std::next(intsBegin)));
			intsBegin++;
			intsBegin++;
		}
		else
		{
			losers.push_back(*intsBegin);
			intsBegin++;
		}
	}

	mergeIsertion(winners);
	ints.assign(winners.begin(), winners.end());

	if (losers.size() == 1)
	{
		ints.insert(ints.begin(), losers.front());
		return ;
	}

	changeOrder(losers);
	for (listIntIter losersIter = losers.begin(); losersIter != losers.end(); )
	{
		ints.insert(lower_bound(ints, *losersIter), *losersIter);
		losersIter++;
	}
}


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

std::ostream & operator<<(std::ostream &ofs, std::list<int> &ints)
{
	std::list<int>::iterator begin = ints.begin();
	std::list<int>::iterator end = ints.end();

	for (size_t i = 0; i < 5 && begin != end; i++, begin++)
	{
		ofs << *begin << " ";
	}
	if (ints.size() > 5)
		ofs << "[...]";
	return ofs;
}