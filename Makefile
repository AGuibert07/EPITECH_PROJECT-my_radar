##
## EPITECH PROJECT, 2025
## G1 - C Graphical Programming - my_hunter
## File description:
## main Makefile
##

CC		=	epiclang

CPPFLAGS	=	-Iinclude/

SRC		=	src/main.c					\
			src/script_data.c

NAME	=	'my_radar'

OBJ		=	$(SRC:.c=.o)

all:	my_radar

libmy.a:
	cd lib/my && make re && cd ../../

libmy_pull:
	cd lib/libmy_repo && git pull && cd ../../

libmy_cp:
	cp -r lib/libmy_repo/* lib/my/
	cp lib/libmy_repo/my.h include/my.h

libmy_update:	libmy_pull libmy_cp

my_radar:	libmy.a	$(OBJ)
	$(CC) $(OBJ) -l csfml-graphics -L lib -l my -o $(NAME) $(CPPFLAGS)

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
	rm -f *.o lib/my/*.o $(NAME) src/*.o
	rm -f lib/libmy.a

re:	fclean all

.PHONY:	all libmy.a libmy_pull libmy_cp libmy_update my_radar clean fclean ffclean re
