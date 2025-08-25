#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class Dog : public Animal
{
	protected:
		std::string _type;

	public:
		Dog ( void );
		Dog ( const Dog &other );
		~Dog();

		Dog & 			    operator=( const Dog &other);
		void 			    makeSound( void ) const override;
		const std::string&  getType  ( void ) const override;
		void 			    setType  ( const std::string &type ) override;
};

#endif
