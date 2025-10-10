#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <list>
# include <algorithm>
# include <iterator>
# include <functional>

class Span
{
	private:
		unsigned int	_N;
		std::list<int>	_elements;

		int				_shortestSpan;
		int				_longestSpan;
		bool			_isUpdated;

		int				getSecondNumber() const;
		void			calculateShortestSpan();

	public:
		Span();
		Span(const Span &other);
		Span & operator=(const Span &other);
		~Span();

		Span(unsigned int N);

		template <class iter>
			Span(iter begin, iter end);

		template <class iter>
			void addNumber(iter begin, iter end);
		void addNumber(int numb);

		int shortestSpan();
		int longestSpan();

		int shortestSpan() const;
		int longestSpan() const;

		unsigned int getN() const;
		#ifdef DEBUG
			void print();
		#endif

		class MaxElementsCountException : public std::exception
		{
			const char *what() const noexcept override;
		};

		class NotEnoughElementsException : public std::exception
		{
			const char *what() const noexcept override;
		};
};

#include "Span.tpp"

#endif /* SPAN_HPP */

