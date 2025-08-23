#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string _name;


	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(const DiamondTrap &other);
		DiamondTrap(std::string _name);

		DiamondTrap &operator=(const DiamondTrap &other);

		using ScavTrap::attack;
		void guardGate( void );
		void showStatistics( void );
		std::string getName() const;
		void setName( const std::string name );
		void whoAmI();
};

#endif