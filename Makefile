##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for the My RPG project
##

SRC	=	src/main.c		\
		src/game.c		\
		src/load_file.c		\
		src/string.c		\
		src/pathfinding.c	\
		src/finder.c		\
		src/draw_path.c		\
		src/map_render.c	\
		src/check_click.c	\
		src/player_move.c	\
		src/check_position.c	\
		src/display.c		\
		src/init_game.c		\
		src/sprite_scale.c	\
		src/print_functions.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS = -I ./include -lc_graph_prog -Wall #-Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
