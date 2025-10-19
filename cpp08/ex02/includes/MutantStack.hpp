#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template<typename _Tp>
class MutantStack : public std::stack<_Tp>
{
	public:
		MutantStack();
		MutantStack(const MutantStack<_Tp> &other);
		MutantStack & operator=(const MutantStack<_Tp> &other);
		~MutantStack();

		using iterator = typename std::stack<_Tp>::container_type::iterator;
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"

#endif /* MUTANTSTACK_HPP */
