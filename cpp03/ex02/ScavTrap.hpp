#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class ScavTrap : public ClapTrap
{
	private:
		static const unsigned int _defaultHitPoint;
		static const unsigned int _defaultEnergyPoint;
		static const unsigned int _defaultAttackDamage;

	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap(std::string _name);

		ScavTrap &operator=(const ScavTrap &other);

		void attack(const std::string& target);
		void guardGate( void );
		void showStatistics( void );

		unsigned int getDefaultHitPoint() const;
		unsigned int getDefaultEnergyPoint() const;
		unsigned int getDefaultAttackDamage() const;
};

#endif