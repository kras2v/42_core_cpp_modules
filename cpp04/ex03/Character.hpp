#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include <iomanip>
# include <iostream>

# define MAX_MATERIAS_AMOUNT 4

class Character : public ICharacter
{
	private:
		AMateria	*_slots[MAX_MATERIAS_AMOUNT];
		std::string	_name;

	public:
		Character();
		Character( const Character &other );
		Character( const std::string &name );
		~Character();

		Character &operator=( const Character &other );
		virtual std::string const & getName() const override;
		virtual void equip(AMateria* m) override;
		virtual void unequip(int idx) override;
		virtual void use(int idx, ICharacter& target) override;
		virtual void showInventory( void ) override;
};

#endif