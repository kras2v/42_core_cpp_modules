#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>

class Cat : public Animal
{
	protected:
		std::string _type;

	public:
		Cat ( void );
		Cat ( const Cat &other );
		~Cat();

		Cat &			    operator=( const Cat &other );
		void			    makeSound( void ) const override;
		const std::string&  getType  ( void ) const override;
		void			    setType  ( const std::string &type ) override;
};

#endif