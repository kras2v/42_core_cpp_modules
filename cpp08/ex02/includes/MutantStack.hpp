#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include "CustomList.hpp"
# include <stack>

template <typename T>
class MutantStack
{
	private:
		CustomList<T> _elements;

	public:
		MutantStack();
		MutantStack(const MutantStack<T> &other);
		MutantStack & operator=(const MutantStack<T> &other);
		~MutantStack();

		const CustomList<T> &getList() const;

		void		empty();
		size_t		size() const;
		T&			top() const;
		void		pop();
		void		push(const T &element);

		//Iterators
		class iterator
		{
			private:
				Node<T> *pointer;
				iterator() = delete;

			public:
				iterator(Node<T>* node);
				// iterator(const iterator<T> &other);
				// iterator & operator=(const iterator<T> &other);
				// ~iterator();

				const T & operator*() const;
				bool operator==(const iterator & other) const;
				bool operator!=(const iterator & other) const;
				T & operator++();
				T & operator--();
		};

		iterator	begin();
		iterator	end();
};

#include "MutantStack.tpp"

#endif /* MUTANTSTACK_HPP */
