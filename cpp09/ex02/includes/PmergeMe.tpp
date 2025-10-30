#include "PmergeMe.hpp"

using Iterator = typename std::list<int>::iterator;

std::vector<size_t> PmergeMe::jacobsthalNumbers;

int comparisons = 0;

void PmergeMe::assignJacobsthal(size_t size)
{
	uint jacobsthalN = jacobsthal(2);
	jacobsthalNumbers.push_back(jacobsthalN);
	for (size_t i = 3; jacobsthalN < size; i++)
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

void PmergeMe::changeOrder(std::list<int> &b, size_t elementsInGroup)
{
	size_t amountOfGroups = b.size() / elementsInGroup;
	if (amountOfGroups == 1) return ;

	std::list<int> bOrdered;
	for (auto current = jacobsthalNumbers.begin(); amountOfGroups >= *current; current++)
	{
		//-1 because we convert jacobsthal sequence to indexes, and last -2 because it's excluded
		auto next = current + 1;
		size_t firstIndex = (*current > 0) ? *current - 1 : 0;
		size_t lastIndex  = (*next  > 1) ? *next  - 2 : 0;

		size_t lastIndexInOriginalContainer = (lastIndex * elementsInGroup) + (elementsInGroup - 1);
		size_t firstIndexInOriginalContainer = (firstIndex * elementsInGroup);

		if (lastIndexInOriginalContainer  >= b.size())
			lastIndexInOriginalContainer = b.size() - 1;

		while (lastIndexInOriginalContainer >= firstIndexInOriginalContainer)
		{
			bOrdered.insert(bOrdered.end(),
				std::next(b.begin(), lastIndexInOriginalContainer + 1 - elementsInGroup),
				std::next(b.begin(), lastIndexInOriginalContainer + 1)
			);

			if (lastIndexInOriginalContainer < elementsInGroup)
				break;
			lastIndexInOriginalContainer -= elementsInGroup;
		}
	}
	b = bOrdered;
}

typename std::list<int>::iterator PmergeMe::lower_bound(std::list<int> &ints, int numb, size_t elementsNum, size_t totalGroupSize)
{
	size_t left = 0, right = totalGroupSize, mid = left + (right - left) / 2;
	while (left < right)
	{
		if (numb > *std::next(ints.begin(), (mid * elementsNum) + (elementsNum - 1)))
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
		comparisons++;
		mid = left + (right - left) / 2;
	}
	return std::next(ints.begin(), left * elementsNum);
}


void PmergeMe::insertion(std::list<int> &a, std::list<int> &b, size_t elementsNum)
{
	size_t groupLVL = 2;
	size_t amountOfComparisons = std::min(static_cast<size_t>(TWO_IN_POWER_OF(groupLVL) - 1), a.size() / elementsNum);

	size_t jacobianStepSize = 2;
	for (auto currentJacNumb = jacobsthalNumbers.begin(); !b.empty(); --jacobianStepSize)
	{
		if (jacobianStepSize == 0)
		{
			currentJacNumb++;
			groupLVL++;
			jacobianStepSize = *std::next(currentJacNumb) - *currentJacNumb;
			amountOfComparisons = std::min(static_cast<size_t>(TWO_IN_POWER_OF(groupLVL) - 1), a.size() / elementsNum);
		}

		auto LowerBound = lower_bound(a, *std::next(b.begin(), elementsNum - 1), elementsNum, amountOfComparisons);
		int indexintoInsert = std::distance(a.begin(), LowerBound);

		a.insert(std::next(a.begin(), indexintoInsert), b.begin(), std::next(b.begin(), elementsNum));
		b.erase(b.begin(), std::next(b.begin(), elementsNum));

	}
}

void PmergeMe::compareGroupsInPair(std::list<int> &pairs, size_t numberOfElementsInGroup)
{
	size_t currIndex = numberOfElementsInGroup - 1;
	size_t maxIndex = pairs.size();

	for (auto currentPairBegin = pairs.begin();
		currentPairBegin != pairs.end();
		currIndex += numberOfElementsInGroup * 2, comparisons++)
	{
		if (currIndex + numberOfElementsInGroup >= maxIndex) break;
		auto currentPairEnd = std::next(pairs.begin(), currIndex);
		auto nextPairEnd = std::next(currentPairEnd, numberOfElementsInGroup);

		if (*currentPairEnd > *nextPairEnd)
		{
			auto pairsCopynextPairBegin = std::next(currentPairBegin, numberOfElementsInGroup);
			std::swap_ranges(currentPairBegin, std::next(currentPairBegin, numberOfElementsInGroup), pairsCopynextPairBegin);
		}
		currentPairBegin = std::next(nextPairEnd);
	}
}

void PmergeMe::splitIntoLargerAndSmaller(std::list<int> &pairs, std::list<int> &larger, std::list<int> &smaller, std::list<int> &leftovers, size_t elementsPerPair, size_t numPairs, size_t numberOfElementsInGroup)
{
	size_t leftoversElements = pairs.size() - (numPairs * elementsPerPair);
	size_t elemInPairInLastIteration = numberOfElementsInGroup;

	if (leftoversElements >= elemInPairInLastIteration)
		numPairs += leftoversElements / elemInPairInLastIteration;

	typename std::list<int>::iterator currentPairBegin;
	for (currentPairBegin = pairs.begin();
		numPairs > 0 &&
		currentPairBegin != pairs.end() &&
		static_cast<size_t>(std::distance(currentPairBegin, pairs.end())) >= elementsPerPair;
		numPairs--
	)
	{
		auto it = currentPairBegin;
		smaller.insert(smaller.end(), it, std::next(it, elementsPerPair / 2));
		it = std::next(it, elementsPerPair / 2);

		larger.insert(larger.end(), it, std::next(it, elementsPerPair / 2));
		it = std::next(it, elementsPerPair / 2);

		currentPairBegin = it;
	}

	for (; numPairs > 0; numPairs--, currentPairBegin = std::next(currentPairBegin, elementsPerPair / 2))
	{
		smaller.insert(smaller.end(), currentPairBegin, std::next(currentPairBegin, elementsPerPair / 2));
	}

	leftovers.insert(leftovers.end(), currentPairBegin, pairs.end());
}

void PmergeMe::insertSmallestElementInLargest(std::list<int> &larger, std::list<int> &smaller, size_t elementsPerPair)
{
	larger.insert(larger.begin(), smaller.begin(), std::next(smaller.begin(), elementsPerPair / 2));
	smaller.erase(smaller.begin(), std::next(smaller.begin(), elementsPerPair / 2));
}

void PmergeMe::merge(std::list<int> &pairs, uint recursionLevel)
{
	size_t numberOfElementsInGroup = TWO_IN_POWER_OF(recursionLevel);

	if (static_cast<size_t>(pairs.size()) < numberOfElementsInGroup * 2) return;

	size_t numPairs = (pairs.size() / numberOfElementsInGroup) / 2;
	size_t elementsPerPair = numberOfElementsInGroup * 2;

	compareGroupsInPair(pairs, numberOfElementsInGroup);
	if (numPairs > 1) merge(pairs, recursionLevel + 1);

	std::list<int> larger;
	std::list<int> smaller;
	std::list<int> leftovers;
	splitIntoLargerAndSmaller(pairs, larger, smaller, leftovers, elementsPerPair, numPairs, numberOfElementsInGroup);
	insertSmallestElementInLargest(larger, smaller, elementsPerPair);
	changeOrder(smaller, numberOfElementsInGroup);
	insertion(larger, smaller, elementsPerPair / 2);

	larger.insert(larger.end(), leftovers.begin(), leftovers.end());
	pairs = larger;
}

void PmergeMe::mergeIsertion(std::list<int> &ints)
{
	comparisons = 0;
	merge(ints, 0);
	#ifdef DEBUG
		std::cout << "comparisons: " << comparisons << std::endl;
	#endif
}

void PmergeMe::changeOrder(std::vector<int> &b, size_t elementsInGroup)
{
	size_t amountOfGroups = b.size() / elementsInGroup;
	if (amountOfGroups == 1) return ;

	std::vector<int> bOrdered;
	for (auto current = jacobsthalNumbers.begin(); amountOfGroups >= *current; current++)
	{
		//-1 because we convert jacobsthal sequence to indexes, and last -2 because it's excluded
		auto next = current + 1;
		size_t firstIndex = (*current > 0) ? *current - 1 : 0;
		size_t lastIndex  = (*next  > 1) ? *next  - 2 : 0;

		size_t lastIndexInOriginalContainer = (lastIndex * elementsInGroup) + (elementsInGroup - 1);
		size_t firstIndexInOriginalContainer = (firstIndex * elementsInGroup);

		if (lastIndexInOriginalContainer  >= b.size())
			lastIndexInOriginalContainer = b.size() - 1;

		while (lastIndexInOriginalContainer >= firstIndexInOriginalContainer)
		{
			bOrdered.insert(bOrdered.end(),
				b.begin() + lastIndexInOriginalContainer + 1 - elementsInGroup,
				b.begin() + lastIndexInOriginalContainer + 1
			);

			if (lastIndexInOriginalContainer < elementsInGroup)
				break;
			lastIndexInOriginalContainer -= elementsInGroup;
		}
	}
	b = bOrdered;
}

typename std::vector<int>::iterator PmergeMe::lower_bound(std::vector<int> &ints, int numb, size_t elementsNum, size_t totalGroupSize)
{
	size_t left = 0, right = totalGroupSize, mid = left + (right - left) / 2;
	while (left < right)
	{
		if (numb > ints[(mid * elementsNum) + (elementsNum - 1)])
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
		comparisons++;
		mid = left + (right - left) / 2;
	}
	return ints.begin() + left * elementsNum;
}


void PmergeMe::insertion(std::vector<int> &a, std::vector<int> &b, size_t elementsNum)
{
	size_t groupLVL = 2;
	size_t amountOfComparisons = std::min(static_cast<size_t>(TWO_IN_POWER_OF(groupLVL) - 1), a.size() / elementsNum);

	size_t jacobianStepSize = 2;
	for (auto currentJacNumb = jacobsthalNumbers.begin(); !b.empty(); --jacobianStepSize)
	{
		if (jacobianStepSize == 0)
		{
			currentJacNumb++;
			groupLVL++;
			jacobianStepSize = *(currentJacNumb + 1) - *currentJacNumb;
			amountOfComparisons = std::min(static_cast<size_t>(TWO_IN_POWER_OF(groupLVL) - 1), a.size() / elementsNum);
		}

		auto LowerBound = lower_bound(a, *(b.begin() + elementsNum - 1), elementsNum, amountOfComparisons);

		a.insert(LowerBound, b.begin(), b.begin() + elementsNum);
		b.erase(b.begin(), b.begin() + elementsNum);
	}
}

void PmergeMe::compareGroupsInPair(std::vector<int> &pairs, size_t numberOfElementsInGroup)
{
	size_t currIndex = numberOfElementsInGroup - 1;
	size_t maxIndex = pairs.size();

	for (size_t i = 0; i < pairs.size(); currIndex += numberOfElementsInGroup * 2, comparisons++)
	{
		if (currIndex + numberOfElementsInGroup >= maxIndex) break;

		if (pairs[currIndex] > pairs[currIndex + numberOfElementsInGroup])
		{
			std::swap_ranges(pairs.begin() + i, pairs.begin() + i + numberOfElementsInGroup, pairs.begin() + i + numberOfElementsInGroup);
		}
		i = currIndex + numberOfElementsInGroup + 1;
	}
}

void PmergeMe::splitIntoLargerAndSmaller(std::vector<int> &pairs, std::vector<int> &larger, std::vector<int> &smaller, std::vector<int> &leftovers, size_t elementsPerPair, size_t numPairs, size_t numberOfElementsInGroup)
{
	size_t leftoversElements = pairs.size() - (numPairs * elementsPerPair);
	size_t elemInPairInLastIteration = numberOfElementsInGroup;

	if (leftoversElements >= elemInPairInLastIteration)
		numPairs += leftoversElements / elemInPairInLastIteration;

	typename std::vector<int>::iterator currentPairBegin;
	for (currentPairBegin = pairs.begin();
		numPairs > 0 &&
		currentPairBegin != pairs.end() &&
		static_cast<size_t>(std::distance(currentPairBegin, pairs.end())) >= elementsPerPair;
		numPairs--
	)
	{
		auto it = currentPairBegin;
		smaller.insert(smaller.end(), it, it + elementsPerPair / 2);
		it += elementsPerPair / 2;

		larger.insert(larger.end(), it, it + elementsPerPair / 2);
		it += elementsPerPair / 2;

		currentPairBegin = it;
	}

	for (; numPairs > 0; numPairs--, currentPairBegin += elementsPerPair / 2)
	{
		smaller.insert(smaller.end(), currentPairBegin, currentPairBegin + elementsPerPair / 2);
	}

	leftovers.insert(leftovers.end(), currentPairBegin, pairs.end());
}

void PmergeMe::insertSmallestElementInLargest(std::vector<int> &larger, std::vector<int> &smaller, size_t elementsPerPair)
{
	larger.insert(larger.begin(), smaller.begin(), smaller.begin() + elementsPerPair / 2);
	smaller.erase(smaller.begin(), smaller.begin() + elementsPerPair / 2);
}

void PmergeMe::merge(std::vector<int> &pairs, uint recursionLevel)
{
	size_t numberOfElementsInGroup = TWO_IN_POWER_OF(recursionLevel);

	if (static_cast<size_t>(pairs.size()) < numberOfElementsInGroup * 2) return;

	size_t numPairs = (pairs.size() / numberOfElementsInGroup) / 2;
	size_t elementsPerPair = numberOfElementsInGroup * 2;

	compareGroupsInPair(pairs, numberOfElementsInGroup);
	if (numPairs > 1) merge(pairs, recursionLevel + 1);

	std::vector<int> larger;
	std::vector<int> smaller;
	std::vector<int> leftovers;
	splitIntoLargerAndSmaller(pairs, larger, smaller, leftovers, elementsPerPair, numPairs, numberOfElementsInGroup);
	insertSmallestElementInLargest(larger, smaller, elementsPerPair);
	changeOrder(smaller, numberOfElementsInGroup);
	insertion(larger, smaller, elementsPerPair / 2);

	larger.insert(larger.end(), leftovers.begin(), leftovers.end());
	pairs = larger;
}

void PmergeMe::mergeIsertion(std::vector<int> &ints)
{
	comparisons = 0;
	merge(ints, 0);
	#ifdef DEBUG
		std::cout << "comparisons: " << comparisons << std::endl;
	#endif
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
