#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <iomanip>

class ClapTrap
{
	private:
		std::string _name;
		unsigned int _hitPoint;
		unsigned int _energyPoint;
		unsigned int _attackDamage;

	public:
		ClapTrap();
		~ClapTrap();
		ClapTrap(const ClapTrap &other);
		ClapTrap(std::string _name);

		ClapTrap &operator=(const ClapTrap &other);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void showStatistics();

		std::string getName() const;
		unsigned int getHitPoint() const;
		unsigned int getEnergyPoint() const;
		unsigned int getAttackDamage() const;

		void setName( const std::string name );
		void setHitPoint( unsigned int hitP );
		void setEnergyPoint( unsigned int energyP );
		void setAttackDamage( unsigned int attackDamage );
};

#endif