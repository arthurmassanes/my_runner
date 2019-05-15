##
## EPITECH PROJECT, 2018
## my runner
## File description:
## makefile
##

SRC	=	src/main.c	\
		src/create_object.c	\
		src/display.c	\
		src/event.c	\
		src/sound.c	\
		src/ground.c	\
		src/help.c	\
		src/my_runner.c	\
		src/create_player.c	\
		src/score.c	\
		src/menu.c	\
		src/random.c	\
		src/replay.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

HEAD	=	-I./include

LIB	=	-lcsfml-window -lcsfml-graphics -lcsfml-audio

all:
	@gcc -o $(NAME) $(SRC) $(LIB) $(HEAD)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
