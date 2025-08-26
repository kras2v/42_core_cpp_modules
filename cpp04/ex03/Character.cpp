#include "Character.hpp"

Character::Character( void )
	: _unequipMateriaList(), _name("boris")
{
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_slots[i] = nullptr;
	}
	#ifndef DEBUG
		std::cout << "Character default constructor" << std::endl;
	#endif
}

Character::Character( const Character &other )
	:  ICharacter(other), _unequipMateriaList()
{
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_slots[i] = nullptr;
	}
	*this = other;
	#ifndef DEBUG
		std::cout << "Character copy constructor" << std::endl;
	#endif
}

Character::~Character()
{
	#ifndef DEBUG
		std::cout << "Character " << this->_name << " destructor" << std::endl;
	#endif
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		if (this->_slots[i] != nullptr)
			delete this->_slots[i];
	}
}

Character::Character( const std::string &name )
	: _unequipMateriaList(), _name(name)
{
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_slots[i] = nullptr;
	}
	#ifndef DEBUG
		std::cout << "Character parameterized constructor" << std::endl;
	#endif
}

Character & Character::operator=( const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
		{
			if (this->_slots[i])
			{
				delete this->_slots[i];
				this->_slots[i] = nullptr;
			}
			if (other._slots[i])
				this->_slots[i] = other._slots[i]->clone();
		}
		this->_unequipMateriaList = other._unequipMateriaList;
	}
	#ifndef DEBUG
		std::cout << "Character copy assignment operator" << std::endl;
	#endif
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (m == nullptr) return;
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		if (this->_slots[i] == nullptr)
		{
			this->_slots[i] = m->clone();
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < MAX_MATERIAS_AMOUNT && this->_slots[idx] != nullptr)
	{
		this->_unequipMateriaList.addBack(this->_slots[idx]);
		this->_slots[idx] = nullptr;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < MAX_MATERIAS_AMOUNT && this->_slots[idx] != nullptr)
		this->_slots[idx]->use(target);
}

void Character::showInventory( void )
{
	const int width = 10;
	std::cout << "Inventory of character " << this->_name << std::endl;
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

void Character::showUneqipedMaterias(void)
{
	const int width = 10;
	const int maxPerRow = 3;
	int count = this->_unequipMateriaList.getSize();
	t_materia_node *curr = this->_unequipMateriaList.getFirst();
	std::cout << "List of created materials:" << std::endl;
	for (int row = 0; row < (count + maxPerRow - 1) / maxPerRow; ++row) {
		int start = row * maxPerRow;
		int end = std::min(start + maxPerRow, count);

		// Top border
		std::cout << std::string(width * (end - start) + 4, '=') << std::endl;

		// Slot headers
		std::cout << "|";
		for (int i = start; i < end; ++i)
			std::cout << " Mat. " << i << std::setw(width - 7) << std::left << " " << "|";
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