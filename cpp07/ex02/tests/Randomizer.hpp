#ifndef RANDOMIZER_HPP
# define RANDOMIZER_HPP

# include <string>
# include "Point.hpp"

# define SIZE 10
# define MAX 100
# define MIN 10

class Randomizer
{
	private:
		Randomizer() = delete;
		Randomizer(const Randomizer &other) = delete;
		Randomizer &operator=(const Randomizer &other) = delete;
		~Randomizer() = delete;

	public:
		static int 			getRandom(int min, int max);
		static int 			randomInt();
		static std::string 	randomString();
		static Point 		randomPoint();
};

#endif /* RANDOMIZER_HPP */
