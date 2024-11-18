##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## call to Makefile in lib
##

SRC	=	src/main.cpp	\
		src/multiplayer.cpp	\
		src/server.cpp	\
		src/join.cpp		\
		src/is_number.cpp		\

OBJ	=	$(SRC:.cpp=.o)

NAME    =	aConnect4

INCL	=	-Iinclude

CC		=	g++

FLAGS	=	-g -g3

SFML	=	-lsfml-network -lsfml-system -lsfml-graphics -lsfml-window

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(SRC) $(INCL) $(FLAGS) $(SFML)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f #*#

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
