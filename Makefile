##
## EPITECH PROJECT, 2017
## MAKEFILE
## File description:
## Makefile
##

NAME	= bsq

CC	= gcc -g

RM	= rm -f

SRCS	=	./src/main.c 		\
		./src/open_my_file.c	\
		./src/fill_struct.c

OBJS	= $(SRCS:.c=.o)

LIB = -L ./lib/ -lmy

CFLAGS = -I ./include/

CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 make -C ./lib/my/
	 $(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./lib/my/

re: fclean all

.PHONY: all clean fclean re
