##
## EPITECH PROJECT, 2018
## iostream
## File description:
## Makefile
##


CXXFLAGS += -Wall -Werror -Wextra -std=c++11 -g3
CXXFLAGS += -I include/

SRC	=	main.cpp	\
		src/components/AComponent.cpp	\
		src/components/ComponentFactory.cpp	\
		src/components/Pin.cpp		\
		src/components/Input.cpp	\
		src/components/Output.cpp	\
		src/components/Clock.cpp	\
		src/components/True.cpp		\
		src/components/False.cpp	\
		src/components/LogicGates.cpp	\
		src/components/C4081.cpp	\
		src/components/C4001.cpp	\
		src/components/C4011.cpp	\
		src/components/C4030.cpp	\
		src/components/C4071.cpp	\
		src/components/C4069.cpp	\
		src/components/C4013.cpp	\
		src/components/C4008.cpp	\
		src/NtsManager.cpp		\
		src/exceptions/Exceptions.cpp \
		src/parser/Parser.cpp	\
		src/console/ConsoleAnalyser.cpp

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
