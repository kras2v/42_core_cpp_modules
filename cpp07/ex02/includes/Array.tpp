#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T			  *_elements;
		unsigned int  _size;
		void		  initByDefault();

	public:
		#pragma region Orthodox form
			Array<T>();
			Array<T>(const Array<T> &other);
			Array<T> &operator=(const Array<T> &other);
			~Array<T>();

			template <typename U>
				Array<T>(const Array<U> &other);
			template <typename U>
				Array<T> &operator=(const Array<U> &other);
		#pragma endregion

		Array<T>(unsigned int n);

		unsigned int size() const;
		T &operator[](unsigned int index) const;

		class OutOfBoundsException : public std::exception
		{
			const char *what() const noexcept override;
		};
};

#endif /* ARRAY_TPP */