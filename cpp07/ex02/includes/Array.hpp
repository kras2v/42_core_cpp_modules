#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T			  *_elements;
		unsigned int  _size;
		void		  initByDefault();

	public:
		Array<T>();
		Array<T>(const Array<T> &other);
		Array<T> &operator=(const Array<T> &other);
		~Array<T>();

		Array<T>(unsigned int n);

		unsigned int size() const;
		T &operator[](unsigned int index) const;

		class OutOfBoundsException : public std::exception
		{
			const char *what() const noexcept override;
		};
};

# include "Array.tpp"

#endif /* ARRAY_HPP */