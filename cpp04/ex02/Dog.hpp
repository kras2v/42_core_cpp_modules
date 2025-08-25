#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>

class Dog : public AAnimal
{
	protected:
		std::string _type;
		Brain*		_brain;

	public:
		Dog ( void );
		Dog ( const Dog &other );
		~Dog();

		Dog & 			    operator=( const Dog &other);
		void 			    makeSound( void ) const override;
		const std::string&  getType  ( void ) const override;
		void 			    setType  ( const std::string &type ) override;
		const Brain&	    getBrain  ( void ) const;
		void			    setBrain  ( const Brain &Brain );
};

#endif
