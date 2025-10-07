#ifndef ARRAY_HPP
# define ARRAY_HPP

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

			template <typename U>
				Array<T>(const Array<U> &other);
			template <typename U>
				Array<T> &operator=(const Array<U> &other);

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