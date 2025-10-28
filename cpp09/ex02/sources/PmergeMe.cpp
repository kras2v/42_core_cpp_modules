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
void PmergeMe::changeOrder(Container<T> &losers, size_t step)
{
	size_t amountOfElements = step == 0 ? losers.size() : losers.size() / step;

	std::vector<size_t>::iterator first = jacobsthalNumbers.begin();
	std::vector<size_t>::iterator last = std::upper_bound(jacobsthalNumbers.begin(),
		jacobsthalNumbers.end(), amountOfElements);

	size_t amountOfGroups = last - first;
	Container<T> losersOrdered;

	// std::cout << "step: " << step << std::endl;
	// std::cout << "losers.size(): " << losers.size() << std::endl;
	// std::cout << "first: " << *first << std::endl;
	// std::cout << "last: " << *last << std::endl;
	// std::cout << "amountOfGroups: " << amountOfGroups << std::endl;

	if (amountOfGroups == 0 || losers.size() < 2) return;
	for (size_t i = 0; i < amountOfGroups; i++)
	{
		last = first + 1;
		size_t firstIndex = *first;
		size_t lastIndex = *last;

		size_t groupSize = (lastIndex - firstIndex);
		// std::cout << "groupSize: " << groupSize << std::endl;

		firstIndex = (firstIndex) < 2 ? 0 : firstIndex - 1;
		lastIndex = (lastIndex) < 2 ? 0 : lastIndex - 2;
		
		// std::cout << "firstIndex: " << firstIndex << std::endl;
		// std::cout << "lastIndex: " << lastIndex << std::endl;

		size_t lastIndexInOriginalContainer =  (step != 0) ? (lastIndex * step) + (step - 1) : lastIndex;
		size_t firstIndexInOriginalContainer = (step != 0) ? (firstIndex * step) : firstIndex;

		if (lastIndexInOriginalContainer  >= losers.size())
		{
			lastIndexInOriginalContainer = losers.size() - 1;
		}

		// std::cout << "RANGE [" << firstIndexInOriginalContainer << " - " << lastIndexInOriginalContainer << "]"<< std::endl;

		if (step == 0)
		{
			for (; groupSize > 0 && lastIndexInOriginalContainer >= firstIndexInOriginalContainer; groupSize--)
			{
				// std::cout << "Elem[" << lastIndexInOriginalContainer << "] = " << *std::next(losers.begin(), lastIndexInOriginalContainer) << std::endl;
				losersOrdered.push_back(*std::next(losers.begin(), lastIndexInOriginalContainer));
				lastIndexInOriginalContainer--;
				if (groupSize == 0) break;
			}
		}

		for (; groupSize > 0 && lastIndexInOriginalContainer > firstIndexInOriginalContainer; groupSize--)
		{
			size_t copyTill = lastIndexInOriginalContainer + 1;
			for (size_t i = lastIndexInOriginalContainer - step + 1; i < copyTill; i++)
			{
				// std::cout << "Elem[" << i << "] = " << *std::next(losers.begin(), i) << std::endl;
				losersOrdered.push_back(*std::next(losers.begin(), i));
				lastIndexInOriginalContainer--;
			}
			if (groupSize == 0) break;
		}
		first++;
	}
	losers = losersOrdered;
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

using listIntIter = std::list<int>::iterator;
listIntIter PmergeMe::lower_bound(std::list<int> &ints, int numb, size_t elementsNum, bool isSameIndex)
{
	(void)isSameIndex;
	size_t left = 0, right = ints.size() / elementsNum, mid = left + (right - left) / 2;
	while (left != right)
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
	// std::cout << "MID => " <<  *std::next(ints.begin(), mid * elementsNum) << std::endl;
	return std::next(ints.begin(), mid * elementsNum);
}


using listIntIter = std::list<int>::iterator;

template <template <typename...> class Container, typename T>
void PmergeMe::insertion(Container<T> &a, Container<T> &b, size_t elementsNum)
{
	Container<T> tempA;

	std::vector<size_t>::iterator currentJacNumb = jacobsthalNumbers.begin();
	std::vector<size_t>::iterator nextJacNumb = currentJacNumb + 1;

	size_t groupSize = *nextJacNumb - *currentJacNumb + 1;
	if (groupSize > a.size() * elementsNum)
		groupSize = a.size() / elementsNum;

	auto aBeginIter = a.begin();
	// std::cout << "groupSize ==> " << groupSize << std::endl;
	for (size_t i = 0; i < groupSize && aBeginIter != a.end(); i++)
	{
		for (size_t j = 0; j < elementsNum; j++)
		{
			tempA.push_back(*aBeginIter);
			aBeginIter = std::next(aBeginIter);
		}
	}
	groupSize--;

	auto bBeginIter = b.begin();
	while (bBeginIter != b.end())
	{
		Container<T> tempPairB;
		// std::cout << "BPair { ";
		for (size_t i = 0; i < elementsNum; i++, bBeginIter = std::next(bBeginIter))
		{
			// std::cout << *bBeginIter << " ";
			tempPairB.push_back(*bBeginIter);
		}
		// std::cout << "}" << std::endl;

		// std::cout << "[A]: ";
		// for (auto aBeginIter = a.begin(); aBeginIter != a.end(); aBeginIter = std::next(aBeginIter))
		// 	std::cout << *aBeginIter << " ";
		// std::cout << std::endl;

		// std::cout << "[Temp A] before: ";
		// for (auto aBeginIter = tempA.begin(); aBeginIter != tempA.end(); aBeginIter = std::next(aBeginIter))
		// 	std::cout << *aBeginIter << " ";
		// std::cout << std::endl;


		auto LowerBound = lower_bound(tempA, tempPairB.back(), elementsNum, groupSize == 1);
		int indexToInsert = std::distance(tempA.begin(), LowerBound);
		// std::cout << "Lower bound index is " << indexToInsert << std::endl;
		tempA.insert(std::next(tempA.begin(), indexToInsert), tempPairB.begin(), tempPairB.end());

		// std::cout << "[Temp A] after: ";
		// for (auto aBeginIter = tempA.begin(); aBeginIter != tempA.end(); aBeginIter = std::next(aBeginIter))
		// {
		// 	std::cout << *aBeginIter << " ";
		// }
		// std::cout << std::endl;

		if (groupSize != 0)
			groupSize--;
		if (groupSize == 0)
		{
			currentJacNumb++;
			nextJacNumb = currentJacNumb + 1;

			// std::cout << "currentJacNumb " << *currentJacNumb << std::endl;
			// std::cout << "nextJacNumb " << *nextJacNumb << std::endl;
	
			// std::cout << "groupSize ==> " << groupSize << std::endl;

			groupSize = *nextJacNumb - *currentJacNumb;
			if (groupSize > a.size() * elementsNum)
				groupSize = a.size() / elementsNum;

			for (size_t i = 0; i < groupSize && aBeginIter != a.end(); i++)
			{
				for (size_t j = 0; j < elementsNum; j++)
				{
					tempA.push_back(*aBeginIter);
					aBeginIter = std::next(aBeginIter);
				}
			}
		}
	}

	for (size_t i = 0; i < groupSize && aBeginIter != a.end(); groupSize--)
	{
		for (size_t j = 0; j < elementsNum; j++)
		{
			tempA.push_back(*aBeginIter);
			aBeginIter = std::next(aBeginIter);
		}
	}
	// std::cout << "[temp a]: " << tempA << std::endl;
	a = tempA;
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

			// std::swap_ranges(pairsCopyBegin, std::next(pairsCopyBegin, step), pairsCopynextPairBegin);
			for (int i = 0; i < step; i++)
			{
				std::swap(*pairsCopyBegin, *pairsCopynextPairBegin);
				pairsCopyBegin = std::next(pairsCopyBegin);
				pairsCopynextPairBegin = std::next(pairsCopynextPairBegin);
			}
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

	changeOrder(b, 0);
	// std::cout << "[b changed]: " << b << std::endl;
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