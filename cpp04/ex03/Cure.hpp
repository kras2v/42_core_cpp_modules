#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <iostream>
# include <string>

class Cure : public AMateria
{
	protected:
		std::string const _type;

	public:
		Cure( void );
		Cure( const Cure &other );
		virtual ~Cure();

		Cure & 			operator=( const Cure &other);
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* 	clone() const;
		virtual void		use(ICharacter& target);
};

#endif