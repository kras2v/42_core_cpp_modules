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
void PmergeMe::merge(Container<T> &pairs, uint recursionLevel)
{
	int step = std::pow(2, recursionLevel);

	// std::cout << "Pairs size = " << pairs.size() << " recursionLevel= " << recursionLevel << std::endl;
	if (static_cast<int>(pairs.size()) < step * 2) return;

	int currIndex = step - 1;
	int maxIndex = pairs.size();

	int numPairs = (maxIndex / step) / 2;
	int elementsPerPair = step * 2;
	int leftoverElements = maxIndex - (numPairs * elementsPerPair);
	int elemInPairInLastIteration = step;

	// std::cout << pairs << "[" << recursionLevel << "]" << std::endl
	// 		<< " number of pairs: " << numPairs << std::endl
	// 		<< " number of elements per pair: " << elementsPerPair << std::endl
	// 		<< " number of elements without pair: " << leftoverElements << std::endl
	// 		<< " number of elements in pair in last iteration: " << elemInPairInLastIteration << std::endl
	// 		<< std::endl;

	listIntIter pairsEnd = pairs.end();
	for (listIntIter currentPairBegin = pairs.begin(); currentPairBegin != pairsEnd;)
	{
		if (currIndex + step >= maxIndex) break;
		listIntIter currentPairEnd = std::next(pairs.begin(), currIndex);
		listIntIter nextPairEnd = std::next(currentPairEnd, step);

		if (*currentPairEnd > *nextPairEnd)
		{
			listIntIter pairsCopyBegin = currentPairBegin;
			listIntIter pairsCopynextPairBegin = std::next(pairsCopyBegin, step);

			std::swap_ranges(pairsCopyBegin, std::next(pairsCopyBegin, step), pairsCopynextPairBegin);
		}
		comparisons++;
		// std::cout << pairs << "[" << recursionLevel << "]" << "curr index = " << currIndex << std::endl;
		currIndex += step * 2;
		currentPairBegin = std::next(nextPairEnd);
	}

	// std::cout << pairs << "[" << recursionLevel << "]" << std::endl;
	merge(pairs, recursionLevel + 1);
	Container<T> a;
	Container<T> b;

	// if (numPairs == 1) return;

	if (leftoverElements >= elemInPairInLastIteration)
	{
		numPairs += leftoverElements / elemInPairInLastIteration;
	}

	// std::cout << "Num pairs: " << numPairs << std::endl;

	pairsEnd = pairs.end();
	listIntIter currentPairBegin = pairs.begin();
	for (currentPairBegin = pairs.begin();
		currentPairBegin != pairsEnd &&
		static_cast<int>(std::distance(currentPairBegin, pairsEnd)) >= elementsPerPair;
	)
	{
		auto it = currentPairBegin;
		b.insert(b.end(), it, std::next(it, elementsPerPair / 2));
		it = std::next(it, elementsPerPair / 2);

		a.insert(a.end(), it, std::next(it, elementsPerPair / 2));
		it = std::next(it, elementsPerPair / 2);

		currentPairBegin = it;

		if (numPairs > 0)
			numPairs--;
	}

	// std::cout << "ORIGIGNAL A B: " << std::endl;
	// std::cout << "[a]: " << a << std::endl;
	// std::cout << "[b]: " << b << std::endl;

	while (numPairs)
	{
		auto it = currentPairBegin;
		for (int i = 0; i < elementsPerPair / 2; ++i)
		{
			b.push_back(*it);
			++it;
		}
		currentPairBegin = it;

		if (numPairs > 0)
			numPairs--;
	}

	Container<T> leftovers;
	for (; currentPairBegin != pairs.end(); currentPairBegin = std::next(currentPairBegin))
	{
		leftovers.push_back(*currentPairBegin);
	}

	a.insert(a.begin(), b.begin(), std::next(b.begin(), elementsPerPair / 2));
	b.erase(b.begin(), std::next(b.begin(), elementsPerPair / 2));

	// std::cout << "[pairs]: " << pairs << std::endl;
	// std::cout << "[numOfElem]: " << elementsPerPair / 2 << std::endl;
	// std::cout << "[a]: " << a << std::endl;
	// std::cout << "[b]: " << b << std::endl;
	// std::cout << "[leftovers]: " << leftovers << std::endl;

	changeOrder(b, step);
	// std::cout << "[b changed]: " << b << std::endl;
	insertion(a, b, elementsPerPair / 2);
	a.insert(a.end(), leftovers.begin(), leftovers.end());
	pairs = a;

	// std::cout << "[RESULT] [" << recursionLevel << "]" << pairs;
}

