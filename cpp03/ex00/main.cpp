#include "ClapTrap.hpp"

int main()
{
	{
		ClapTrap bob("Bob");
		ClapTrap tom("Tom");
		bob.attack("Tom");
		for (size_t i = 0; i < 5; i++)
		{
			tom.beRepaired(1);
		}
		bob.attack("Tom");
		bob.showStatistics();
		tom.showStatistics();
	}
	std::cout << std::string (50, '*') << std::endl;
	{
		ClapTrap bob("Bob");
		ClapTrap tom(bob);
		std::cout << "Name after copy constructor: " << tom.getName() << std::endl;
		tom.setName("Tom");
		for (size_t i = 0; bob.getEnergyPoint() > 0 && tom.getEnergyPoint() > 0; i++)
		{
			bob.attack("Tom");
			tom.takeDamage(bob.getAttackDamage());
			if (i % 2 == 0)
			{
				tom.attack("Bob");
				bob.takeDamage(tom.getAttackDamage());
			}
			bob.showStatistics();
			tom.showStatistics();
			if (bob.getEnergyPoint() == 0 || tom.getEnergyPoint() == 0)
				break;
		}
		bob.beRepaired(1);
		tom.beRepaired(1);
	}
	return (0);
}