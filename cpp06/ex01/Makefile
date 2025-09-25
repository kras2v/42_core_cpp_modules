NAME		=	Serializer
CPP_FLAGS	=	c++ -Wall -Wextra -Werror -Wno-unused-parameter -std=c++17
SRCS		=	main.cpp \
				Serializer.cpp \
				Data.cpp

BUILT_DIR	=	objs/
OBJS		=	$(SRCS:.cpp=.o)
OBJECTS		=	$(addprefix $(BUILT_DIR), $(OBJS))

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CPP_FLAGS) $(OBJECTS) -o $@

debug: CPP_FLAGS += -DDEBUG
debug: $(OBJECTS) $(NAME)

$(BUILT_DIR)%.o : %.cpp
	@mkdir -p $(BUILT_DIR)
	$(CPP_FLAGS) -c $< -o $@

clean :
	rm -rf $(BUILT_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all re clean fclean
