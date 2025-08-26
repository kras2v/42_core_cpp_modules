#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	protected:
		std::string _type;

	public:
		Animal ();
		Animal ( std::string type );
		Animal ( const Animal &other );
		virtual ~Animal();

		Animal &				  operator=( const Animal &other);
		virtual void 			  makeSound( void ) const;
		virtual const std::string &getType ( void ) const;
		virtual void			  setType  ( const std::string &type );
};

#endif
