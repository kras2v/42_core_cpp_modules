#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _createdMateriaAmount(0)
{
	std::cout << "MateriaSource default constructor" << std::endl;
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
		this->_slots[i] = nullptr;
	this->_createdMaterias = nullptr;
}

MateriaSource::MateriaSource( const MateriaSource &other )
	: IMateriaSource(other), _createdMateriaAmount(0)
{
	std::cout << "MateriaSource copy constructor" << std::endl;
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
		this->_slots[i] = nullptr;
	this->_createdMaterias = nullptr;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor" << std::endl;
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		if (this->_slots[i] != nullptr)
			delete this->_slots[i];
	}
	for (size_t i = 0; i < this->_createdMateriaAmount; i++)
	{
		if (this->_createdMaterias[i] != nullptr)
			delete this->_createdMaterias[i];
	}
	if (this->_createdMaterias)
		delete [] this->_createdMaterias;
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
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		if (this->_slots[i] == nullptr)
		{
			this->_slots[i] = materia;
			break;
		}
	}
}

AMateria* MateriaSource::createMateria( std::string const &type )
{
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		if (this->_slots[i]->getType() == type)
		{
			this->_createdMateriaAmount++;
			if (this->_createdMaterias == nullptr
				|| this->_createdMateriaAmount >= sizeof(this->_createdMaterias) / sizeof(this->_createdMaterias[0]))
			{
				unsigned int newSize = this->_createdMateriaAmount * 2;
				AMateria **tmp = new AMateria*[newSize];
				for (size_t i = 0; i < newSize; i++)
				{
					if (this->_createdMaterias && this->_createdMaterias[i])
					{
						tmp[i] = this->_createdMaterias[i]->clone();
						delete this->_createdMaterias[i];
					}
					else
					{
						tmp[i] = nullptr;
					}
				}
				delete [] this->_createdMaterias;
				this->_createdMaterias = tmp;
			}
			this->_createdMaterias[this->_createdMateriaAmount - 1] = this->_slots[i]->clone();
			return (this->_createdMaterias[this->_createdMateriaAmount - 1]);
		}
	}
	return (nullptr);
}

void MateriaSource::showCreatedMaterias( void )
{
	const int width = 20;
	std::cout << std::string(width * MAX_MATERIAS_AMOUNT + 5, '=') << std::endl;
	std::cout << "|";
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
		std::cout << " Slot " << i << std::setw(width - 7) << std::left << " " << "|";
	std::cout << std::endl;
	std::cout << std::string(width * MAX_MATERIAS_AMOUNT + 5, '-') << std::endl;
	std::cout << "|";
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		std::string content = (this->_slots[i] ? this->_slots[i]->getType() : "empty");
		std::cout << " " << std::setw(width - 1) << std::left << content << "|";
	}
	std::cout << std::endl;
	std::cout << std::string(width * MAX_MATERIAS_AMOUNT + 5, '=') << std::endl;
}