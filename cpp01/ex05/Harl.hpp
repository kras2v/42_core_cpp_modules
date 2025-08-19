#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# define NUMBER_OF_COMPLAINS 4

class Harl;

typedef struct complain
{
	void (Harl::*function)( void );
	std::string name;
} t_complain;

typedef enum complain_num
{
	DEBUG,
	INFO,
	WARNING,
	ERROR
} t_complain_num;

class Harl
{
	private:
		void		debug( void );
		void		info( void );
		void		warning( void );
		void		error( void );
		t_complain _complains[NUMBER_OF_COMPLAINS];

	public:
		Harl();
		~Harl();
		void complain( std::string level );
};

#endif