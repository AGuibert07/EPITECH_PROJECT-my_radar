##
## EPITECH PROJECT, 2025
## G1 - C Graphical Programming - my_hunter
## File description:
## main Makefile
##

CC		=	epiclang

CPPFLAGS	=	-Iinclude/

SRC		=	main.c

NAME	=	'my_radar'

OBJ		=	$(SRC:.c=.o)

all:	my_hunter

libmy.a:
	cd lib/my && make re && cd ../../

my_hunter:	libmy.a	$(OBJ)
	$(CC) $(OBJ) -l csfml-graphics -l csfml-system -lm -L lib -l my -o $(NAME) $(CPPFLAGS)

clean:
	cd lib/my && rm -f && cd ../../
	rm lib/my/*.o lib/libmy.a

fclean:
	rm -f *~
	rm -f \#*#
	rm -f *.gc*
	rm -f unit_tests*
	rm -fr .vscode

ffclean:	fclean
	rm -f *.o lib/my/*.o $(NAME) src_files/*.o src_files/*/*.o
	rm -f lib/libmy.a

re:	fclean all

.PHONY:	all libmy.a my_hunter clean fclean ffclean re
