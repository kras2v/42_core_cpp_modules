NAME		=	bureaucrat
CPP_FLAGS	=	c++ -Wall -Wextra -Werror -MMD -MP -std=c++17

SRCS_DIR	=	Sources/
ICNL_DIR	=	Includes/
BUILT_DIR	=	Objects/

SRCS		=	main.cpp \
				Bureaucrat.cpp \
				PresidentialPardonForm.cpp \
				RobotomyRequestForm.cpp \
				ShrubberyCreationForm.cpp \
				Intern.cpp \
				AForm.cpp

SOURCES		=	$(addprefix $(SRCS_DIR), $(SRCS))
OBJECTS		=	$(addprefix $(BUILT_DIR), $(SRCS:.cpp=.o))
DEPENDS		=	$(addprefix $(BUILT_DIR), $(SRCS:.cpp=.d))

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CPP_FLAGS) -I$(ICNL_DIR) $(OBJECTS) -o $@

-include $(DEPENDS)

debug: CPP_FLAGS += -DDEBUG
debug: $(OBJECTS) $(NAME)

$(BUILT_DIR)%.o : $(SRCS_DIR)%.cpp
	@mkdir -p $(BUILT_DIR)
	$(CPP_FLAGS) -I$(ICNL_DIR) -c $< -o $@

clean :
	rm -rf objs

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all re clean fclean
