#include "Character.hpp"

Character::Character( void )
	: _name("boris")
{
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_slots[i] = nullptr;
	}
	std::cout << "Character default constructor" << std::endl;
}

Character::Character( const Character &other )
	: ICharacter(other)
{
	*this = other;
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_slots[i] = nullptr;
	}
	std::cout << "Character copy constructor" << std::endl;
}

Character::~Character()
{
	std::cout << "Character destructor" << std::endl;
}

Character::Character( const std::string &name )
	: _name(name)
{
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		this->_slots[i] = nullptr;
	}
	std::cout << "Character parameterized constructor" << std::endl;
}

Character & Character::operator=( const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		for (AMateria *materia : this->_slots)
			if (materia != nullptr) delete materia;
	}
	std::cout << "Character copy assignment operator" << std::endl;
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	std::cout << "trying to equip " << m->getType() << std::endl;
	for (size_t i = 0; i < MAX_MATERIAS_AMOUNT; i++)
	{
		if (this->_slots[i] == nullptr)
		{
			this->_slots[i] = m;
			break;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < MAX_MATERIAS_AMOUNT && this->_slots[idx] != nullptr)
		this->_slots[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < MAX_MATERIAS_AMOUNT && this->_slots[idx] != nullptr)
		this->_slots[idx]->use(target);
}

void Character::showInventory( void )
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