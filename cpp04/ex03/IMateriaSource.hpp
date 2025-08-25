#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

class IMateriaSource
{
	protected:
		IMateriaSource( void );
		IMateriaSource( const IMateriaSource &other );
		IMateriaSource & operator=( const IMateriaSource &other);

	public:
		virtual ~IMateriaSource();

		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif