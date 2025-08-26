NAME			=	materia
CPP_FLAGS		=	c++ -g -Wall -Wextra -Werror -std=c++17
SRCS			=	AMateria.cpp \
					Character.cpp \
					Cure.cpp \
					Ice.cpp \
					ICharacter.cpp \
					IMateriaSource.cpp \
					MateriaList.cpp \
					main.cpp \
					MateriaSource.cpp
BUILT_DIR		=	objs/
OBJS			=	$(SRCS:.cpp=.o)
OBJECTS			=	$(addprefix $(BUILT_DIR), $(OBJS))
DEPENDENCIES	=	$(OBJECTS:.o=.d)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CPP_FLAGS) $(OBJECTS) -o $@

debug: CPP_FLAGS += -DDEBUG
debug: $(OBJECTS) $(NAME)

$(BUILT_DIR)%.o : %.cpp
	@mkdir -p $(BUILT_DIR)
	$(CPP_FLAGS) -MMD -MP  -c $< -o $@

-include $(DEPENDENCIES)

clean :
	rm -rf objs

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all re clean fclean
