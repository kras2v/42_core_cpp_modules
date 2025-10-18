#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

# include <iostream>
# include <vector>
# include <list>

class Validator {

	private:
		Validator();
		Validator(const Validator&);
		Validator& operator=(const Validator&);
		~Validator();

	public:
		static bool validateInput(char *argv[], std::vector<int> &vect_ints, std::list<int> &list_ints);
};

#endif /*  VALIDATOR_HPP */
