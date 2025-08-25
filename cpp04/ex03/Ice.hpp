#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <iostream>
# include <string>

class Ice : public AMateria
{
	protected:
		std::string const _type;

	public:
		Ice( void );
		Ice( const Ice &other );
		virtual ~Ice();

		Ice & 			operator=( const Ice &other);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* 	clone() const;
		virtual void		use(ICharacter& target);
};

#endif