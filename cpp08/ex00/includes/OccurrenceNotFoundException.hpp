#ifndef ITER_NOT_FOUND_EXCEPTION_HPP
# define ITER_NOT_FOUND_EXCEPTION_HPP

# include <iostream>

class OccurrenceNotFoundException : public std::exception
{
	const char *what() const noexcept override;
};

#endif /* ITER_NOT_FOUND_EXCEPTION_HPP */
