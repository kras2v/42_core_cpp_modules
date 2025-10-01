#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *address, size_t lenght, void(*func)(T &))
{
	for (size_t i = 0; i < lenght; i++)
	{
		func(address[i]);
	}
}

template <typename T>
void iter(const T *address, size_t lenght, void(*func)(const T &))
{
	for (size_t i = 0; i < lenght; i++)
	{
		func(address[i]);
	}
}

#endif /* ITER_HPP */
