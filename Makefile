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
		$(RM) $(NAME) .DS_Store a.out
		rm -rf $(NAME).dSYM a.out.dSYM

re: clean
	all
	
.PHONY: all clean re