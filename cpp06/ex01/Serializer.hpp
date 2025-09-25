#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

class Serializer
{
	private:
		Serializer() = delete;
		Serializer(const Serializer &other) = delete;
		Serializer operator=(const Serializer &other) = delete;
		~Serializer() = delete;

	public:
		// It takes a pointer and converts it to the unsigned integer type uintptr_t.
		static uintptr_t serialize(Data* ptr);
		// It takes an unsigned integer parameter and converts it to a pointer to Data.
		static Data* deserialize(uintptr_t raw);
};

#endif /* SERIALIZER_HPP */
