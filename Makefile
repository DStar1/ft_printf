# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 20:09:46 by hasmith           #+#    #+#              #
#    Updated: 2017/11/22 20:13:21 by hasmith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

LIBF = libft/

LIB = libftprintf.a

MAIN = main.c

TEST = <argv[1]>

SRC =	ft_printf.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

# add $(FALGS) after all gcc
$(NAME):
	make all -C libft
	gcc -g -c $(SRC)
	ar rc $(LIB) *.o libft/libft.a
	ranlib $(LIB)
#	gcc -g -o $(NAME) $(LIB) $(MAIN)

cmain:
	gcc -g -o $(NAME) $(LIB) $(MAIN)
	./$(NAME)

clean:
	/bin/rm -f *.o
	make clean -C libft
	/bin/rm -f $(LIB)

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all

