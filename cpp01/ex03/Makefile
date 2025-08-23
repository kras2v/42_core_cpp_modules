NAME		=	unnecessary_violence
CPP_FLAGS	=	c++ -Wall -Wextra -Werror -std=c++11
SRCS		=	main.cpp \
				Weapon.cpp \
				HumanA.cpp \
				HumanB.cpp
BUILT_DIR	=	objs/
OBJS		=	$(SRCS:.cpp=.o)
OBJECTS		=	$(addprefix $(BUILT_DIR), $(OBJS))

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CPP_FLAGS) $(OBJECTS) -o $@

debug: CPP_FLAGS += -Ddebug
debug: $(OBJECTS) $(NAME)

$(BUILT_DIR)%.o : %.cpp
	@mkdir -p $(BUILT_DIR)
	$(CPP_FLAGS) -c $< -o $@

clean :
	rm -rf objs

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all re clean fclean
