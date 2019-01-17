##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

D_SRC	=	./src/
D_INC	=	./include/
D_LIB	=	./lib/my/

SRC	=	$(D_SRC)main.c			\
		$(D_SRC)set.c			\
		$(D_SRC)set2.c			\
		$(D_SRC)set_obj.c		\
		$(D_SRC)map.c			\
		$(D_SRC)circle.c		\
		$(D_SRC)draw.c			\
		$(D_SRC)line.c			\
		$(D_SRC)time.c			\
		$(D_SRC)set_img.c		\
		$(D_SRC)colision.c		\
		$(D_SRC)collision_circle.c	\
		$(D_SRC)txt.c			\
		$(D_SRC)bullet.c		\
		$(D_SRC)check.c

OBJ	=	$(SRC:%.c=%.o)

NAME	=	my_radar

CFLAGS	=	-W -Wall -Wextra -I$(D_INC)

LDFLAGS	=	-L$(D_LIB) -lmy

all:	$(NAME)

libmy:
	make -C $(D_LIB)

clean:
	rm -f $(OBJ)

fclean:
	$(MAKE) clean
	$(MAKE) -C $(D_LIB) fclean
	rm -f $(NAME)
	rm -f *~

$(NAME): $(OBJ)
	$(MAKE) -C lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) -l csfml-graphics -l csfml-system -lm
	rm -f $(OBJ)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
