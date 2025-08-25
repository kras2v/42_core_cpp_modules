#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include <iostream>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_slots[4];
		unsigned int _materiaAmount;

	public:
		MateriaSource();
		MateriaSource( const MateriaSource &other );
		~MateriaSource();

		MateriaSource &operator=( const MateriaSource &other );

		void learnMateria( AMateria* materia ) override;
		AMateria* createMateria( std::string const &type ) override;
};

#endif
