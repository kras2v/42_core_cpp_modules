NAME = program

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++17 -Iincludes -Itests

SRC_DIR = sources
TST_DIR = tests
OBJ_DIR = objects

SRCS = \
	$(SRC_DIR)/main.cpp \
	$(SRC_DIR)/Point.cpp \
	$(TST_DIR)/Randomizer.cpp

OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(notdir $(SRCS)))
DEPS = $(OBJS:.o=.d)

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

-include $(DEPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(TST_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

debug: CXXFLAGS += -DDEBUG
debug: re

.PHONY: all clean fclean re debug