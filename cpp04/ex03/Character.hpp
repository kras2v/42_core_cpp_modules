#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include <iostream>

class Character : public ICharacter
{
	private:
		AMateria	*_slots[4];
		unsigned int _materiaAmount;
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
};

#endif