#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>

template <typename T>
class MutantStack
{
	private:
		std::deque<T> _elements;

	public:
		MutantStack();
		MutantStack(const MutantStack<T> &other);
		MutantStack & operator=(const MutantStack<T> &other);
		~MutantStack();

		const std::deque<T> &getList() const;

		bool		empty() const;
		void		clear();
		size_t		size() const;
		T			top() const;
		void		pop();
		void		push(const T &element);

		class iterator
		{
			private:
				T *pointer;
				iterator() = delete;

			public:
				iterator(T* node);
				iterator(const iterator &other);
				iterator & operator=(const iterator &other);
				~iterator();

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
