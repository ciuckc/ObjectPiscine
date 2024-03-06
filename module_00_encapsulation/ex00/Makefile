NAME = divide_and_conquer

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++11#-g -fsanitize=address

INCLUDE = inc

SRC_DIR = src

SRC = main.cpp Bank.cpp BankAccount.cpp

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

DEP_DIR = dep

DEPS =  $(addprefix $(DEP_DIR)/, $(SRC:.cpp=.d))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) $^ -o $@

$(DEP_DIR):
	mkdir -p $@

$(OBJ_DIR):
	mkdir -p $@

-include $(DEPS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(DEP_DIR) $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -MM -MT $@ -MF $(@:$(OBJ_DIR)/%.o=$(DEP_DIR)/%.d) $< 
	$(CXX) $(CXXFLAGS) -I $(INCLUDE) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	$(RM) -r $(NAME)

re: fclean
	$(MAKE)

.PHONY: all clean fclean re

