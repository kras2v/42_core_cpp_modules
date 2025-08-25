#ifndef CAT_HPP
# define CAT_HPP

# include "Brain.hpp"
# include "AAnimal.hpp"
# include <iostream>
# include <string>

class Cat : public AAnimal
{
	protected:
		std::string _type;
		Brain*		_brain;

	public:
		Cat ( void );
		Cat ( const Cat &other );
		~Cat();

		Cat &			    operator=( const Cat &other );
		void			    makeSound( void ) const override;
		const std::string&  getType  ( void ) const override;
		void			    setType  ( const std::string &type ) override;
		const Brain&	    getBrain  ( void ) const;
		void			    setBrain  ( const Brain &Brain );
};

#endif