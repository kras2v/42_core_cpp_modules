#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	private:
		static const unsigned int _ideas_count;
		std::string				  _ideas[100];

	public:
		Brain ( void );
		Brain ( const Brain &other );
		~Brain();

		Brain &			    operator=( const Brain &other );
};

#endif