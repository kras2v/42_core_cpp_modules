#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"
# include <iostream>
# include <iomanip>
# define MAX_MATERIAS_AMOUNT 4

class MateriaSource : public IMateriaSource
{
	private:
		AMateria		**_createdMaterias;
		AMateria		*_slots[MAX_MATERIAS_AMOUNT];
		unsigned int	_createdMateriaAmount;

	public:
		MateriaSource();
		MateriaSource( const MateriaSource &other );
		~MateriaSource();

		MateriaSource &operator=( const MateriaSource &other );

		void learnMateria( AMateria* materia ) override;
		AMateria* createMateria( std::string const &type ) override;


		void MateriaSource::showCreatedMaterias( void );
};

#endif
