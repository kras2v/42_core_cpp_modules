#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class Dog : public Animal
{
	public:
		Dog ( void );
		Dog ( const Dog &other );
		~Dog();

		Dog & 			    operator=( const Dog &other);
		void 			    makeSound( void ) const override;
};

#endif
