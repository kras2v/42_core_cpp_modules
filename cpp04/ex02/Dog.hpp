#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Dog : public AAnimal
{
	protected:
		Brain*		_brain;

	public:
		Dog ( void );
		Dog ( const Dog &other );
		~Dog();

		Dog & 			    operator=( const Dog &other);
		void 			    makeSound( void ) const override;
		const Brain&	    getBrain  ( void ) const;
		void			    setBrain  ( const Brain &Brain );
};

#endif
