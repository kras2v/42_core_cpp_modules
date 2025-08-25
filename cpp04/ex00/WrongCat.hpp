#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>

class WrongCat : public AWrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongCat ( void );
		WrongCat ( const WrongCat &other );
		~WrongCat();

		WrongCat &			operator=( const WrongCat &other );
		void			    makeSound( void ) const;
		const std::string&  getType  ( void ) const override;
		void			    setType  ( const std::string &type ) override;
};

#endif