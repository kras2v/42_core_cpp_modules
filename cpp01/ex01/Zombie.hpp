#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

# define my_string std::string
# define my_cout std::cout
# define my_cerr std::cerr
# define my_cin std::cin
# define my_endl std::endl

class Zombie
{
	private:
		my_string _name;
		Zombie();
	public:
		Zombie(my_string t_name);
		~Zombie();
		void announce( void );
		Zombie* zombieHorde( int N, std::string name );
};

#endif