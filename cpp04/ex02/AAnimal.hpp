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
		AAnimal ( std::string type );
		virtual ~AAnimal() = 0;

		AAnimal &				  operator=( const AAnimal &other);
		virtual void 			  makeSound( void ) const = 0;
		const std::string &getType ( void ) const;
		void			  setType  ( const std::string &type );
};

#endif
