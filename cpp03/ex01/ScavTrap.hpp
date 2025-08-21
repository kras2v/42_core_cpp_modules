#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class ScavTrap : public ClapTrap
{
	private:

	public:
		ScavTrap();
		~ScavTrap();
		ScavTrap(const ScavTrap &other);
		ScavTrap(std::string _name);

		void guardGate( void );
};

#endif