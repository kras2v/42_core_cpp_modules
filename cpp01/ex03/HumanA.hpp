#include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon &_weapon;
	public:
		HumanA(std::string t_name, Weapon &t_weapon);
		~HumanA();
		void attack();
};
