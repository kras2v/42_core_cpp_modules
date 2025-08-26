#ifndef CAT_HPP
# define CAT_HPP

# include "Brain.hpp"
# include "Animal.hpp"
# include <iostream>
# include <string>

class Cat : public Animal
{
	protected:
		Brain*		_brain;

	public:
		Cat ( void );
		Cat ( const Cat &other );
		~Cat();

		Cat &			    operator=( const Cat &other );
		void			    makeSound( void ) const override;
		const Brain&	    getBrain  ( void ) const;
		void			    setBrain  ( const Brain &Brain );
};

#endif