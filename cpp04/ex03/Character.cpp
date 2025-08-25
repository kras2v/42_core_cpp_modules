#include "Character.hpp"

Character::Character( void )
	: _materiaAmount(0), _name("boris")
{
	for (size_t i = 0; i < 4; i++)
	{
		this->_slots[i] = nullptr;
	}
	std::cout << "Character default constructor" << std::endl;
}

Character::Character( const Character &other ) 
	: ICharacter(other), _materiaAmount(0)
{
	for (size_t i = 0; i < 4; i++)
	{
		this->_slots[i] = nullptr;
	}
	*this = other;
	std::cout << "Character copy constructor" << std::endl;
}

Character::~Character()
{
	std::cout << "Character destructor" << std::endl;
	for (size_t i = 0; i < this->_materiaAmount; i++)
	{
		if (this->_slots[i] != nullptr)
			delete this->_slots[i];
	}
	
}

Character::Character( const std::string &name )
	: _materiaAmount(0), _name(name)
{
	std::cout << "Character parameterized constructor" << std::endl;
}

Character & Character::operator=( const Character &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_materiaAmount = other._materiaAmount;
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
	std::cout << this->_materiaAmount << std::endl;
	if (this->_materiaAmount < 4)
	{
		this->_slots[this->_materiaAmount] = m;
		this->_materiaAmount++;
	}
}

void Character::unequip(int idx)
{
	if (this->_materiaAmount < 4)
	{
		(void)idx;
		// this->_slots[this->_materiaAmount - 1] = idx;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (this->_materiaAmount != 0 && idx <= (int)this->_materiaAmount - 1)
	{
		this->_slots[idx]->use(target);
	}
}
