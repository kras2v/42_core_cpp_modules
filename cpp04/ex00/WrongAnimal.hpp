#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal();
		WrongAnimal( const WrongAnimal &other );
		WrongAnimal ( std::string type );
		virtual ~WrongAnimal();

		WrongAnimal &			  operator=( const WrongAnimal &other);
		void 					  makeSound( void ) const;
		virtual const std::string &getType ( void ) const;
		virtual void			  setType  ( const std::string &type );
};

#endif
