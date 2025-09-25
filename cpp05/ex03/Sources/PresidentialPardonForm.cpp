#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("home")
{
	#ifdef DEBUG
		std::cout << "PresidentialPardonForm default constructor" << std::endl;
	#endif
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	#ifdef DEBUG
		std::cout << "PresidentialPardonForm default constructor" << std::endl;
	#endif
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	#ifdef DEBUG
		std::cout << "PresidentialPardonForm destructor" << std::endl;
	#endif
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm(other)
{
	#ifdef DEBUG
		std::cout << "PresidentialPardonForm copy constructor" << std::endl;
	#endif
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	#ifdef DEBUG
		std::cout << "PresidentialPardonForm copy assignment operator" << std::endl;
	#endif
	if (this != &other)
	{
		*this = other;
	}
	return *this;
}

void PresidentialPardonForm::action() const
{
	std::cout << BOLD << CYAN
	<< "╔══════════════════════════════════════════════════════════╗"  << std::endl
	<< "║                🪐 GALACTIC PARDON DECREE                 ║"  << std::endl
	<< "╚══════════════════════════════════════════════════════════╝" << std::endl << std::endl << RESET;

	std::cout << YELLOW << "Issued by: His Extragalactic Highness, Zaphod Beeblebrox"  << std::endl << RESET
		<< MAGENTA << "Date: Mostly Whenever"  << std::endl << RESET
		<< BLUE << "Location: Somewhere Between Betelgeuse and That Place With the Really Big Fish" << std::endl << std::endl << RESET;

	std::cout << BOLD << "TO WHOM IT MAY CONCERN:"  << std::endl << RESET
		<< "This is to inform that " << GREEN << this->_target << RESET
		<< " has been officially pardoned by " << CYAN << "Zaphod Beeblebrox" << RESET << ","  << std::endl
		<< "President of Something Very Important (the other title is classified), for the following reasons:" << std::endl << std::endl;

	std::cout << BOLD << "-- Excessive enthusiasm for improbable hats --"  << std::endl << RESET
		<< "\tIt is recognized that " << GREEN << this->_target << RESET
		<< "'s devotion to headgear has single-handedly prevented at least 3 intergalactic fashion disasters." << std::endl << std::endl;

	std::cout << BOLD << "-- Unnecessary heroics involving a towel --"  << std::endl << RESET
		<< "\t" << GREEN << this->_target << RESET 
		<< " bravely carried a towel on at least two occasions," << std::endl
		<< "\twhich may or may not have saved the universe from mild embarrassment." << std::endl << std::endl;

	std::cout << BOLD << "-- Accidental diplomacy with a paranoid space slug --" << std::endl << RESET
		<< "\t" << GREEN << this->_target << RESET 
		<< " somehow negotiated peace between sentient mollusks without actually meaning to." << std::endl << std::endl;

	std::cout << "Therefore, by the supreme and entirely arbitrary authority vested in me" << std::endl
		<< "(mostly because I'm awesome and own a spaceship)," << std::endl
		<< "I hereby declare " << GREEN << this->_target << RESET
		<< " free from all minor cosmic penalties," << std::endl
		<< "overdue space library fees, and mildly annoying space bureaucracy." << std::endl << std::endl;

	std::cout << BOLD
		<< "╔═══════════════════════════════════════════════════════════╗" << std::endl
		<< "║           Signed, Sealed, and Slightly Confused           ║" << std::endl
		<< "╚═══════════════════════════════════════════════════════════╝" << std::endl << RESET;

	std::cout << CYAN << "Zaphod Beeblebrox"  << std::endl
		<< "President of of the Galaxy."  << std::endl
		<< "[Two-headed signature goes here]"  << std::endl << RESET;
}

const std::string PresidentialPardonForm::getAdditionalInfo() const
{
	return "- Target: " + this->_target;
}

std::string PresidentialPardonForm::checkTarget(std::string target) const
{
	if (target.empty()) return "empty";
	return target;
}