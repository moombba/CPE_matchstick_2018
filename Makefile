##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Task 01
##

SRCDIR	=	src/

SRC =   create_map.c \
        my_getnbr.c \
        display.c \
        in_game.c \
        remove.c \
        main.c \
        tool.c \
        ai.c \
        printf/*

SRCS =  $(addprefix $(SRCDIR), $(SRC))

CFLAGS  +=  -I./include -W -Wall -Wextra

CC	=	gcc -g3 -o

NAME 	=  matchstick

all:	$(NAME)

LIB:	make -C

$(NAME):
	$(CC) $(NAME) $(SRCS) $(CFLAGS)

clean:
	rm -f $(OBJ);

fclean:	clean
	rm -f $(NAME);
	rm -f *.gc*

re:	fclean all

auteur:
	echo $(USER) > auteur


