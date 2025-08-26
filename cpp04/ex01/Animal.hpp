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
		Animal ( const Animal &other );
		Animal ( std::string type );
		virtual ~Animal();

		Animal &				  operator=( const Animal &other);
		virtual void 			  makeSound( void ) const;
		virtual const std::string &getType ( void ) const;
		virtual void			  setType  ( const std::string &type );
};

#endif
