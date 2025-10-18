#ifndef VALIDATOR_HPP
#define VALIDATOR_HPP

# include <iostream>
# include <vector>
# include <list>

class Validator {

	private:
		Validator() = delete;
		Validator(const Validator& other) = delete;
		Validator& operator=(const Validator& other) = delete;
		~Validator() = delete;

	public:
		static bool validateInput(char *argv[], std::vector<int> &vect_ints, std::list<int> &list_ints);
};

#endif /*  VALIDATOR_HPP */