void PmergeMe::mergeIsertion(std::list<int> &ints)
{
	listIntIter intsEnd = ints.end();
	for (listIntIter intsBegin = ints.begin(); intsBegin != intsEnd;)
	{
		listIntIter nextIt = std::next(intsBegin);
		if (nextIt == intsEnd) break;

		//Biggest number goes on second position, so we have pair = {min, max}
		if (*intsBegin > *nextIt)
		{
			std::swap(*intsBegin, *nextIt);
		}
		comparisons++;
		intsBegin = std::next(nextIt);
	}

	merge(ints, 1);

	std::list<int> a;
	std::list<int> b;

	listIntIter currentPairBegin = ints.begin();
	for (currentPairBegin = ints.begin();
		currentPairBegin != intsEnd;
	)
	{
		auto it = currentPairBegin;
		b.insert(b.end(), it, std::next(it, 1));

		if (std::next(it) == intsEnd) break;

		it = std::next(it, 1);

		a.insert(a.end(), it, std::next(it, 1));
		it = std::next(it,1);

		currentPairBegin = it;
	}

	// std::cout << "ORIGIGNAL A B: " << std::endl;
	// std::cout << "[a]: " << a << std::endl;
	// std::cout << "[b]: " << b << std::endl;

	a.insert(a.begin(), b.begin(), std::next(b.begin(), 1));
	b.erase(b.begin(), std::next(b.begin(), 1));

	// std::cout << "[pairs]: " << ints << std::endl;
	// std::cout << "[a]: " << a << std::endl;
	// std::cout << "[b]: " << b << std::endl;
	// // std::cout << "[leftovers]: " << leftovers << std::endl;

	std::cout << "[pairs]: " << ints << std::endl;
	std::cout << "[a]: " << a << std::endl;
	std::cout << "[b]: " << b << std::endl;
	changeOrder(b, 1);
	std::cout << "[b changed]: " << b << std::endl;

	insertion(a, b, 1);
	ints = a;
	// std::cout << "[RESULT] [" << 0 << "]" << ints;
	std::cout << "comparisons: " << comparisons << std::endl;
}

using listIntIter = std::list<int>::iterator;

// void PmergeMe::mergeIsertion(std::list<int> &ints)
// {
// 	if (ints.size() == 1) return;

// 	std::list<int> winners;
// 	std::list<int> losers;

// 	listIntIter intsEnd = ints.end();
// 	for (listIntIter intsBegin = ints.begin(); intsBegin != intsEnd;)
// 	{
// 		if (std::next(intsBegin) != intsEnd)
// 		{
// 			losers.push_back(std::min(*intsBegin, *std::next(intsBegin)));
// 			winners.push_back(std::max(*intsBegin, *std::next(intsBegin)));
// 			intsBegin++;
// 			intsBegin++;
// 		}
// 		else
// 		{
// 			losers.push_back(*intsBegin);
// 			intsBegin++;
// 		}
// 	}

// 	mergeIsertion(winners);
// 	ints.assign(winners.begin(), winners.end());

// 	if (losers.size() == 1)
// 	{
// 		ints.insert(ints.begin(), losers.front());
// 		return ;
// 	}

// 	changeOrder(losers);
// 	for (listIntIter losersIter = losers.begin(); losersIter != losers.end(); )
// 	{
// 		ints.insert(lower_bound(ints, *losersIter), *losersIter);
// 		losersIter++;
// 	}
// }


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
