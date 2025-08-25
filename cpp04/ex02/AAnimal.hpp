#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal ();
		AAnimal ( const AAnimal &other );
		virtual ~AAnimal() = 0;

		AAnimal &				  operator=( const AAnimal &other);
		virtual void 			  makeSound( void ) const = 0;
		virtual const std::string &getType ( void ) const = 0;
		virtual void			  setType  ( const std::string &type ) = 0;
};

#endif
