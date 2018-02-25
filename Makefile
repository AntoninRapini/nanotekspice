##
## EPITECH PROJECT, 2018
## iostream
## File description:
## Makefile
##


CXXFLAGS += -Wall -Werror -Wextra
CXXFLAGS += -I include/

SRC	=	main.cpp	\

OBJ	=	$(SRC:.cpp=.o)

NAME	= 	nanotekspice

$(NAME): $(OBJ)
	g++ $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
