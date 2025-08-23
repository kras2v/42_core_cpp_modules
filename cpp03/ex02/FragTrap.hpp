#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class FragTrap : public ClapTrap
{
	private:
		static const unsigned int _defaultHitPoint;
		static const unsigned int _defaultEnergyPoint;
		static const unsigned int _defaultAttackDamage;

	public:
		FragTrap();
		~FragTrap();
		FragTrap(const FragTrap &other);
		FragTrap(std::string _name);

		FragTrap &operator=(const FragTrap &other);

		void attack(const std::string& target);
		void highFivesGuys(void);
		void showStatistics( void );

		unsigned int getDefaultHitPoint() const;
		unsigned int getDefaultEnergyPoint() const;
		unsigned int getDefaultAttackDamage() const;
};

#endif