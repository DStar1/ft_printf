# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 20:09:46 by hasmith           #+#    #+#              #
#    Updated: 2017/12/08 19:55:28 by hasmith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = ft_printf.a

GIT = test

libft = libft/ft_bzero.c \
	   libft/ft_atoi.c \
	   libft/ft_itoa.c \
	   libft/ft_isalpha.c \
	   libft/ft_isdigit.c \
	   libft/ft_isalnum.c \
	   libft/ft_isascii.c \
	   libft/ft_isprint.c \
	   libft/ft_toupper.c \
	   libft/ft_tolower.c \
	   libft/ft_memset.c \
	   libft/ft_memcpy.c \
	   libft/ft_memccpy.c \
	   libft/ft_memmove.c \
	   libft/ft_memchr.c \
	   libft/ft_memcmp.c \
	   libft/ft_memalloc.c \
	   libft/ft_memdel.c \
	   libft/ft_putchar.c \
	   libft/ft_putstr.c \
	   libft/ft_putendl.c \
	   libft/ft_putnbr.c \
	   libft/ft_putchar_fd.c \
	   libft/ft_putstr_fd.c \
	   libft/ft_putendl_fd.c \
	   libft/ft_putnbr_fd.c \
	   libft/ft_strlen.c \
	   libft/ft_strdup.c \
	   libft/ft_strcpy.c \
	   libft/ft_strncpy.c \
	   libft/ft_strcat.c \
	   libft/ft_strncat.c \
	   libft/ft_strlcat.c \
	   libft/ft_strchr.c \
	   libft/ft_strrchr.c \
	   libft/ft_strstr.c \
	   libft/ft_strnstr.c \
	   libft/ft_strcmp.c \
	   libft/ft_strncmp.c \
	   libft/ft_strnew.c \
	   libft/ft_strdel.c \
	   libft/ft_strclr.c \
	   libft/ft_striter.c \
	   libft/ft_striteri.c \
	   libft/ft_strmap.c \
	   libft/ft_strmapi.c \
	   libft/ft_strequ.c \
	   libft/ft_strnequ.c \
	   libft/ft_strsub.c \
	   libft/ft_strjoin.c \
	   libft/ft_strtrim.c \
	   libft/ft_strsplit.c \
	   libft/ft_lstnew.c \
	   libft/ft_lstdelone.c \
	   libft/ft_lstdel.c \
	   libft/ft_lstadd.c \
	   libft/ft_lstiter.c \
	   libft/ft_intlen.c \
	   libft/ft_atoi_base.c \
	   libft/ft_power.c \
	   libft/ft_lstmap.c

PRINTF = 	parse.c \
			string.c \
			ft_int.c \
			ft_puthex.c \
			ft_hex.c \
			ft_pf_intlen.c \
			ft_pf_putnbr.c \
			ft_percent.c \
			ft_unsigned_int.c \
			ft_oct.c \
			ft_putoct.c \
			ft_pointer.c \
			wchars.c \
			ft_print_bits.c \
			flags.c \
			ft_n.c \
			ft_printf.c

NAME = libftprintf.a

MAIN = main.c

EXE = ft_printf

TEST = <argv[1]>

SRC = $(PRINTF)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make all -C libft
	gcc -g -c $(SRC)
	cp libft/libft.a $(NAME) 
	ar rcs $(NAME) *.o

cmain:
	make re
	gcc -g -o $(EXE) $(NAME) $(MAIN)
	make clean
	./$(EXE)

clean:
	/bin/rm -f *.o
	make clean -C libft

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all

rhe: fclean H

git:
	make fclean
	git add *
	git commit -m '$(GIT)'
	git push