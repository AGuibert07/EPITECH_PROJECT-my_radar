##
## EPITECH PROJECT, 2025
## G1 - C Graphical Programming - my_hunter
## File description:
## main Makefile
##

CC		=	epiclang

CPPFLAGS	=	-Iinclude/

SRC		=	src/main.c											\
			src/script_data.c									\
			src/sprites_structs.c								\
			src/collisions.c									\
			src/render_screen.c									\
			src/events_traitment.c								\
			src/set_textures_and_sprites.c						\
			src/textures_tools.c								\
			src/keyboard_events/enable_and_disable_elements.c	\
			src/keyboard_events/switch_textures.c				\
			src/keyboard_events/other_keyboard_events.c

REPORT	=	src/report.c

BONUS	=	bonus/report.c

NAME	=	'my_radar'

OBJ		=	$(SRC:.c=.o)

OBJ_REPORT	=	$(REPORT:.c=.o)

OBJ_BONUS	=	$(BONUS:.c=.o)

all:	my_radar

libmy.a:
	cd lib/my && make re && cd ../../

libmy_pull:
	cd lib/libmy_repo && git pull && cd ../../

libmy_cp:
	cp -r lib/libmy_repo/* lib/my/
	cp lib/libmy_repo/my.h include/my.h

libmy_update:	libmy_pull libmy_cp

my_radar:	libmy.a	$(OBJ) $(OBJ_REPORT)
	$(CC) $(OBJ) $(OBJ_REPORT) -l csfml-graphics -l csfml-system -l m -L lib -l my -o $(NAME) $(CPPFLAGS)

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
	rm -f *.o lib/my/*.o $(NAME) src/*.o src/*/*.o
	rm -f lib/libmy.a

re:	fclean all

bonus:		libmy.a $(OBJ) $(OBJ_BONUS)
	$(CC) $(OBJ) $(OBJ_BONUS) -l csfml-graphics -l csfml-system -l m -L lib -l my -o $(NAME) $(CPPFLAGS)

.PHONY:	all libmy.a libmy_pull libmy_cp libmy_update my_radar clean fclean ffclean re
