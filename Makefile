##
## EPITECH PROJECT, 2021
## makefile
## File description:
## makefile
##

NAME = 42sh

SRC = *.c

all:
	gcc -g3 -o $(NAME) $(SRC) -L./include -I./include

clean:
	rm -f *~ | rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all
