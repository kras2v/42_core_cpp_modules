#ifndef EASYFIND_TPP
#define EASYFIND_TPP

# include <algorithm>
# include "OccurrenceNotFoundException.hpp"

template <typename T>
typename T::iterator easyfind(T &param, int toFind)
{
	auto iter = std::find(param.begin(), param.end(), toFind);
	if (iter == param.end())
		throw OccurrenceNotFoundException();
	return iter;
}

#endif /* EASYFIND_TPP */