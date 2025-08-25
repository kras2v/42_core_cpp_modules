#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>
# include <string>

class AMateria
{
	protected:
		std::string const _type;

	public:
		AMateria( void );
		AMateria( const AMateria &other );
		AMateria( std::string const & type );
		virtual ~AMateria();

		AMateria & 			operator=( const AMateria &other);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* 	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif