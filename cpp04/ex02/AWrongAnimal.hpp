#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class AWrongAnimal
{
	protected:
		std::string _type;
	public:
		AWrongAnimal();
		AWrongAnimal( const AWrongAnimal &other );
		virtual ~AWrongAnimal();

		AWrongAnimal &			  operator=( const AWrongAnimal &other);
		void 					  makeSound( void ) const;
		virtual const std::string &getType ( void ) const;
		virtual void			  setType  ( const std::string &type );
};

#endif
