# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkobb <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/14 09:17:57 by tkobb             #+#    #+#              #
#    Updated: 2018/08/14 21:10:23 by tkobb            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
FLAGS = -Wall -Wextra -Werror
SRCS = lib.c llist.c error.c first_line.c read_map.c print_map.c solver.c bsq.c main.c

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) -o $(NAME)

clean:

fclean:
	/bin/rm -f $(NAME)