#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "MateriaList.hpp"
# include "AMateria.hpp"
# include <iostream>
# include <iomanip>
# define MAX_MATERIAS_AMOUNT 4

class MateriaSource : public IMateriaSource
{
	private:
		MateriaList		_materiaList;
		AMateria		*_slots[MAX_MATERIAS_AMOUNT];

	public:
		MateriaSource ( );
		MateriaSource ( const MateriaSource &other );
		~MateriaSource( );

		MateriaSource&	operator=( const MateriaSource &other );

		void			learnMateria( AMateria* materia ) override;
		AMateria*		createMateria( std::string const &type ) override;

		void			showCreatedMaterias( void );
};

#endif
