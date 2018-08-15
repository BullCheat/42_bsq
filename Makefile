# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkobb <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 09:17:57 by tkobb             #+#    #+#              #
#    Updated: 2018/08/15 13:03:21 by adrean           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
FLAGS = -Wall -Wextra -Werror -O3 -m32
SRCS = lib.c \
	   llist.c \
	   error.c \
	   first_line.c \
	   transform.c \
	   read_map.c \
	   print_map.c \
	   solver.c \
	   bsq.c \
	   main.c

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) -o $(NAME)

clean:

fclean:
	/bin/rm -f $(NAME)

re: fclean all
