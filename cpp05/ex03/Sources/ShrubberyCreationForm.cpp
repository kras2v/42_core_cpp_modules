#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("home")
{
	#ifdef DEBUG
		std::cout << "ShrubberyCreationForm default constructor" << std::endl;
	#endif
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	#ifdef DEBUG
		std::cout << "ShrubberyCreationForm default constructor" << std::endl;
	#endif
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	#ifdef DEBUG
		std::cout << "ShrubberyCreationForm destructor" << std::endl;
	#endif

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
	AForm(other)
{
	#ifdef DEBUG
		std::cout << "ShrubberyCreationForm copy constructor" << std::endl;
	#endif
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	#ifdef DEBUG
		std::cout << "ShrubberyCreationForm copy assignment operator" << std::endl;
	#endif
	if (this != &other)
	{
		*this = other;
	}
	return *this;
}

void ShrubberyCreationForm::action() const
{
	std::ofstream ifs;
	ifs.open(this->_target + "_shrubbery", std::ofstream::out);
	if (ifs.fail())
	{
		std::cerr << "Cannot create file." << std::endl;
		return ;
	}
	ifs << "                      & %  @@                  " << std::endl
		<<  "              #&%&##&@ #@&   %%@              " << std::endl
		<<  "               &##@@@%@@   &@%@@              " << std::endl
		<<  "               #%\\#%%@@@  %%&%@%#@#          " << std::endl
		<<  "              @ # :@##_%&&%#%%%@_%&           " << std::endl
		<<  "                   ~@&%&&@%&%&&&  &@          " << std::endl
		<<  "                  |   ##%%&#%#@@              " << std::endl
		<<  "                  @##   &&&_%%\\%&            " << std::endl
		<<  "            @@@ %@|%#:%&\\&~@%@@%%#@#         " << std::endl
		<<  "           #&@#&%# ||%&%__\\%&&@@%|@%@@       " << std::endl
		<<  "          @%&%@%%@&%|##%@&%&@@@#%@%#@&        " << std::endl
		<<  "          %%@%%%@&&|%# @%%#&%@&#@%&@#&%##     " << std::endl
		<<  "           %& &&%&||&# &&#%@&~&@&&@%_#;%&%&   " << std::endl
		<<  "           #  # &#;|&&#& #&#%&%&%#%#%###%#&   " << std::endl
		<<  "              %  % ||\\#@ #%&% ##%@%#%@% %&%  " << std::endl
		<<  "       @ &@        |;  =##%# %@@@& %%@%       " << std::endl
		<<  "     @&##@@#%#            :|  ~ & &#%@%  &% % " << std::endl
		<<  "  @*%@%#%\\@#&@@          ||  |  @%           " << std::endl
		<<  "&@&%&&% \\ @&##%%@ @     ||| |;/ &            " << std::endl
		<<  " %&###&% &@&&#@%@        :|| |~~_@#:_\\\\\\   " << std::endl
		<<  "    @#%% #@#@ /          ||//                 " << std::endl
		<<  "      # @& @// &         |//                  " << std::endl
		<<  "         =||            =//                   " << std::endl
		<<  "          ||            ||=       @           " << std::endl
		<<  "           ||             |;|                 " << std::endl
		<<  "    \\___./|||\\.______./|||\\._.-.           " << std::endl
		<<  "     \\  .     .                 #  /         " << std::endl
		<<  "      \\___________________________/          " << std::endl
		<<  "        ‾                       ‾             " << std::endl;
}

const std::string ShrubberyCreationForm::getAdditionalInfo() const
{
	return "- Target: " + this->_target;
}

std::string ShrubberyCreationForm::checkTarget(std::string target) const
{
	if (target.empty()) return "empty";
	return target;
}