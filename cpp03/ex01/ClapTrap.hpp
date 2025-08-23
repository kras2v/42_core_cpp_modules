#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>
# include <iomanip>

# define RED			"\e[0;31m"
# define BLUE			"\e[0;34m"
# define WHITE			"\e[0;37m"
# define RESET			"\e[0m"

class ClapTrap
{
	private:
		std::string _name;
		unsigned int _hitPoint;
		unsigned int _energyPoint;
		unsigned int _attackDamage;

		static const unsigned int _defaultHitPoint;
		static const unsigned int _defaultEnergyPoint;
		static const unsigned int _defaultAttackDamage;

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

		virtual std::string getName() const;
		unsigned int getHitPoint() const;
		unsigned int getEnergyPoint() const;
		unsigned int getAttackDamage() const;

		unsigned int getDefaultHitPoint() const;
		unsigned int getDefaultEnergyPoint() const;
		unsigned int getDefaultAttackDamage() const;

		void setName( const std::string name );
		void setHitPoint( unsigned int hitP );
		void setEnergyPoint( unsigned int energyP );
		void setAttackDamage( unsigned int attackDamage );
};

#endif