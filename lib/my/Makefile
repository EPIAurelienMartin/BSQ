##
## EPITECH PROJECT, 2017
## makefile
## File description:
## make
##

CC	=	gcc

RM	=	rm -rf

CFLAGS	+=	-Wextra -Wall

CFLAGS	+=	-I ./include/

NAME	=	libmy.a

SRCS	=	concat_params.c				\
		my_compute_factorial_it.c		\
		my_compute_factorial_rec.c		\
		my_compute_power_it.c			\
		my_compute_square_root.c		\
		my_evil_str.c				\
		my_find_prime_sup.c			\
		my_getnbr.c				\
		my_is_prime.c				\
		my_isneg.c				\
		my_print_alpha.c			\
		my_print_comb.c				\
		my_print_comb2.c			\
		my_print_digits.c			\
		my_print_revalpha.c			\
		my_put_nbr.c				\
		my_putchar.c				\
		my_putnbr_base.c			\
		my_putstr.c				\
		my_revstr.c				\
		my_show_word_array.c			\
		my_showmem.c				\
		my_showstr.c				\
		my_sort_int_array.c			\
		my_str_isalpha.c			\
		my_str_islower.c			\
		my_str_isnum.c				\
		my_str_isprintable.c			\
		my_str_isupper.c			\
		my_str_to_word_array.c			\
		my_strcapitalize.c			\
		my_strcat.c				\
		my_strcmp.c				\
		my_strcpy.c				\
		my_strdup.c				\
		my_strlen.c				\
		my_strlowcase.c				\
		my_strncat.c				\
		my_strncmp.c				\
		my_strncpy.c				\
		my_strstr.c				\
		my_strupcase.c				\
		my_swap.c				\
		my_getnbr_base.c			\
		my_printf.c				\
		my_put_nbr_unsigned.c			\
		my_nb_len.c				\
		convert_base.c				\
		my_getnb.c				\
		next_flag.c				\
		my_sign.c				\
		my_size_space_check.c			\
		my_modu_l.c				\
		to_send_inp.c				\
		my_speciale_putnbr.c

OBJS	=	$(SRCS:.c=.o)

HEADER	=	my.h

all	:	$(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
	cp my.h ../../include/
	cp libmy.a ../
	rm *.o

clean	:
	$(RM) $(OBJS)

fclean :	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY:	all clean fclean re
