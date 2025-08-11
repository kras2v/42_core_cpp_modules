#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;
	public:
		HumanB(std::string t_name, Weapon t_weapon);
		HumanB(std::string t_name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &t_weapon);
};

