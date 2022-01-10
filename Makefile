NAME	= vector
SRC 	= main.cpp
HEADER	= vector.hpp RandIter.hpp ReverseRandIter.hpp
RM		= rm -f
FLAGS	= -g -Wall -Wextra -Werror -std=c++98
CC		= clang++

all:	$(HEADER)
		$(CC) $(FLAGS) $(SRC) -o $(NAME)

$(NAME): all

clean:
		$(RM) $(NAME) .DS_Store
		rm -rf $(NAME).dSYM

re: clean
	all
	
.PHONY: all clean re