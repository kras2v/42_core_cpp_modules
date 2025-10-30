#include "PmergeMe.hpp"

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

template <template <typename...> class Container, typename T>
void PmergeMe::changeOrder(Container<T> &b, size_t elementsInGroup)
{
	size_t amountOfGroups = b.size() / elementsInGroup;
	if (amountOfGroups == 1) return ;

	Container<T> bOrdered;
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

using listIntIter = std::list<int>::iterator;
listIntIter PmergeMe::lower_bound(std::list<int> &ints, int numb, size_t elementsNum, size_t totalGroupSize)
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

using listIntIter = std::list<int>::iterator;

template <template <typename...> class Container, typename T>
void PmergeMe::insertion(Container<T> &a, Container<T> &b, size_t elementsNum)
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
		int indexToInsert = std::distance(a.begin(), LowerBound);

		a.insert(std::next(a.begin(), indexToInsert), b.begin(), std::next(b.begin(), elementsNum));
		b.erase(b.begin(), std::next(b.begin(), elementsNum));

		// std::cout << "[amountOfComparisons]: " << amountOfComparisons << std::endl;
		// std::cout << "Comparisons: " << comparisons << std::endl;
	}
	// std::cout << "END" << std::endl;
	// std::cout << "[A]: " << a << std::endl;
	// std::cout << "[B]: " << b << std::endl;
}

template <template <typename...> class Container, typename T>
void PmergeMe::compareGroupsInPair(Container<T> &pairs, size_t numberOfElementsInGroup)
{
	size_t currIndex = numberOfElementsInGroup - 1;
	size_t maxIndex = pairs.size();

	for (listIntIter currentPairBegin = pairs.begin();
		currentPairBegin != pairs.end();
		currIndex += numberOfElementsInGroup * 2, comparisons++)
	{
		if (currIndex + numberOfElementsInGroup >= maxIndex) break;
		listIntIter currentPairEnd = std::next(pairs.begin(), currIndex);
		listIntIter nextPairEnd = std::next(currentPairEnd, numberOfElementsInGroup);

		if (*currentPairEnd > *nextPairEnd)
		{
			listIntIter pairsCopynextPairBegin = std::next(currentPairBegin, numberOfElementsInGroup);
			std::swap_ranges(currentPairBegin, std::next(currentPairBegin, numberOfElementsInGroup), pairsCopynextPairBegin);
		}
		currentPairBegin = std::next(nextPairEnd);
	}
}

template <template <typename...> class Container, typename T>
void PmergeMe::splitIntoLargerAndSmaller(Container<T> &pairs, Container<T> &larger, Container<T> &smaller, Container<T> &leftovers, size_t elementsPerPair, size_t numPairs, size_t numberOfElementsInGroup)
{
	size_t leftoversElements = pairs.size() - (numPairs * elementsPerPair);
	size_t elemInPairInLastIteration = numberOfElementsInGroup;

	if (leftoversElements >= elemInPairInLastIteration)
		numPairs += leftoversElements / elemInPairInLastIteration;

	listIntIter currentPairBegin;
	for (currentPairBegin = pairs.begin();
		currentPairBegin != pairs.end() &&
		static_cast<size_t>(std::distance(currentPairBegin, pairs.end())) >= elementsPerPair;
	)
	{
		auto it = currentPairBegin;
		smaller.insert(smaller.end(), it, std::next(it, elementsPerPair / 2));
		it = std::next(it, elementsPerPair / 2);

		larger.insert(larger.end(), it, std::next(it, elementsPerPair / 2));
		it = std::next(it, elementsPerPair / 2);

		currentPairBegin = it;

		if (numPairs > 0)
			numPairs--;
	}

	for (; numPairs > 0; numPairs--)
	{
		smaller.insert(smaller.end(), currentPairBegin, std::next(currentPairBegin, elementsPerPair / 2));
		currentPairBegin = std::next(currentPairBegin, elementsPerPair / 2);
	}

	for (; currentPairBegin != pairs.end(); currentPairBegin = std::next(currentPairBegin))
	{
		leftovers.push_back(*currentPairBegin);
	}
}

template <template <typename...> class Container, typename T>
void PmergeMe::insertSmallestElementInLargest(Container<T> &larger, Container<T> &smaller, size_t elementsPerPair)
{
	larger.insert(larger.begin(), smaller.begin(), std::next(smaller.begin(), elementsPerPair / 2));
	smaller.erase(smaller.begin(), std::next(smaller.begin(), elementsPerPair / 2));
}

template <template <typename...> class Container, typename T>
void PmergeMe::merge(Container<T> &pairs, uint recursionLevel)
{
	size_t numberOfElementsInGroup = TWO_IN_POWER_OF(recursionLevel);

	if (static_cast<size_t>(pairs.size()) < numberOfElementsInGroup * 2) return;

	size_t numPairs = (pairs.size() / numberOfElementsInGroup) / 2;
	size_t elementsPerPair = numberOfElementsInGroup * 2;

	compareGroupsInPair(pairs, numberOfElementsInGroup);
	if (numPairs > 1) merge(pairs, recursionLevel + 1);

	Container<T> larger;
	Container<T> smaller;
	Container<T> leftovers;
	splitIntoLargerAndSmaller(pairs, larger, smaller, leftovers, elementsPerPair, numPairs, numberOfElementsInGroup);
	insertSmallestElementInLargest(larger, smaller, elementsPerPair);
	changeOrder(smaller, numberOfElementsInGroup);
	insertion(larger, smaller, elementsPerPair / 2);

	larger.insert(larger.end(), leftovers.begin(), leftovers.end());
	pairs = larger;
}

void PmergeMe::mergeIsertion(std::list<int> &ints)
{
	merge(ints, 0);
	#ifdef DEBUG
		std::cout << "comparisons: " << comparisons << std::endl;
	#endif
}

std::ostream & operator<<(std::ostream &ofs, std::vector<int> &ints)
{
	for (size_t i = 0;/*  i < 5 && */ i < ints.size(); i++)
	{
		ofs << ints[i] << " ";
	}
	// if (ints.size() > 5)
		// ofs << "[...]";
	return ofs;
}

std::ostream & operator<<(std::ostream &ofs, std::vector<long unsigned int> &ints)
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

	for (size_t i = 0; /* i < 5 &&  */begin != end; i++, begin++)
	{
		ofs << *begin << " ";
	}
	if (ints.size() > 5)
		ofs << "[...]";
	return ofs;
}
