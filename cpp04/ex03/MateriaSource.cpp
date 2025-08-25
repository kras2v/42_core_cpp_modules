#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
	: _materiaAmount(0)
{
	std::cout << "MateriaSource default constructor" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		this->_slots[i] = nullptr;
	}
}

MateriaSource::MateriaSource( const MateriaSource &other )
	: IMateriaSource(other),
	_materiaAmount(0)
{
	std::cout << "MateriaSource copy constructor" << std::endl;
	for (size_t i = 0; i < 4; i++)
	{
		this->_slots[i] = nullptr;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor" << std::endl;
	for (AMateria *materia : this->_slots)
		if (materia != nullptr) delete materia;
}

MateriaSource &MateriaSource::operator=( const MateriaSource &other )
{
	if (this != &other)
	{
		// COPY
	}
	std::cout << "MateriaSource copy assignment operator" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria( AMateria* materia )
{
	if (this->_materiaAmount < 4)
	{
		this->_slots[this->_materiaAmount] = materia;
		this->_materiaAmount++;
	}
}

AMateria* MateriaSource::createMateria( std::string const &type )
{
	for (size_t i = 0; i < this->_materiaAmount; i++)
	{
		if (this->_slots[i]->getType() == type)
			return (this->_slots[i]->clone());
	}
	return (nullptr);
}
