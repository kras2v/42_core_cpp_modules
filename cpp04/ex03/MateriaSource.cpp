#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _materiaList()
{
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
		this->_slots[i] = nullptr;
	#ifndef DEBUG
		std::cout << "MateriaSource default constructor" << std::endl;
	#endif
}

MateriaSource::MateriaSource( const MateriaSource &other )
	: IMateriaSource(other), _materiaList()
{
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
		this->_slots[i] = nullptr;
	#ifndef DEBUG
		std::cout << "MateriaSource copy constructor" << std::endl;
	#endif
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		if (this->_slots[i] != nullptr)
			delete this->_slots[i];
	}
	#ifndef DEBUG
		std::cout << "MateriaSource destructor" << std::endl;
	#endif
}

MateriaSource &MateriaSource::operator=( const MateriaSource &other )
{
	if (this != &other)
	{
		// COPY
	}
	#ifndef DEBUG
		std::cout << "MateriaSource copy assignment operator" << std::endl;
	#endif
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
			this->_materiaList.addBack(this->_slots[i]->clone());
			return (this->_materiaList.getLast()->curr);
		}
	}
	return (nullptr);
}

void MateriaSource::showCreatedMaterias(void)
{
	const int width = 10;
	const int maxPerRow = 3;
	int count = this->_materiaList.getSize();
	t_materia_node *curr = this->_materiaList.getFirst();
	std::cout << "List of created materials:" << std::endl;
	for (int row = 0; row < (count + maxPerRow - 1) / maxPerRow; ++row) {
		int start = row * maxPerRow;
		int end = std::min(start + maxPerRow, count);

		// Top border
		std::cout << std::string(width * (end - start) + 4, '=') << std::endl;

		// Slot headers
		std::cout << "|";
		for (int i = start; i < end; ++i)
			std::cout << " Slot " << i << std::setw(width - 7) << std::left << " " << "|";
		std::cout << std::endl;

		// Separator
		std::cout << std::string(width * (end - start) + 4, '-') << std::endl;

		// Content
		std::cout << "|";
		size_t	counter = 0;
		while (counter < 3 && curr != nullptr)
		{
			std::string content = (curr->curr ? curr->curr->getType() : "empty");
			std::cout << " " << std::setw(width - 1) << std::left << content << "|";
			curr = curr->next;
			counter++;
		}
		std::cout << std::endl;

		// Bottom border
		std::cout << std::string(width * (end - start) + 4, '=') << std::endl;
	}
}